/* Decompiled from supplied 5.2.2 arm package. VA 0x27b09c. _ff_compute_safe_ssd_integral_image_neon */

void _ff_compute_safe_ssd_integral_image_neon
               (int *param_1,ulong param_2,byte *param_3,long param_4,byte *param_5,long param_6,
               uint param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 auVar10 [16];
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined7 uVar15;
  undefined7 uVar16;
  byte *pbVar17;
  byte *pbVar25;
  int *piVar33;
  int *piVar41;
  int *piVar48;
  int *piVar56;
  int *piVar63;
  int *piVar64;
  uint uVar65;
  byte bVar66;
  byte bVar67;
  short sVar68;
  short sVar69;
  short sVar70;
  short sVar71;
  short sVar72;
  short sVar73;
  short sVar74;
  int iVar75;
  int iVar76;
  int iVar77;
  int iVar78;
  undefined1 auVar79 [16];
  undefined1 auVar80 [16];
  undefined1 auVar81 [16];
  byte *pbVar18;
  byte *pbVar19;
  byte *pbVar20;
  byte *pbVar21;
  byte *pbVar22;
  byte *pbVar23;
  byte *pbVar24;
  byte *pbVar26;
  byte *pbVar27;
  byte *pbVar28;
  byte *pbVar29;
  byte *pbVar30;
  byte *pbVar31;
  byte *pbVar32;
  int *piVar34;
  int *piVar35;
  int *piVar36;
  int *piVar37;
  int *piVar38;
  int *piVar39;
  int *piVar40;
  int *piVar42;
  int *piVar43;
  int *piVar44;
  int *piVar45;
  int *piVar46;
  int *piVar47;
  int *piVar49;
  int *piVar50;
  int *piVar51;
  int *piVar52;
  int *piVar53;
  int *piVar54;
  int *piVar55;
  int *piVar57;
  int *piVar58;
  int *piVar59;
  int *piVar60;
  int *piVar61;
  int *piVar62;
  
  piVar64 = param_1 + -(param_2 & 0xffffffff);
  do {
    piVar63 = piVar64 + -1;
    iVar77 = param_1[-1];
    uVar65 = param_7;
    do {
      bVar66 = *param_3;
      pbVar17 = param_3 + 1;
      pbVar18 = param_3 + 2;
      pbVar19 = param_3 + 3;
      pbVar20 = param_3 + 4;
      pbVar21 = param_3 + 5;
      pbVar22 = param_3 + 6;
      pbVar23 = param_3 + 7;
      uVar15 = *(undefined7 *)(param_3 + 8);
      pbVar24 = param_3 + 0xf;
      param_3 = param_3 + 0x10;
      bVar67 = *param_5;
      pbVar25 = param_5 + 1;
      pbVar26 = param_5 + 2;
      pbVar27 = param_5 + 3;
      pbVar28 = param_5 + 4;
      pbVar29 = param_5 + 5;
      pbVar30 = param_5 + 6;
      pbVar31 = param_5 + 7;
      uVar16 = *(undefined7 *)(param_5 + 8);
      pbVar32 = param_5 + 0xf;
      param_5 = param_5 + 0x10;
      iVar75 = *piVar63;
      piVar33 = piVar63 + 1;
      piVar34 = piVar63 + 2;
      piVar35 = piVar63 + 3;
      piVar36 = piVar63 + 4;
      piVar37 = piVar63 + 5;
      piVar38 = piVar63 + 6;
      piVar39 = piVar63 + 7;
      piVar40 = piVar63 + 8;
      sVar68 = (ushort)(byte)uVar15 - (ushort)(byte)uVar16;
      sVar69 = (ushort)(byte)((uint7)uVar15 >> 8) - (ushort)(byte)((uint7)uVar16 >> 8);
      sVar70 = (ushort)(byte)((uint7)uVar15 >> 0x10) - (ushort)(byte)((uint7)uVar16 >> 0x10);
      sVar71 = (ushort)(byte)((uint7)uVar15 >> 0x18) - (ushort)(byte)((uint7)uVar16 >> 0x18);
      sVar72 = (ushort)(byte)((uint7)uVar15 >> 0x20) - (ushort)(byte)((uint7)uVar16 >> 0x20);
      sVar73 = (ushort)(byte)((uint7)uVar15 >> 0x28) - (ushort)(byte)((uint7)uVar16 >> 0x28);
      sVar74 = (ushort)(byte)((uint7)uVar15 >> 0x30) - (ushort)(byte)((uint7)uVar16 >> 0x30);
      piVar41 = piVar63 + 9;
      piVar42 = piVar63 + 10;
      piVar43 = piVar63 + 0xb;
      piVar44 = piVar63 + 0xc;
      piVar45 = piVar63 + 0xd;
      piVar46 = piVar63 + 0xe;
      piVar47 = piVar63 + 0xf;
      piVar63 = piVar63 + 0x10;
      iVar76 = *piVar64;
      piVar48 = piVar64 + 1;
      piVar49 = piVar64 + 2;
      piVar50 = piVar64 + 3;
      piVar51 = piVar64 + 4;
      piVar52 = piVar64 + 5;
      piVar53 = piVar64 + 6;
      piVar54 = piVar64 + 7;
      piVar55 = piVar64 + 8;
      piVar56 = piVar64 + 9;
      piVar57 = piVar64 + 10;
      piVar58 = piVar64 + 0xb;
      piVar59 = piVar64 + 0xc;
      piVar60 = piVar64 + 0xd;
      piVar61 = piVar64 + 0xe;
      piVar62 = piVar64 + 0xf;
      piVar64 = piVar64 + 0x10;
      iVar75 = (iVar76 - iVar75) +
               (int)(short)((ushort)bVar66 - (ushort)bVar67) *
               (int)(short)((ushort)bVar66 - (ushort)bVar67);
      iVar76 = (*piVar48 - *piVar33) +
               (int)(short)((ushort)*pbVar17 - (ushort)*pbVar25) *
               (int)(short)((ushort)*pbVar17 - (ushort)*pbVar25);
      iVar1 = (*piVar49 - *piVar34) +
              (int)(short)((ushort)*pbVar18 - (ushort)*pbVar26) *
              (int)(short)((ushort)*pbVar18 - (ushort)*pbVar26);
      iVar78 = (*piVar50 - *piVar35) +
               (int)(short)((ushort)*pbVar19 - (ushort)*pbVar27) *
               (int)(short)((ushort)*pbVar19 - (ushort)*pbVar27);
      iVar2 = (*piVar51 - *piVar36) +
              (int)(short)((ushort)*pbVar20 - (ushort)*pbVar28) *
              (int)(short)((ushort)*pbVar20 - (ushort)*pbVar28);
      iVar3 = (*piVar52 - *piVar37) +
              (int)(short)((ushort)*pbVar21 - (ushort)*pbVar29) *
              (int)(short)((ushort)*pbVar21 - (ushort)*pbVar29);
      iVar4 = (*piVar53 - *piVar38) +
              (int)(short)((ushort)*pbVar22 - (ushort)*pbVar30) *
              (int)(short)((ushort)*pbVar22 - (ushort)*pbVar30);
      iVar5 = (*piVar54 - *piVar39) +
              (int)(short)((ushort)*pbVar23 - (ushort)*pbVar31) *
              (int)(short)((ushort)*pbVar23 - (ushort)*pbVar31);
      iVar6 = (*piVar55 - *piVar40) + (int)sVar68 * (int)sVar68;
      iVar7 = (*piVar56 - *piVar41) + (int)sVar69 * (int)sVar69;
      iVar8 = (*piVar57 - *piVar42) + (int)sVar70 * (int)sVar70;
      iVar9 = (*piVar58 - *piVar43) + (int)sVar71 * (int)sVar71;
      iVar11 = (*piVar59 - *piVar44) + (int)sVar72 * (int)sVar72;
      iVar12 = (*piVar60 - *piVar45) + (int)sVar73 * (int)sVar73;
      iVar13 = (*piVar61 - *piVar46) + (int)sVar74 * (int)sVar74;
      iVar14 = (*piVar62 - *piVar47) +
               (int)(short)((ushort)*pbVar24 - (ushort)*pbVar32) *
               (int)(short)((ushort)*pbVar24 - (ushort)*pbVar32);
      auVar79[4] = (char)iVar76;
      auVar79._0_4_ = iVar75;
      auVar79[5] = (char)((uint)iVar76 >> 8);
      auVar79[6] = (char)((uint)iVar76 >> 0x10);
      auVar79[7] = (char)((uint)iVar76 >> 0x18);
      auVar79[8] = (char)iVar1;
      auVar79[9] = (char)((uint)iVar1 >> 8);
      auVar79[10] = (char)((uint)iVar1 >> 0x10);
      auVar79[0xb] = (char)((uint)iVar1 >> 0x18);
      auVar79[0xc] = (char)iVar78;
      auVar79[0xd] = (char)((uint)iVar78 >> 8);
      auVar79[0xe] = (char)((uint)iVar78 >> 0x10);
      auVar79[0xf] = (char)((uint)iVar78 >> 0x18);
      auVar79 = NEON_ext(ZEXT816(0),auVar79,0xc,1);
      auVar80 = NEON_ext(ZEXT816(0),auVar79,0xc,1);
      auVar81 = NEON_ext(ZEXT816(0),auVar80,0xc,1);
      iVar78 = iVar77 + iVar78 + auVar79._12_4_ + auVar80._12_4_ + auVar81._12_4_;
      *param_1 = iVar77 + iVar75 + auVar79._0_4_ + auVar80._0_4_ + auVar81._0_4_;
      param_1[1] = iVar77 + iVar76 + auVar79._4_4_ + auVar80._4_4_ + auVar81._4_4_;
      param_1[2] = iVar77 + iVar1 + auVar79._8_4_ + auVar80._8_4_ + auVar81._8_4_;
      param_1[3] = iVar78;
      auVar80[4] = (char)iVar3;
      auVar80._0_4_ = iVar2;
      auVar80[5] = (char)((uint)iVar3 >> 8);
      auVar80[6] = (char)((uint)iVar3 >> 0x10);
      auVar80[7] = (char)((uint)iVar3 >> 0x18);
      auVar80[8] = (char)iVar4;
      auVar80[9] = (char)((uint)iVar4 >> 8);
      auVar80[10] = (char)((uint)iVar4 >> 0x10);
      auVar80[0xb] = (char)((uint)iVar4 >> 0x18);
      auVar80[0xc] = (char)iVar5;
      auVar80[0xd] = (char)((uint)iVar5 >> 8);
      auVar80[0xe] = (char)((uint)iVar5 >> 0x10);
      auVar80[0xf] = (char)((uint)iVar5 >> 0x18);
      auVar79 = NEON_ext(ZEXT816(0),auVar80,0xc,1);
      auVar80 = NEON_ext(ZEXT816(0),auVar79,0xc,1);
      auVar81 = NEON_ext(ZEXT816(0),auVar80,0xc,1);
      iVar77 = iVar78 + iVar5 + auVar79._12_4_ + auVar80._12_4_ + auVar81._12_4_;
      param_1[4] = iVar78 + iVar2 + auVar79._0_4_ + auVar80._0_4_ + auVar81._0_4_;
      param_1[5] = iVar78 + iVar3 + auVar79._4_4_ + auVar80._4_4_ + auVar81._4_4_;
      param_1[6] = iVar78 + iVar4 + auVar79._8_4_ + auVar80._8_4_ + auVar81._8_4_;
      param_1[7] = iVar77;
      auVar81._4_2_ = (short)iVar7;
      auVar81._0_4_ = iVar6;
      auVar81._6_2_ = (short)((uint)iVar7 >> 0x10);
      auVar81._8_2_ = (short)iVar8;
      auVar81._10_2_ = (short)((uint)iVar8 >> 0x10);
      auVar81._12_2_ = (short)iVar9;
      auVar81._14_2_ = (short)((uint)iVar9 >> 0x10);
      auVar79 = NEON_ext(ZEXT816(0),auVar81,0xc,1);
      auVar80 = NEON_ext(ZEXT816(0),auVar79,0xc,1);
      auVar81 = NEON_ext(ZEXT816(0),auVar80,0xc,1);
      iVar75 = iVar77 + iVar9 + auVar79._12_4_ + auVar80._12_4_ + auVar81._12_4_;
      param_1[8] = iVar77 + iVar6 + auVar79._0_4_ + auVar80._0_4_ + auVar81._0_4_;
      param_1[9] = iVar77 + iVar7 + auVar79._4_4_ + auVar80._4_4_ + auVar81._4_4_;
      param_1[10] = iVar77 + iVar8 + auVar79._8_4_ + auVar80._8_4_ + auVar81._8_4_;
      param_1[0xb] = iVar75;
      auVar10._4_2_ = (short)iVar12;
      auVar10._0_4_ = iVar11;
      auVar10._6_2_ = (short)((uint)iVar12 >> 0x10);
      auVar10._8_2_ = (short)iVar13;
      auVar10._10_2_ = (short)((uint)iVar13 >> 0x10);
      auVar10._12_2_ = (short)iVar14;
      auVar10._14_2_ = (short)((uint)iVar14 >> 0x10);
      auVar79 = NEON_ext(ZEXT816(0),auVar10,0xc,1);
      auVar80 = NEON_ext(ZEXT816(0),auVar79,0xc,1);
      auVar81 = NEON_ext(ZEXT816(0),auVar80,0xc,1);
      iVar77 = iVar75 + iVar14 + auVar79._12_4_ + auVar80._12_4_ + auVar81._12_4_;
      param_1[0xc] = iVar75 + iVar11 + auVar79._0_4_ + auVar80._0_4_ + auVar81._0_4_;
      param_1[0xd] = iVar75 + iVar12 + auVar79._4_4_ + auVar80._4_4_ + auVar81._4_4_;
      param_1[0xe] = iVar75 + iVar13 + auVar79._8_4_ + auVar80._8_4_ + auVar81._8_4_;
      param_1[0xf] = iVar77;
      param_1 = param_1 + 0x10;
      uVar65 = uVar65 - 0x10;
    } while (uVar65 != 0);
    param_3 = param_3 + (param_4 - (ulong)param_7);
    param_5 = param_5 + (param_6 - (ulong)param_7);
    param_1 = param_1 + (param_2 - param_7);
    piVar64 = piVar64 + (param_2 - param_7);
    param_8 = param_8 + -1;
  } while (param_8 != 0);
  return;
}


