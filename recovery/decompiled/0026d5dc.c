/* Decompiled from supplied 5.2.2 arm package. VA 0x26d5dc. FUN_0026d5dc */

int FUN_0026d5dc(uint param_1)

{
  if (param_1 < 0xa0 && (param_1 & 0xf) < 10) {
    return (param_1 & 0xf) + (param_1 >> 4) * 10;
  }
  return 0;
}


