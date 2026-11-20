/* Decompiled from supplied 5.2.2 arm package. VA 0x26a8ac. FUN_0026a8ac */

void FUN_0026a8ac(uint *param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  long lVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int *piVar20;
  uint uVar21;
  uint uVar22;
  long lVar23;
  int *piVar24;
  int *piVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  int *piVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  int local_a8 [16];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar6 = *param_1;
  uVar7 = param_1[1];
  uVar8 = param_1[2];
  uVar9 = param_1[3];
  uVar10 = param_1[4];
  uVar2 = param_1[5];
  uVar4 = param_1[6];
  uVar3 = param_1[7];
  uVar5 = param_1[8];
  uVar11 = param_1[9];
  for (lVar23 = 0; lVar23 != 0x40; lVar23 = lVar23 + 4) {
    *(undefined4 *)((long)local_a8 + lVar23) = *(undefined4 *)(param_2 + lVar23);
  }
  lVar15 = 0x10;
  uVar32 = uVar10;
  uVar16 = uVar8;
  uVar1 = uVar7;
  uVar21 = uVar9;
  uVar28 = uVar6;
  uVar22 = uVar5;
  uVar26 = uVar4;
  uVar19 = uVar3;
  uVar31 = uVar11;
  uVar27 = uVar2;
  for (lVar23 = 0; uVar17 = uVar31, uVar30 = uVar26, uVar31 = uVar22, uVar22 = uVar32,
      lVar23 != 0x40; lVar23 = lVar23 + 4) {
    uVar18 = uVar16 >> 0x16;
    uVar12 = uVar16 << 10;
    uVar28 = (uVar16 ^ uVar21 ^ uVar1) + uVar28 + local_a8[*(int *)((long)&DAT_00c51424 + lVar23)];
    uVar13 = 0x20U - *(int *)((long)&DAT_00c51564 + lVar23) & 0x1f;
    uVar26 = uVar27 + ((uVar19 | uVar31 ^ 0xffffffff) ^ uVar30) +
             local_a8[*(int *)((long)&DAT_00c516a4 + lVar23)] + 0x50a28be6;
    uVar27 = 0x20U - *(int *)((long)&DAT_00c517e4 + lVar23) & 0x1f;
    uVar32 = uVar21;
    uVar16 = uVar1;
    uVar1 = (uVar28 >> uVar13 | uVar28 << 0x20 - uVar13) + uVar22;
    uVar21 = uVar18 | uVar12;
    uVar28 = uVar22;
    uVar22 = uVar19 >> 0x16 | uVar19 << 10;
    uVar26 = (uVar26 >> uVar27 | uVar26 << 0x20 - uVar27) + uVar17;
    uVar19 = uVar30;
    uVar27 = uVar17;
  }
  lVar23 = 0;
  for (; uVar18 = uVar17, uVar32 = uVar21, uVar26 = uVar1, lVar15 < 0x20; lVar15 = lVar15 + 1) {
    uVar1 = uVar28 + ((uVar16 ^ uVar32) & uVar30 ^ uVar32) +
            local_a8[*(int *)((long)&DAT_00c51464 + lVar23)] + 0x5a827999;
    uVar28 = 0x20U - *(int *)((long)&DAT_00c515a4 + lVar23) & 0x1f;
    uVar21 = uVar27 + ((uVar19 ^ uVar26) & uVar31 ^ uVar19) +
             local_a8[*(int *)((long)&DAT_00c516e4 + lVar23)] + 0x5c4dd124;
    uVar27 = (uVar1 >> uVar28 | uVar1 << 0x20 - uVar28) + uVar22;
    uVar1 = 0x20U - *(int *)((long)&DAT_00c51824 + lVar23) & 0x1f;
    uVar12 = uVar19 >> 0x16;
    uVar13 = uVar19 << 10;
    lVar23 = lVar23 + 4;
    uVar28 = uVar22;
    uVar1 = (uVar21 >> uVar1 | uVar21 << 0x20 - uVar1) + uVar18;
    uVar21 = uVar16 >> 0x16 | uVar16 << 10;
    uVar22 = uVar32;
    uVar16 = uVar30;
    uVar19 = uVar26;
    uVar30 = uVar27;
    uVar17 = uVar31;
    uVar27 = uVar18;
    uVar31 = uVar12 | uVar13;
  }
  for (; uVar17 = uVar31, uVar1 = uVar26, uVar21 = uVar32, lVar15 < 0x30; lVar15 = lVar15 + 1) {
    uVar12 = uVar16 >> 0x16;
    uVar13 = uVar16 << 10;
    lVar23 = lVar23 + 4;
    uVar31 = uVar28 + ((uVar30 | uVar16 ^ 0xffffffff) ^ uVar17) +
             local_a8[(int)(&DAT_00c51424)[lVar15]] + 0x6ed9eba1;
    uVar14 = 0x20 - (&DAT_00c51564)[lVar15] & 0x1f;
    uVar16 = uVar27 + ((uVar1 | uVar19 ^ 0xffffffff) ^ uVar21) +
             local_a8[(int)(&DAT_00c516a4)[lVar15]] + 0x6d703ef3;
    uVar26 = 0x20 - (&DAT_00c517e4)[lVar15] & 0x1f;
    uVar28 = uVar22;
    uVar32 = uVar19 >> 0x16 | uVar19 << 10;
    uVar26 = (uVar16 >> uVar26 | uVar16 << 0x20 - uVar26) + uVar18;
    uVar16 = uVar30;
    uVar19 = uVar1;
    uVar30 = (uVar31 >> uVar14 | uVar31 << 0x20 - uVar14) + uVar22;
    uVar27 = uVar18;
    uVar31 = uVar12 | uVar13;
    uVar22 = uVar17;
    uVar18 = uVar21;
  }
  for (; uVar26 = uVar17, uVar32 = uVar1, uVar31 = uVar21, lVar15 < 0x40; lVar15 = lVar15 + 1) {
    uVar17 = uVar16 >> 0x16;
    uVar12 = uVar16 << 10;
    uVar27 = uVar27 + ((uVar30 ^ uVar16) & uVar26 ^ uVar16) +
             local_a8[*(int *)((long)&DAT_00c51464 + lVar23)] + 0x8f1bbcdc;
    uVar13 = 0x20U - *(int *)((long)&DAT_00c515a4 + lVar23) & 0x1f;
    uVar1 = uVar28 + ((uVar31 ^ uVar19) & uVar32 ^ uVar31) +
            local_a8[*(int *)((long)&DAT_00c516e4 + lVar23)] + 0x7a6d76e9;
    uVar14 = 0x20U - *(int *)((long)&DAT_00c51824 + lVar23) & 0x1f;
    lVar23 = lVar23 + 4;
    uVar28 = uVar18;
    uVar21 = uVar19 >> 0x16 | uVar19 << 10;
    uVar16 = uVar30;
    uVar1 = (uVar1 >> uVar14 | uVar1 << 0x20 - uVar14) + uVar18;
    uVar19 = uVar32;
    uVar30 = (uVar27 >> uVar13 | uVar27 << 0x20 - uVar13) + uVar22;
    uVar27 = uVar22;
    uVar17 = uVar17 | uVar12;
    uVar22 = uVar26;
    uVar18 = uVar31;
  }
  piVar20 = (int *)((long)&DAT_00c51464 + lVar23);
  piVar24 = (int *)((long)&DAT_00c515a4 + lVar23);
  piVar25 = (int *)((long)&DAT_00c516e4 + lVar23);
  piVar29 = (int *)((long)&DAT_00c51824 + lVar23);
  for (; lVar15 < 0x50; lVar15 = lVar15 + 1) {
    uVar1 = ((uVar19 | uVar26 ^ 0xffffffff) ^ uVar30) + uVar27 + local_a8[*piVar20] + 0xa953fd4e;
    uVar27 = 0x20U - *piVar24 & 0x1f;
    uVar17 = uVar19 >> 0x16;
    uVar13 = uVar19 << 10;
    uVar21 = (uVar16 ^ uVar32 ^ uVar31) + uVar28 + local_a8[*piVar25];
    uVar19 = 0x20U - *piVar29 & 0x1f;
    uVar12 = uVar16 >> 0x16;
    uVar14 = uVar16 << 10;
    piVar20 = piVar20 + 1;
    piVar24 = piVar24 + 1;
    piVar25 = piVar25 + 1;
    piVar29 = piVar29 + 1;
    uVar28 = uVar18;
    uVar16 = uVar32;
    uVar32 = (uVar21 >> uVar19 | uVar21 << 0x20 - uVar19) + uVar18;
    uVar19 = uVar30;
    uVar30 = (uVar1 >> uVar27 | uVar1 << 0x20 - uVar27) + uVar22;
    uVar27 = uVar22;
    uVar22 = uVar26;
    uVar26 = uVar17 | uVar13;
    uVar18 = uVar31;
    uVar31 = uVar12 | uVar14;
  }
  *param_1 = uVar6 + uVar27;
  param_1[1] = uVar7 + uVar30;
  param_1[2] = uVar8 + uVar19;
  param_1[3] = uVar9 + uVar26;
  param_1[4] = uVar10 + uVar18;
  param_1[5] = uVar2 + uVar28;
  param_1[6] = uVar4 + uVar32;
  param_1[7] = uVar3 + uVar16;
  param_1[8] = uVar5 + uVar31;
  param_1[9] = uVar11 + uVar22;
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


