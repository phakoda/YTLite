/* Decompiled from supplied 5.2.2 arm package. VA 0x275f98. FUN_00275f98 */

void FUN_00275f98(void)

{
  double dVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  double dVar5;
  
  dVar1 = DAT_00c51e88;
  lVar2 = 0x1ffc;
  lVar3 = 4;
  for (lVar4 = 0; lVar4 != 0x401; lVar4 = lVar4 + 1) {
    dVar5 = (double)_cos((double)(int)lVar4 * dVar1);
    (&_ff_cos_4096_float)[lVar4] = (float)dVar5;
  }
  for (; lVar3 != 0x1000; lVar3 = lVar3 + 4) {
    *(undefined4 *)((long)&_ff_cos_4096_float + lVar2) =
         *(undefined4 *)((long)&_ff_cos_4096_float + lVar3);
    lVar2 = lVar2 + -4;
  }
  return;
}


