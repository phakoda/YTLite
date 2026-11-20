/* Decompiled from supplied 5.2.2 arm package. VA 0x244364. _shine_mdct_sub */

void _shine_mdct_sub(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  undefined4 uVar17;
  ulong uVar18;
  int iVar19;
  long lVar20;
  int *piVar21;
  long lVar22;
  long lVar23;
  long lVar24;
  int *piVar25;
  ulong uVar26;
  int *local_148;
  int *local_140;
  undefined4 local_134;
  int *local_130;
  ulong local_128;
  int *local_120;
  long lStack_118;
  long local_110;
  int *local_108;
  int *local_100;
  int aiStack_f8 [28];
  int local_88 [8];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  iVar10 = *param_1;
  local_134 = param_2;
  if (iVar10 != 0) {
    local_140 = param_1 + (long)(iVar10 + -1) * 0x6c0 + 0xd6e;
    local_148 = param_1 + (long)(iVar10 + -1) * 0x6c0 + 0xd4e;
    local_108 = param_1 + 0x519f;
    do {
      iVar19 = param_1[4];
      iVar10 = iVar10 + -1;
      local_128 = (ulong)iVar10;
      if (0 < iVar19) {
        local_130 = param_1 + local_128 * 2 + 0x222;
        local_100 = local_148;
        lVar22 = 0;
        piVar21 = local_140;
        do {
          uVar18 = local_128;
          piVar25 = local_130;
          uVar17 = local_134;
          lVar23 = 0;
          lStack_118 = lVar22 + 1;
          local_120 = piVar21;
          do {
            local_110 = lVar23;
            _shine_window_filter_subband(piVar25,piVar21,uVar18 & 0xffffffff,param_1,uVar17);
            _shine_window_filter_subband(piVar25,piVar21 + 0x20,uVar18 & 0xffffffff,param_1,uVar17);
            piVar21[0x21] = -piVar21[0x21];
            piVar21[0x23] = -piVar21[0x23];
            piVar21[0x25] = -piVar21[0x25];
            piVar21[0x27] = -piVar21[0x27];
            piVar21[0x29] = -piVar21[0x29];
            piVar21[0x2b] = -piVar21[0x2b];
            piVar21[0x2d] = -piVar21[0x2d];
            piVar21[0x2f] = -piVar21[0x2f];
            piVar21[0x31] = -piVar21[0x31];
            piVar21[0x33] = -piVar21[0x33];
            piVar21[0x35] = -piVar21[0x35];
            piVar21[0x37] = -piVar21[0x37];
            piVar21[0x39] = -piVar21[0x39];
            piVar21[0x3b] = -piVar21[0x3b];
            piVar21[0x3d] = -piVar21[0x3d];
            lVar23 = local_110 + 2;
            piVar21[0x3f] = -piVar21[0x3f];
            piVar21 = piVar21 + 0x40;
          } while (lVar23 < 0x12);
          lVar23 = 0;
          do {
            do {
              lVar20 = lVar23;
              piVar21 = local_100 + lVar20;
              lVar23 = 0x8c;
              do {
                piVar4 = (int *)((long)aiStack_f8 + lVar23);
                *(int *)((long)&local_140 + lVar23) = *piVar21;
                piVar25 = piVar21 + 0x240;
                lVar23 = lVar23 + -4;
                piVar21 = piVar21 + -0x20;
                *piVar4 = *piVar25;
              } while (lVar23 != 0x44);
              piVar21 = local_108;
              lVar23 = 0x11;
              do {
                lVar24 = 0;
                uVar26 = (ulong)((long)param_1[(long)(&UNK_00004f3f + lVar23 * 0x24)] *
                                (long)local_88[7]) >> 0x20;
                piVar25 = piVar21;
                do {
                  piVar5 = (int *)((long)local_88 + lVar24);
                  piVar1 = piVar25 + 2;
                  piVar7 = piVar25 + 3;
                  iVar19 = *piVar25;
                  piVar8 = piVar25 + 1;
                  piVar2 = piVar25 + -2;
                  piVar9 = piVar25 + -1;
                  lVar11 = lVar24 + 0x14;
                  lVar12 = lVar24 + 0x18;
                  piVar4 = piVar25 + -3;
                  lVar13 = lVar24 + 0xc;
                  lVar14 = lVar24 + 0x10;
                  lVar15 = lVar24 + 4;
                  lVar16 = lVar24 + 8;
                  lVar24 = lVar24 + -0x1c;
                  piVar25 = piVar25 + -7;
                  uVar3 = (int)((ulong)((long)*piVar7 * (long)*(int *)((long)local_88 + lVar12)) >>
                               0x20) + (int)uVar26 +
                          (int)((ulong)((long)*piVar1 * (long)*(int *)((long)local_88 + lVar11)) >>
                               0x20) +
                          (int)((ulong)((long)*piVar8 * (long)*(int *)((long)local_88 + lVar14)) >>
                               0x20) +
                          (int)((ulong)((long)iVar19 * (long)*(int *)((long)local_88 + lVar13)) >>
                               0x20) +
                          (int)((ulong)((long)*piVar9 * (long)*(int *)((long)local_88 + lVar16)) >>
                               0x20) +
                          (int)((ulong)((long)*piVar2 * (long)*(int *)((long)local_88 + lVar15)) >>
                               0x20) + (int)((ulong)((long)*piVar4 * (long)*piVar5) >> 0x20);
                  uVar26 = (ulong)uVar3;
                } while (lVar24 != -0x8c);
                param_1[(long)(&UNK_000018ae +
                              uVar18 * 0x480 + lVar22 * 0x240 + lVar20 * 0x12 + lVar23)] = uVar3;
                piVar21 = piVar21 + -0x24;
                bVar6 = lVar23 != 0;
                lVar23 = lVar23 + -1;
              } while (bVar6);
              lVar23 = 1;
            } while (lVar20 == 0);
            piVar21 = param_1 + (long)(&UNK_000018ae +
                                      uVar18 * 0x480 + lVar22 * 0x240 + lVar20 * 0x12);
            iVar19 = piVar21[-1];
            piVar21[-1] = (int)((ulong)((long)*piVar21 * -0x41daff35 + (long)iVar19 * 0x6dc25403) >>
                               0x1f);
            *piVar21 = (int)((ulong)((long)*piVar21 * 0x6dc25403 + (long)iVar19 * 0x41daff35) >>
                            0x1f);
            iVar19 = piVar21[-2];
            piVar21[-2] = (int)((ulong)((long)piVar21[1] * -0x3c61b690 + (long)iVar19 * 0x70dcebf8)
                               >> 0x1f);
            piVar21[1] = (int)((ulong)((long)piVar21[1] * 0x70dcebf8 + (long)iVar19 * 0x3c61b690) >>
                              0x1f);
            iVar19 = piVar21[-3];
            piVar21[-3] = (int)((ulong)((long)piVar21[2] * -0x281cc09e + (long)iVar19 * 0x798d6e7a)
                               >> 0x1f);
            piVar21[2] = (int)((ulong)((long)piVar21[2] * 0x798d6e7a + (long)iVar19 * 0x281cc09e) >>
                              0x1f);
            iVar19 = piVar21[-4];
            piVar21[-4] = (int)((ulong)((long)piVar21[3] * -0x1748ee85 + (long)iVar19 * 0x7ddd40a7)
                               >> 0x1f);
            piVar21[3] = (int)((ulong)((long)piVar21[3] * 0x7ddd40a7 + (long)iVar19 * 0x1748ee85) >>
                              0x1f);
            iVar19 = piVar21[-5];
            piVar21[-5] = (int)((ulong)((long)piVar21[4] * -0xc1b01d3 + (long)iVar19 * 0x7f6d20b6)
                               >> 0x1f);
            piVar21[4] = (int)((ulong)((long)piVar21[4] * 0x7f6d20b6 + (long)iVar19 * 0xc1b01d3) >>
                              0x1f);
            iVar19 = piVar21[-6];
            piVar21[-6] = (int)((ulong)((long)piVar21[5] * -0x53e5c37 + (long)iVar19 * 0x7fe47e3f)
                               >> 0x1f);
            piVar21[5] = (int)((ulong)((long)piVar21[5] * 0x7fe47e3f + (long)iVar19 * 0x53e5c37) >>
                              0x1f);
            iVar19 = piVar21[-7];
            piVar21[-7] = (int)((ulong)((long)piVar21[6] * -0x1d14239 + (long)iVar19 * 0x7ffcb262)
                               >> 0x1f);
            piVar21[6] = (int)((ulong)((long)piVar21[6] * 0x7ffcb262 + (long)iVar19 * 0x1d14239) >>
                              0x1f);
            iVar19 = piVar21[-8];
            piVar21[-8] = (int)((ulong)((long)piVar21[7] * -0x793da3 + (long)iVar19 * 0x7fffc693) >>
                               0x1f);
            piVar21[7] = (int)((ulong)((long)piVar21[7] * 0x7fffc693 + (long)iVar19 * 0x793da3) >>
                              0x1f);
            lVar23 = lVar20 + 1;
          } while (lVar20 + 1 != 0x20);
          iVar19 = param_1[4];
          piVar21 = local_120 + 0x240;
          local_100 = local_100 + 0x240;
          lVar22 = lStack_118;
        } while (lStack_118 < iVar19);
      }
      uVar18 = local_128;
      _memcpy(param_1 + local_128 * 0x6c0 + 0xb2e,
              param_1 + local_128 * 0x6c0 + 0xb2e + (long)iVar19 * 0x240,0x900);
      local_140 = local_140 + -0x6c0;
      local_148 = local_148 + -0x6c0;
    } while ((int)uVar18 != 0);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


