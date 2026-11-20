/* Decompiled from supplied 5.2.2 arm package. VA 0x2729dc. FUN_002729dc */

void FUN_002729dc(long param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  int *piVar8;
  float *pfVar9;
  code *pcVar10;
  long lVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float local_158 [30];
  float local_e0 [30];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar1 = *(uint *)(param_1 + 4);
  lVar7 = (long)(int)uVar1;
  piVar3 = *(int **)(param_1 + 0x20);
  pcVar10 = *(code **)(&DAT_0106d428 + (long)(0x1f - (int)LZCOUNT(uVar1 | 1)) * 8);
  piVar4 = piVar3;
  for (lVar5 = 0; lVar5 < lVar7; lVar5 = lVar5 + 1) {
    piVar8 = piVar4;
    for (lVar6 = 0; lVar6 != 0x78; lVar6 = lVar6 + 8) {
      *(undefined8 *)((long)local_158 + lVar6) = *(undefined8 *)(param_3 + (long)*piVar8 * 8);
      piVar8 = piVar8 + 1;
    }
    lVar11 = *(long *)(param_1 + 0x18);
    iVar2 = *(int *)(*(long *)(param_1 + 0x28) + lVar5 * 4);
    lVar6 = -0x30;
    pfVar9 = local_158;
    while (lVar6 + 8 != 0) {
      fVar12 = pfVar9[1];
      fVar14 = pfVar9[2] + pfVar9[4];
      fVar15 = pfVar9[3] + pfVar9[5];
      fVar17 = _ff_cos_53_float * (pfVar9[3] - pfVar9[5]);
      fVar13 = DAT_01a777a4 * (pfVar9[2] - pfVar9[4]);
      fVar18 = *pfVar9 - DAT_01a777a8 * fVar14;
      fVar16 = fVar12 - DAT_01a777a8 * fVar15;
      *(float *)((long)local_e0 + lVar6 + 0x30) = *pfVar9 + fVar14;
      *(float *)((long)local_e0 + lVar6 + 0x34) = fVar15 + fVar12;
      *(float *)((long)local_e0 + lVar6 + 0x58) = fVar17 + fVar18;
      *(float *)((long)local_e0 + lVar6 + 0x5c) = fVar16 - fVar13;
      *(float *)(&stack0xffffffffffffffa0 + lVar6) = fVar18 - fVar17;
      *(float *)(&stack0xffffffffffffffa4 + lVar6) = fVar13 + fVar16;
      lVar6 = lVar6 + 8;
      pfVar9 = pfVar9 + 6;
    }
    pfVar9 = (float *)(lVar11 + (long)iVar2 * 8);
    fVar12 = local_e0[2] + local_e0[8];
    fVar14 = local_e0[3] + local_e0[9];
    fVar16 = local_e0[4] + local_e0[6];
    *pfVar9 = fVar16 + fVar12 + local_e0[0];
    fVar19 = local_e0[5] + local_e0[7];
    pfVar9[1] = fVar19 + fVar14 + local_e0[1];
    fVar18 = DAT_01a777bc;
    fVar15 = DAT_01a777b8;
    fVar17 = DAT_01a777b4;
    fVar13 = DAT_01a777b0;
    fVar20 = fVar12 * DAT_01a777b0 - fVar16 * DAT_01a777b8;
    fVar22 = fVar14 * DAT_01a777b0 - fVar19 * DAT_01a777b8;
    fVar21 = (local_e0[3] - local_e0[9]) * DAT_01a777b4 + (local_e0[5] - local_e0[7]) * DAT_01a777bc
    ;
    fVar23 = (local_e0[2] - local_e0[8]) * DAT_01a777b4 + (local_e0[4] - local_e0[6]) * DAT_01a777bc
    ;
    pfVar9[lVar7 * 0xc] = local_e0[0] + fVar20 + fVar21;
    (pfVar9 + lVar7 * 0xc)[1] = local_e0[1] + (fVar22 - fVar23);
    fVar12 = fVar16 * fVar13 - fVar12 * fVar15;
    fVar15 = fVar19 * fVar13 - fVar14 * fVar15;
    fVar13 = (local_e0[5] - local_e0[7]) * fVar17 - (local_e0[3] - local_e0[9]) * fVar18;
    fVar17 = (local_e0[4] - local_e0[6]) * fVar17 - (local_e0[2] - local_e0[8]) * fVar18;
    pfVar9[lVar7 * 0x18] = local_e0[0] + (fVar12 - fVar13);
    (pfVar9 + lVar7 * 0x18)[1] = local_e0[1] + fVar15 + fVar17;
    pfVar9[lVar7 * 6] = local_e0[0] + fVar12 + fVar13;
    (pfVar9 + lVar7 * 6)[1] = local_e0[1] + (fVar15 - fVar17);
    pfVar9[lVar7 * 0x12] = local_e0[0] + (fVar20 - fVar21);
    (pfVar9 + lVar7 * 0x12)[1] = local_e0[1] + fVar22 + fVar23;
    fVar12 = local_e0[0xc] + local_e0[0x12];
    fVar14 = local_e0[0xe] + local_e0[0x10];
    pfVar9[lVar7 * 0x14] = fVar14 + fVar12 + local_e0[10];
    fVar16 = local_e0[0xd] + local_e0[0x13];
    fVar19 = local_e0[0xf] + local_e0[0x11];
    (pfVar9 + lVar7 * 0x14)[1] = fVar19 + fVar16 + local_e0[0xb];
    fVar18 = DAT_01a777bc;
    fVar15 = DAT_01a777b8;
    fVar17 = DAT_01a777b4;
    fVar13 = DAT_01a777b0;
    fVar20 = fVar12 * DAT_01a777b0 - fVar14 * DAT_01a777b8;
    fVar22 = fVar16 * DAT_01a777b0 - fVar19 * DAT_01a777b8;
    fVar21 = (local_e0[0xd] - local_e0[0x13]) * DAT_01a777b4 +
             (local_e0[0xf] - local_e0[0x11]) * DAT_01a777bc;
    fVar23 = (local_e0[0xc] - local_e0[0x12]) * DAT_01a777b4 +
             (local_e0[0xe] - local_e0[0x10]) * DAT_01a777bc;
    pfVar9[lVar7 * 2] = local_e0[10] + fVar20 + fVar21;
    (pfVar9 + lVar7 * 2)[1] = local_e0[0xb] + (fVar22 - fVar23);
    fVar14 = fVar14 * fVar13 - fVar12 * fVar15;
    fVar12 = fVar19 * fVar13 - fVar16 * fVar15;
    fVar15 = (local_e0[0xf] - local_e0[0x11]) * fVar17 - (local_e0[0xd] - local_e0[0x13]) * fVar18;
    fVar13 = (local_e0[0xe] - local_e0[0x10]) * fVar17 - (local_e0[0xc] - local_e0[0x12]) * fVar18;
    pfVar9[lVar7 * 0xe] = local_e0[10] + (fVar14 - fVar15);
    (pfVar9 + lVar7 * 0xe)[1] = local_e0[0xb] + fVar12 + fVar13;
    pfVar9[lVar7 * 0x1a] = local_e0[10] + fVar14 + fVar15;
    (pfVar9 + lVar7 * 0x1a)[1] = local_e0[0xb] + (fVar12 - fVar13);
    pfVar9[lVar7 * 8] = local_e0[10] + (fVar20 - fVar21);
    (pfVar9 + lVar7 * 8)[1] = local_e0[0xb] + fVar22 + fVar23;
    fVar13 = local_e0[0x16] + local_e0[0x1c];
    fVar17 = local_e0[0x17] + local_e0[0x1d];
    fVar15 = local_e0[0x18] + local_e0[0x1a];
    pfVar9[lVar7 * 10] = fVar15 + fVar13 + local_e0[0x14];
    fVar18 = local_e0[0x19] + local_e0[0x1b];
    (pfVar9 + lVar7 * 10)[1] = fVar18 + fVar17 + local_e0[0x15];
    fVar12 = fVar15 * DAT_01a777b0;
    fVar22 = fVar13 * DAT_01a777b8;
    fVar14 = fVar18 * DAT_01a777b0;
    fVar23 = fVar17 * DAT_01a777b8;
    fVar16 = (local_e0[0x19] - local_e0[0x1b]) * DAT_01a777b4;
    fVar21 = (local_e0[0x17] - local_e0[0x1d]) * DAT_01a777bc;
    fVar19 = (local_e0[0x18] - local_e0[0x1a]) * DAT_01a777b4;
    fVar20 = (local_e0[0x16] - local_e0[0x1c]) * DAT_01a777bc;
    fVar13 = fVar13 * DAT_01a777b0 - fVar15 * DAT_01a777b8;
    fVar15 = fVar17 * DAT_01a777b0 - fVar18 * DAT_01a777b8;
    fVar17 = (local_e0[0x17] - local_e0[0x1d]) * DAT_01a777b4 +
             (local_e0[0x19] - local_e0[0x1b]) * DAT_01a777bc;
    fVar18 = (local_e0[0x16] - local_e0[0x1c]) * DAT_01a777b4 +
             (local_e0[0x18] - local_e0[0x1a]) * DAT_01a777bc;
    pfVar9[lVar7 * 0x16] = local_e0[0x14] + fVar13 + fVar17;
    (pfVar9 + lVar7 * 0x16)[1] = local_e0[0x15] + (fVar15 - fVar18);
    fVar12 = fVar12 - fVar22;
    fVar14 = fVar14 - fVar23;
    fVar16 = fVar16 - fVar21;
    fVar19 = fVar19 - fVar20;
    pfVar9[lVar7 * 4] = local_e0[0x14] + (fVar12 - fVar16);
    (pfVar9 + lVar7 * 4)[1] = local_e0[0x15] + fVar14 + fVar19;
    pfVar9[lVar7 * 0x10] = local_e0[0x14] + fVar12 + fVar16;
    (pfVar9 + lVar7 * 0x10)[1] = local_e0[0x15] + (fVar14 - fVar19);
    pfVar9[lVar7 * 0x1c] = local_e0[0x14] + (fVar13 - fVar17);
    (pfVar9 + lVar7 * 0x1c)[1] = local_e0[0x15] + fVar15 + fVar18;
    piVar4 = piVar4 + 0xf;
  }
  lVar6 = 0x10;
  lVar5 = 0;
  while (lVar6 = lVar6 + -1, lVar6 != 0) {
    (*pcVar10)(*(long *)(param_1 + 0x18) + lVar5);
    lVar5 = lVar5 + lVar7 * 8;
  }
  for (lVar5 = 0; lVar5 < lVar7 * 0xf; lVar5 = lVar5 + 1) {
    *(undefined8 *)(param_2 + lVar5 * 8) =
         *(undefined8 *)(*(long *)(param_1 + 0x18) + (long)piVar3[(int)(uVar1 * 0xf) + lVar5] * 8);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


