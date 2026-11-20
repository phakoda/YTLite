/* Decompiled from supplied 5.2.2 arm package. VA 0x25e9bc. _av_image_fill_pointers */

int _av_image_fill_pointers(long *param_1,undefined4 param_2,int param_3,long param_4,int *param_5)

{
  int iVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  int local_58 [4];
  long local_48;
  
  lVar8 = *(long *)PTR____stack_chk_guard_01060708;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_48 = lVar8;
  lVar2 = _av_pix_fmt_desc_get(param_2);
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  if ((lVar2 != 0) && (uVar4 = *(ulong *)(lVar2 + 0x10), ((uint)uVar4 >> 3 & 1) == 0)) {
    *param_1 = param_4;
    iVar6 = 0;
    if (param_3 != 0) {
      iVar6 = 0x7ffffbff / param_3;
    }
    if (*param_5 <= iVar6) {
      iVar6 = *param_5 * param_3;
      lVar5 = 0x18;
      if ((uVar4 & 0x42) == 0) {
        while (lVar5 + 0x20 != 0xb8) {
          local_58[*(int *)(lVar2 + lVar5)] = 1;
          lVar5 = lVar5 + 0x20;
        }
        iVar3 = iVar6;
        for (lVar5 = 1; (lVar5 < 4 && (local_58[lVar5] != 0)); lVar5 = lVar5 + 1) {
          if (lVar5 - 1U < 2) {
            uVar7 = (uint)*(byte *)(lVar2 + 10);
          }
          else {
            uVar7 = 0;
          }
          param_4 = param_4 + iVar6;
          param_1[lVar5] = param_4;
          iVar6 = param_3 + -1 + (1 << (ulong)(uVar7 & 0x1f)) >> (uVar7 & 0x1f);
          iVar1 = 0;
          if (iVar6 != 0) {
            iVar1 = 0x7fffffff / iVar6;
          }
          if ((iVar1 < param_5[lVar5]) ||
             (iVar6 = iVar6 * param_5[lVar5], 0x7fffffff - iVar6 < iVar3)) goto LAB_0025eaf8;
          iVar3 = iVar6 + iVar3;
        }
      }
      else {
        param_1[1] = param_4 + iVar6;
        iVar3 = iVar6 + 0x400;
      }
      goto LAB_0025eafc;
    }
  }
LAB_0025eaf8:
  iVar3 = -0x16;
LAB_0025eafc:
  if (lVar8 != local_48) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return iVar3;
}


