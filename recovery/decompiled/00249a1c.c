/* Decompiled from supplied 5.2.2 arm package. VA 0x249a1c. FUN_00249a1c */

void FUN_00249a1c(void *param_1,long param_2,int param_3,int param_4,uint param_5)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  long *plVar7;
  long lVar8;
  undefined1 auStack_c2 [90];
  long local_68;
  
  lVar8 = *(long *)PTR____stack_chk_guard_01060708;
  iVar4 = param_4 - param_5;
  sVar2 = (short)iVar4 + 1;
  sVar1 = sVar2;
  if ((param_5 & 0xffff) == 0x28) {
    uVar3 = param_5;
    if ((int)param_5 < 0) {
      uVar3 = param_5 + 1;
    }
    sVar1 = (short)((int)uVar3 >> 1) + sVar2;
  }
  sVar5 = (short)param_5;
  sVar6 = (short)param_3;
  local_68 = lVar8;
  if (iVar4 < param_3) {
    if (param_3 < sVar1) {
      uVar3 = (uint)(short)(sVar5 + (sVar6 - sVar2) * 2);
      if ((int)uVar3 < 0) {
        uVar3 = uVar3 + 1;
      }
      sVar1 = (short)(uVar3 >> 1);
      plVar7 = (long *)(param_2 + (long)param_4 * 2);
    }
    else {
      if (param_3 - sVar1 <= iVar4) {
        thunk_FUN_0024de70(param_2 + -8,0,4);
        thunk_FUN_0024de70(param_2 + (long)param_4 * 2,0,4);
        FUN_0024e304(param_2 + (long)((short)((short)iVar4 - (short)(param_3 - sVar1)) + 4) * 2,
                     param_1,&DAT_00c4f528,8,param_5);
        goto LAB_00249b98;
      }
      thunk_FUN_0024de70(param_2 + (long)param_4 * 2,0,4);
      FUN_0024e304(param_2 + (long)((iVar4 * 0x10000 + -0x80000 >> 0x10) + 7) * 2,auStack_c2,
                   &DAT_00c4f528,8,(int)(short)(sVar5 + 5));
      sVar1 = (((sVar6 + -0x15) - (short)param_4) + sVar5 * 2) - sVar1;
      plVar7 = &local_68;
    }
    FUN_00246f0c((int)sVar1,plVar7,param_1);
  }
  else {
    _memcpy(param_1,(void *)(param_2 + (long)param_4 * 2 + (long)(int)(short)(sVar5 + sVar6) * -2),
            -(ulong)(param_5 >> 0x1f) & 0xfffffffe00000000 | (ulong)param_5 << 1);
  }
LAB_00249b98:
  if (lVar8 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


