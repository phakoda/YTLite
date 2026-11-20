/* Decompiled from supplied 5.2.2 arm package. VA 0x26bba8. _av_sha512_init */

undefined4 _av_sha512_init(undefined1 *param_1,uint param_2)

{
  undefined8 uVar1;
  
  *param_1 = (char)(param_2 >> 6);
  if ((int)param_2 < 0x180) {
    if (param_2 == 0xe0) {
      *(undefined8 *)(param_1 + 0x90) = 0x8c3d37c819544da2;
      *(undefined8 *)(param_1 + 0x98) = 0x73e1996689dcd4d6;
      *(undefined8 *)(param_1 + 0xa0) = 0x1dfab7ae32ff9c82;
      *(undefined8 *)(param_1 + 0xa8) = 0x679dd514582f9fcf;
      *(undefined8 *)(param_1 + 0xb0) = 0xf6d2b697bd44da8;
      *(undefined8 *)(param_1 + 0xb8) = 0x77e36f7304c48942;
      *(undefined8 *)(param_1 + 0xc0) = 0x3f9d85a86a1d36c8;
      uVar1 = 0x1112e6ad91d692a1;
    }
    else {
      if (param_2 != 0x100) {
        return 0xffffffea;
      }
      *(undefined8 *)(param_1 + 0x90) = 0x22312194fc2bf72c;
      *(undefined8 *)(param_1 + 0x98) = 0x9f555fa3c84c64c2;
      *(undefined8 *)(param_1 + 0xa0) = 0x2393b86b6f53b151;
      *(undefined8 *)(param_1 + 0xa8) = 0x963877195940eabd;
      *(undefined8 *)(param_1 + 0xb0) = 0x96283ee2a88effe3;
      *(undefined8 *)(param_1 + 0xb8) = 0xbe5e1e2553863992;
      *(undefined8 *)(param_1 + 0xc0) = 0x2b0199fc2c85b8aa;
      uVar1 = 0xeb72ddc81c52ca2;
    }
  }
  else if (param_2 == 0x180) {
    *(undefined8 *)(param_1 + 0x90) = 0xcbbb9d5dc1059ed8;
    *(undefined8 *)(param_1 + 0x98) = 0x629a292a367cd507;
    *(undefined8 *)(param_1 + 0xa0) = 0x9159015a3070dd17;
    *(undefined8 *)(param_1 + 0xa8) = 0x152fecd8f70e5939;
    *(undefined8 *)(param_1 + 0xb0) = 0x67332667ffc00b31;
    *(undefined8 *)(param_1 + 0xb8) = 0x8eb44a8768581511;
    *(undefined8 *)(param_1 + 0xc0) = 0xdb0c2e0d64f98fa7;
    uVar1 = 0x47b5481dbefa4fa4;
  }
  else {
    if (param_2 != 0x200) {
      return 0xffffffea;
    }
    *(undefined8 *)(param_1 + 0x90) = 0x6a09e667f3bcc908;
    *(undefined8 *)(param_1 + 0x98) = 0xbb67ae8584caa73b;
    *(undefined8 *)(param_1 + 0xa0) = 0x3c6ef372fe94f82b;
    *(undefined8 *)(param_1 + 0xa8) = 0xa54ff53a5f1d36f1;
    *(undefined8 *)(param_1 + 0xb0) = 0x510e527fade682d1;
    *(undefined8 *)(param_1 + 0xb8) = 0x9b05688c2b3e6c1f;
    *(undefined8 *)(param_1 + 0xc0) = 0x1f83d9abfb41bd6b;
    uVar1 = 0x5be0cd19137e2179;
  }
  *(undefined8 *)(param_1 + 200) = uVar1;
  *(undefined8 *)(param_1 + 8) = 0;
  return 0;
}


