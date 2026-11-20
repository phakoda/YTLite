/* Decompiled from supplied 5.2.2 arm package. VA 0x27a8e4. FUN_0027a8e4 */

void FUN_0027a8e4(void)

{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  double dVar7;
  
  dVar2 = DAT_00c51f00;
  dVar1 = DAT_00c51e88;
  lVar4 = 0x1ffc;
  lVar5 = 4;
  for (lVar6 = 0; lVar6 != 0x401; lVar6 = lVar6 + 1) {
    dVar7 = (double)_cos((double)(int)lVar6 * dVar1);
    uVar3 = _lrintf((float)(dVar7 * dVar2));
    (&_ff_cos_4096_int32)[lVar6] = uVar3;
  }
  for (; lVar5 != 0x1000; lVar5 = lVar5 + 4) {
    *(undefined4 *)((long)&_ff_cos_4096_int32 + lVar4) =
         *(undefined4 *)((long)&_ff_cos_4096_int32 + lVar5);
    lVar4 = lVar4 + -4;
  }
  return;
}


