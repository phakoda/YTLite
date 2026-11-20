/* Decompiled from supplied 5.2.2 arm package. VA 0x246f0c. FUN_00246f0c */

void FUN_00246f0c(uint param_1,long param_2,void *param_3)

{
  long lVar1;
  void *pvVar2;
  long lVar3;
  undefined1 auStack_60 [8];
  long local_58;
  
  lVar3 = *(long *)PTR____stack_chk_guard_01060708;
  pvVar2 = (void *)(param_2 + (long)(int)param_1 * -2);
  local_58 = lVar3;
  _memcpy(param_3,pvVar2,-(ulong)(param_1 >> 0x1f) & 0xfffffffe00000000 | (ulong)param_1 << 1);
  lVar1 = (long)param_3 + ((long)((ulong)(param_1 + 0xfffc) << 0x30) >> 0x2f);
  FUN_0024e3a4(lVar1,(long)pvVar2 + -8,&DAT_00c4f538,4,0xf);
  FUN_0024e378(auStack_60,param_2 + -8,&DAT_00c4f53e,4,0xf);
  thunk_FUN_0024e3e8(lVar1,lVar1,auStack_60,4,0);
  _memcpy((void *)((long)param_3 + (long)(int)param_1 * 2),pvVar2,
          -(ulong)(0x28 - param_1 >> 0x1f) & 0xfffffffe00000000 | (ulong)(0x28 - param_1) << 1);
  if (lVar3 == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


