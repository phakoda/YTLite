import Foundation
import CryptoKit

enum FixtureError: Error { case usage, malformedInput, invalidHex }

func unhex(_ text: String) throws -> Data {
    guard text.count % 2 == 0 else { throw FixtureError.invalidHex }
    var result = Data()
    var index = text.startIndex
    while index != text.endIndex {
        let end = text.index(index, offsetBy: 2)
        guard let byte = UInt8(text[index..<end], radix: 16) else { throw FixtureError.invalidHex }
        result.append(byte)
        index = end
    }
    return result
}

// Fixture generation only. AES-GCM encryption uses CryptoKit, independently of
// the reconstructed CommonCrypto decryption code under test. No real secrets,
// network requests, user Keychain items, or executable package code are used.
guard CommandLine.arguments.count == 3 else { throw FixtureError.usage }
let input = URL(fileURLWithPath: CommandLine.arguments[1])
let output = URL(fileURLWithPath: CommandLine.arguments[2])
guard var fixtures = try JSONSerialization.jsonObject(with: Data(contentsOf: input)) as? [String: Any],
      let records = fixtures["records"] as? [[String: Any]] else { throw FixtureError.malformedInput }
fixtures["records"] = try records.map { entry -> [String: Any] in
    var record = entry
    guard let key = entry["key"] as? String, let salt = entry["salt"] as? String,
          let nonce = entry["nonce"] as? String, let plaintext = entry["plaintext_base64"] as? String,
          let bytes = Data(base64Encoded: plaintext) else { throw FixtureError.malformedInput }
    let sealed = try AES.GCM.seal(bytes, using: SymmetricKey(data: unhex(key)), nonce: AES.GCM.Nonce(data: unhex(nonce)))
    var packagedRecord = try unhex(salt)
    packagedRecord.append(contentsOf: sealed.nonce)
    packagedRecord.append(sealed.tag)
    packagedRecord.append(sealed.ciphertext)
    record["encoded"] = packagedRecord.base64EncodedString()
    return record
}
try JSONSerialization.data(withJSONObject: fixtures, options: [.prettyPrinted, .sortedKeys]).write(to: output, options: .atomic)
print("Generated CryptoKit AES-GCM fixtures without contacting a server or reading a Keychain.")
