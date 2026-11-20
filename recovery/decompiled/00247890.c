/* Decompiled from supplied 5.2.2 arm package. VA 0x247890. FUN_00247890 */

void FUN_00247890(void *param_1,long param_2,void *param_3,uint param_4,short *param_5)

{
  void *pvVar1;
  uint uVar2;
  short sVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  short *local_88;
  undefined1 auStack_7e [22];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  pvVar1 = (void *)((long)param_3 + (long)(int)param_4 * 2);
  uVar2 = param_4 + 1;
  sVar3 = (short)uVar2;
  if (*param_5 == 0x1e) {
    FUN_0024a60c(auStack_7e,param_5 + 0x12,param_3,(long)DAT_00c4f110,param_4);
    uVar7 = -(ulong)(uVar2 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar2 << 1;
    _memcpy(param_1,auStack_7e,uVar7);
    FUN_00245af8(param_2,auStack_7e,&DAT_00c4e828,(int)sVar3);
    lVar6 = (-(ulong)(param_4 >> 0x1f) & 0xfffffffe00000000 | (ulong)param_4 << 1) + 2;
    lVar5 = lVar6;
    for (lVar4 = 2; lVar4 != 0xc; lVar4 = lVar4 + 2) {
      FUN_0024a60c(auStack_7e,param_3,pvVar1,(long)*(short *)((long)&DAT_00c4f110 + lVar4),param_4);
      _memcpy((void *)((long)param_1 + lVar5),auStack_7e,uVar7);
      FUN_00245af8(param_2 + lVar5,auStack_7e,&DAT_00c4e828,(int)sVar3);
      lVar5 = lVar5 + lVar6;
    }
  }
  else {
    lVar4 = 0;
    for (lVar6 = 0; lVar6 < param_5[2]; lVar6 = lVar6 + 1) {
      FUN_0024a60c(auStack_7e,param_5 + 0x12,param_3,(long)(short)(&DAT_00c4f108)[lVar6],param_4);
      _memcpy((void *)((long)param_1 + lVar4),auStack_7e,
              -(ulong)(uVar2 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar2 << 1);
      FUN_00245af8(param_2 + lVar4,auStack_7e,&DAT_00c4e828,(int)sVar3);
      lVar4 = lVar4 + (-(ulong)(param_4 >> 0x1f) & 0xfffffffe00000000 | (ulong)param_4 << 1) + 2;
    }
  }
  local_88 = param_5 + 0x12;
  if (*param_5 == 0x1e) {
    param_3 = pvVar1;
  }
  _memcpy(local_88,param_3,(long)(int)param_4 << 1);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


