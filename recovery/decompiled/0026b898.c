/* Decompiled from supplied 5.2.2 arm package. VA 0x26b898. FUN_0026b898 */

void FUN_0026b898(uint *param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  long lVar19;
  ulong uVar20;
  uint uVar21;
  uint local_168 [64];
  long local_68;
  
  uVar20 = 0;
  lVar19 = *(long *)PTR____stack_chk_guard_01060708;
  local_68 = lVar19;
  uVar1 = *param_1;
  uVar5 = param_1[1];
  uVar2 = param_1[2];
  uVar6 = param_1[3];
  uVar3 = param_1[4];
  uVar7 = param_1[5];
  uVar4 = param_1[6];
  uVar8 = param_1[7];
  uVar10 = uVar1;
  uVar11 = uVar3;
  uVar15 = uVar5;
  uVar16 = uVar2;
  uVar13 = uVar6;
  uVar17 = uVar4;
  uVar21 = uVar8;
  uVar14 = uVar7;
  while( true ) {
    uVar18 = uVar17;
    uVar17 = uVar16;
    uVar16 = uVar15;
    uVar12 = uVar11;
    uVar15 = uVar10;
    if (uVar20 == 0x40) break;
    if (uVar20 < 0x10) {
      uVar10 = *(uint *)(param_2 + uVar20 * 4);
      uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
      uVar10 = uVar10 >> 0x10 | uVar10 << 0x10;
    }
    else {
      uVar10 = local_168[(int)uVar20 - 0xf];
      uVar11 = local_168[(int)(uVar20 + 0xfffffff9) + 5];
      uVar10 = local_168[uVar20 + 0xfffffff9 & 0xffffffff] + local_168[(int)uVar20 - 0x10] +
               ((uVar10 >> 0x12 | uVar10 << 0xe) ^ uVar10 >> 3 ^ (uVar10 >> 7 | uVar10 << 0x19)) +
               ((uVar11 >> 0x13 | uVar11 << 0xd) ^ uVar11 >> 10 ^ (uVar11 >> 0x11 | uVar11 << 0xf));
    }
    iVar9 = (&DAT_00c51a64)[uVar20];
    local_168[uVar20] = uVar10;
    iVar9 = ((uVar12 >> 6 | uVar12 << 0x1a) ^ (uVar12 >> 0xb | uVar12 << 0x15) ^
            (uVar12 >> 0x19 | uVar12 << 7)) + uVar21 + ((uVar18 ^ uVar14) & uVar12 ^ uVar18) +
            uVar10 + iVar9;
    uVar20 = uVar20 + 1;
    uVar10 = ((uVar17 | uVar16) & uVar15 | uVar17 & uVar16) +
             ((uVar15 >> 2 | uVar15 << 0x1e) ^ (uVar15 >> 0xd | uVar15 << 0x13) ^
             (uVar15 >> 0x16 | uVar15 << 10)) + iVar9;
    uVar11 = iVar9 + uVar13;
    uVar13 = uVar17;
    uVar17 = uVar14;
    uVar21 = uVar18;
    uVar14 = uVar12;
  }
  *param_1 = uVar1 + uVar15;
  param_1[1] = uVar5 + uVar16;
  param_1[2] = uVar2 + uVar17;
  param_1[3] = uVar6 + uVar13;
  param_1[4] = uVar3 + uVar12;
  param_1[5] = uVar7 + uVar14;
  param_1[6] = uVar4 + uVar18;
  param_1[7] = uVar8 + uVar21;
  if (lVar19 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


