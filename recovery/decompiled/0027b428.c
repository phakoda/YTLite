/* Decompiled from supplied 5.2.2 arm package. VA 0x27b428. FUN_0027b428 */

void FUN_0027b428(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 local_38;
  
  lVar6 = **(long **)(param_1 + 0x20);
  lVar4 = **(long **)(param_1 + 0x38);
  lVar5 = *(long *)(param_1 + 0x48);
  local_38 = _ff_all_channel_counts();
  iVar1 = _ff_channel_layouts_ref(local_38,lVar6 + 0x78);
  if (-1 < iVar1) {
    if (*(int *)(lVar5 + 0x30) == 0) {
      local_38 = 0;
      uVar3 = *(ulong *)(lVar5 + 0xa0);
      if (uVar3 == 0) {
        uVar3 = (long)*(int *)(lVar5 + 0x28) | 0x8000000000000000;
      }
      iVar1 = _ff_add_channel_layout(&local_38,uVar3);
      if (iVar1 < 0) {
        return;
      }
      iVar1 = _ff_channel_layouts_ref(local_38,lVar4 + 0x70);
    }
    else {
      local_38 = _ff_all_channel_counts();
      iVar1 = _ff_set_common_channel_layouts(param_1,local_38);
    }
    if (-1 < iVar1) {
      uVar2 = _ff_make_format_list(&DAT_00c53754);
      iVar1 = _ff_set_common_formats(param_1,uVar2);
      if (-1 < iVar1) {
        uVar2 = _ff_all_samplerates();
        _ff_set_common_samplerates(param_1,uVar2);
      }
    }
  }
  return;
}


