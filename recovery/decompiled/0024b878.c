/* Decompiled from supplied 5.2.2 arm package. VA 0x24b878. FUN_0024b878 */

void FUN_0024b878(void *param_1,long param_2,void *param_3,void *param_4,void *param_5,void *param_6
                 ,uint param_7,short *param_8)

{
  void *pvVar1;
  void *pvVar2;
  uint uVar3;
  short sVar4;
  short sVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  size_t sVar9;
  long lVar10;
  ulong uVar11;
  int iVar12;
  undefined1 auStack_7e [22];
  long local_68;
  
  uVar11 = (ulong)param_7;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar3 = param_7 + 1;
  sVar5 = (short)uVar3;
  if (*param_8 == 0x1e) {
    pvVar1 = (void *)((long)param_3 + (long)(int)param_7 * 2);
    pvVar2 = (void *)((long)param_4 + (long)(int)param_7 * 2);
    iVar12 = (int)DAT_00c4f110;
    FUN_0024a664(auStack_7e,param_6,param_4,iVar12,uVar11);
    uVar6 = -(ulong)(uVar3 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar3 << 1;
    _memcpy(param_1,auStack_7e,uVar6);
    FUN_0024a664(auStack_7e,param_5,param_3,iVar12,uVar11);
    FUN_00245af8(param_2,auStack_7e,&DAT_00c4e83e,(int)sVar5);
    lVar7 = (-(ulong)(param_7 >> 0x1f) & 0xfffffffe00000000 | uVar11 << 1) + 2;
    lVar10 = lVar7;
    for (lVar8 = 1; lVar8 < param_8[2]; lVar8 = lVar8 + 1) {
      sVar4 = (&DAT_00c4f110)[lVar8];
      FUN_0024a664(auStack_7e,param_4,pvVar2,(int)sVar4,uVar11);
      _memcpy((void *)((long)param_1 + lVar10),auStack_7e,uVar6);
      FUN_0024a664(auStack_7e,param_3,pvVar1,(int)sVar4,uVar11);
      FUN_00245af8(param_2 + lVar10,auStack_7e,&DAT_00c4e83e,(int)sVar5);
      lVar10 = lVar10 + lVar7;
    }
    sVar9 = (long)(int)param_7 << 1;
    _memcpy(param_5,pvVar1,sVar9);
    _memcpy(param_6,pvVar2,sVar9);
    lVar7 = *(long *)PTR____stack_chk_guard_01060708;
  }
  else {
    lVar8 = 0;
    for (lVar7 = 0; lVar7 < param_8[2]; lVar7 = lVar7 + 1) {
      sVar4 = (&DAT_00c4f108)[lVar7];
      FUN_0024a664(auStack_7e,param_6,param_4,(int)sVar4,uVar11);
      _memcpy((void *)((long)param_1 + lVar8),auStack_7e,
              -(ulong)(uVar3 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar3 << 1);
      FUN_0024a664(auStack_7e,param_5,param_3,(int)sVar4,uVar11);
      FUN_00245af8(param_2 + lVar8,auStack_7e,&DAT_00c4e83e,(int)sVar5);
      lVar8 = lVar8 + (-(ulong)(param_7 >> 0x1f) & 0xfffffffe00000000 | uVar11 << 1) + 2;
    }
    sVar9 = (long)(int)param_7 << 1;
    _memcpy(param_5,param_3,sVar9);
    _memcpy(param_6,param_4,sVar9);
    lVar7 = *(long *)PTR____stack_chk_guard_01060708;
  }
  if (lVar7 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


