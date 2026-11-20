/* Decompiled from supplied 5.2.2 arm package. VA 0x2606d8. FUN_002606d8 */

void FUN_002606d8(byte *param_1)

{
  byte bVar1;
  
  for (; bVar1 = *param_1, bVar1 != 0; param_1 = param_1 + 1) {
    if (bVar1 < 8 || (byte)(bVar1 - 0xe) < 0x12) {
      *param_1 = 0x3f;
    }
  }
  return;
}


