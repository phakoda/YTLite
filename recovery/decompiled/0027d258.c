/* Decompiled from supplied 5.2.2 arm package. VA 0x27d258. FUN_0027d258 */

void FUN_0027d258(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + 0x48);
  _av_log(param_1,0x20,"Detected %s in %lld of %lld samples (%g%%).\n");
  _av_audio_fifo_free(*(undefined8 *)(lVar4 + 0xb0));
  _av_audio_fifo_free(*(undefined8 *)(lVar4 + 0xa8));
  _av_freep(lVar4 + 0xb8);
  _av_frame_free(lVar4 + 0x50);
  _av_frame_free(lVar4 + 0x58);
  _av_frame_free(lVar4 + 0x60);
  _av_frame_free(lVar4 + 0x68);
  _av_frame_free(lVar4 + 0x70);
  plVar3 = (long *)(lVar4 + 0x78);
  if (*plVar3 != 0) {
    lVar5 = -1;
    lVar2 = 0;
    while (lVar5 = lVar5 + 1, lVar5 < *(int *)(lVar4 + 0x88)) {
      lVar1 = *plVar3 + lVar2;
      _av_freep(lVar1 + 8);
      _av_freep(lVar1);
      _av_freep(lVar1 + 0x10);
      _av_freep(lVar1 + 0x18);
      _av_freep(lVar1 + 0x20);
      _av_freep(lVar1 + 0x60);
      _av_freep(lVar1 + 0x68);
      _av_freep(lVar1 + 0x28);
      _av_freep(lVar1 + 0x30);
      *(undefined4 *)(lVar1 + 0x38) = 0;
      _av_freep(lVar1 + 0x70);
      *(undefined4 *)(lVar1 + 0x78) = 0;
      _av_freep(lVar1 + 0x40);
      *(undefined4 *)(lVar1 + 0x48) = 0;
      _av_freep(lVar1 + 0x50);
      *(undefined4 *)(lVar1 + 0x58) = 0;
      lVar2 = lVar2 + 0x80;
    }
  }
  _av_freep(plVar3);
  *(undefined4 *)(lVar4 + 0x88) = 0;
  return;
}


