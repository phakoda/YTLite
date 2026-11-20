/* Decompiled from supplied 5.2.2 arm package. VA 0x25b6bc. _av_frame_get_buffer */

int _av_frame_get_buffer(long param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  int iVar10;
  ulong uVar11;
  long *plVar12;
  uint *puVar13;
  
  if (-1 < *(int *)(param_1 + 0x74)) {
    bVar3 = true;
    bVar4 = false;
    if (0 < (int)*(undefined8 *)(param_1 + 0x68)) {
      iVar5 = (int)((ulong)*(undefined8 *)(param_1 + 0x68) >> 0x20);
      bVar4 = SBORROW4(iVar5,1);
      bVar3 = iVar5 + -1 < 0;
    }
    if (bVar3 == bVar4) {
      lVar7 = _av_pix_fmt_desc_get();
      uVar2 = 0x20;
      if (0x1f < (int)param_2) {
        uVar2 = param_2;
      }
      if (lVar7 != 0) {
        iVar5 = _av_image_check_size
                          (*(undefined4 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x6c),0,0);
        if (iVar5 < 0) {
          return iVar5;
        }
        puVar13 = (uint *)(param_1 + 0x40);
        if (*puVar13 == 0) {
          uVar1 = 0x20;
          if (0 < (int)param_2) {
            uVar1 = param_2;
          }
          iVar5 = 1;
          do {
            if ((int)uVar1 < iVar5) break;
            iVar6 = _av_image_fill_linesizes
                              (puVar13,*(undefined4 *)(param_1 + 0x74),
                               (iVar5 + *(int *)(param_1 + 0x68)) - 1U & -iVar5);
            if (iVar6 < 0) {
              return iVar6;
            }
            iVar5 = iVar5 << 1;
          } while ((*puVar13 & uVar1 - 1) != 0);
          for (lVar7 = 0; (lVar7 < 4 && (iVar5 = *(int *)(param_1 + 0x40 + lVar7 * 4), iVar5 != 0));
              lVar7 = lVar7 + 1) {
            *(uint *)(param_1 + 0x40 + lVar7 * 4) = iVar5 + (uVar1 - 1) & -uVar1;
          }
        }
        uVar1 = *(int *)(param_1 + 0x6c) + 0x1fU & 0xffffffe0;
        iVar5 = _av_image_fill_pointers(param_1,*(undefined4 *)(param_1 + 0x74),uVar1,0,puVar13);
        if (iVar5 < 0) {
          return iVar5;
        }
        lVar7 = _av_buffer_alloc(iVar5 + uVar2 * 4);
        *(long *)(param_1 + 0x120) = lVar7;
        if (lVar7 == 0) {
          iVar5 = -0xc;
        }
        else {
          iVar5 = _av_image_fill_pointers
                            (param_1,*(undefined4 *)(param_1 + 0x74),uVar1,
                             *(undefined8 *)(lVar7 + 8),puVar13);
          if (-1 < iVar5) {
            if ((int)param_2 < 0x21) {
              param_2 = 0x20;
            }
            uVar11 = (ulong)param_2;
            for (lVar7 = 8; lVar7 != 0x20; lVar7 = lVar7 + 8) {
              if (*(long *)(param_1 + lVar7) != 0) {
                *(ulong *)(param_1 + lVar7) = *(long *)(param_1 + lVar7) + uVar11;
              }
              uVar11 = uVar11 + param_2;
            }
            *(long *)(param_1 + 0x60) = param_1;
            return 0;
          }
        }
        _av_frame_unref(param_1);
        return iVar5;
      }
    }
    else if ((0 < *(int *)(param_1 + 0x70)) &&
            ((*(long *)(param_1 + 0x118) != 0 || (0 < *(int *)(param_1 + 0x1bc))))) {
      iVar6 = _av_sample_fmt_is_planar(*(undefined4 *)(param_1 + 0x74));
      iVar5 = *(int *)(param_1 + 0x1bc);
      if (iVar5 == 0) {
        iVar5 = _av_get_channel_layout_nb_channels(*(undefined8 *)(param_1 + 0x118));
        *(int *)(param_1 + 0x1bc) = iVar5;
      }
      iVar10 = iVar5;
      if (iVar6 == 0) {
        iVar10 = 1;
      }
      if ((*(int *)(param_1 + 0x40) == 0) &&
         (iVar5 = _av_samples_get_buffer_size
                            ((int *)(param_1 + 0x40),iVar5,*(undefined4 *)(param_1 + 0x70),
                             *(undefined4 *)(param_1 + 0x74),param_2), iVar5 < 0)) {
        return iVar5;
      }
      if (iVar10 < 9) {
        *(long *)(param_1 + 0x60) = param_1;
      }
      else {
        lVar7 = _av_mallocz_array((long)iVar10,8);
        plVar12 = (long *)(param_1 + 0x60);
        *plVar12 = lVar7;
        lVar7 = _av_mallocz_array((long)(iVar10 + -8),8);
        *(long *)(param_1 + 0x160) = lVar7;
        if ((lVar7 == 0) || (*plVar12 == 0)) {
          _av_freep(plVar12);
          _av_freep(param_1 + 0x160);
          return -0xc;
        }
        *(int *)(param_1 + 0x168) = iVar10 + -8;
      }
      lVar7 = 0;
      iVar5 = iVar10 + -8;
      if (7 < iVar10) {
        iVar10 = 8;
      }
      for (; lVar7 < iVar10; lVar7 = lVar7 + 1) {
        lVar8 = _av_buffer_alloc(*(undefined4 *)(param_1 + 0x40));
        *(long *)(param_1 + lVar7 * 8 + 0x120) = lVar8;
        if (lVar8 == 0) goto LAB_0025b9bc;
        uVar9 = *(undefined8 *)(lVar8 + 8);
        *(undefined8 *)(param_1 + lVar7 * 8) = uVar9;
        *(undefined8 *)(*(long *)(param_1 + 0x60) + lVar7 * 8) = uVar9;
      }
      lVar7 = 0;
      while( true ) {
        if (iVar5 <= lVar7) {
          return 0;
        }
        uVar9 = _av_buffer_alloc(*(undefined4 *)(param_1 + 0x40));
        *(undefined8 *)(*(long *)(param_1 + 0x160) + lVar7 * 8) = uVar9;
        lVar8 = *(long *)(*(long *)(param_1 + 0x160) + lVar7 * 8);
        if (lVar8 == 0) break;
        *(undefined8 *)(*(long *)(param_1 + 0x60) + lVar7 * 8 + 0x40) = *(undefined8 *)(lVar8 + 8);
        lVar7 = lVar7 + 1;
      }
LAB_0025b9bc:
      _av_frame_unref(param_1);
      return -0xc;
    }
  }
  return -0x16;
}


