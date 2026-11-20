/* Decompiled from supplied 5.2.2 arm package. VA 0x25de0c. _av_hwdevice_ctx_create */

int _av_hwdevice_ctx_create
              (long *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
              undefined4 param_5)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  long local_48;
  
  lVar2 = _av_hwdevice_ctx_alloc(param_2);
  local_48 = lVar2;
  if (lVar2 == 0) {
    iVar1 = -0xc;
  }
  else {
    pcVar3 = *(code **)(**(long **)(*(long *)(lVar2 + 8) + 8) + 0x40);
    if (pcVar3 == (code *)0x0) {
      iVar1 = -0x4e;
    }
    else {
      iVar1 = (*pcVar3)(*(long *)(lVar2 + 8),param_3,param_4,param_5);
      if (-1 < iVar1) {
        iVar1 = _av_hwdevice_ctx_init(lVar2);
        if (-1 < iVar1) {
          iVar1 = 0;
          goto LAB_0025dea4;
        }
      }
    }
  }
  _av_buffer_unref(&local_48);
  lVar2 = 0;
LAB_0025dea4:
  *param_1 = lVar2;
  return iVar1;
}


