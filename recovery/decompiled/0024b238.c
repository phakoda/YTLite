/* Decompiled from supplied 5.2.2 arm package. VA 0x24b238. FUN_0024b238 */

void FUN_0024b238(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  long lVar9;
  short *psVar10;
  int iVar11;
  uint uVar12;
  ulong uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  undefined8 uVar18;
  short local_80 [6];
  short local_74 [6];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_80[0] = 0x400;
  local_74[0] = 0x400;
  psVar10 = (short *)(param_1 + 0x14);
  for (lVar9 = 0; (int)lVar9 != 10; lVar9 = lVar9 + 2) {
    sVar3 = *psVar10;
    sVar2 = *(short *)((long)local_80 + lVar9);
    iVar11 = (int)*(short *)(param_1 + 2 + lVar9);
    *(short *)((long)local_74 + lVar9 + 2) =
         *(short *)((long)local_74 + lVar9) + (short)((uint)(iVar11 - sVar3) >> 2);
    *(short *)((long)local_80 + lVar9 + 2) = (short)((uint)(sVar3 + iVar11) >> 2) - sVar2;
    psVar10 = psVar10 + -1;
  }
  uVar16 = (uint)DAT_00c4f21c;
  uVar6 = FUN_00246dec((long)(short)DAT_00c4f21c,local_80);
  iVar11 = 0;
  uVar13 = 0;
  for (lVar9 = 1; lVar9 < 0x3c && iVar11 < 10; lVar9 = lVar9 + 1) {
    uVar4 = (&DAT_00c4f21c)[lVar9];
    uVar7 = FUN_00246dec((long)(short)uVar4,local_80 + (long)(int)(uint)uVar13 * 6);
    uVar12 = (uint)uVar4;
    if ((int)(uVar7 * (int)(short)uVar6) < 1) {
      iVar15 = 5;
      while( true ) {
        uVar14 = uVar6;
        uVar17 = uVar16;
        sVar2 = (short)uVar12;
        iVar15 = iVar15 + -1;
        sVar3 = (short)uVar7;
        sVar8 = (short)uVar17;
        if (iVar15 == 0) break;
        uVar1 = ((uint)(int)sVar8 >> 1) + ((uint)(int)sVar2 >> 1);
        uVar6 = FUN_00246dec((int)(short)uVar1,local_80 + (long)(int)(uint)uVar13 * 6);
        uVar16 = uVar1;
        if (0 < (int)(uVar6 * (int)sVar3)) {
          uVar16 = uVar17;
          uVar12 = uVar1;
          uVar7 = uVar6;
          uVar6 = uVar14;
        }
      }
      uVar16 = (uVar14 & 0xffff) - (int)sVar3;
      uVar6 = uVar12;
      if ((uVar16 & 0xffff) != 0) {
        uVar4 = -(ushort)uVar16;
        if (-0x10000 < (int)(uVar16 * 0x10000)) {
          uVar4 = (ushort)uVar16;
        }
        if (uVar4 == 0) {
          uVar6 = 0;
        }
        else {
          uVar14 = (int)(short)uVar4 ^ (int)((uint)uVar4 << 0x10) >> 0x1f;
          uVar6 = 0;
          if (uVar14 >> 0xf == 0) {
            uVar6 = 0x10;
          }
          uVar17 = uVar6 | 8;
          if ((0xff800000U >> (ulong)uVar6 & uVar14) != 0) {
            uVar17 = uVar6;
          }
          uVar1 = uVar17 | 4;
          if ((0xf8000000U >> (ulong)uVar17 & uVar14) != 0) {
            uVar1 = uVar17;
          }
          uVar6 = uVar1 | 2;
          if ((0xe0000000U >> (ulong)uVar1 & uVar14) != 0) {
            uVar6 = uVar1;
          }
          if ((0xc0000000U >> (ulong)(uint)(int)(short)uVar6 & uVar14) == 0) {
            uVar6 = (int)(short)uVar6 + 1;
          }
        }
        uVar6 = (int)(uVar6 * 0x10000 + -0x100000) >> 0x10;
        sVar5 = FUN_0024df78(0x1fff8000,(int)(short)((int)(short)uVar4 << (ulong)(uVar6 & 0x1f)));
        sVar8 = (short)((int)sVar5 * (int)(short)(sVar8 - sVar2) >> (0x13 - uVar6 & 0x1f));
        if ((int)(uVar16 * 0x10000) < 0) {
          sVar8 = -sVar8;
        }
        uVar6 = (int)sVar2 - ((uint)((int)sVar8 * (int)sVar3) >> 10);
      }
      *(short *)((long)param_2 + (long)iVar11 * 2) = (short)uVar6;
      iVar11 = iVar11 + 1;
      if (iVar11 < 10) {
        uVar13 = (ulong)(~(uint)uVar13 & 1);
        uVar7 = FUN_00246dec((int)(short)uVar6,local_80 + uVar13 * 6);
        uVar12 = uVar6;
      }
    }
    uVar16 = uVar12;
    uVar6 = uVar7;
  }
  if (iVar11 < 10) {
    *(undefined4 *)(param_2 + 2) = *(undefined4 *)(param_3 + 2);
    uVar18 = *param_3;
    param_2[1] = param_3[1];
    *param_2 = uVar18;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


