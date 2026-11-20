/* Decompiled from supplied 5.2.2 arm package. VA 0x26be6c. _av_sha512_update */

void _av_sha512_update(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  ulong *puVar12;
  long lVar13;
  uint uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  long lVar19;
  ulong uVar20;
  ulong uVar21;
  ulong uVar22;
  ulong uVar23;
  ulong uVar24;
  ulong uVar25;
  ulong uVar26;
  ulong auStack_368 [9];
  ulong auStack_320 [5];
  ulong auStack_2f8 [82];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar14 = (uint)*(long *)(param_1 + 8) & 0x7f;
  *(ulong *)(param_1 + 8) = *(long *)(param_1 + 8) + (ulong)param_3;
  for (lVar13 = 0; (uint)lVar13 != param_3; lVar13 = lVar13 + 1) {
    uVar1 = uVar14 + 1;
    *(undefined1 *)(param_1 + (ulong)uVar14 + 0x10) = *(undefined1 *)(param_2 + lVar13);
    uVar14 = uVar1;
    if (uVar1 == 0x80) {
      uVar2 = *(ulong *)(param_1 + 0x90);
      uVar6 = *(ulong *)(param_1 + 0x98);
      uVar3 = *(ulong *)(param_1 + 0xa0);
      uVar7 = *(ulong *)(param_1 + 0xa8);
      uVar4 = *(ulong *)(param_1 + 0xb0);
      uVar8 = *(ulong *)(param_1 + 0xb8);
      uVar5 = *(ulong *)(param_1 + 0xc0);
      uVar9 = *(ulong *)(param_1 + 200);
      uVar23 = uVar5;
      puVar12 = auStack_2f8 + 2;
      uVar16 = uVar8;
      uVar17 = uVar7;
      uVar18 = uVar3;
      uVar20 = uVar9;
      uVar11 = uVar2;
      uVar22 = uVar4;
      uVar25 = uVar6;
      for (lVar10 = 0; uVar21 = uVar11, uVar11 = uVar23, lVar10 != 0x50; lVar10 = lVar10 + 1) {
        if (lVar10 < 0x10) {
          uVar23 = *(ulong *)(param_1 + 0x10 + lVar10 * 8);
          uVar23 = (uVar23 & 0xff00ff00ff00ff00) >> 8 | (uVar23 & 0xff00ff00ff00ff) << 8;
          uVar23 = (uVar23 & 0xffff0000ffff0000) >> 0x10 | (uVar23 & 0xffff0000ffff) << 0x10;
          uVar23 = uVar23 >> 0x20 | uVar23 << 0x20;
        }
        else {
          uVar23 = puVar12[-0xf];
          uVar26 = puVar12[-2];
          uVar23 = puVar12[-7] + puVar12[-0x10] +
                   ((uVar23 >> 8 | uVar23 << 0x38) ^ uVar23 >> 7 ^ (uVar23 >> 1 | uVar23 << 0x3f)) +
                   ((uVar26 >> 0x3d | uVar26 << 3) ^ uVar26 >> 6 ^ (uVar26 >> 0x13 | uVar26 << 0x2d)
                   );
        }
        uVar15 = uVar18 | uVar25;
        uVar24 = uVar18 & uVar25;
        lVar19 = (&DAT_00c51b70)[lVar10];
        *puVar12 = uVar23;
        lVar19 = ((uVar22 >> 0xe | uVar22 << 0x32) ^ (uVar22 >> 0x12 | uVar22 << 0x2e) ^
                 (uVar22 >> 0x29 | uVar22 << 0x17)) + uVar20 + ((uVar11 ^ uVar16) & uVar22 ^ uVar11)
                 + uVar23 + lVar19;
        uVar26 = lVar19 + uVar17;
        uVar23 = uVar16;
        puVar12 = puVar12 + 1;
        uVar16 = uVar22;
        uVar17 = uVar18;
        uVar18 = uVar25;
        uVar20 = uVar11;
        uVar11 = ((uVar21 >> 0x1c | uVar21 << 0x24) ^ (uVar21 >> 0x22 | uVar21 << 0x1e) ^
                 (uVar21 >> 0x27 | uVar21 << 0x19)) + (uVar21 & uVar15 | uVar24) + lVar19;
        uVar22 = uVar26;
        uVar25 = uVar21;
      }
      uVar14 = 0;
      *(ulong *)(param_1 + 0x90) = uVar21 + uVar2;
      *(ulong *)(param_1 + 0x98) = uVar25 + uVar6;
      *(ulong *)(param_1 + 0xa0) = uVar18 + uVar3;
      *(ulong *)(param_1 + 0xa8) = uVar17 + uVar7;
      *(ulong *)(param_1 + 0xb0) = uVar22 + uVar4;
      *(ulong *)(param_1 + 0xb8) = uVar16 + uVar8;
      *(ulong *)(param_1 + 0xc0) = uVar11 + uVar5;
      *(ulong *)(param_1 + 200) = uVar20 + uVar9;
    }
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


