/* Decompiled from supplied 5.2.2 arm package. VA 0x275f14. FUN_00275f14 */

void FUN_00275f14(void)

{
  double dVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  double dVar5;
  
  dVar1 = DAT_00c51e80;
  lVar2 = 0xffc;
  lVar3 = 4;
  for (lVar4 = 0; lVar4 != 0x201; lVar4 = lVar4 + 1) {
    dVar5 = (double)_cos((double)(int)lVar4 * dVar1);
    (&_ff_cos_2048_float)[lVar4] = (float)dVar5;
  }
  for (; lVar3 != 0x800; lVar3 = lVar3 + 4) {
    *(undefined4 *)((long)&_ff_cos_2048_float + lVar2) =
         *(undefined4 *)((long)&_ff_cos_2048_float + lVar3);
    lVar2 = lVar2 + -4;
  }
  return;
}


