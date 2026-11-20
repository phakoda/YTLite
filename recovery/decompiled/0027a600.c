/* Decompiled from supplied 5.2.2 arm package. VA 0x27a600. FUN_0027a600 */

void FUN_0027a600(void)

{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  double dVar7;
  
  dVar2 = DAT_00c51f00;
  dVar1 = DAT_00c51e60;
  lVar4 = 0xfc;
  lVar5 = 4;
  for (lVar6 = 0; lVar6 != 0x21; lVar6 = lVar6 + 1) {
    dVar7 = (double)_cos((double)(int)lVar6 * dVar1);
    uVar3 = _lrintf((float)(dVar7 * dVar2));
    (&_ff_cos_128_int32)[lVar6] = uVar3;
  }
  for (; lVar5 != 0x80; lVar5 = lVar5 + 4) {
    *(undefined4 *)((long)&_ff_cos_128_int32 + lVar4) =
         *(undefined4 *)((long)&_ff_cos_128_int32 + lVar5);
    lVar4 = lVar4 + -4;
  }
  return;
}


