/* Decompiled from supplied 5.2.2 arm package. VA 0x27e850. FUN_0027e850 */

undefined8 FUN_0027e850(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  undefined4 uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  undefined1 auStack_58 [12];
  int local_4c;
  long local_48;
  
  uVar7 = **(undefined8 **)(param_1 + 0x20);
  lVar6 = **(long **)(param_1 + 0x38);
  lVar8 = *(long *)(param_1 + 0x48);
  local_48 = 0;
  iVar1 = _ff_outlink_get_status(lVar6);
  if (iVar1 == 0) {
    lVar4 = *(long *)(lVar8 + 0x28);
    if (lVar4 != 0) {
      uVar5 = (undefined4)lVar4;
      if (0x7ff < lVar4) {
        lVar4 = 0x800;
        uVar5 = 0x800;
      }
      lVar2 = _ff_get_audio_buffer(lVar6,uVar5);
      if (lVar2 == 0) {
        return 0xfffffff4;
      }
      *(long *)(lVar8 + 0x28) = *(long *)(lVar8 + 0x28) - (long)(int)lVar4;
      local_48 = lVar2;
      _av_samples_set_silence
                (*(undefined8 *)(lVar2 + 0x60),0,*(undefined4 *)(lVar2 + 0x70),
                 *(undefined4 *)(lVar6 + 0xc4),*(undefined4 *)(lVar2 + 0x74));
      lVar9 = *(long *)(lVar8 + 0x38);
      *(long *)(lVar2 + 0x88) = lVar9;
      if (lVar9 != -0x8000000000000000) {
        lVar4 = _av_rescale_q((long)(int)lVar4,(ulong)*(uint *)(lVar6 + 0x40) << 0x20 | 1,
                              *(undefined8 *)(lVar6 + 0x48));
        *(long *)(lVar8 + 0x38) = lVar4 + lVar9;
      }
      uVar7 = _ff_filter_frame(lVar6,lVar2);
      return uVar7;
    }
    uVar3 = _ff_inlink_consume_frame(uVar7,&local_48);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    if ((int)uVar3 < 1) {
      iVar1 = _ff_inlink_acknowledge_status(uVar7,&local_4c,auStack_58);
      if ((iVar1 == 0) || (local_4c != -0x20464f45)) {
        if (*(int *)(lVar8 + 0x40) == 0) {
          if (*(int *)(lVar6 + 0xe8) == 0) {
            return 0xa6bbadb2;
          }
          _ff_inlink_request_frame(uVar7);
          goto LAB_0027e89c;
        }
      }
      else {
        *(undefined4 *)(lVar8 + 0x40) = 1;
      }
      lVar4 = *(long *)(lVar8 + 0x30);
      if (lVar4 == 0) {
        _ff_avfilter_link_set_in_status(lVar6,0xdfb9b0bb,*(undefined8 *)(lVar8 + 0x38));
        goto LAB_0027e89c;
      }
      uVar5 = (undefined4)lVar4;
      if (0x7ff < lVar4) {
        lVar4 = 0x800;
        uVar5 = 0x800;
      }
      local_48 = _ff_get_audio_buffer(lVar6,uVar5);
      if (local_48 == 0) {
        return 0xfffffff4;
      }
      *(long *)(lVar8 + 0x30) = *(long *)(lVar8 + 0x30) - (long)(int)lVar4;
      _av_samples_set_silence
                (*(undefined8 *)(local_48 + 0x60),0,*(undefined4 *)(local_48 + 0x70),
                 *(undefined4 *)(lVar6 + 0xc4),*(undefined4 *)(local_48 + 0x74));
      *(undefined8 *)(local_48 + 0x88) = *(undefined8 *)(lVar8 + 0x38);
    }
    uVar7 = FUN_0027f194(uVar7,local_48);
  }
  else {
    _ff_inlink_set_status(uVar7,iVar1);
LAB_0027e89c:
    uVar7 = 0;
  }
  return uVar7;
}


