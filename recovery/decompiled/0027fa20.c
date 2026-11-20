/* Decompiled from supplied 5.2.2 arm package. VA 0x27fa20. FUN_0027fa20 */

undefined8 FUN_0027fa20(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined1 auStack_60 [12];
  int local_54;
  long local_50;
  long local_48;
  
  lVar4 = **(long **)(param_1 + 0x20);
  plVar3 = (long *)**(undefined8 **)(param_1 + 0x38);
  lVar5 = *(long *)(param_1 + 0x48);
  iVar1 = _ff_outlink_get_status(plVar3);
  if (iVar1 != 0) {
    _ff_inlink_set_status(lVar4,iVar1);
    return 0;
  }
  uVar2 = _ff_inlink_consume_frame(lVar4,&local_50);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if (0 < (int)uVar2) {
    local_48 = local_50;
    lVar7 = *(long *)(lVar4 + 0x10);
    lVar6 = *(long *)(lVar7 + 0x48);
    iVar1 = _av_frame_is_writable(local_50);
    lVar5 = local_50;
    if (iVar1 == 0) {
      lVar5 = _ff_get_audio_buffer(**(undefined8 **)(lVar7 + 0x38),*(undefined4 *)(local_50 + 0x70))
      ;
      if (lVar5 == 0) {
        _av_frame_free(&local_48);
        return 0xfffffff4;
      }
      _av_frame_copy_props(lVar5,local_50);
    }
    (**(code **)(lVar6 + 0x60))
              (lVar6,*(undefined8 *)(lVar6 + 0x38),*(undefined8 *)(local_50 + 0x60),
               *(undefined8 *)(lVar5 + 0x60),*(undefined4 *)(local_50 + 0x70),
               *(undefined4 *)(lVar4 + 0xc4));
    lVar8 = *(long *)(local_50 + 0x88);
    lVar4 = _av_rescale_q((long)*(int *)(local_50 + 0x70),(ulong)*(uint *)(lVar4 + 0x40) << 0x20 | 1
                          ,*(undefined8 *)(lVar4 + 0x48));
    *(long *)(lVar6 + 0x58) = lVar4 + lVar8;
    if (lVar5 != local_50) {
      _av_frame_free(&local_48);
    }
    plVar3 = (long *)**(undefined8 **)(lVar7 + 0x38);
    goto LAB_0027fc68;
  }
  if (*(int *)(lVar5 + 0x50) == 0) {
    iVar1 = _ff_inlink_acknowledge_status(lVar4,&local_54,auStack_60);
    if ((iVar1 != 0) && (local_54 == -0x20464f45)) {
      *(undefined4 *)(lVar5 + 0x50) = 1;
      goto LAB_0027fb80;
    }
    if (*(int *)(lVar5 + 0x50) != 0) goto LAB_0027fb80;
    if ((int)plVar3[0x1d] != 0) {
      _ff_inlink_request_frame(lVar4);
      return 0;
    }
  }
  else {
LAB_0027fb80:
    if (*(int *)(lVar5 + 0x44) < 1) {
      _ff_avfilter_link_set_in_status(plVar3,0xdfb9b0bb,*(undefined8 *)(lVar5 + 0x58));
      return 0;
    }
  }
  lVar4 = *(long *)(*plVar3 + 0x48);
  iVar1 = 0x800;
  if (*(int *)(lVar4 + 0x44) < 0x801) {
    iVar1 = *(int *)(lVar4 + 0x44);
  }
  lVar5 = _ff_get_audio_buffer(plVar3,iVar1);
  if (lVar5 == 0) {
    return 0xfffffff4;
  }
  *(int *)(lVar4 + 0x44) = *(int *)(lVar4 + 0x44) - iVar1;
  _av_samples_set_silence
            (*(undefined8 *)(lVar5 + 0x60),0,*(undefined4 *)(lVar5 + 0x70),
             *(undefined4 *)((long)plVar3 + 0xc4),*(undefined4 *)(lVar5 + 0x74));
  (**(code **)(lVar4 + 0x60))
            (lVar4,*(undefined8 *)(lVar4 + 0x38),*(undefined8 *)(lVar5 + 0x60),
             *(undefined8 *)(lVar5 + 0x60),*(undefined4 *)(lVar5 + 0x70),
             *(undefined4 *)((long)plVar3 + 0xc4));
  lVar6 = *(long *)(lVar4 + 0x58);
  *(long *)(lVar5 + 0x88) = lVar6;
  if (lVar6 != -0x8000000000000000) {
    lVar7 = _av_rescale_q((long)iVar1,(ulong)*(uint *)(plVar3 + 8) << 0x20 | 1,plVar3[9]);
    *(long *)(lVar4 + 0x58) = lVar7 + lVar6;
  }
LAB_0027fc68:
  uVar2 = _ff_filter_frame(plVar3,lVar5);
  return uVar2;
}


