/* Decompiled from supplied 5.2.2 arm package. VA 0x25e008. _ff_hwframe_map_create */

int _ff_hwframe_map_create(long param_1,long param_2,undefined8 param_3,long param_4,long param_5)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar4 = *(undefined8 *)(param_1 + 8);
  plVar2 = (long *)_av_mallocz(0x20);
  if (plVar2 == (long *)0x0) {
    iVar1 = -0xc;
    goto LAB_0025e0bc;
  }
  lVar3 = _av_frame_alloc();
  *plVar2 = lVar3;
  if (lVar3 == 0) {
LAB_0025e0a0:
    iVar1 = -0xc;
  }
  else {
    iVar1 = _av_frame_ref(lVar3,param_3);
    if (-1 < iVar1) {
      lVar3 = _av_buffer_ref(param_1);
      plVar2[1] = lVar3;
      if (lVar3 != 0) {
        plVar2[2] = param_4;
        plVar2[3] = param_5;
        lVar3 = _av_buffer_create(plVar2,0x20,FUN_0025e0e0,uVar4,0);
        *(long *)(param_2 + 0x120) = lVar3;
        if (lVar3 != 0) {
          return 0;
        }
      }
      goto LAB_0025e0a0;
    }
  }
  _av_buffer_unref(plVar2 + 1);
  _av_frame_free(plVar2);
LAB_0025e0bc:
  _av_free(plVar2);
  return iVar1;
}


