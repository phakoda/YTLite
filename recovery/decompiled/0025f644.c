/* Decompiled from supplied 5.2.2 arm package. VA 0x25f644. _av_image_fill_black */

void _av_image_fill_black
               (undefined8 *param_1,long *param_2,int param_3,int param_4,undefined4 param_5,
               int param_6)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  size_t sVar4;
  byte bVar5;
  byte bVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  long lVar11;
  undefined8 uVar12;
  short sVar13;
  uint uVar14;
  ulong uVar15;
  ulong uVar16;
  int *piVar17;
  byte *pbVar18;
  long lVar19;
  byte *pbVar20;
  void *pvVar21;
  ulong uVar22;
  long lVar23;
  short local_178 [32];
  undefined8 local_138 [4];
  ulong local_118 [4];
  int local_f8 [4];
  byte local_e8 [128];
  long local_68;
  
  lVar23 = *(long *)PTR____stack_chk_guard_01060708;
  local_68 = lVar23;
  lVar11 = _av_pix_fmt_desc_get(param_3);
  iVar8 = _av_pix_fmt_count_planes(param_3);
  _memset(local_e8,0,0x80);
  local_f8[0] = 0;
  local_f8[1] = 0;
  local_f8[2] = 0;
  local_f8[3] = 0;
  local_118[2] = 0;
  local_118[3] = 0;
  local_118[0] = 0;
  local_118[1] = 0;
  uVar12 = 0xffffffea;
  if ((lVar11 != 0) && (iVar8 - 1U < 4)) {
    uVar15 = *(ulong *)(lVar11 + 0x10);
    if (((uint)uVar15 >> 3 & 1) == 0) {
      bVar7 = (uVar15 & 0x20) == 0;
      if (((uint)uVar15 >> 2 & 1) == 0) {
        uVar16 = (ulong)*(byte *)(lVar11 + 8);
        piVar17 = (int *)(lVar11 + 0x1c);
        lVar19 = -1;
        do {
          lVar19 = lVar19 + 1;
          if ((long)uVar16 <= lVar19) {
            uVar22 = 0;
            goto LAB_0025f84c;
          }
          iVar9 = *piVar17;
          piVar1 = piVar17 + -1;
          piVar17 = piVar17 + 8;
          iVar10 = local_f8[*piVar1];
          if (local_f8[*piVar1] <= iVar9) {
            iVar10 = iVar9;
          }
          local_f8[*piVar1] = iVar10;
        } while (iVar10 < 0x21);
      }
      else {
        iVar9 = _av_image_get_linesize(param_3,param_5,0);
        iVar10 = 0xff;
        if (param_3 != 9) {
          iVar10 = 0;
        }
        if (iVar8 == 1) {
          uVar12 = 0xffffffea;
          if ((0 < iVar9) && (param_3 - 9U < 2 || (uVar15 & 0x20) != 0)) {
            if (param_1 != (undefined8 *)0x0) {
              pvVar21 = (void *)*param_1;
              param_6 = param_6 + 1;
              while (param_6 = param_6 + -1, 0 < param_6) {
                _memset(pvVar21,iVar10,(long)iVar9);
                pvVar21 = (void *)((long)pvVar21 + *param_2);
              }
            }
LAB_0025faa8:
            uVar12 = 0;
          }
          goto LAB_0025f7dc;
        }
      }
    }
    uVar12 = 0xffffffea;
  }
  goto LAB_0025f7dc;
