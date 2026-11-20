/* Decompiled from supplied 5.2.2 arm package. VA 0x241d98. _shine_format_bitstream */

void _shine_format_bitstream(uint *param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  byte bVar12;
  ushort uVar13;
  int iVar14;
  uint uVar15;
  char cVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  undefined8 uVar21;
  long lVar22;
  uint *puVar23;
  uint *puVar24;
  ulong uVar25;
  uint *puVar26;
  uint *puVar27;
  long lVar28;
  uint *puVar29;
  uint *puVar30;
  long lVar31;
  long lVar32;
  uint uVar33;
  int *piVar34;
  uint uVar35;
  uint *local_238;
  uint *local_230;
  undefined4 local_1f8 [2];
  int local_1f0 [8];
  uint local_1d0 [12];
  uint local_1a0 [80];
  
  if (0 < (int)*param_1) {
    lVar22 = 0;
    uVar25 = (ulong)param_1[4];
    puVar23 = param_1 + 0x22e;
    puVar24 = param_1 + 0x18ae;
    do {
      if (0 < (int)uVar25) {
        lVar28 = 0;
        puVar29 = puVar24;
        puVar27 = puVar23;
        do {
          lVar31 = 0x240;
          puVar26 = puVar29;
          puVar30 = puVar27;
          do {
            if (((int)*puVar26 < 0) && (0 < (int)*puVar30)) {
              *puVar30 = -*puVar30;
            }
            lVar31 = lVar31 + -1;
            puVar30 = puVar30 + 1;
            puVar26 = puVar26 + 1;
          } while (lVar31 != 0);
          uVar25 = (ulong)(int)param_1[4];
          lVar28 = lVar28 + 1;
          puVar27 = puVar27 + 0x240;
          puVar29 = puVar29 + 0x240;
        } while (lVar28 < (long)uVar25);
      }
      lVar22 = lVar22 + 1;
      puVar23 = puVar23 + 0x480;
      puVar24 = puVar24 + 0x480;
    } while (lVar22 < (int)*param_1);
  }
  _memcpy(local_1f8,param_1 + 0x1e,0x198);
  puVar23 = param_1 + 0x18;
  _shine_putbits(puVar23,0x7ff,0xb);
  _shine_putbits(puVar23,param_1[2],2);
  _shine_putbits(puVar23,param_1[3],2);
  _shine_putbits(puVar23,param_1[0x13] == 0,1);
  _shine_putbits(puVar23,param_1[0x11],4);
  _shine_putbits(puVar23,(int)param_1[0x12] % 3,2);
  _shine_putbits(puVar23,param_1[8],1);
  _shine_putbits(puVar23,param_1[0x14],1);
  _shine_putbits(puVar23,param_1[5],2);
  _shine_putbits(puVar23,param_1[0x15],2);
  _shine_putbits(puVar23,param_1[0x16],1);
  _shine_putbits(puVar23,param_1[0x17],1);
  _shine_putbits(puVar23,param_1[7],2);
  if (param_1[2] == 3) {
    _shine_putbits(puVar23,0,9);
    if (*param_1 == 2) {
      uVar21 = 3;
    }
    else {
      uVar21 = 5;
    }
  }
  else {
    _shine_putbits(puVar23,0,8);
    if (*param_1 == 2) {
      uVar21 = 2;
    }
    else {
      uVar21 = 1;
    }
  }
  _shine_putbits(puVar23,local_1f8[0],uVar21);
  if ((param_1[2] == 3) && (0 < (int)*param_1)) {
    lVar22 = 0;
    piVar34 = local_1f0 + 3;
    do {
      _shine_putbits(puVar23,piVar34[-3],1);
      _shine_putbits(puVar23,piVar34[-2],1);
      _shine_putbits(puVar23,piVar34[-1],1);
      _shine_putbits(puVar23,*piVar34,1);
      lVar22 = lVar22 + 1;
      piVar34 = piVar34 + 4;
    } while (lVar22 < (int)*param_1);
  }
  uVar20 = param_1[4];
  if (0 < (int)uVar20) {
    uVar25 = (ulong)*param_1;
    lVar22 = 0;
    puVar24 = local_1d0 + 0xc;
    do {
      if (0 < (int)uVar25) {
        lVar28 = 0;
        puVar27 = puVar24;
        do {
          _shine_putbits(puVar23,puVar27[-0xc],0xc);
          _shine_putbits(puVar23,puVar27[-0xb],9);
          _shine_putbits(puVar23,puVar27[-9],8);
          if (param_1[2] == 3) {
            uVar21 = 4;
          }
          else {
            uVar21 = 9;
          }
          _shine_putbits(puVar23,puVar27[-8],uVar21);
          _shine_putbits(puVar23,0,1);
          _shine_putbits(puVar23,puVar27[-7],5);
          _shine_putbits(puVar23,puVar27[-6],5);
          _shine_putbits(puVar23,puVar27[-5],5);
          _shine_putbits(puVar23,puVar27[-4],4);
          _shine_putbits(puVar23,puVar27[-3],3);
          if (param_1[2] == 3) {
            _shine_putbits(puVar23,puVar27[-2],1);
          }
          _shine_putbits(puVar23,puVar27[-1],1);
          _shine_putbits(puVar23,*puVar27,1);
          uVar25 = (ulong)(int)*param_1;
          lVar28 = lVar28 + 1;
          puVar27 = puVar27 + 0x17;
        } while (lVar28 < (long)uVar25);
        uVar20 = param_1[4];
      }
      lVar22 = lVar22 + 1;
      puVar24 = puVar24 + 0x2e;
    } while (lVar22 < (int)uVar20);
  }
  _memcpy(local_1f8,param_1 + 0x1e,0x198);
  if (0 < (int)uVar20) {
    lVar22 = 0;
    uVar25 = (ulong)*param_1;
    puVar24 = param_1 + 0x22f;
    puVar27 = param_1 + 0x22e;
    do {
      if (0 < (int)uVar25) {
        lVar28 = 0;
        local_238 = puVar27;
        local_230 = puVar24;
        do {
          uVar10 = *(undefined4 *)
                    (&_shine_slen1_tab + (ulong)local_1d0[lVar22 * 0x2e + lVar28 * 0x17 + 4] * 4);
          uVar11 = *(undefined4 *)
                    (&_shine_slen2_tab + (ulong)local_1d0[lVar22 * 0x2e + lVar28 * 0x17 + 4] * 4);
          if ((lVar22 == 0) || (local_1f0[lVar28 * 4] == 0)) {
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x12e],uVar10);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x12f],uVar10);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x130],uVar10);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x131],uVar10);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x132],uVar10);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x133],uVar10);
            if (lVar22 != 0) goto LAB_002422a8;
