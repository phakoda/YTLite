/* Decompiled from supplied 5.2.2 arm package. VA 0x27d810. FUN_0027d810 */

undefined8 FUN_0027d810(long param_1)

{
  long *plVar1;
  double dVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  
  lVar10 = *(long *)(*(long *)(param_1 + 0x10) + 0x48);
  *(undefined8 *)(lVar10 + 0x80) = 0x8000000000000000;
  dVar2 = DAT_00c4c4a0;
  iVar6 = (int)(((double)*(int *)(param_1 + 0x40) * *(double *)(lVar10 + 8)) / DAT_00c4c4a0);
  *(int *)(lVar10 + 0x44) = iVar6;
  if (99 < iVar6) {
    dVar11 = (double)iVar6;
    dVar12 = (dVar11 * *(double *)(lVar10 + 0x20)) / DAT_00c53798;
    dVar13 = *(double *)(lVar10 + 0x10) / DAT_00c53798;
    if (dVar12 <= 1.0) {
      dVar12 = 1.0;
    }
    *(int *)(lVar10 + 0x40) = (int)((dVar11 * *(double *)(lVar10 + 0x28)) / dVar2);
    *(int *)(lVar10 + 0x3c) = (int)dVar12;
    iVar7 = (int)(dVar11 * (1.0 - dVar13));
    *(int *)(lVar10 + 0x48) = iVar7;
    if (0 < iVar7) {
      lVar3 = _av_calloc((long)iVar6,8);
      *(long *)(lVar10 + 0xb8) = lVar3;
      dVar12 = DAT_00c537d8;
      dVar11 = DAT_00c51e38;
      dVar2 = DAT_00c508b0;
      if (lVar3 != 0) {
        iVar6 = *(int *)(lVar10 + 0x44);
        for (lVar8 = 0; lVar8 < iVar6; lVar8 = lVar8 + 1) {
          dVar13 = (double)_sin(((double)(int)lVar8 * dVar2) / (double)iVar6);
          *(double *)(lVar3 + lVar8 * 8) =
               dVar13 * (*(double *)(lVar10 + 0x10) / dVar12 + 1.0) * dVar11;
        }
        _av_frame_free((long *)(lVar10 + 0x58));
        _av_frame_free((long *)(lVar10 + 0x60));
        _av_frame_free((long *)(lVar10 + 0x68));
        _av_frame_free(lVar10 + 0x70);
        uVar4 = _ff_get_audio_buffer(param_1,*(undefined4 *)(lVar10 + 0x44));
        *(undefined8 *)(lVar10 + 0x50) = uVar4;
        uVar4 = _ff_get_audio_buffer(param_1,*(undefined4 *)(lVar10 + 0x44));
        *(undefined8 *)(lVar10 + 0x58) = uVar4;
        uVar4 = _ff_get_audio_buffer(param_1,*(undefined4 *)(lVar10 + 0x44));
        *(undefined8 *)(lVar10 + 0x60) = uVar4;
        uVar4 = _ff_get_audio_buffer(param_1,*(int *)(lVar10 + 0x44) << 1);
        *(undefined8 *)(lVar10 + 0x68) = uVar4;
        lVar3 = _ff_get_audio_buffer(param_1,*(undefined4 *)(lVar10 + 0x44));
        *(long *)(lVar10 + 0x70) = lVar3;
        if ((*(long *)(lVar10 + 0x58) != 0) && (*(long *)(lVar10 + 0x60) != 0)) {
          if (lVar3 == 0) {
            return 0xfffffff4;
          }
          if (*(long *)(lVar10 + 0x68) == 0) {
            return 0xfffffff4;
          }
          if (*(long *)(lVar10 + 0x50) != 0) {
            lVar3 = _av_audio_fifo_alloc
                              (*(undefined4 *)(param_1 + 0x44),1,*(undefined4 *)(lVar10 + 0x44));
            *(long *)(lVar10 + 0xa8) = lVar3;
            if (lVar3 != 0) {
              lVar3 = _av_audio_fifo_alloc
                                (*(undefined4 *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0xc4),
                                 *(undefined4 *)(lVar10 + 0x44));
              *(long *)(lVar10 + 0xb0) = lVar3;
              if (lVar3 != 0) {
                if (*(int *)(lVar10 + 0x30) == 0) {
                  *(undefined4 *)(lVar10 + 0x4c) = 0;
                }
                else {
                  iVar7 = *(int *)(lVar10 + 0x44) - *(int *)(lVar10 + 0x48);
                  iVar6 = iVar7;
                  if (iVar7 < 0) {
                    iVar6 = iVar7 + 1;
                  }
                  *(int *)(lVar10 + 0x4c) = iVar6 >> 1;
                  if (1 < iVar7) {
                    _av_audio_fifo_write(lVar3,*(undefined8 *)(*(long *)(lVar10 + 0x58) + 0x60));
                  }
                }
                iVar6 = *(int *)(param_1 + 0xc4);
                *(int *)(lVar10 + 0x88) = iVar6;
                lVar3 = _av_calloc((long)iVar6,0x80);
                *(long *)(lVar10 + 0x78) = lVar3;
                if (lVar3 != 0) {
                  lVar8 = 0;
                  lVar3 = -1;
                  while( true ) {
                    lVar3 = lVar3 + 1;
                    if (*(int *)(param_1 + 0xc4) <= lVar3) {
                      return 0;
                    }
                    lVar9 = *(long *)(lVar10 + 0x78);
                    lVar5 = _av_calloc((long)*(int *)(lVar10 + 0x44),8);
                    plVar1 = (long *)(lVar9 + lVar8);
                    plVar1[1] = lVar5;
                    lVar5 = _av_calloc((long)*(int *)(lVar10 + 0x3c) + 1,8);
                    *plVar1 = lVar5;
                    lVar5 = _av_calloc((long)*(int *)(lVar10 + 0x3c) + 1,8);
                    plVar1[2] = lVar5;
                    lVar5 = _av_calloc((long)*(int *)(lVar10 + 0x3c) + 1,8);
                    plVar1[3] = lVar5;
                    lVar5 = _av_calloc((long)*(int *)(lVar10 + 0x3c),8);
                    plVar1[4] = lVar5;
                    lVar5 = _av_calloc((long)*(int *)(lVar10 + 0x44),1);
                    plVar1[0xc] = lVar5;
                    lVar5 = _av_calloc((long)*(int *)(lVar10 + 0x44),4);
                    plVar1[0xd] = lVar5;
                    lVar5 = _av_calloc((long)*(int *)(lVar10 + 0x44),8);
                    plVar1[5] = lVar5;
                    if ((((*plVar1 == 0) || (plVar1[2] == 0)) || (plVar1[1] == 0)) ||
                       (plVar1[0xc] == 0)) break;
                    if (lVar5 == 0) {
                      return 0xfffffff4;
                    }
                    if (plVar1[0xd] == 0) {
                      return 0xfffffff4;
                    }
                    if (plVar1[3] == 0) {
                      return 0xfffffff4;
                    }
                    lVar8 = lVar8 + 0x80;
                    if (plVar1[4] == 0) {
                      return 0xfffffff4;
                    }
                  }
                }
              }
            }
          }
        }
      }
      return 0xfffffff4;
    }
  }
  return 0xffffffea;
}


