/* Decompiled from supplied 5.2.2 arm package. VA 0x25d31c. _av_hwdevice_ctx_alloc */

long _av_hwdevice_ctx_alloc(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 *local_38;
  
  puVar2 = PTR__ff_hwcontext_type_videotoolbox_01064648;
  bVar1 = false;
  do {
    if (bVar1) {
      return 0;
    }
    bVar1 = true;
  } while (*(int *)PTR__ff_hwcontext_type_videotoolbox_01064648 != param_1);
  puVar4 = (undefined8 *)_av_mallocz(0x30);
  if (puVar4 == (undefined8 *)0x0) {
    return 0;
  }
  local_38 = puVar4;
  uVar5 = _av_mallocz(0x18);
  puVar3 = local_38;
  puVar4[1] = uVar5;
  puVar4 = local_38;
  if (local_38[1] != 0) {
    if (*(long *)(puVar2 + 0x20) != 0) {
      uVar5 = _av_mallocz();
      *(undefined8 *)(puVar3[1] + 8) = uVar5;
      puVar4 = local_38;
      if (*(long *)(local_38[1] + 8) == 0) goto LAB_0025d404;
    }
    puVar4 = local_38;
    if (*(long *)(puVar2 + 0x18) != 0) {
      uVar5 = _av_mallocz();
      puVar4[3] = uVar5;
      puVar4 = local_38;
      if (local_38[3] == 0) goto LAB_0025d404;
    }
    puVar4 = local_38;
    lVar6 = _av_buffer_create(local_38,0x30,FUN_0025d448,0,1);
    if (lVar6 != 0) {
      *(int *)(puVar4 + 2) = param_1;
      *puVar4 = &PTR_s_AVHWDeviceContext_01064658;
      *(undefined **)local_38[1] = puVar2;
      return lVar6;
    }
  }
LAB_0025d404:
  lVar6 = puVar4[1];
  if (lVar6 != 0) {
    _av_freep(lVar6 + 8);
  }
  _av_freep(puVar4 + 1);
  _av_freep(puVar4 + 3);
  _av_freep(&local_38);
  return 0;
}