LAB_002422bc:
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x134],uVar10);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x135],uVar10);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x136],uVar10);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x137],uVar10);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x138],uVar10);
            if (lVar22 != 0) goto LAB_00242328;
LAB_00242338:
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x139],uVar11);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x13a],uVar11);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x13b],uVar11);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x13c],uVar11);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x13d],uVar11);
            if (lVar22 != 0) goto LAB_002423a4;
LAB_002423b4:
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x13e],uVar11);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x13f],uVar11);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x140],uVar11);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x141],uVar11);
            _shine_putbits(puVar23,param_1[lVar22 * 0x2c + lVar28 * 0x16 + 0x142],uVar11);
          }
          else {
LAB_002422a8:
            if (local_1f0[lVar28 * 4 + 1] == 0) goto LAB_002422bc;
LAB_00242328:
            if (local_1f0[lVar28 * 4 + 2] == 0) goto LAB_00242338;
LAB_002423a4:
            if (local_1f0[lVar28 * 4 + 3] == 0) goto LAB_002423b4;
          }
          uVar20 = param_1[0x12];
          iVar17 = _shine_get_bits_count(puVar23);
          iVar18 = local_1d0[lVar22 * 0x2e + lVar28 * 0x17 + 1] * 2;
          if (0 < iVar18) {
            lVar32 = (long)*(int *)(&_shine_scale_fact_band_index +
                                   (ulong)(local_1d0[lVar22 * 0x2e + lVar28 * 0x17 + 8] +
                                           local_1d0[lVar22 * 0x2e + lVar28 * 0x17 + 9] + 2) * 4 +
                                   (long)(int)uVar20 * 0x5c);
            iVar14 = *(int *)(&_shine_scale_fact_band_index +
                             (ulong)(local_1d0[lVar22 * 0x2e + lVar28 * 0x17 + 8] + 1) * 4 +
                             (long)(int)uVar20 * 0x5c);
            lVar31 = 0;
            puVar29 = local_230;
            do {
              uVar25 = 1;
              if (lVar32 <= lVar31) {
                uVar25 = 2;
              }
              uVar5 = (ulong)(lVar32 <= lVar31);
              if (iVar14 <= lVar31) {
                uVar5 = uVar25;
              }
              uVar20 = local_1d0[lVar22 * 0x2e + lVar28 * 0x17 + uVar5 + 5];
              if (uVar20 != 0) {
                uVar9 = puVar29[-1];
                uVar7 = *puVar29;
                lVar1 = (long)(int)uVar20 * 0x20;
                uVar6 = -uVar9;
                if (-1 < (int)uVar9) {
                  uVar6 = uVar9;
                }
                uVar8 = -uVar7;
                if (-1 < (int)uVar7) {
                  uVar8 = uVar7;
                }
                if ((int)uVar20 < 0x10) {
                  uVar20 = uVar8 + *(int *)(&DAT_01063304 + lVar1) * uVar6;
                  uVar13 = *(ushort *)(*(long *)(&DAT_01063310 + lVar1) + (ulong)uVar20 * 2);
                  uVar19 = (uint)uVar13;
                  bVar12 = *(byte *)(*(long *)(&DAT_01063318 + lVar1) + (ulong)uVar20);
                  uVar20 = (uint)bVar12;
                  if (uVar6 != 0) {
                    uVar19 = (uint)((int)uVar9 < 1) | (uint)uVar13 << 1;
                    uVar20 = bVar12 + 1;
                  }
                  if (uVar8 != 0) {
                    uVar19 = (uint)((int)uVar7 < 1) | uVar19 << 1;
                    uVar20 = uVar20 + 1;
                  }
                  _shine_putbits(puVar23,uVar19,uVar20);
                }
                else {
                  uVar19 = *(uint *)(&DAT_01063308 + lVar1);
                  uVar20 = uVar8 - 0xf;
                  uVar3 = 0xf;
                  if ((int)uVar8 < 0xf) {
                    uVar20 = 0;
                    uVar3 = uVar8;
                  }
                  uVar4 = 0xf;
                  if ((int)uVar6 < 0xf) {
                    uVar4 = uVar6;
                  }
                  uVar15 = uVar3 + uVar4 * *(int *)(&DAT_01063304 + lVar1);
                  uVar35 = uVar6 - 0xf;
                  uVar33 = uVar19;
                  if ((int)uVar6 < 0xf) {
                    uVar35 = 0;
                    uVar33 = 0;
                  }
                  if (uVar4 != 0) {
                    uVar35 = (uint)((int)uVar9 < 1) | uVar35 << 1;
                    uVar33 = uVar33 + 1;
                  }
                  if ((int)uVar8 < 0xf) {
                    if (uVar3 != 0) goto LAB_002425b0;
                  }
                  else {
                    uVar35 = uVar35 << (ulong)(uVar19 & 0x1f) | uVar20;
                    uVar33 = uVar33 + uVar19;
LAB_002425b0:
                    uVar35 = (uint)((int)uVar7 < 1) | uVar35 << 1;
                    uVar33 = uVar33 + 1;
                  }
                  _shine_putbits(puVar23,*(undefined2 *)
                                          (*(long *)(&DAT_01063310 + lVar1) + (ulong)uVar15 * 2),
                                 *(undefined1 *)(*(long *)(&DAT_01063318 + lVar1) + (ulong)uVar15));
                  _shine_putbits(puVar23,uVar35,uVar33);
                }
              }
              lVar31 = lVar31 + 2;
              puVar29 = puVar29 + 2;
            } while (lVar31 < iVar18);
          }
          iVar14 = iVar18 + local_1d0[lVar22 * 0x2e + lVar28 * 0x17 + 2] * 4;
          if (iVar18 < iVar14) {
            lVar31 = (ulong)(local_1d0[lVar22 * 0x2e + lVar28 * 0x17 + 0xc] + 0x20) * 0x20;
            puVar29 = local_238 + iVar18;
            lVar32 = *(long *)(&DAT_01063310 + lVar31);
            lVar31 = *(long *)(&DAT_01063318 + lVar31);
            puVar30 = local_238 + (iVar18 + 3);
            puVar26 = local_238 + (iVar18 + 2);
            do {
              uVar6 = *puVar29;
              uVar7 = puVar29[1];
              uVar9 = *puVar26;
              uVar8 = *puVar30;
              uVar20 = -uVar6;
              if (-1 < (int)uVar6) {
                uVar20 = uVar6;
              }
              uVar19 = -uVar7;
              if (-1 < (int)uVar7) {
                uVar19 = uVar7;
              }
              uVar3 = -uVar9;
              if (-1 < (int)uVar9) {
                uVar3 = uVar9;
              }
              uVar4 = -uVar8;
              if (-1 < (int)uVar8) {
                uVar4 = uVar8;
              }
              iVar2 = uVar20 + uVar19 * 2 + uVar3 * 4 + uVar4 * 8;
              _shine_putbits(puVar23,*(undefined2 *)(lVar32 + (long)iVar2 * 2),
                             *(undefined1 *)(lVar31 + iVar2));
              cVar16 = uVar20 != 0;
              bVar12 = (bool)cVar16 && (int)uVar6 < 1;
              if (uVar19 != 0) {
                bVar12 = (0 < (int)uVar7 | bVar12 << 1) ^ 1;
                cVar16 = cVar16 + '\x01';
              }
              if (uVar3 != 0) {
                bVar12 = (0 < (int)uVar9 | bVar12 << 1) ^ 1;
                cVar16 = cVar16 + '\x01';
              }
              if (uVar4 != 0) {
                bVar12 = (0 < (int)uVar8 | bVar12 << 1) ^ 1;
                cVar16 = cVar16 + '\x01';
              }
              _shine_putbits(puVar23,bVar12,cVar16);
              iVar18 = iVar18 + 4;
              puVar29 = puVar29 + 4;
              puVar30 = puVar30 + 4;
              puVar26 = puVar26 + 4;
            } while (iVar18 < iVar14);
          }
          iVar18 = _shine_get_bits_count(puVar23);
          uVar20 = (local_1d0[lVar22 * 0x2e + lVar28 * 0x17] -
                   local_1d0[lVar22 * 0x2e + lVar28 * 0x17 + 0xd]) + (iVar17 - iVar18);
          if (uVar20 != 0) {
            uVar6 = (int)uVar20 % 0x20;
            if (0x3e < uVar20 + 0x1f) {
              uVar7 = uVar20 + 0x1f;
              if (-1 < (int)uVar20) {
                uVar7 = uVar20;
              }
              iVar18 = (int)uVar7 >> 5;
              do {
                iVar18 = iVar18 + -1;
                _shine_putbits(puVar23,0xffffffff,0x20);
              } while (iVar18 != 0);
            }
            if (uVar6 != 0) {
              _shine_putbits(puVar23,(int)(1L << ((ulong)uVar6 & 0x3f)) + -1,uVar6);
            }
          }
          uVar25 = (ulong)(int)*param_1;
          lVar28 = lVar28 + 1;
          local_230 = local_230 + 0x480;
          local_238 = local_238 + 0x480;
        } while (lVar28 < (long)uVar25);
        uVar20 = param_1[4];
      }
      lVar22 = lVar22 + 1;
      puVar24 = puVar24 + 0x240;
      puVar27 = puVar27 + 0x240;
    } while (lVar22 < (int)uVar20);
  }
  return;
}


