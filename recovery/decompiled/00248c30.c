/* Decompiled from supplied 5.2.2 arm package. VA 0x248c30. FUN_00248c30 */

ulong FUN_00248c30(long param_1,void *param_2,short *param_3)

{
  undefined8 *puVar1;
  short *psVar2;
  short *psVar3;
  undefined1 *puVar4;
  short *psVar5;
  short *psVar6;
  short sVar7;
  long lVar8;
  int iVar9;
  uint uVar10;
  short sVar11;
  bool bVar12;
  short sVar13;
  ushort uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  short *psVar20;
  ulong uVar21;
  uint uVar22;
  short sVar23;
  short sVar24;
  long lVar25;
  int iVar26;
  ulong uVar27;
  long lVar28;
  ulong uVar29;
  undefined8 uVar30;
  ushort local_2bc [6];
  ushort local_2b0 [3];
  ushort local_2aa [3];
  int local_2a4 [52];
  short sStack_1d2;
  undefined8 local_1d0 [2];
  undefined4 local_1c0;
  undefined8 auStack_1bc [2];
  undefined4 auStack_1ac [16];
  undefined1 auStack_16c [20];
  undefined1 auStack_158 [240];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar14 = param_3[1];
  psVar2 = param_3 + 0x16c;
  psVar3 = param_3 + 0x3ef;
  _memmove(psVar2,psVar2 + (short)uVar14,(0x280 - (long)(short)uVar14) * 2);
  _memcpy(psVar2 + (0x280 - (long)param_3[1]),param_2,(long)param_3[1] << 1);
  sVar7 = *param_3;
  uVar22 = 2;
  if (sVar7 == 0x1e) {
    uVar22 = 3;
  }
  uVar27 = (ulong)uVar22;
  sVar23 = 0x140;
  if (sVar7 != 0x1e) {
    sVar23 = 0x1b8;
  }
  _memmove(psVar3,psVar3 + uVar27,(ulong)(8 - uVar22) << 1);
  iVar15 = (int)((long)(short)uVar14 + 0x78);
  if (iVar15 < 0) {
    iVar15 = iVar15 + 1;
  }
  (*DAT_0191b808)(psVar2 + (0x280 - ((long)(short)uVar14 + 0x78)),
                  (int)((uint)uVar14 * 0x10000 + 0x7b0000) >> 0x10,local_1d0,iVar15 >> 1,
                  &DAT_00c4e42e,7,2,3);
  uVar29 = 0x14;
  uVar19 = 0x14;
  for (lVar25 = 0; lVar25 < (long)uVar27; lVar25 = lVar25 + 1) {
    lVar8 = (lVar25 << 0x10) >> 0x10;
    lVar28 = lVar8 * 0x50;
    puVar4 = auStack_16c + lVar28;
    iVar15 = (*DAT_0191b7d0)(local_1d0 + lVar8 * 10,0x59);
    iVar16 = FUN_0024958c(iVar15 * iVar15);
    iVar15 = 0;
    if (-1 < iVar16 + -0x19) {
      iVar15 = iVar16 + -0x19;
    }
    (*DAT_0191b800)(local_2a4 + 3,auStack_158 + lVar28,puVar4,0x28,0x32,(int)(short)iVar15,
                    0xffffffff);
    lVar28 = 0;
    while( true ) {
      iVar16 = FUN_0024eacc(local_2a4 + 3,0x32);
      uVar14 = (ushort)iVar16;
      if (lVar28 == 2) break;
      local_2bc[lVar28] = uVar14;
      uVar17 = iVar16 * 0x10000 + -0x20000 >> 0x10;
      iVar16 = iVar16 * 0x10000 + 0x20000 >> 0x10;
      iVar26 = 0x31;
      if (iVar16 < 0x32) {
        iVar26 = iVar16;
      }
      local_2a4[lVar28] = local_2a4[(long)(short)uVar14 + 3];
      if ((int)uVar17 < 1) {
        uVar17 = 0;
      }
      for (uVar29 = (ulong)uVar17; (long)uVar29 <= (long)iVar26; uVar29 = uVar29 + 1) {
        local_2a4[uVar29 + 3] = 0;
      }
      lVar28 = lVar28 + 1;
    }
    local_2bc[2] = uVar14;
    local_2a4[2] = local_2a4[(long)(short)uVar14 + 3];
    for (lVar28 = 0; lVar28 != 3; lVar28 = lVar28 + 1) {
      iVar16 = local_2a4[lVar28];
      uVar17 = FUN_0024958c(iVar16);
      iVar26 = 0xf - (uVar17 & 0xffff);
      iVar18 = FUN_0024e098(puVar4 + (long)(short)local_2bc[lVar28] * -2,
                            puVar4 + (long)(short)local_2bc[lVar28] * -2,0x28,iVar15);
      uVar17 = FUN_0024958c();
      iVar9 = 0xf - (uVar17 & 0xffff);
      sVar24 = (short)iVar26;
      sVar11 = (short)iVar9;
      sVar13 = (short)(iVar16 << (ulong)((int)sVar24 & 0x1f));
      if (iVar26 * 0x10000 < -0xffff) {
        sVar13 = (short)(iVar16 >> (-(int)sVar24 & 0x1fU));
      }
      uVar14 = (ushort)(iVar18 << (ulong)((int)sVar11 & 0x1f));
      if (iVar9 * 0x10000 < -0xffff) {
        uVar14 = (ushort)(iVar18 >> (-(int)sVar11 & 0x1fU));
      }
      local_2bc[lVar28 + 9] = sVar11 + sVar24 * -2;
      local_2bc[lVar28 + 3] = uVar14;
      local_2bc[lVar28 + 6] = (ushort)((uint)((int)sVar13 * (int)sVar13) >> 0x10);
    }
    iVar15 = 0;
    lVar28 = 1;
    while( true ) {
      sVar13 = (short)iVar15;
      if (lVar28 == 3) break;
      uVar14 = local_2bc[(long)sVar13 + 9];
      iVar16 = (int)(short)local_2bc[lVar28 + 9];
      iVar15 = (short)uVar14 - iVar16;
      if (iVar15 == 0 || (short)uVar14 < iVar16) {
        iVar15 = 0x1f;
        if (iVar16 - (short)uVar14 < 0x20) {
          iVar15 = iVar16 - (short)uVar14;
        }
        iVar26 = (int)(short)local_2bc[lVar28 + 3] * (int)(short)local_2bc[(long)sVar13 + 6] >>
                 ((int)(short)iVar15 & 0x1fU);
        iVar16 = (int)(short)local_2bc[(long)sVar13 + 3] * (int)(short)local_2bc[lVar28 + 6];
      }
      else {
        iVar26 = (int)(short)local_2bc[lVar28 + 3] * (int)(short)local_2bc[(long)sVar13 + 6];
        iVar16 = 0x1f;
        if (iVar15 < 0x20) {
          iVar16 = iVar15;
        }
        iVar16 = (int)(short)local_2bc[(long)sVar13 + 3] * (int)(short)local_2bc[lVar28 + 6] >>
                 ((int)(short)iVar16 & 0x1fU);
      }
      iVar15 = (int)lVar28;
      if (iVar16 <= iVar26) {
        iVar15 = (int)sVar13;
      }
      lVar28 = lVar28 + 1;
    }
    uVar17 = (uint)local_2bc[sVar13] * 0x10000 + 0xa0000;
    param_3[lVar25 + (ulong)(8 - uVar22) + 0x3ef] = (short)(uVar17 >> 0xd);
    uVar17 = (int)uVar17 >> 0xf;
    uVar29 = (ulong)uVar17;
    if (*(int *)(param_3 + 0x20) == 1) {
      bVar12 = lVar25 == 0;
    }
    else {
      bVar12 = lVar25 == 1;
    }
    if (!bVar12) {
      uVar17 = uVar19;
    }
    uVar19 = uVar17;
  }
  uVar22 = 0x50;
  if (sVar7 != 0x1e) {
    uVar22 = 0x28;
  }
  if (*(int *)(param_3 + 0x20) - 1U < 2) {
    lVar25 = (long)param_2 + (long)(int)uVar19 * 2 + -2;
    iVar15 = (*DAT_0191b7d0)(lVar25,(uVar22 | 3) + 0x7f & 0x7a);
    (*DAT_0191b800)(local_2a4 + 3,param_2,lVar25,uVar22,3,(ulong)(5000 < iVar15) << 1,1);
    iVar15 = FUN_0024eacc(local_2a4 + 3,3);
    uVar17 = (uVar19 + iVar15) - 1;
    uVar29 = (ulong)uVar17;
    if (*(int *)(param_3 + 0x20) == 1) {
      if (uVar17 - uVar22 == 0 || (int)uVar17 < (int)uVar22) {
        uVar10 = uVar22 - uVar17;
        _memcpy((void *)((long)local_1d0 + (long)(int)uVar10 * 2),param_2,
                -(ulong)(uVar17 >> 0x1f) & 0xfffffffe00000000 | uVar29 << 1);
        psVar20 = param_3 + (long)(int)(((0x280 - uVar22) + uVar17) - (int)param_3[1]) + 0x16c;
        uVar21 = -(ulong)(uVar10 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar10 << 1;
      }
      else {
        psVar20 = (short *)((long)param_2 + (long)(int)(uVar17 - uVar22) * 2);
        uVar21 = (ulong)uVar22 << 1;
      }
      ___memcpy_chk(local_1d0,psVar20,uVar21,0x168);
    }
    else {
      iVar16 = ((iVar15 + -1) - uVar22) + uVar19;
      uVar10 = uVar22;
      while( true ) {
        if (uVar10 - uVar17 == 0 || (int)uVar10 < (int)uVar17) break;
        _memcpy((void *)((long)local_1d0 + (long)(int)((-uVar19 - iVar15) + uVar10 + 1) * 2),param_2
                ,-(ulong)(uVar17 >> 0x1f) & 0xfffffffe00000000 | uVar29 << 1);
        iVar16 = iVar16 + iVar15 + -1 + uVar19;
        uVar10 = uVar10 - uVar17;
      }
      ___memcpy_chk(local_1d0,(void *)((long)param_2 + (long)iVar16 * 2),
                    -(ulong)(uVar10 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar10 << 1,0x168);
    }
    if (*(int *)(param_3 + 0x20) == 1) {
      iVar15 = (*DAT_0191b7d0)(param_3 + (long)(int)((0x280 - uVar22) - (int)param_3[1]) + 0x16c,
                               uVar22);
      iVar16 = (*DAT_0191b7d0)(local_1d0,uVar22);
      if (iVar15 <= iVar16) {
        iVar15 = iVar16;
      }
      sVar13 = FUN_0024960c(iVar15);
      iVar15 = (int)(short)(0x16 - sVar13);
      if (iVar15 < 1) {
        iVar15 = 0;
      }
      iVar16 = FUN_0024e098(param_3 + (long)(int)((0x280 - uVar22) - (int)param_3[1]) + 0x16c,
                            param_3 + (long)(int)((0x280 - uVar22) - (int)param_3[1]) + 0x16c,uVar22
                            ,iVar15);
      iVar15 = FUN_0024e098(local_1d0,local_1d0,uVar22,iVar15);
      if (0 < iVar15 && iVar16 < iVar15 >> 2) {
        uVar19 = FUN_0024960c(iVar15);
        sVar13 = (short)(iVar15 << (ulong)(uVar19 - 0x10 & 0x1f));
        if ((int)(uVar19 - 0x10) < 0) {
          sVar13 = (short)(iVar15 >> (0x10 - uVar19 & 0x1f));
        }
        iVar15 = iVar16 << (ulong)(uVar19 & 0x1f);
        if ((int)uVar19 < 0) {
          iVar15 = iVar16 >> (-uVar19 & 0x1f);
        }
        uVar19 = FUN_0024df78(iVar15,(int)sVar13);
        uVar14 = FUN_0024eebc(-(uVar19 >> 0xf & 1) & 0xc0000000 | (uVar19 & 0xffff) << 0xe);
        FUN_0024f170(local_1d0,local_1d0,(int)(short)uVar14,(int)(short)(uVar22 - 0x10),0xe);
        iVar15 = 0;
        psVar20 = (short *)((long)local_1d0 + (long)(int)(uVar22 - 0x10) * 2);
        iVar16 = 0x10;
        while (0 < iVar16) {
          *psVar20 = (short)((uint)((int)*psVar20 * (int)(short)(uVar14 + ((short)iVar15 >> 1))) >>
                            0xe);
          iVar15 = (0x800 - ((int)((uint)uVar14 << 0x10) >> 0x13)) + (int)(short)iVar15;
          psVar20 = psVar20 + 1;
          iVar16 = iVar16 + -1;
        }
      }
      sVar13 = 0;
      uVar21 = (ulong)uVar22;
      sVar24 = 0xca;
      if (sVar7 != 0x1e) {
        sVar24 = 400;
      }
      psVar20 = param_3 + (0x3eb - (long)param_3[1]);
      for (; (int)uVar21 != 0; uVar21 = uVar21 - 1) {
        sVar7 = *psVar20;
        sVar13 = sVar24 + sVar13;
        *psVar20 = (short)((uint)((int)sVar7 * (int)sVar13) >> 0xe);
        *psVar20 = (short)((uint)((int)(&sStack_1d2)[uVar21] * (int)(short)(0x4000 - sVar13)) >> 0xe
                          ) + (short)((uint)((int)sVar7 * (int)sVar13) >> 0xe);
        psVar20 = psVar20 + -1;
      }
    }
    else {
      psVar20 = param_3 + (long)(int)((0x280 - uVar22) - (int)param_3[1]) + 0x16c;
      _memcpy(psVar20,local_1d0,(ulong)uVar22 << 1);
      thunk_FUN_0024de70(param_3 + 8,0,10);
      psVar5 = param_3 + 0x166;
      thunk_FUN_0024de70(psVar5,0,4);
      psVar6 = param_3 + 0x164;
      thunk_FUN_0024de70(psVar6,0,2);
      local_1c0 = *(undefined4 *)(param_3 + 0x10);
      local_1d0[1] = *(undefined8 *)(param_3 + 0xc);
      local_1d0[0] = *(undefined8 *)(param_3 + 8);
      iVar16 = (int)(short)uVar17;
      FUN_0024e20c(psVar20,auStack_1bc,
                   (long)param_3 + ((long)param_3[2] * 0xb00000000 + -0xb00000000 >> 0x1f) + 0x244,
                   0xb,iVar16);
      lVar25 = (long)(int)(uVar19 + iVar15 + -0xb) * 2;
      puVar1 = (undefined8 *)((long)auStack_1bc + lVar25);
      local_1c0 = *(undefined4 *)((long)auStack_1ac + lVar25);
      local_1d0[1] = *(undefined8 *)((long)auStack_1bc + lVar25 + 8);
      local_1d0[0] = *puVar1;
      FUN_00249f8c(auStack_1bc,&DAT_00c4e41a,psVar5,psVar6,iVar16);
      FUN_0024e20c(psVar20,auStack_1bc,
                   (long)param_3 + ((long)param_3[2] * 0xb00000000 + -0xb00000000 >> 0x1f) + 0x244,
                   0xb,iVar16);
      *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)((long)auStack_1ac + lVar25);
      uVar30 = *puVar1;
      *(undefined8 *)(param_3 + 0xc) = *(undefined8 *)((long)auStack_1bc + lVar25 + 8);
      *(undefined8 *)(param_3 + 8) = uVar30;
      FUN_00249f8c(auStack_1bc,&DAT_00c4e41a,psVar5,psVar6,iVar16);
    }
  }
  lVar25 = -1;
  iVar15 = 0;
  while (lVar25 = lVar25 + 1, lVar25 < (long)uVar27) {
    FUN_00248b70(param_1,psVar2,0x280,(int)(short)(sVar23 + (short)((uint)iVar15 >> 0x10) * 0x50),
                 psVar3,&DAT_00c4f65c,8);
    param_1 = param_1 + 0xa0;
    iVar15 = iVar15 + 0x10000;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return uVar29;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


