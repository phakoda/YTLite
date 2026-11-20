/* Decompiled from supplied 5.2.2 arm package. VA 0x27a978. FUN_0027a978 */

void FUN_0027a978(void)

{
  undefined4 *puVar1;
  double dVar2;
  double dVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  double dVar8;
  
  dVar3 = DAT_00c51f00;
  dVar2 = DAT_00c51e90;
  lVar5 = 0x3ffc;
  lVar6 = 4;
  for (lVar7 = 0; lVar7 != 0x801; lVar7 = lVar7 + 1) {
    dVar8 = (double)_cos((double)(int)lVar7 * dVar2);
    uVar4 = _lrintf((float)(dVar8 * dVar3));
    (&_ff_cos_8192_int32)[lVar7] = uVar4;
  }
  for (; lVar5 != 0x2000; lVar5 = lVar5 + -4) {
    puVar1 = (undefined4 *)((long)&_ff_cos_8192_int32 + lVar6);
    lVar6 = lVar6 + 4;
    *(undefined4 *)((long)&_ff_cos_8192_int32 + lVar5) = *puVar1;
  }
  return;
}


