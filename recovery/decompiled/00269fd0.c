/* Decompiled from supplied 5.2.2 arm package. VA 0x269fd0. FUN_00269fd0 */

void FUN_00269fd0(uint *param_1,long param_2)

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
  int *piVar10;
  int *piVar11;
  uint uVar12;
  long lVar13;
  uint uVar14;
  long lVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  int *piVar25;
  uint uVar26;
  int local_a8 [16];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar6 = *param_1;
  uVar2 = param_1[1];
  uVar4 = param_1[2];
  uVar3 = param_1[3];
  uVar5 = param_1[4];
  for (lVar13 = 0; lVar13 != 0x40; lVar13 = lVar13 + 4) {
    *(undefined4 *)((long)local_a8 + lVar13) = *(undefined4 *)(param_2 + lVar13);
  }
  lVar15 = 0x10;
  uVar9 = uVar6;
  uVar16 = uVar3;
  uVar23 = uVar3;
  uVar21 = uVar5;
  uVar12 = uVar6;
  uVar14 = uVar5;
  uVar22 = uVar2;
  uVar20 = uVar2;
  uVar8 = uVar4;
  uVar17 = uVar4;
  for (lVar13 = 0; uVar26 = uVar20, uVar24 = uVar22, uVar19 = uVar21, uVar21 = uVar23,
      uVar20 = uVar16, lVar13 != 0x40; lVar13 = lVar13 + 4) {
    uVar22 = (uVar17 ^ uVar24 ^ uVar20) + uVar9 + local_a8[*(int *)((long)&DAT_00c51424 + lVar13)];
    uVar9 = 0x20U - *(int *)((long)&DAT_00c51564 + lVar13) & 0x1f;
    uVar1 = uVar12 + ((uVar8 | uVar21 ^ 0xffffffff) ^ uVar26) +
            local_a8[*(int *)((long)&DAT_00c516a4 + lVar13)] + 0x50a28be6;
    uVar22 = (uVar22 >> uVar9 | uVar22 << 0x20 - uVar9) + uVar14;
    uVar7 = 0x20U - *(int *)((long)&DAT_00c517e4 + lVar13) & 0x1f;
    uVar9 = uVar14;
    uVar16 = uVar17 >> 0x16 | uVar17 << 10;
    uVar23 = uVar8 >> 0x16 | uVar8 << 10;
    uVar12 = uVar19;
    uVar14 = uVar20;
    uVar20 = (uVar1 >> uVar7 | uVar1 << 0x20 - uVar7) + uVar19;
    uVar8 = uVar26;
    uVar17 = uVar24;
  }
  lVar13 = 0;
  for (; uVar23 = uVar26, uVar16 = uVar19, uVar19 = uVar21, uVar22 = uVar20, lVar15 < 0x20;
      lVar15 = lVar15 + 1) {
    uVar9 = uVar9 + ((uVar22 ^ uVar17) & uVar24 ^ uVar22) +
            local_a8[*(int *)((long)&DAT_00c51464 + lVar13)] + 0x5a827999;
    uVar26 = uVar12 + ((uVar8 ^ uVar23) & uVar19 ^ uVar8) +
             local_a8[*(int *)((long)&DAT_00c516e4 + lVar13)] + 0x5c4dd124;
    uVar21 = 0x20U - *(int *)((long)&DAT_00c515a4 + lVar13) & 0x1f;
    uVar7 = 0x20U - *(int *)((long)&DAT_00c51824 + lVar13) & 0x1f;
    uVar1 = (uVar9 >> uVar21 | uVar9 << 0x20 - uVar21) + uVar14;
    lVar13 = lVar13 + 4;
    uVar9 = uVar14;
    uVar20 = uVar17 >> 0x16 | uVar17 << 10;
    uVar21 = uVar8 >> 0x16 | uVar8 << 10;
    uVar12 = uVar16;
    uVar14 = uVar22;
    uVar26 = (uVar26 >> uVar7 | uVar26 << 0x20 - uVar7) + uVar16;
    uVar8 = uVar23;
    uVar17 = uVar24;
    uVar24 = uVar1;
  }
  for (; uVar20 = uVar19, uVar21 = uVar22, lVar15 < 0x30; lVar15 = lVar15 + 1) {
    uVar22 = uVar9 + ((uVar24 | uVar17 ^ 0xffffffff) ^ uVar21) +
             local_a8[(int)(&DAT_00c51424)[lVar15]] + 0x6ed9eba1;
    uVar9 = uVar12 + ((uVar23 | uVar8 ^ 0xffffffff) ^ uVar20) +
            local_a8[(int)(&DAT_00c516a4)[lVar15]] + 0x6d703ef3;
    uVar12 = 0x20 - (&DAT_00c51564)[lVar15] & 0x1f;
    uVar19 = 0x20 - (&DAT_00c517e4)[lVar15] & 0x1f;
    uVar26 = (uVar22 >> uVar12 | uVar22 << 0x20 - uVar12) + uVar14;
    uVar1 = (uVar9 >> uVar19 | uVar9 << 0x20 - uVar19) + uVar16;
    lVar13 = lVar13 + 4;
    uVar9 = uVar14;
    uVar22 = uVar17 >> 0x16 | uVar17 << 10;
    uVar12 = uVar16;
    uVar19 = uVar8 >> 0x16 | uVar8 << 10;
    uVar16 = uVar20;
    uVar14 = uVar21;
    uVar8 = uVar23;
    uVar23 = uVar1;
    uVar17 = uVar24;
    uVar24 = uVar26;
  }
  for (; uVar19 = uVar20, uVar22 = uVar21, lVar15 < 0x40; lVar15 = lVar15 + 1) {
    uVar9 = uVar9 + ((uVar17 ^ uVar24) & uVar22 ^ uVar17) +
            local_a8[*(int *)((long)&DAT_00c51464 + lVar13)] + 0x8f1bbcdc;
    uVar21 = uVar12 + ((uVar19 ^ uVar8) & uVar23 ^ uVar19) +
             local_a8[*(int *)((long)&DAT_00c516e4 + lVar13)] + 0x7a6d76e9;
    uVar12 = 0x20U - *(int *)((long)&DAT_00c515a4 + lVar13) & 0x1f;
    uVar20 = 0x20U - *(int *)((long)&DAT_00c51824 + lVar13) & 0x1f;
    uVar26 = (uVar9 >> uVar12 | uVar9 << 0x20 - uVar12) + uVar14;
    uVar1 = (uVar21 >> uVar20 | uVar21 << 0x20 - uVar20) + uVar16;
    lVar13 = lVar13 + 4;
    uVar9 = uVar14;
    uVar21 = uVar17 >> 0x16 | uVar17 << 10;
    uVar12 = uVar16;
    uVar20 = uVar8 >> 0x16 | uVar8 << 10;
    uVar16 = uVar19;
    uVar14 = uVar22;
    uVar8 = uVar23;
    uVar23 = uVar1;
    uVar17 = uVar24;
    uVar24 = uVar26;
  }
  piVar10 = (int *)((long)&DAT_00c51464 + lVar13);
  piVar11 = (int *)((long)&DAT_00c515a4 + lVar13);
  piVar18 = (int *)((long)&DAT_00c516e4 + lVar13);
  piVar25 = (int *)((long)&DAT_00c51824 + lVar13);
  for (; lVar15 < 0x50; lVar15 = lVar15 + 1) {
    uVar9 = uVar9 + ((uVar17 | uVar22 ^ 0xffffffff) ^ uVar24) + local_a8[*piVar10] + 0xa953fd4e;
    uVar21 = 0x20U - *piVar11 & 0x1f;
    uVar21 = (uVar9 >> uVar21 | uVar9 << 0x20 - uVar21) + uVar14;
    uVar9 = (uVar8 ^ uVar23 ^ uVar19) + uVar12 + local_a8[*piVar18];
    uVar12 = 0x20U - *piVar25 & 0x1f;
    uVar20 = (uVar9 >> uVar12 | uVar9 << 0x20 - uVar12) + uVar16;
    piVar10 = piVar10 + 1;
    piVar11 = piVar11 + 1;
    piVar18 = piVar18 + 1;
    piVar25 = piVar25 + 1;
    uVar9 = uVar14;
    uVar14 = uVar22;
    uVar22 = uVar17 >> 0x16 | uVar17 << 10;
    uVar12 = uVar16;
    uVar16 = uVar19;
    uVar19 = uVar8 >> 0x16 | uVar8 << 10;
    uVar8 = uVar23;
    uVar23 = uVar20;
    uVar17 = uVar24;
    uVar24 = uVar21;
  }
  param_1[1] = uVar16 + uVar22 + uVar4;
  param_1[2] = uVar12 + uVar14 + uVar3;
  param_1[3] = uVar23 + uVar9 + uVar5;
  param_1[4] = uVar8 + uVar24 + uVar6;
  *param_1 = uVar19 + uVar17 + uVar2;
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


