/* Decompiled from supplied 5.2.2 arm package. VA 0x2441dc. _shine_mdct_initialise */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _shine_mdct_initialise(long param_1)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  long lVar5;
  code *pcVar6;
  code *pcVar7;
  long lVar8;
  int iVar9;
  ulong uVar10;
  double dVar12;
  undefined8 uVar13;
  int iVar21;
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  double dVar22;
  undefined1 auVar17 [16];
  double dVar11;
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  double dVar23;
  undefined1 auVar20 [16];
  undefined1 auVar24 [16];
  
  uVar3 = _UNK_00c4d6e8;
  uVar2 = _DAT_00c4d6e0;
  pcVar6 = _objc_msgSend + param_1 + 4;
  auVar24 = NEON_fmov(0x3fe0000000000000,8);
  lVar5 = 0x11;
  do {
    uVar4 = (undefined4)(lVar5 << 1);
    uVar10 = CONCAT44(uVar4,uVar4) | 0x100000001;
    auVar14._0_8_ = (long)(int)uVar10;
    auVar14._8_8_ = (long)(int)(uVar10 >> 0x20);
    auVar14 = NEON_scvtf(auVar14,8);
    lVar8 = 0x23;
    pcVar7 = pcVar6;
    do {
      iVar9 = (int)lVar8 + (int)uVar2;
      iVar21 = (int)lVar8 + (int)uVar3;
      auVar15._0_8_ = (long)iVar9;
      auVar15._8_8_ = (long)iVar21;
      auVar16 = NEON_scvtf(auVar15,8);
      dVar22 = (auVar16._8_8_ + auVar24._8_8_) * 0.087266462599717;
      auVar17._8_8_ = 0;
      auVar17._0_8_ = dVar22;
      dVar11 = (double)_sin(auVar17);
      auVar19._8_8_ = dVar22;
      auVar19._0_8_ = (auVar16._0_8_ + auVar24._0_8_) * 0.087266462599717;
      dVar22 = (double)_sin(auVar19);
      auVar18._0_8_ = (long)(iVar9 * 2 + 0x13);
      auVar18._8_8_ = (long)(iVar21 * 2 + 0x13);
      auVar19 = NEON_scvtf(auVar18,8);
      dVar23 = auVar14._8_8_ * auVar19._8_8_ * 0.043633231299858195;
      auVar20._8_8_ = 0;
      auVar20._0_8_ = dVar23;
      dVar12 = (double)_cos(auVar20);
      auVar16._8_8_ = dVar23;
      auVar16._0_8_ = auVar14._0_8_ * auVar19._0_8_ * 0.043633231299858195;
      dVar23 = (double)_cos(auVar16);
      lVar8 = lVar8 + -2;
      uVar13 = NEON_rev64(CONCAT44((int)(long)(dVar11 * dVar12 * 2147483647.0),
                                   (int)(long)(dVar22 * dVar23 * 2147483647.0)),4);
      *(undefined8 *)pcVar7 = uVar13;
      pcVar7 = pcVar7 + -8;
    } while (lVar8 != -1);
    pcVar6 = pcVar6 + -0x90;
    bVar1 = lVar5 != 0;
    lVar5 = lVar5 + -1;
  } while (bVar1);
  return;
}


