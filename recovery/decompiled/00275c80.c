/* Decompiled from supplied 5.2.2 arm package. VA 0x275c80. FUN_00275c80 */

void FUN_00275c80(void)

{
  double dVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  double dVar5;
  
  dVar1 = DAT_00c51e58;
  lVar2 = 0x7c;
  lVar3 = 4;
  for (lVar4 = 0; lVar4 != 0x11; lVar4 = lVar4 + 1) {
    dVar5 = (double)_cos((double)(int)lVar4 * dVar1);
    (&_ff_cos_64_float)[lVar4] = (float)dVar5;
  }
  for (; lVar3 != 0x40; lVar3 = lVar3 + 4) {
    *(undefined4 *)((long)&_ff_cos_64_float + lVar2) =
         *(undefined4 *)((long)&_ff_cos_64_float + lVar3);
    lVar2 = lVar2 + -4;
  }
  return;
}


