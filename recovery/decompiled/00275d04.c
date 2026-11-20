/* Decompiled from supplied 5.2.2 arm package. VA 0x275d04. FUN_00275d04 */

void FUN_00275d04(void)

{
  double dVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  double dVar5;
  
  dVar1 = DAT_00c51e60;
  lVar2 = 0xfc;
  lVar3 = 4;
  for (lVar4 = 0; lVar4 != 0x21; lVar4 = lVar4 + 1) {
    dVar5 = (double)_cos((double)(int)lVar4 * dVar1);
    (&_ff_cos_128_float)[lVar4] = (float)dVar5;
  }
  for (; lVar3 != 0x80; lVar3 = lVar3 + 4) {
    *(undefined4 *)((long)&_ff_cos_128_float + lVar2) =
         *(undefined4 *)((long)&_ff_cos_128_float + lVar3);
    lVar2 = lVar2 + -4;
  }
  return;
}


