/* Decompiled from supplied 5.2.2 arm package. VA 0x25c1ec. _av_frame_make_writable */

int _av_frame_make_writable(void *param_1)

{
  int iVar1;
  undefined1 auStack_248 [96];
  undefined1 *local_1e8;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined8 local_130;
  undefined4 local_8c;
  
  if (*(long *)((long)param_1 + 0x120) == 0) {
    return -0x16;
  }
  iVar1 = _av_frame_is_writable(param_1);
  if (iVar1 == 0) {
    _bzero(auStack_248,0x218);
    local_1d4 = *(undefined4 *)((long)param_1 + 0x74);
    local_1e0 = (undefined4)*(undefined8 *)((long)param_1 + 0x68);
    local_1dc = (undefined4)((ulong)*(undefined8 *)((long)param_1 + 0x68) >> 0x20);
    local_8c = *(undefined4 *)((long)param_1 + 0x1bc);
    local_130 = *(undefined8 *)((long)param_1 + 0x118);
    local_1d8 = *(undefined4 *)((long)param_1 + 0x70);
    if (*(long *)((long)param_1 + 0x1e0) == 0) {
      iVar1 = _av_frame_get_buffer(auStack_248,0);
    }
    else {
      iVar1 = _av_hwframe_get_buffer(*(long *)((long)param_1 + 0x1e0),auStack_248,0);
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = _av_frame_copy(auStack_248,param_1);
    if (-1 < iVar1) {
      iVar1 = FUN_0025bbd8(auStack_248,param_1,1);
      if (-1 < iVar1) {
        _av_frame_unref(param_1);
        _memcpy(param_1,auStack_248,0x218);
        if (auStack_248 == local_1e8) {
          *(void **)((long)param_1 + 0x60) = param_1;
          return 0;
        }
        goto LAB_0025c2dc;
      }
    }
    _av_frame_unref(auStack_248);
  }
  else {
LAB_0025c2dc:
    iVar1 = 0;
  }
  return iVar1;
}


