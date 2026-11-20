/* Decompiled from supplied 5.2.2 arm package. VA 0x25daa8. _av_hwframe_get_buffer */

int _av_hwframe_get_buffer(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long local_38;
  
  lVar3 = *(long *)(param_1 + 8);
  if ((*(long **)(lVar3 + 8))[3] == 0) {
    if (*(long *)(**(long **)(lVar3 + 8) + 0x78) == 0) {
      return -0x4e;
    }
    if (*(long *)(lVar3 + 0x38) == 0) {
      return -0x16;
    }
    lVar2 = _av_buffer_ref();
    *(long *)(param_2 + 0x1e0) = lVar2;
    if (lVar2 != 0) {
      iVar1 = (**(code **)(**(long **)(lVar3 + 8) + 0x78))(lVar3,param_2);
      if (-1 < iVar1) {
        *(long *)(param_2 + 0x60) = param_2;
        return 0;
      }
      _av_buffer_unref(param_2 + 0x1e0);
      return iVar1;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x74) = *(undefined4 *)(lVar3 + 0x44);
    lVar2 = _av_buffer_ref();
    *(long *)(param_2 + 0x1e0) = lVar2;
    if ((lVar2 != 0) && (lVar2 = _av_frame_alloc(), lVar2 != 0)) {
      local_38 = lVar2;
      iVar1 = _av_hwframe_get_buffer(*(undefined8 *)(*(long *)(lVar3 + 8) + 0x18),lVar2);
      if (-1 < iVar1) {
        iVar1 = _av_hwframe_map(param_2,lVar2,*(undefined4 *)(*(long *)(lVar3 + 8) + 0x20));
        if (iVar1 == 0) {
          _av_frame_free(&local_38);
          return 0;
        }
        _av_log(lVar3,0x10,"Failed to map frame into derived frame context: %d.\n");
      }
      _av_frame_free(&local_38);
      return iVar1;
    }
  }
  return -0xc;
}


