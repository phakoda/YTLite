/* Decompiled from supplied 5.2.2 arm package. VA 0x27f3a4. FUN_0027f3a4 */

undefined8 FUN_0027f3a4(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  long local_48;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x10) + 0x48);
  uVar3 = **(undefined8 **)(*(long *)(param_1 + 0x10) + 0x38);
  local_48 = param_2;
  lVar1 = _ff_get_audio_buffer(uVar3,*(undefined4 *)(param_2 + 0x70));
  if (lVar1 == 0) {
LAB_0027f450:
    _av_frame_free(&local_48);
    uVar3 = 0xfffffff4;
  }
  else {
    _av_frame_copy_props(lVar1,param_2);
    lVar2 = *(long *)(lVar4 + 8);
    if (lVar2 == 0) {
      lVar2 = _ff_get_audio_buffer(param_1,1);
      *(long *)(lVar4 + 8) = lVar2;
      param_2 = local_48;
      if (lVar2 == 0) goto LAB_0027f450;
    }
    (**(code **)(lVar4 + 0x10))
              (*(undefined8 *)(lVar1 + 0x60),*(undefined8 *)(lVar2 + 0x60),
               *(undefined8 *)(param_2 + 0x60),*(undefined4 *)(param_2 + 0x70),
               *(undefined4 *)(param_2 + 0x1bc));
    _av_frame_free(&local_48);
    uVar3 = _ff_filter_frame(uVar3,lVar1);
  }
  return uVar3;
}


