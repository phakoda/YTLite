/* Decompiled from supplied 5.2.2 arm package. VA 0x27ab4c. FUN_0027ab4c */

void FUN_0027ab4c(void)

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
  dVar2 = DAT_00c51ea8;
  lVar5 = 0x1fffc;
  lVar6 = 4;
  for (puVar7 = (undefined *)0x0; puVar7 != &UNK_00004001; puVar7 = puVar7 + 1) {
    dVar8 = (double)_cos((double)(int)puVar7 * dVar2);
    uVar4 = _lrintf((float)(dVar8 * dVar3));
    (&_ff_cos_65536_int32)[(long)puVar7] = uVar4;
  }
  for (; lVar5 != 0x10000; lVar5 = lVar5 + -4) {
    puVar1 = (undefined4 *)((long)&_ff_cos_65536_int32 + lVar6);
    lVar6 = lVar6 + 4;
    *(undefined4 *)((long)&_ff_cos_65536_int32 + lVar5) = *puVar1;
  }
  return;
}


