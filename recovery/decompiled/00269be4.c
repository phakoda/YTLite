/* Decompiled from supplied 5.2.2 arm package. VA 0x269be4. FUN_00269be4 */

void FUN_00269be4(uint *param_1,long param_2)

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
  long lVar13;
  uint uVar14;
  long lVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  long lVar20;
  long lVar21;
  int local_a8 [16];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar3 = *param_1;
  uVar4 = param_1[1];
  uVar5 = param_1[2];
  uVar6 = param_1[3];
  for (lVar15 = 0; lVar15 != 0x40; lVar15 = lVar15 + 4) {
    *(undefined4 *)((long)local_a8 + lVar15) = *(undefined4 *)(param_2 + lVar15);
  }
  uVar11 = uVar4;
  uVar19 = uVar5;
  uVar1 = uVar3;
  uVar12 = uVar4;
  uVar17 = uVar6;
  uVar10 = uVar3;
  uVar16 = uVar5;
  uVar9 = uVar6;
  for (lVar15 = 0; uVar14 = uVar16, uVar16 = uVar12, uVar18 = uVar19, uVar19 = uVar11,
      lVar15 != 0x40; lVar15 = lVar15 + 4) {
    uVar1 = (uVar18 ^ uVar19 ^ uVar17) + uVar1 + local_a8[*(int *)((long)&DAT_00c51424 + lVar15)];
    uVar11 = 0x20U - *(int *)((long)&DAT_00c51564 + lVar15) & 0x1f;
    uVar12 = uVar10 + ((uVar14 ^ uVar16) & uVar9 ^ uVar14) +
             local_a8[*(int *)((long)&DAT_00c516a4 + lVar15)] + 0x50a28be6;
    uVar10 = 0x20U - *(int *)((long)&DAT_00c517e4 + lVar15) & 0x1f;
    uVar11 = uVar1 >> uVar11 | uVar1 << 0x20 - uVar11;
    uVar1 = uVar17;
    uVar12 = uVar12 >> uVar10 | uVar12 << 0x20 - uVar10;
    uVar17 = uVar18;
    uVar10 = uVar9;
    uVar9 = uVar14;
  }
  lVar20 = 0;
  for (lVar15 = 0; uVar11 = uVar14, uVar14 = uVar16, uVar16 = uVar17, uVar12 = uVar19,
      lVar15 + 0x10 < 0x20; lVar15 = lVar15 + 1) {
    uVar1 = uVar1 + ((uVar16 ^ uVar18) & uVar12 ^ uVar16) +
            local_a8[*(int *)((long)&DAT_00c51464 + lVar20)] + 0x5a827999;
    uVar2 = uVar10 + ((uVar14 | uVar11 ^ 0xffffffff) ^ uVar9) +
            local_a8[*(int *)((long)&DAT_00c516e4 + lVar20)] + 0x5c4dd124;
    uVar17 = 0x20U - *(int *)((long)&DAT_00c515a4 + lVar20) & 0x1f;
    uVar7 = 0x20U - *(int *)((long)&DAT_00c51824 + lVar20) & 0x1f;
    lVar20 = lVar20 + 4;
    uVar19 = uVar1 >> uVar17 | uVar1 << 0x20 - uVar17;
    uVar17 = uVar18;
    uVar1 = uVar16;
    uVar10 = uVar9;
    uVar16 = uVar2 >> uVar7 | uVar2 << 0x20 - uVar7;
    uVar9 = uVar11;
    uVar18 = uVar12;
  }
  for (lVar21 = 0; uVar19 = uVar11, uVar11 = uVar14, uVar17 = uVar16, lVar13 = lVar15 + lVar21,
      lVar13 + 0x10 < 0x30; lVar21 = lVar21 + 1) {
    uVar2 = uVar1 + ((uVar12 | uVar18 ^ 0xffffffff) ^ uVar17) +
            local_a8[*(int *)((long)&DAT_00c51464 + lVar21 * 4 + lVar20)] + 0x6ed9eba1;
    uVar14 = uVar10 + ((uVar9 ^ uVar19) & uVar11 ^ uVar9) +
             local_a8[*(int *)((long)&DAT_00c516e4 + lVar21 * 4 + lVar20)] + 0x6d703ef3;
    uVar7 = 0x20U - *(int *)((long)&DAT_00c515a4 + lVar21 * 4 + lVar20) & 0x1f;
    uVar8 = 0x20U - *(int *)((long)&DAT_00c51824 + lVar21 * 4 + lVar20) & 0x1f;
    uVar16 = uVar18;
    uVar1 = uVar17;
    uVar10 = uVar9;
    uVar14 = uVar14 >> uVar8 | uVar14 << 0x20 - uVar8;
    uVar9 = uVar19;
    uVar18 = uVar12;
    uVar12 = uVar2 >> uVar7 | uVar2 << 0x20 - uVar7;
  }
  for (; uVar16 = uVar17, lVar13 + 0x10 < 0x40; lVar13 = lVar13 + 1) {
    uVar14 = (uVar19 ^ uVar11 ^ uVar9) + uVar10 + local_a8[(int)(&DAT_00c516e4)[lVar13]];
    uVar2 = uVar1 + ((uVar18 ^ uVar12) & uVar16 ^ uVar18) + local_a8[(int)(&DAT_00c51464)[lVar13]] +
            0x8f1bbcdc;
    uVar7 = 0x20 - (&DAT_00c51824)[lVar13] & 0x1f;
    uVar8 = 0x20 - (&DAT_00c515a4)[lVar13] & 0x1f;
    uVar17 = uVar18;
    uVar1 = uVar16;
    uVar10 = uVar9;
    uVar9 = uVar19;
    uVar19 = uVar11;
    uVar11 = uVar14 >> uVar7 | uVar14 << 0x20 - uVar7;
    uVar18 = uVar12;
    uVar12 = uVar2 >> uVar8 | uVar2 << 0x20 - uVar8;
  }
  param_1[1] = uVar10 + uVar16 + uVar5;
  param_1[2] = uVar11 + uVar1 + uVar6;
  param_1[3] = uVar19 + uVar12 + uVar3;
  *param_1 = uVar9 + uVar18 + uVar4;
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


