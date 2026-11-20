/* Decompiled from supplied 5.2.2 arm package. VA 0x25c460. _av_frame_apply_cropping */

undefined4 _av_frame_apply_cropping(long *param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  long *plVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  uint uVar7;
  undefined4 uVar8;
  long lVar9;
  long *plVar10;
  long local_78 [4];
  long local_58;
  
  lVar9 = *(long *)PTR____stack_chk_guard_01060708;
  lVar1 = param_1[0xd];
  local_58 = lVar9;
  if (((int)lVar1 < 1) || ((int)((ulong)lVar1 >> 0x20) < 1)) {
    uVar8 = 0xffffffea;
    goto LAB_0025c548;
  }
  if ((ulong)param_1[0x40] < 0x7fffffffU - param_1[0x41]) {
    if ((((ulong)param_1[0x3e] < 0x7fffffffU - param_1[0x3f]) &&
        ((ulong)(param_1[0x41] + param_1[0x40]) < (ulong)(long)(int)lVar1)) &&
       ((ulong)(param_1[0x3f] + param_1[0x3e]) < (ulong)(lVar1 >> 0x20))) {
      uVar8 = 0xdeb8aabe;
      lVar1 = _av_pix_fmt_desc_get(*(undefined4 *)((long)param_1 + 0x74));
      if (lVar1 != 0) {
        if ((*(byte *)(lVar1 + 0x10) & 0xc) == 0) {
          FUN_0025c68c(local_78,param_1,lVar1);
          plVar3 = param_1;
          plVar10 = local_78;
          if ((param_2 & 1) == 0) {
            uVar2 = param_1[0x40];
            if (uVar2 == 0) {
              uVar4 = 0x7fffffff;
            }
            else {
              uVar4 = ((uint)uVar2 & 0xaaaaaaaa) >> 1 | ((uint)uVar2 & 0x55555555) << 1;
              uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
              uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
              uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
              uVar4 = (uint)LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10);
            }
            uVar5 = 0x7fffffff;
            for (lVar6 = 0; *(long *)((long)param_1 + lVar6) != 0; lVar6 = lVar6 + 8) {
              if (*(long *)((long)local_78 + lVar6) == 0) {
                uVar7 = 0x7fffffff;
              }
              else {
                uVar7 = (uint)*(long *)((long)local_78 + lVar6);
                uVar7 = (uVar7 & 0xaaaaaaaa) >> 1 | (uVar7 & 0x55555555) << 1;
                uVar7 = (uVar7 & 0xcccccccc) >> 2 | (uVar7 & 0x33333333) << 2;
                uVar7 = (uVar7 & 0xf0f0f0f0) >> 4 | (uVar7 & 0xf0f0f0f) << 4;
                uVar7 = (uVar7 & 0xff00ff00) >> 8 | (uVar7 & 0xff00ff) << 8;
                uVar7 = (uint)LZCOUNT(uVar7 >> 0x10 | uVar7 << 0x10);
              }
              if (uVar7 <= uVar5) {
                uVar5 = uVar7;
              }
            }
            if (uVar4 < uVar5) goto LAB_0025c548;
            if (uVar5 < 5) {
              param_1[0x40] = uVar2 & (long)(-1 << (ulong)((uVar4 + 5) - uVar5 & 0x1f));
              FUN_0025c68c(local_78,param_1,lVar1);
            }
            plVar10 = local_78;
          }
          for (; *plVar3 != 0; plVar3 = plVar3 + 1) {
            *plVar3 = *plVar3 + *plVar10;
            plVar10 = plVar10 + 1;
          }
          uVar8 = 0;
          *(int *)(param_1 + 0xd) = (int)param_1[0xd] - ((int)param_1[0x41] + (int)param_1[0x40]);
          *(int *)((long)param_1 + 0x6c) =
               *(int *)((long)param_1 + 0x6c) - ((int)param_1[0x3f] + (int)param_1[0x3e]);
          param_1[0x40] = 0;
          param_1[0x41] = 0;
          param_1[0x3e] = 0;
          param_1[0x3f] = 0;
        }
        else {
          uVar8 = 0;
          lVar1 = param_1[0x41];
          param_1[0x41] = 0;
          *(int *)(param_1 + 0xd) = (int)param_1[0xd] - (int)lVar1;
          *(int *)((long)param_1 + 0x6c) = *(int *)((long)param_1 + 0x6c) - (int)param_1[0x3f];
          param_1[0x3f] = 0;
        }
      }
      goto LAB_0025c548;
    }
  }
  uVar8 = 0xffffffde;
LAB_0025c548:
  if (lVar9 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return uVar8;
}


