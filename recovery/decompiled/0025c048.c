/* Decompiled from supplied 5.2.2 arm package. VA 0x25c048. _av_frame_clone */

long _av_frame_clone(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  long local_28;
  
  lVar2 = _av_frame_alloc();
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    local_28 = lVar2;
    iVar1 = _av_frame_ref(lVar2,param_1);
    if (iVar1 < 0) {
      _av_frame_free(&local_28);
      lVar2 = local_28;
    }
  }
  return lVar2;
}


