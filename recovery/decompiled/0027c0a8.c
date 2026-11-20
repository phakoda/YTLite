/* Decompiled from supplied 5.2.2 arm package. VA 0x27c0a8. FUN_0027c0a8 */

int FUN_0027c0a8(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long local_40;
  long local_38;
  
  uVar3 = **(undefined8 **)(*(long *)(param_1 + 0x10) + 0x38);
  local_38 = param_2;
  lVar2 = _ff_get_audio_buffer(uVar3,*(undefined4 *)(param_2 + 0x70));
  local_40 = lVar2;
  if (lVar2 == 0) {
    iVar1 = -0xc;
  }
  else {
    iVar1 = _av_frame_copy_props(lVar2,param_2);
    if (-1 < iVar1) {
      iVar1 = _av_frame_copy(lVar2,param_2);
      if (-1 < iVar1) {
        _av_frame_free(&local_38);
        iVar1 = _ff_filter_frame(uVar3,local_40);
        return iVar1;
      }
    }
  }
  _av_frame_free(&local_38);
  _av_frame_free(&local_40);
  return iVar1;
}


