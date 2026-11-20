/* Decompiled from supplied 5.2.2 arm package. VA 0x24ecbc. FUN_0024ecbc */

void FUN_0024ecbc(uint *param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  long lVar5;
  long lVar6;
  short asStack_1068 [2048];
  long local_68;
  
  lVar5 = *(long *)PTR____stack_chk_guard_01060708;
  iVar2 = 1 << (ulong)(*param_1 & 0x1f);
  uVar1 = iVar2 + 2;
  local_68 = lVar5;
  ___memcpy_chk(asStack_1068,param_2,
                -(ulong)(uVar1 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar1 << 1,0x1000);
  psVar3 = asStack_1068 + (long)(int)uVar1 + 1;
  psVar4 = (short *)(param_2 + (((long)(iVar2 << 1) | 1U) - (long)(int)uVar1) * 2);
  for (lVar6 = (long)(int)uVar1; lVar6 < iVar2 << 1; lVar6 = lVar6 + 2) {
    psVar3[-1] = psVar4[-1];
    *psVar3 = -*psVar4;
    psVar3 = psVar3 + 2;
    psVar4 = psVar4 + -2;
  }
  FUN_0024d8fc(asStack_1068,*param_1);
  FUN_0024dbf0(asStack_1068,*param_1,1);
  psVar3 = asStack_1068;
  for (lVar6 = 0; lVar6 < iVar2; lVar6 = lVar6 + 1) {
    *(short *)(param_3 + lVar6 * 2) = *psVar3;
    psVar3 = psVar3 + 2;
  }
  if (lVar5 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


