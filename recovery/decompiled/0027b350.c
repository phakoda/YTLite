/* Decompiled from supplied 5.2.2 arm package. VA 0x27b350. FUN_0027b350 */

void FUN_0027b350(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  undefined4 local_40;
  undefined4 uStack_3c;
  ulong local_38 [3];
  
  lVar3 = *(long *)PTR____stack_chk_guard_01060708;
  lVar2 = *(long *)(param_1 + 0x48);
  local_38[0] = *(ulong *)(lVar2 + 0x18);
  if (local_38[0] == 0) {
    local_38[0] = (long)*(int *)(lVar2 + 0x28) | 0x8000000000000000;
  }
  local_38[1] = 0xffffffffffffffff;
  local_40 = *(undefined4 *)(lVar2 + 0x10);
  uStack_3c = 0xffffffff;
  local_38[2] = lVar3;
  lVar2 = _ff_make_format_list(&DAT_00c5374c);
  if (lVar2 != 0) {
    uVar1 = _ff_set_common_formats(param_1,lVar2);
    if ((int)uVar1 < 0) goto LAB_0027b408;
    lVar2 = _avfilter_make_format64_list(local_38);
    if (lVar2 != 0) {
      uVar1 = _ff_set_common_channel_layouts(param_1,lVar2);
      if ((int)uVar1 < 0) goto LAB_0027b408;
      lVar2 = _ff_make_format_list(&local_40);
      if (lVar2 != 0) {
        uVar1 = _ff_set_common_samplerates(param_1,lVar2);
        goto LAB_0027b408;
      }
    }
  }
  uVar1 = 0xfffffff4;
LAB_0027b408:
  if (lVar3 == local_38[2]) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar1);
}


