/* Decompiled from supplied 5.2.2 arm package. VA 0x269360. _av_reduce */

bool _av_reduce(int *param_1,undefined4 *param_2,ulong param_3,ulong param_4,long param_5)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  int iVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  long lVar17;
  
  uVar11 = -param_3;
  if (-1 < (long)param_3) {
    uVar11 = param_3;
  }
  uVar16 = -param_4;
  if (-1 < (long)param_4) {
    uVar16 = param_4;
  }
  lVar3 = _av_gcd(uVar11,uVar16);
  uVar5 = param_3;
  uVar13 = param_4;
  if (lVar3 != 0) {
    uVar5 = 0;
    if (lVar3 != 0) {
      uVar5 = (long)uVar11 / lVar3;
    }
    uVar13 = 0;
    if (lVar3 != 0) {
      uVar13 = (long)uVar16 / lVar3;
    }
  }
  uVar4 = 1;
  if ((long)uVar13 <= param_5 && (long)uVar5 <= param_5) {
    uVar4 = (uint)uVar5;
  }
  uVar11 = (ulong)uVar4;
  uVar4 = 0;
  if ((long)uVar13 <= param_5 && (long)uVar5 <= param_5) {
    uVar4 = (uint)uVar13;
  }
  uVar16 = (ulong)uVar4;
  if ((uVar13 == 0) || ((long)uVar13 <= param_5 && (long)uVar5 <= param_5)) {
    uVar14 = 0;
  }
  else {
    uVar7 = 1;
    uVar12 = uVar11;
    iVar9 = 0;
    do {
      uVar8 = uVar16 & 0xffffffff;
      iVar10 = (int)uVar12;
      uVar15 = 0;
      if (uVar13 != 0) {
        uVar15 = (long)uVar5 / (long)uVar13;
      }
      lVar3 = (long)iVar10;
      iVar6 = (int)uVar16;
      lVar17 = (long)iVar6;
      uVar11 = uVar15 * lVar3 + (long)iVar9;
      iVar2 = (int)uVar7;
      uVar16 = uVar15 * lVar17 + (long)iVar2;
      if (param_5 < (long)uVar11 || param_5 < (long)uVar16) {
        if (iVar10 != 0) {
          uVar15 = 0;
          if (lVar3 != 0) {
            uVar15 = (param_5 - iVar9) / lVar3;
          }
        }
        uVar16 = uVar15;
        if (iVar6 != 0) {
          uVar16 = 0;
          if (lVar17 != 0) {
            uVar16 = (param_5 - iVar2) / lVar17;
          }
          if (uVar15 <= uVar16) {
            uVar16 = uVar15;
          }
        }
        uVar11 = ((long)iVar2 + lVar17 * uVar16 * 2) * uVar13;
        uVar14 = uVar13;
        if (uVar11 < uVar5 * lVar17 || uVar11 - uVar5 * lVar17 == 0) {
          uVar11 = uVar12 & 0xffffffff;
          uVar16 = uVar8;
        }
        else {
          uVar11 = (ulong)(uint)(iVar9 + (int)uVar16 * iVar10);
          uVar16 = (ulong)(uint)(iVar2 + (int)uVar16 * iVar6);
        }
        break;
      }
      uVar14 = uVar5 - uVar15 * uVar13;
      bVar1 = uVar5 != uVar15 * uVar13;
      uVar5 = uVar13;
      uVar7 = uVar8;
      uVar12 = uVar11;
      uVar13 = uVar14;
      iVar9 = iVar10;
    } while (bVar1);
  }
  iVar9 = -(int)uVar11;
  if (-1 < (long)(param_4 ^ param_3)) {
    iVar9 = (int)uVar11;
  }
  *param_1 = iVar9;
  *param_2 = (int)uVar16;
  return uVar14 == 0;
}


