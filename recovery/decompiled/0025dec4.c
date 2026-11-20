/* Decompiled from supplied 5.2.2 arm package. VA 0x25dec4. _av_hwdevice_ctx_create_derived_opts */

int _av_hwdevice_ctx_create_derived_opts
              (long *param_1,int param_2,long param_3,undefined8 param_4,undefined4 param_5)

{
  int iVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  long lVar5;
  long local_58;
  
  local_58 = 0;
  for (lVar2 = param_3; lVar2 != 0; lVar2 = *(long *)(*(long *)(*(long *)(lVar2 + 8) + 8) + 0x10)) {
    if (*(int *)(*(long *)(lVar2 + 8) + 0x10) == param_2) {
      lVar2 = _av_buffer_ref();
      if (lVar2 != 0) goto LAB_0025dfb4;
      local_58 = 0;
      goto LAB_0025dfbc;
    }
  }
  local_58 = _av_hwdevice_ctx_alloc(param_2);
  if (local_58 == 0) {
LAB_0025dfbc:
    iVar1 = -0xc;
  }
  else {
    lVar5 = *(long *)(local_58 + 8);
    for (lVar2 = param_3; lVar2 != 0; lVar2 = *(long *)(*(long *)(lVar2 + 8) + 0x10)) {
      lVar2 = *(long *)(lVar2 + 8);
      pcVar4 = *(code **)(**(long **)(lVar5 + 8) + 0x48);
      if (pcVar4 != (code *)0x0) {
        iVar1 = (*pcVar4)(lVar5,lVar2,param_4,param_5);
        if (iVar1 != -0x4e) {
          if (iVar1 != 0) goto LAB_0025dfc8;
          lVar3 = _av_buffer_ref(param_3);
          lVar2 = local_58;
          *(long *)(*(long *)(lVar5 + 8) + 0x10) = lVar3;
          if (lVar3 == 0) goto LAB_0025dfbc;
          iVar1 = _av_hwdevice_ctx_init(local_58);
          if (-1 < iVar1) goto LAB_0025dfb4;
          goto LAB_0025dfc8;
        }
      }
    }
    iVar1 = -0x4e;
  }
LAB_0025dfc8:
  _av_buffer_unref(&local_58);
  lVar2 = 0;
LAB_0025dfd4:
  *param_1 = lVar2;
  return iVar1;
LAB_0025dfb4:
  iVar1 = 0;
  goto LAB_0025dfd4;
}


