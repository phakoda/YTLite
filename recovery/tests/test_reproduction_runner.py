#!/usr/bin/env python3
"""Regression checks for command selection and reproduction result reporting."""
import importlib.util
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import json

ROOT = Path(__file__).resolve().parents[2]
SPEC = importlib.util.spec_from_file_location("reproduction", ROOT / "recovery/tools/verify_reproduction.py")
runner = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(runner)


def document(commands):
    return ("## Verify the current reconstructed source\n\n```sh\n"
            "git clone https://example.invalid/setup\n```\n\n"
            "<!-- current-source-verification -->\n```sh\n" + commands +
            "\n```\n<!-- /current-source-verification -->\n")


class ReproductionTests(unittest.TestCase):
    def test_real_document_selects_verification_not_setup(self):
        commands = runner.load_commands(ROOT / "recovery/REPRODUCE.md", ROOT)
        self.assertIn(["python3", "recovery/tools/source_inventory.py"], commands)
        self.assertIn(["python3", "recovery/tools/first_package_audit_inventory.py"], commands)
        self.assertTrue(all(command[0] == "python3" for command in commands))

    def test_rejects_missing_ambiguous_empty_and_external_commands(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            path = root / "commands.md"
            script = root / "test.py"
            script.write_text("pass\n")
            for text in ("```sh\npython3 test.py\n```", document(""),
                         document("python3 test.py") * 2,
                         document("python3 ../test.py"), document("git status"),
                         document("python3 missing.py")):
                with self.subTest(text=text):
                    path.write_text(text)
                    with self.assertRaises(ValueError):
                        runner.load_commands(path, root)

    def test_keeps_exit_status_not_assertion_text_and_continues(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "recovery").mkdir()
            (root / "ok.py").write_text('print("AssertionError: deliberately rejected regression")\n')
            (root / "fail.py").write_text('raise SystemExit(7)\n')
            (root / "after.py").write_text('print("still ran")\n')
            (root / "recovery/REPRODUCE.md").write_text(document(
                "python3 ok.py\npython3 fail.py\npython3 after.py"))
            with patch.object(runner, "ROOT", root):
                self.assertEqual(runner.main(), 1)
            report = json.loads((root / ".recovery-work/reproduction/report.json").read_text())
            self.assertEqual(report["status"], "failed")
            self.assertEqual([c["exit_code"] for c in report["commands"]], [0, 7, 0])
            self.assertFalse(report["original_binary_executed"])
            self.assertEqual(report["device_validation"], "not performed")


if __name__ == "__main__":
    unittest.main()
