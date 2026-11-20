#import <CommonCrypto/CommonCryptor.h>

// The package links the legacy CCCryptorGCM entry point, which writes the
// computed tag even for decryption. Its caller must compare that output with
// the stored tag. Do not replace it with a differently-shaped oneshot API.
// Contract checked against Apple's CommonCrypto/lib/CommonCryptorGCM.c:
// https://github.com/apple-oss-distributions/CommonCrypto/blob/main/lib/CommonCryptorGCM.c
extern CCCryptorStatus CCCryptorGCM(CCOperation operation, CCAlgorithm algorithm,
    const void *key, size_t keyLength, const void *iv, size_t ivLength,
    const void *additionalData, size_t additionalDataLength,
    const void *input, size_t inputLength, void *output, void *tag, size_t *tagLength);
