/* Decompiled from supplied 5.2.2 arm package. VA 0x27b674. FUN_0027b674 */

undefined8 FUN_0027b674(long *param_1)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined1 auStack_b8 [128];
  long local_38;
  
  lVar3 = *(long *)PTR____stack_chk_guard_01060708;
  lVar4 = *(long *)(*param_1 + 0x48);
  uVar1 = *(undefined4 *)(lVar4 + 0x10);
  *(undefined4 *)(param_1 + 9) = 1;
  *(undefined4 *)((long)param_1 + 0x4c) = uVar1;
  iVar2 = *(int *)(lVar4 + 0x10);
  *(int *)(param_1 + 8) = iVar2;
  *(undefined8 *)(lVar4 + 0x78) = 0x7ff8000000000000;
  *(double *)(lVar4 + 0x90) = (double)iVar2;
  *(double *)(lVar4 + 0x80) = (double)*(int *)((long)param_1 + 0xc4);
  local_38 = lVar3;
  _av_get_channel_layout_string(auStack_b8,0x80,0,*(undefined8 *)(lVar4 + 0x18));
  _av_log(*param_1,0x28,"sample_rate:%d chlayout:%s duration:%lld\n");
  if (lVar3 == local_38) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