LAB_0025f84c:
  if ((long)uVar16 <= (long)uVar22) goto LAB_0025f94c;
  lVar23 = lVar11 + uVar22 * 0x20;
  uVar14 = *(uint *)(lVar23 + 0x28);
  if ((0x10 < (int)uVar14) || ((int)uVar14 < 8 && bVar7)) {
LAB_0025f938:
    uVar12 = 0xffffffea;
    goto LAB_0025f93c;
  }
  iVar10 = 0;
  if (*(int *)(lVar23 + 0x1c) != 0) {
    iVar10 = local_f8[*(int *)(lVar23 + 0x18)] / *(int *)(lVar23 + 0x1c);
  }
  if (iVar10 < 1) goto LAB_0025f938;
  if ((param_4 == 2 || !bVar7) || uVar22 != 0) {
    if (((uVar15 & 0x20) == 0) && ((int)uVar22 - 1U < 2)) {
      sVar13 = (short)(0x80 << (ulong)(uVar14 - 8 & 0x1f));
    }
    else if (uVar22 == 3) {
      sVar13 = (short)(1 << (ulong)(uVar14 & 0x1f)) + -1;
    }
    else {
      sVar13 = 0;
    }
  }
  else {
    sVar13 = (short)(0x10 << (ulong)(uVar14 - 8 & 0x1f));
  }
  for (lVar23 = 0; lVar23 < iVar10; lVar23 = lVar23 + 1) {
    local_178[lVar23] = sVar13;
  }
  pbVar18 = local_e8;
  for (lVar23 = 0; lVar23 != 0x20; lVar23 = lVar23 + 8) {
    *(byte **)((long)local_138 + lVar23) = pbVar18;
    pbVar18 = pbVar18 + 0x20;
  }
  _av_write_image_line(local_178,local_138,&DAT_00c50e84,lVar11,0,0,uVar22 & 0xffffffff);
  uVar16 = (ulong)*(byte *)(lVar11 + 8);
  uVar22 = uVar22 + 1;
  goto LAB_0025f84c;
LAB_0025f94c:
  uVar15 = 0;
  lVar23 = *(long *)PTR____stack_chk_guard_01060708;
  do {
    if ((long)iVar8 <= (long)uVar15) {
      if (param_1 != (undefined8 *)0x0) {
        pbVar18 = local_e8;
        for (lVar23 = 0; lVar23 < iVar8; lVar23 = lVar23 + 1) {
          uVar15 = local_118[lVar23];
          pvVar21 = (void *)param_1[lVar23];
          if ((int)lVar23 - 1U < 2) {
            uVar14 = (uint)*(byte *)(lVar11 + 10);
          }
          else {
            uVar14 = 0;
          }
          pbVar2 = local_e8 + lVar23 * 0x20;
          iVar10 = param_6 + -1 + (1 << (ulong)(uVar14 & 0x1f)) >> (uVar14 & 0x1f);
          while (0 < iVar10) {
            iVar9 = local_f8[lVar23];
            uVar16 = (ulong)iVar9;
            if (iVar9 != 0) {
              uVar22 = 0;
              pbVar20 = pbVar18;
              do {
                if (uVar16 <= uVar22) {
                  bVar6 = *pbVar2;
                  goto LAB_0025fa98;
                }
                bVar5 = *pbVar20;
                bVar6 = *pbVar2;
                uVar22 = uVar22 + 1;
                pbVar20 = pbVar20 + 1;
              } while (bVar5 == bVar6);
              if (iVar9 == 1) {
LAB_0025fa98:
                _memset(pvVar21,(uint)bVar6,uVar15);
              }
              else {
                sVar4 = uVar15;
                if (uVar16 <= uVar15) {
                  sVar4 = uVar16;
                }
                iVar3 = (int)uVar15;
                if (uVar16 <= uVar15) {
                  iVar3 = iVar9;
                }
                _memcpy(pvVar21,pbVar2,sVar4);
                _av_memcpy_backptr((long)pvVar21 + sVar4,iVar3,(int)uVar15 - iVar3);
              }
            }
            pvVar21 = (void *)((long)pvVar21 + param_2[lVar23]);
            iVar10 = iVar10 + -1;
          }
          pbVar18 = pbVar18 + 0x20;
        }
        uVar12 = 0;
LAB_0025f93c:
        lVar23 = *(long *)PTR____stack_chk_guard_01060708;
        break;
      }
      goto LAB_0025faa8;
    }
    iVar10 = _av_image_get_linesize(param_3,param_5,uVar15 & 0xffffffff);
    local_118[uVar15] = (long)iVar10;
    uVar15 = uVar15 + 1;
    uVar12 = 0xffffffea;
  } while (-1 < iVar10);
LAB_0025f7dc:
  if (lVar23 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(uVar12);
  }
  return;
}


