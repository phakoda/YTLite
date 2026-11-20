/* Decompiled from supplied 5.2.2 arm package. VA 0x246050. FUN_00246050 */

/* WARNING: Type propagation algorithm not settling */

void FUN_00246050(long param_1,long param_2,ushort *param_3,undefined8 param_4,long param_5,
                 int param_6,uint param_7,undefined8 param_8,short param_9)

{
  int iVar1;
  long lVar2;
  ushort uVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  long lVar16;
  short *psVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  short *psVar21;
  short sVar22;
  ushort *puVar23;
  int iVar24;
  ulong uVar25;
  uint uVar26;
  long lVar27;
  short sVar28;
  undefined4 *puVar29;
  ushort uVar30;
  ulong uVar31;
  short asStackY_20cd8 [256];
  short asStackY_20ad8 [65164];
  undefined1 *local_d80;
  long local_d70;
  undefined1 *local_d58;
  uint local_d10;
  undefined4 local_cec;
  short local_ce6;
  short local_ce4;
  short local_ce2;
  short local_ce0 [2];
  undefined4 local_cdc;
  short asStack_cd8 [20];
  undefined1 auStack_cb0 [472];
  short asStack_ad8 [20];
  undefined1 auStack_ab0 [472];
  undefined1 auStack_8d8 [160];
  undefined1 auStack_838 [160];
  short local_798 [20];
  undefined1 auStack_770 [40];
  undefined4 auStack_748 [74];
  undefined8 local_620;
  undefined8 uStack_618;
  undefined4 local_610;
  short local_60c [44];
  undefined1 auStack_5b4 [512];
  undefined4 auStack_3b4 [20];
  undefined4 auStack_364 [108];
  undefined8 auStack_1b2 [2];
  undefined4 uStack_1a2;
  undefined4 auStack_19e [75];
  undefined2 local_70;
  short local_6e [3];
  long local_68;
  
  uVar25 = (ulong)param_7;
  local_d10 = param_7 & 0xffff;
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  iVar11 = param_6 + -0x13;
  if ((param_7 & 0xffff) != 0x28) {
    iVar11 = (param_6 + 1) - param_7;
  }
  local_cdc = 0;
  local_ce0[1] = 0x8000;
  iVar14 = (int)param_9;
  sVar22 = *(short *)(&DAT_00c4f55e + (long)iVar14 * 2);
  uVar31 = (ulong)sVar22;
  local_ce0[0] = 0;
  local_ce2 = 0;
  iVar9 = (int)(short)((short)param_6 - sVar22);
  thunk_FUN_0024de70(auStack_1b2,0,iVar9 + 10);
  lVar19 = (long)auStack_19e + (long)iVar9 * 2;
  FUN_0024e20c(param_5 + (long)iVar9 * 2,lVar19,param_8,0xb,uVar31 & 0xffffffff);
  local_610 = *(undefined4 *)(lVar19 + uVar31 * 2 + -4);
  uStack_618 = *(undefined8 *)(lVar19 + uVar31 * 2 + -0xc);
  local_620 = *(undefined8 *)(lVar19 + uVar31 * 2 + -0x14);
  FUN_0024e20c(param_4,local_60c,param_8,0xb,uVar25);
  ___memcpy_chk(local_798,local_60c,-(ulong)(param_7 >> 0x1f) & 0xfffffffe00000000 | uVar25 << 1,
                0x50);
  iVar9 = (*DAT_0191b7d0)(auStack_19e,param_6);
  iVar10 = (*DAT_0191b7d0)(local_60c,param_7);
  if (iVar9 < 1 || iVar10 < 1) {
    uVar26 = 0x1e;
  }
  else {
    if (iVar9 <= iVar10) {
      iVar9 = iVar10;
    }
    uVar12 = iVar9 * iVar9;
    bVar8 = uVar12 >> 0x10 != 0;
    lVar19 = (ulong)bVar8 << 4;
    uVar26 = (uint)lVar19;
    if ((0xff00 << lVar19 & uVar12) != 0) {
      uVar26 = (uint)bVar8 << 4 | 8;
    }
    if ((0xf0 << (ulong)uVar26 & uVar12) != 0) {
      uVar26 = uVar26 | 4;
    }
    if ((0xc << (ulong)uVar26 & uVar12) != 0) {
      uVar26 = uVar26 | 2;
    }
    if ((2 << (ulong)(uint)(int)(short)uVar26 & uVar12) != 0) {
      uVar26 = (int)(short)uVar26 + 1;
    }
    if ((1 << (ulong)((int)(short)uVar26 & 0x1f) & uVar12) != 0) {
      uVar26 = (int)(short)uVar26 + 1;
    }
  }
  lVar19 = (long)(int)param_7;
  iVar9 = (int)(uVar26 * 0x10000 + -0x190000) >> 0x10;
  iVar10 = 0;
  if (-1 < iVar9) {
    iVar10 = iVar9;
  }
  iVar9 = FUN_0024e098(local_60c,local_60c,param_7,iVar10);
  FUN_00249684(auStack_748,auStack_19e,param_6,(int)sVar22);
  sVar22 = *(short *)(&DAT_00c4f540 + (long)iVar14 * 6);
  sVar28 = (short)iVar10;
  sVar6 = (short)iVar11;
  if (local_d10 == 0x28) {
    FUN_0024a3f8(auStack_838,auStack_19e,param_6);
    FUN_0024a3f8(auStack_8d8,auStack_748,param_6);
    iVar7 = (int)sVar28;
    FUN_00245e18(auStack_838,auStack_19e,iVar7,0x14,asStack_ad8,asStack_cd8);
    FUN_00245e18(auStack_8d8,auStack_748,iVar7,(int)(short)(sVar6 + 0x14),asStack_ad8,asStack_cd8);
    FUN_00245c90((int)sVar22,auStack_19e,auStack_748,param_6,0x28,auStack_ab0,auStack_cb0,iVar7,
                 sVar6);
  }
  else {
    FUN_00245c90((int)sVar22,auStack_19e,auStack_748,param_6,uVar25,asStack_ad8,asStack_cd8,
                 (int)sVar28,sVar6);
    iVar7 = (int)sVar6 - (int)sVar22;
    thunk_FUN_0024de70(asStack_ad8 + (int)sVar22,0,iVar7);
    thunk_FUN_0024de70(asStack_ad8 + (int)sVar22 + (int)sVar6,0,iVar7);
  }
  local_d58 = auStack_838;
  local_d80 = auStack_8d8;
  iVar24 = (int)sVar6;
  local_d70 = (long)iVar24;
  iVar11 = (iVar11 << 0x10) >> 0xf;
  FUN_00248a04(asStack_ad8,iVar11);
  lVar16 = (long)auStack_19e + (long)param_6 * 2;
  iVar7 = (int)sVar28;
  local_70 = 0x4000;
  lVar20 = lVar16 + lVar19 * -2;
  lVar2 = (long)auStack_748 + (long)param_6 * 2;
  puVar23 = param_3;
  lVar27 = 0;
  sVar22 = 0x4000;
  do {
    if (lVar27 == 3) {
      for (lVar16 = 0; lVar16 < lVar19; lVar16 = lVar16 + 1) {
        local_798[lVar16] = local_798[lVar16] - local_60c[lVar16];
      }
      iVar11 = FUN_0024e098(local_798,local_798,uVar25,iVar10);
      lVar19 = (long)(short)*param_3;
      uVar26 = (uint)*param_3;
      uVar12 = FUN_00246a40();
      uVar13 = FUN_00246a40(iVar9);
      if ((int)uVar13 <= (int)uVar12) {
        uVar12 = uVar13;
      }
      psVar17 = (short *)(&DAT_00c4f59c + lVar19 * 2);
      iVar14 = 0x10 - (uVar12 & 0xffff);
      iVar10 = iVar14 * 0x10000;
      sVar6 = (short)iVar14;
      sVar22 = (short)(iVar9 << (ulong)(-(int)sVar6 & 0x1f));
      if (0xffff < iVar10) {
        sVar22 = (short)(iVar9 >> ((int)sVar6 & 0x1fU));
      }
      sVar28 = (short)(iVar11 << (ulong)(-(int)sVar6 & 0x1f));
      if (0xffff < iVar10) {
        sVar28 = (short)(iVar11 >> ((int)sVar6 & 0x1fU));
      }
      psVar21 = psVar17;
      for (; lVar19 < 0x20; lVar19 = lVar19 + 1) {
        if (((int)*(short *)(&DAT_00c4f5de + lVar19 * 2) * (int)sVar28 <
             (int)sVar22 * ((int)local_6e[0] * (int)local_6e[0] * 4 >> 0x10)) &&
           ((int)*psVar21 < local_6e[0] * 2 + -2)) {
          uVar26 = (uint)lVar19;
          psVar21 = psVar17;
        }
        psVar17 = psVar17 + 1;
      }
      *param_3 = (ushort)uVar26;
      if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    sVar28 = *(short *)(&DAT_00c4f540 + lVar27 * 2 + (long)iVar14 * 6);
    local_cdc = 0;
    local_ce0[1] = 0xff9c;
    local_ce0[0] = 0;
    local_ce2 = 0;
    if ((param_7 & 0xffff) == 0x28) {
      FUN_002459fc(local_60c,lVar16,local_d58,auStack_3b4,0x14,0x27,iVar7);
      puVar29 = auStack_364;
    }
    else {
      puVar29 = auStack_3b4;
    }
    (*DAT_0191b800)(puVar29,local_60c,lVar20,uVar25,(int)sVar28,iVar7,0xffffffff);
    sVar5 = sVar28 + 0x14;
    if ((param_7 & 0xffff) != 0x28) {
      sVar5 = sVar28;
    }
    iVar15 = (int)(short)lVar27;
    FUN_00246ab8(auStack_3b4,(int)sVar5,iVar15,asStack_ad8,asStack_cd8,auStack_5b4,&local_ce4,
                 &local_cec,&local_ce6);
    FUN_00246ca0(local_cec,(long)local_ce6,(long)local_ce4,auStack_3b4[(int)local_ce4],
                 (long)asStack_ad8[(int)local_ce4],(long)asStack_cd8[(int)local_ce4],&local_cdc,
                 local_ce0 + 1,local_ce0,&local_ce2);
    bVar8 = (local_ce0[0] - 0x11U & 0x8000) == 0;
    uVar3 = 0;
    if (bVar8) {
      uVar3 = local_ce0[0] - 0x11U;
    }
    sVar28 = 0x22;
    if (bVar8) {
      sVar28 = local_ce0[0] + 0x11;
    }
    if (sVar5 <= sVar28) {
      sVar28 = sVar5 + -1;
      uVar3 = sVar5 - 0x23;
    }
    if ((param_7 & 0xffff) == 0x28) {
      uVar30 = uVar3;
      if ((short)uVar3 < 0x14) {
        iVar1 = 0x27;
        if (sVar28 + 0x14 < 0x28) {
          iVar1 = sVar28 + 0x14;
        }
        FUN_002459fc(local_60c,lVar2,local_d80,auStack_3b4,(int)(short)(uVar3 + 0x14),
                     (int)(short)iVar1,iVar7);
        uVar30 = 0x14;
      }
      iVar4 = 0x14 - (short)uVar3;
      iVar1 = 0;
      if (-1 < iVar4) {
        iVar1 = iVar4;
      }
      (*DAT_0191b800)(auStack_3b4 + iVar1,local_60c,
                      auStack_770 + (long)(short)uVar30 * -2 + (long)param_6 * 2,0x28,
                      (int)(short)((sVar28 + 1) - uVar30),iVar7,0xffffffff);
    }
    else {
      (*DAT_0191b800)(auStack_3b4,local_60c,lVar2 + (long)(short)uVar3 * -2 + lVar19 * -2,uVar25,
                      (int)(short)((1 - uVar3) + sVar28),iVar7,0xffffffff);
    }
    sVar5 = uVar3 + sVar6;
    FUN_00246ab8(auStack_3b4,(int)(short)((1 - uVar3) + sVar28),iVar15,asStack_ad8 + (int)sVar5,
                 asStack_cd8 + (int)sVar5,auStack_5b4,&local_ce4,&local_cec,&local_ce6);
    iVar1 = (int)local_ce4 + (int)sVar5;
    FUN_00246ca0(local_cec,(long)local_ce6,(int)(short)iVar1,auStack_3b4[local_ce4],
                 (long)asStack_ad8[iVar1],(long)asStack_cd8[iVar1],&local_cdc,local_ce0 + 1,
                 local_ce0,&local_ce2);
    *(short *)(param_2 + lVar27 * 2) = local_ce0[0];
    sVar28 = -sVar22;
    if (-1 < sVar22) {
      sVar28 = sVar22;
    }
    local_ce2 = FUN_00249940((long)local_ce2,(int)sVar28,iVar15,puVar23);
    sVar22 = *(short *)(param_2 + lVar27 * 2);
    iVar15 = (int)sVar22;
    if (param_7 == 0x50U - (int)*(short *)(param_1 + 0xe)) {
      lVar18 = (long)iVar15;
      if (iVar15 < iVar24) {
        puVar29 = (undefined4 *)(lVar20 + lVar18 * -2);
      }
      else {
LAB_00246878:
        puVar29 = (undefined4 *)(lVar2 + local_d70 * 2 + lVar18 * -2 + lVar19 * -2);
      }
    }
    else {
      if (iVar15 < iVar24) {
        if (0x13 < iVar15) {
          *(short *)(param_2 + lVar27 * 2) = sVar22 + -0x14;
          puVar29 = (undefined4 *)(lVar20 + (long)(int)(short)(sVar22 + -0x14) * -2);
          goto LAB_00246494;
        }
        *(short *)(param_2 + lVar27 * 2) = sVar6 + -0x14 + sVar22;
        sVar22 = sVar22 + 0x14;
        lVar18 = lVar16;
      }
      else {
        if (0x13 < iVar15 - iVar24) {
          *(short *)(param_2 + lVar27 * 2) = sVar22 + -0x14;
          lVar18 = (long)(int)(short)(sVar22 + -0x14);
          goto LAB_00246878;
        }
        sVar22 = sVar6 + -0x14 + sVar22;
        *(short *)(param_2 + lVar27 * 2) = sVar22;
        sVar22 = (0x28 - (short)iVar11) + sVar22;
        lVar18 = lVar2;
      }
      puVar29 = auStack_3b4;
      FUN_00246f0c((int)sVar22,lVar18,auStack_3b4);
    }
LAB_00246494:
    FUN_0024e3f4(local_60c,puVar29,(int)-local_ce2,0x2000,0xe,uVar25);
    puVar23 = puVar23 + 1;
    local_6e[lVar27] = local_ce2;
    lVar27 = lVar27 + 1;
    sVar22 = local_ce2;
  } while( true );
}


