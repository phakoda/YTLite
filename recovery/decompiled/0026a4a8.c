/* Decompiled from supplied 5.2.2 arm package. VA 0x26a4a8. FUN_0026a4a8 */

void FUN_0026a4a8(uint *param_1,long param_2)

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
  uint uVar15;
  long lVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  long lVar21;
  uint uVar22;
  uint uVar23;
  long lVar24;
  uint uVar25;
  long lVar26;
  int local_a8 [16];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  uVar3 = *param_1;
  uVar4 = param_1[1];
  uVar5 = param_1[2];
  uVar6 = param_1[3];
  uVar7 = param_1[4];
  uVar8 = param_1[5];
  uVar9 = param_1[6];
  uVar10 = param_1[7];
  for (lVar16 = 0; lVar16 != 0x40; lVar16 = lVar16 + 4) {
    *(undefined4 *)((long)local_a8 + lVar16) = *(undefined4 *)(param_2 + lVar16);
  }
  uVar17 = uVar6;
  uVar19 = uVar7;
  uVar22 = uVar8;
  uVar23 = uVar9;
  uVar15 = uVar3;
  uVar20 = uVar5;
  uVar18 = uVar4;
  uVar13 = uVar10;
  for (lVar16 = 0; uVar14 = uVar23, uVar23 = uVar22, uVar25 = uVar17, lVar16 != 0x40;
      lVar16 = lVar16 + 4) {
    uVar1 = (uVar20 ^ uVar25 ^ uVar18) + uVar15 + local_a8[*(int *)((long)&DAT_00c51424 + lVar16)];
    uVar2 = 0x20U - *(int *)((long)&DAT_00c51564 + lVar16) & 0x1f;
    uVar15 = uVar19 + ((uVar14 ^ uVar23) & uVar13 ^ uVar14) +
             local_a8[*(int *)((long)&DAT_00c516a4 + lVar16)] + 0x50a28be6;
    uVar22 = 0x20U - *(int *)((long)&DAT_00c517e4 + lVar16) & 0x1f;
    uVar17 = uVar20;
    uVar19 = uVar13;
    uVar22 = uVar15 >> uVar22 | uVar15 << 0x20 - uVar22;
    uVar15 = uVar25;
    uVar20 = uVar18;
    uVar18 = uVar1 >> uVar2 | uVar1 << 0x20 - uVar2;
    uVar13 = uVar14;
  }
  lVar26 = 0;
  for (lVar16 = 0; uVar22 = uVar14, uVar14 = uVar23, uVar17 = uVar20, uVar20 = uVar18,
      lVar16 + 0x10 < 0x20; lVar16 = lVar16 + 1) {
    uVar18 = uVar19 + ((uVar17 ^ uVar25) & uVar20 ^ uVar25) +
             local_a8[*(int *)((long)&DAT_00c51464 + lVar26)] + 0x5a827999;
    uVar15 = uVar15 + ((uVar14 | uVar22 ^ 0xffffffff) ^ uVar13) +
             local_a8[*(int *)((long)&DAT_00c516e4 + lVar26)] + 0x5c4dd124;
    uVar19 = 0x20U - *(int *)((long)&DAT_00c515a4 + lVar26) & 0x1f;
    uVar23 = 0x20U - *(int *)((long)&DAT_00c51824 + lVar26) & 0x1f;
    lVar26 = lVar26 + 4;
    uVar18 = uVar18 >> uVar19 | uVar18 << 0x20 - uVar19;
    uVar19 = uVar25;
    uVar23 = uVar15 >> uVar23 | uVar15 << 0x20 - uVar23;
    uVar25 = uVar17;
    uVar15 = uVar13;
    uVar13 = uVar22;
  }
  for (lVar24 = 0; uVar18 = uVar17, uVar23 = uVar20, lVar21 = lVar16 + lVar24, lVar21 + 0x10 < 0x30;
      lVar24 = lVar24 + 1) {
    uVar1 = uVar19 + ((uVar14 | uVar18 ^ 0xffffffff) ^ uVar25) +
            local_a8[*(int *)((long)&DAT_00c51464 + lVar24 * 4 + lVar26)] + 0x6ed9eba1;
    uVar15 = uVar15 + ((uVar13 ^ uVar22) & uVar23 ^ uVar13) +
             local_a8[*(int *)((long)&DAT_00c516e4 + lVar24 * 4 + lVar26)] + 0x6d703ef3;
    uVar2 = 0x20U - *(int *)((long)&DAT_00c515a4 + lVar24 * 4 + lVar26) & 0x1f;
    uVar20 = 0x20U - *(int *)((long)&DAT_00c51824 + lVar24 * 4 + lVar26) & 0x1f;
    uVar20 = uVar15 >> uVar20 | uVar15 << 0x20 - uVar20;
    uVar17 = uVar14;
    uVar19 = uVar25;
    uVar25 = uVar18;
    uVar15 = uVar13;
    uVar13 = uVar22;
    uVar22 = uVar23;
    uVar14 = uVar1 >> uVar2 | uVar1 << 0x20 - uVar2;
  }
  for (; uVar17 = uVar22, uVar20 = uVar18, lVar21 + 0x10 < 0x40; lVar21 = lVar21 + 1) {
    uVar1 = (uVar20 ^ uVar23 ^ uVar13) + uVar15 + local_a8[(int)(&DAT_00c516e4)[lVar21]];
    uVar2 = uVar19 + ((uVar14 ^ uVar17) & uVar25 ^ uVar17) + local_a8[(int)(&DAT_00c51464)[lVar21]]
            + 0x8f1bbcdc;
    uVar11 = 0x20 - (&DAT_00c515a4)[lVar21] & 0x1f;
    uVar12 = 0x20 - (&DAT_00c51824)[lVar21] & 0x1f;
    uVar18 = uVar23;
    uVar19 = uVar25;
    uVar15 = uVar13;
    uVar13 = uVar20;
    uVar22 = uVar14;
    uVar25 = uVar17;
    uVar14 = uVar2 >> uVar11 | uVar2 << 0x20 - uVar11;
    uVar23 = uVar1 >> uVar12 | uVar1 << 0x20 - uVar12;
  }
  *param_1 = uVar3 + uVar19;
  param_1[1] = uVar4 + uVar14;
  param_1[2] = uVar5 + uVar17;
  param_1[3] = uVar6 + uVar13;
  param_1[4] = uVar7 + uVar15;
  param_1[5] = uVar8 + uVar23;
  param_1[6] = uVar9 + uVar20;
  param_1[7] = uVar10 + uVar25;
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


