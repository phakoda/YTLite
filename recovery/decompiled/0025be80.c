/* Decompiled from supplied 5.2.2 arm package. VA 0x25be80. _av_frame_copy */

void _av_frame_copy(long param_1,undefined8 *param_2)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  long local_38;
  
  lVar8 = *(long *)PTR____stack_chk_guard_01060708;
  iVar5 = *(int *)(param_1 + 0x74);
  uVar6 = 0xffffffea;
  local_38 = lVar8;
  if ((-1 < iVar5) && (iVar5 == *(int *)((long)param_2 + 0x74))) {
    if (*(int *)(param_1 + 0x68) < 1 || *(int *)(param_1 + 0x6c) < 1) {
      if ((0 < *(int *)(param_1 + 0x70)) && (0 < *(int *)(param_1 + 0x1bc))) {
        iVar5 = _av_sample_fmt_is_planar(*(undefined4 *)(param_1 + 0x74));
        if ((*(int *)(param_1 + 0x70) == *(int *)(param_2 + 0xe)) &&
           ((iVar4 = *(int *)(param_1 + 0x1bc), iVar4 == *(int *)((long)param_2 + 0x1bc) &&
            (*(long *)(param_1 + 0x118) == param_2[0x23])))) {
          lVar7 = 0;
          lVar3 = (long)iVar4;
          if (iVar5 == 0) {
            lVar3 = 1;
          }
          uVar6 = 0xffffffea;
          do {
            if (lVar3 <= lVar7) {
              _av_samples_copy(*(long *)(param_1 + 0x60),param_2[0xc],0,0,*(int *)(param_1 + 0x70),
                               (long)iVar4,*(undefined4 *)(param_1 + 0x74));
              goto LAB_0025c03c;
            }
            if (*(long *)(*(long *)(param_1 + 0x60) + lVar7 * 8) == 0) goto LAB_0025bfd4;
            lVar1 = lVar7 * 8;
            lVar7 = lVar7 + 1;
          } while (*(long *)(param_2[0xc] + lVar1) != 0);
          goto LAB_0025bfd8;
        }
      }
    }
    else if (((int)param_2[0xd] <= *(int *)(param_1 + 0x68)) &&
            ((int)((ulong)param_2[0xd] >> 0x20) <= *(int *)(param_1 + 0x6c))) {
      if ((param_2[0x3c] == 0) && (*(long *)(param_1 + 0x1e0) == 0)) {
        iVar5 = _av_pix_fmt_count_planes(iVar5);
        lVar7 = 0;
        uVar6 = 0xffffffea;
        do {
          if (iVar5 <= lVar7) {
            uStack_48 = param_2[3];
            local_50 = param_2[2];
            uStack_58 = param_2[1];
            local_60 = *param_2;
            _av_image_copy(param_1,param_1 + 0x40,&local_60,param_2 + 8,
                           *(undefined4 *)(param_1 + 0x74),*(undefined4 *)(param_2 + 0xd),
                           *(undefined4 *)((long)param_2 + 0x6c));
LAB_0025c03c:
            uVar6 = 0;
            break;
          }
          if (*(long *)(param_1 + lVar7 * 8) == 0) goto LAB_0025bfd4;
          plVar2 = param_2 + lVar7;
          lVar7 = lVar7 + 1;
        } while (*plVar2 != 0);
      }
      else {
        uVar6 = _av_hwframe_transfer_data(param_1,param_2,0);
      }
      goto LAB_0025bfd8;
    }
LAB_0025bfd4:
    uVar6 = 0xffffffea;
  }
LAB_0025bfd8:
  if (lVar8 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar6);
}


