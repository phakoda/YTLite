/* Decompiled from supplied 5.2.2 arm package. VA 0x27aaac. FUN_0027aaac */

void FUN_0027aaac(void)

{
  undefined4 *puVar1;
  double dVar2;
  double dVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  undefined *puVar7;
  double dVar8;
  
  dVar3 = DAT_00c51f00;
  dVar2 = DAT_00c51ea0;
  lVar5 = 0xfffc;
  lVar6 = 4;
  for (puVar7 = (undefined *)0x0; puVar7 != &DAT_00002001; puVar7 = puVar7 + 1) {
    dVar8 = (double)_cos((double)(int)puVar7 * dVar2);
    uVar4 = _lrintf((float)(dVar8 * dVar3));
    (&_ff_cos_32768_int32)[(long)puVar7] = uVar4;
  }
  for (; lVar5 != 0x8000; lVar5 = lVar5 + -4) {
    puVar1 = (undefined4 *)((long)&_ff_cos_32768_int32 + lVar6);
    lVar6 = lVar6 + 4;
    *(undefined4 *)((long)&_ff_cos_32768_int32 + lVar5) = *puVar1;
  }
  return;
}


