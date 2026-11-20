/* Decompiled from supplied 5.2.2 arm package. VA 0x25d528. _av_hwframe_ctx_alloc */

long _av_hwframe_ctx_alloc(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long local_50;
  undefined8 *local_48;
  
  lVar6 = *(long *)(param_1 + 8);
  lVar5 = **(long **)(lVar6 + 8);
  local_50 = 0;
  puVar2 = (undefined8 *)_av_mallocz(0x58);
  if (puVar2 == (undefined8 *)0x0) {
    return 0;
  }
  local_48 = puVar2;
  uVar3 = _av_mallocz(0x28);
  puVar1 = local_48;
  puVar2[1] = uVar3;
  puVar2 = local_48;
  if (local_48[1] != 0) {
    if (*(long *)(lVar5 + 0x38) != 0) {
      uVar3 = _av_mallocz();
      *(undefined8 *)(puVar1[1] + 8) = uVar3;
      puVar2 = local_48;
      if (*(long *)(local_48[1] + 8) == 0) goto LAB_0025d624;
    }
    puVar2 = local_48;
    if (*(long *)(lVar5 + 0x30) != 0) {
      uVar3 = _av_mallocz();
      puVar2[4] = uVar3;
      puVar2 = local_48;
      if (local_48[4] == 0) goto LAB_0025d624;
    }
    puVar2 = local_48;
    local_50 = _av_buffer_ref(param_1);
    if (local_50 == 0) goto LAB_0025d638;
    lVar4 = _av_buffer_create(puVar2,0x58,FUN_0025d680,0,1);
    if (lVar4 != 0) {
      *puVar2 = &PTR_s_AVHWFramesContext_010646b0;
      local_48[2] = local_50;
      local_48[3] = lVar6;
      *(undefined4 *)((long)local_48 + 0x44) = 0xffffffff;
      *(undefined4 *)(local_48 + 9) = 0xffffffff;
      *(long *)local_48[1] = lVar5;
      return lVar4;
    }
  }
LAB_0025d624:
  if (local_50 != 0) {
    _av_buffer_unref(&local_50);
    puVar2 = local_48;
  }
LAB_0025d638:
  if (puVar2[1] != 0) {
    _av_freep(puVar2[1] + 8);
    puVar2 = local_48;
  }
  _av_freep(puVar2 + 1);
  _av_freep(puVar2 + 4);
  _av_freep(&local_48);
  return 0;
}


