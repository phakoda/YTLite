/* Decompiled from supplied 5.2.2 arm package. VA 0x27d44c. FUN_0027d44c */

int FUN_0027d44c(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined1 auStack_78 [12];
  int local_6c;
  long local_68;
  long local_60;
  long local_58;
  
  lVar6 = **(long **)(param_1 + 0x20);
  lVar8 = **(long **)(param_1 + 0x38);
  lVar9 = *(long *)(param_1 + 0x48);
  iVar2 = _ff_outlink_get_status(lVar8);
  if (iVar2 != 0) {
    _ff_inlink_set_status(lVar6,iVar2);
    return 0;
  }
  iVar2 = _ff_inlink_consume_samples
                    (lVar6,*(undefined4 *)(lVar9 + 0x44),*(undefined4 *)(lVar9 + 0x44),&local_68);
  if (iVar2 < 0) {
    return iVar2;
  }
  if (0 < iVar2) {
    lVar10 = **(long **)(*(long *)(lVar9 + 0x50) + 0x60);
    if (*(long *)(lVar9 + 0x80) == -0x8000000000000000) {
      *(undefined8 *)(lVar9 + 0x80) = *(undefined8 *)(local_68 + 0x88);
    }
    iVar3 = _av_audio_fifo_write
                      (*(undefined8 *)(lVar9 + 0xb0),*(undefined8 *)(local_68 + 0x60),
                       *(undefined4 *)(local_68 + 0x70));
    iVar2 = *(int *)(local_68 + 0x70);
    for (lVar5 = 0; lVar5 < iVar2; lVar5 = lVar5 + 1) {
      uVar7 = 0x3ff0000000000000;
      if (*(int *)(param_1 + 0x88) != 0) {
        uVar7 = 0;
      }
      *(undefined8 *)(lVar10 + lVar5 * 8) = uVar7;
    }
    _av_audio_fifo_write
              (*(undefined8 *)(lVar9 + 0xa8),*(undefined8 *)(*(long *)(lVar9 + 0x50) + 0x60));
    _av_frame_free(&local_68);
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  iVar2 = _av_audio_fifo_size(*(undefined8 *)(lVar9 + 0xb0));
  if ((*(int *)(lVar9 + 0x44) <= iVar2) || (0 < *(int *)(lVar9 + 0xa0))) {
    lVar10 = *(long *)(lVar6 + 0x10);
    lVar5 = *(long *)(lVar10 + 0x48);
    lVar9 = **(long **)(lVar10 + 0x38);
    lVar8 = _ff_get_audio_buffer(lVar9,*(undefined4 *)(lVar5 + 0x48));
    if (lVar8 == 0) {
      return -0xc;
    }
    local_58 = lVar8;
    iVar2 = _av_audio_fifo_peek(*(undefined8 *)(lVar5 + 0xb0),
                                *(undefined8 *)(*(long *)(lVar5 + 0x58) + 0x60),
                                *(undefined4 *)(lVar5 + 0x44));
    if ((iVar2 < 0) ||
       (local_60 = lVar8,
       iVar2 = (*(code *)**(undefined8 **)(lVar10 + 0x60))
                         (lVar10,FUN_0027df20,&local_60,0,*(undefined4 *)(lVar6 + 0xc4)), iVar2 < 0)
       ) {
      _av_frame_free(&local_58);
      return iVar2;
    }
    iVar2 = 0;
    for (lVar8 = 0; lVar8 < *(int *)(*(long *)(lVar5 + 0x58) + 0x1bc); lVar8 = lVar8 + 1) {
      for (lVar10 = 0; lVar10 < *(int *)(lVar5 + 0x48); lVar10 = lVar10 + 1) {
        iVar2 = (uint)(*(double *)
                        (*(long *)(*(long *)(*(long *)(lVar5 + 0x70) + 0x60) + lVar8 * 8) +
                        lVar10 * 8) != 0.0) + iVar2;
      }
    }
    _av_audio_fifo_drain(*(undefined8 *)(lVar5 + 0xb0),*(undefined4 *)(lVar5 + 0x48));
    _av_audio_fifo_drain(*(undefined8 *)(lVar5 + 0xa8),*(undefined4 *)(lVar5 + 0x48));
    lVar8 = local_58;
    iVar3 = *(int *)(lVar5 + 0xa0);
    if (iVar3 < 1) {
      iVar1 = *(int *)(lVar5 + 0x48);
      iVar3 = *(int *)(local_58 + 0x70);
    }
    else {
      iVar1 = *(int *)(lVar5 + 0x48);
      if (iVar1 <= iVar3) {
        iVar3 = iVar1;
      }
      *(int *)(local_58 + 0x70) = iVar3;
    }
    lVar11 = *(long *)(lVar5 + 0x80);
    *(long *)(local_58 + 0x88) = lVar11;
    lVar10 = _av_rescale_q((long)iVar1,(ulong)*(uint *)(lVar9 + 0x40) << 0x20 | 1,
                           *(undefined8 *)(lVar9 + 0x48));
    *(long *)(lVar5 + 0x80) = lVar10 + lVar11;
    *(long *)(lVar5 + 0x98) = *(long *)(lVar5 + 0x98) + (long)iVar2;
    *(long *)(lVar5 + 0x90) = *(long *)(lVar5 + 0x90) + (long)*(int *)(lVar6 + 0xc4) * (long)iVar3;
    iVar2 = _ff_filter_frame(lVar9,lVar8);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (*(int *)(lVar5 + 0xa0) < 1) {
      return iVar2;
    }
    iVar3 = *(int *)(lVar5 + 0xa0) - *(int *)(lVar5 + 0x48);
    *(int *)(lVar5 + 0xa0) = iVar3;
    if (iVar3 < 1) {
      uVar7 = *(undefined8 *)(lVar5 + 0xb0);
      uVar4 = _av_audio_fifo_size(uVar7);
      _av_audio_fifo_drain(uVar7,uVar4);
      return iVar2;
    }
    return iVar2;
  }
  iVar2 = _av_audio_fifo_size(*(undefined8 *)(lVar9 + 0xb0));
  if (iVar2 < *(int *)(lVar9 + 0x44)) {
    if (*(int *)(lVar9 + 0xa4) == 0) {
      iVar2 = _ff_inlink_acknowledge_status(lVar6,&local_6c,auStack_78);
      if ((iVar2 != 0) && (local_6c == -0x20464f45)) {
        *(undefined4 *)(lVar9 + 0xa4) = 1;
        iVar2 = _av_audio_fifo_size(*(undefined8 *)(lVar9 + 0xb0));
        *(int *)(lVar9 + 0xa0) = iVar2 - *(int *)(lVar9 + 0x4c);
        goto LAB_0027d6f8;
      }
      if (*(int *)(lVar9 + 0xa4) != 0) goto LAB_0027d7b0;
    }
    else {
LAB_0027d7b0:
      if ((int)*(ulong *)(lVar9 + 0xa0) < 1) {
        _ff_avfilter_link_set_in_status(lVar8,0xdfb9b0bb,*(undefined8 *)(lVar9 + 0x80));
        return 0;
      }
      if (*(ulong *)(lVar9 + 0xa0) >> 0x20 != 0) {
        return -0x5944524e;
      }
    }
    if (*(int *)(lVar8 + 0xe8) == 0) {
      return -0x5944524e;
    }
    _ff_inlink_request_frame(lVar6);
  }
  else {
LAB_0027d6f8:
    _ff_filter_set_ready(param_1,100);
  }
  return 0;
}


