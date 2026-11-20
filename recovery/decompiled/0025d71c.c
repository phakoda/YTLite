/* Decompiled from supplied 5.2.2 arm package. VA 0x25d71c. _av_hwframe_ctx_init */

int _av_hwframe_ctx_init(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long local_48;
  
  lVar6 = *(long *)(param_1 + 8);
  if ((*(long **)(lVar6 + 8))[3] == 0) {
    piVar3 = *(int **)(**(long **)(lVar6 + 8) + 0x10);
    do {
      iVar1 = *piVar3;
      if (iVar1 == -1) {
        _av_get_pix_fmt_name();
        _av_log(lVar6,0x10,
                "The hardware pixel format \'%s\' is not supported by the device type \'%s\'\n");
        return -0x4e;
      }
      piVar3 = piVar3 + 1;
    } while (iVar1 != *(int *)(lVar6 + 0x44));
    iVar1 = _av_image_check_size
                      (*(undefined4 *)(lVar6 + 0x4c),*(undefined4 *)(lVar6 + 0x50),0,lVar6);
    if (iVar1 < 0) {
      return iVar1;
    }
    plVar4 = *(long **)(lVar6 + 8);
    if (*(code **)(*plVar4 + 0x68) != (code *)0x0) {
      iVar1 = (**(code **)(*plVar4 + 0x68))(lVar6);
      if (iVar1 < 0) goto LAB_0025d890;
      plVar4 = *(long **)(lVar6 + 8);
    }
    if ((plVar4[2] != 0) && (*(long *)(lVar6 + 0x38) == 0)) {
      *(long *)(lVar6 + 0x38) = plVar4[2];
    }
    if (0 < *(int *)(lVar6 + 0x40)) {
      lVar9 = *(long *)(param_1 + 8);
      local_48 = _av_mallocz_array((long)*(int *)(lVar9 + 0x40),8);
      if (local_48 == 0) {
        iVar1 = -0xc;
      }
      else {
        lVar10 = 0;
        iVar1 = 0;
        lVar7 = local_48;
        do {
          lVar8 = lVar7;
          if (*(int *)(lVar9 + 0x40) <= lVar10) break;
          uVar2 = _av_frame_alloc();
          lVar8 = local_48;
          *(undefined8 *)(lVar7 + lVar10 * 8) = uVar2;
          if (*(long *)(local_48 + lVar10 * 8) == 0) break;
          iVar1 = _av_hwframe_get_buffer(param_1);
          lVar10 = lVar10 + 1;
          lVar7 = lVar8;
        } while (-1 < iVar1);
        lVar10 = -1;
        while (lVar10 = lVar10 + 1, lVar10 < *(int *)(lVar9 + 0x40)) {
          _av_frame_free(lVar8);
          lVar8 = lVar8 + 8;
        }
        _av_freep(&local_48);
        if (-1 < iVar1) {
          return 0;
        }
      }
LAB_0025d890:
      pcVar5 = *(code **)(**(long **)(lVar6 + 8) + 0x70);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(lVar6);
      }
      return iVar1;
    }
  }
  return 0;
}


