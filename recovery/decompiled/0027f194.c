/* Decompiled from supplied 5.2.2 arm package. VA 0x27f194. FUN_0027f194 */

undefined8 FUN_0027f194(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long local_58;
  
  lVar3 = *(long *)(param_1 + 0x10);
  local_58 = param_2;
  if ((*(int *)(lVar3 + 0x88) == 0) &&
     (lVar4 = *(long *)(lVar3 + 0x48), *(long *)(lVar4 + 0x10) != 0)) {
    lVar1 = _ff_get_audio_buffer(**(undefined8 **)(lVar3 + 0x38),*(undefined4 *)(param_2 + 0x70));
    if (lVar1 == 0) {
      _av_frame_free(&local_58);
      uVar2 = 0xfffffff4;
    }
    else {
      _av_frame_copy_props(lVar1,param_2);
      lVar5 = 0;
      for (lVar6 = 0; lVar6 < (int)*(undefined8 *)(lVar4 + 0x20); lVar6 = lVar6 + 1) {
        if (*(int *)(*(long *)(lVar4 + 0x18) + lVar5) == 0) {
          _memcpy(*(void **)(*(long *)(lVar1 + 0x60) + lVar6 * 8),
                  *(void **)(*(long *)(param_2 + 0x60) + lVar6 * 8),
                  (long)((int)((ulong)*(undefined8 *)(lVar4 + 0x20) >> 0x20) *
                        *(int *)(param_2 + 0x70)));
        }
        else {
          (**(code **)(lVar4 + 0x48))();
        }
        lVar5 = lVar5 + 0x18;
      }
      lVar5 = *(long *)(lVar4 + 0x38);
      *(long *)(lVar1 + 0x88) = lVar5;
      lVar6 = _av_rescale_q((long)*(int *)(param_2 + 0x70),
                            (ulong)*(uint *)(param_1 + 0x40) << 0x20 | 1,
                            *(undefined8 *)(param_1 + 0x48));
      *(long *)(lVar4 + 0x38) = lVar5 + lVar6;
      _av_frame_free(&local_58);
      uVar2 = _ff_filter_frame(**(undefined8 **)(lVar3 + 0x38),lVar1);
    }
    return uVar2;
  }
  uVar2 = _ff_filter_frame(**(undefined8 **)(lVar3 + 0x38),param_2);
  return uVar2;
}


