/* Decompiled from supplied 5.2.2 arm package. VA 0x26b6e8. FUN_0026b6e8 */

void FUN_0026b6e8(uint *param_1,uint *param_2)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  int iVar15;
  long lVar16;
  uint uVar17;
  uint local_198 [80];
  long local_58;
  
  lVar14 = *(long *)PTR____stack_chk_guard_01060708;
  lVar16 = -0x50;
  local_58 = lVar14;
  uVar2 = *param_1;
  uVar4 = param_1[1];
  uVar3 = param_1[2];
  uVar5 = param_1[3];
  uVar6 = param_1[4];
  puVar11 = local_198;
  uVar7 = uVar3;
  uVar17 = uVar2;
  uVar13 = uVar4;
  uVar9 = uVar5;
  uVar10 = uVar6;
  while( true ) {
    uVar12 = uVar9;
    uVar8 = uVar17;
    uVar9 = uVar7;
    if (lVar16 == 0) break;
    uVar1 = lVar16 + 0x50;
    if (uVar1 < 0x10) {
      uVar7 = (*param_2 & 0xff00ff00) >> 8 | (*param_2 & 0xff00ff) << 8;
      uVar17 = uVar7 >> 0x10 | uVar7 << 0x10;
    }
    else {
      iVar15 = (int)lVar16;
      uVar7 = local_198[iVar15 + 0x48] ^ local_198[iVar15 + 0x4d] ^ local_198[iVar15 + 0x42] ^
              local_198[iVar15 + 0x40];
      uVar17 = uVar7 >> 0x1f | uVar7 << 1;
    }
    *puVar11 = uVar17;
    if (uVar1 < 0x28) {
      if (uVar1 < 0x14) {
        iVar15 = ((uVar12 ^ uVar9) & uVar13 ^ uVar12) + 0x5a827999;
      }
      else {
        iVar15 = (uVar9 ^ uVar13 ^ uVar12) + 0x6ed9eba1;
      }
    }
    else if (uVar1 < 0x3c) {
      iVar15 = ((uVar9 | uVar13) & uVar12 | uVar9 & uVar13) + 0x8f1bbcdc;
    }
    else {
      iVar15 = (uVar9 ^ uVar13 ^ uVar12) + 0xca62c1d6;
    }
    lVar16 = lVar16 + 1;
    puVar11 = puVar11 + 1;
    param_2 = param_2 + 1;
    uVar7 = uVar13 >> 2 | uVar13 << 0x1e;
    uVar17 = uVar10 + (uVar8 >> 0x1b | uVar8 << 5) + uVar17 + iVar15;
    uVar13 = uVar8;
    uVar10 = uVar12;
  }
  *param_1 = uVar2 + uVar8;
  param_1[1] = uVar4 + uVar13;
  param_1[2] = uVar3 + uVar9;
  param_1[3] = uVar5 + uVar12;
  param_1[4] = uVar6 + uVar10;
  if (lVar14 == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


