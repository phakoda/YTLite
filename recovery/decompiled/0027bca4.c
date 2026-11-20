/* Decompiled from supplied 5.2.2 arm package. VA 0x27bca4. FUN_0027bca4 */

undefined8 FUN_0027bca4(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  long local_38;
  
  uVar3 = **(undefined8 **)(*(long *)(param_1 + 0x10) + 0x38);
  lVar4 = *(long *)(*(long *)(param_1 + 0x10) + 0x48);
  local_38 = param_2;
  iVar1 = _av_frame_is_writable(param_2);
  lVar2 = param_2;
  if (iVar1 == 0) {
    lVar2 = _ff_get_audio_buffer(uVar3,*(undefined4 *)(param_2 + 0x70));
    if (lVar2 == 0) {
      _av_frame_free(&local_38);
      return 0xfffffff4;
    }
    _av_frame_copy_props(lVar2,param_2);
  }
  (**(code **)(lVar4 + 0x10))
            (*(float *)(lVar4 + 8) / DAT_00c5375c,*(undefined8 *)(lVar2 + 0x60),
             *(undefined8 *)(param_2 + 0x60),*(undefined4 *)(param_2 + 0x70),
             *(undefined4 *)(param_2 + 0x1bc));
  if (lVar2 != param_2) {
    _av_frame_free(&local_38);
  }
  uVar3 = _ff_filter_frame(uVar3,lVar2);
  return uVar3;
}


