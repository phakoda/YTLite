/* Decompiled from supplied 5.2.2 arm package. VA 0x26172c. FUN_0026172c */

void FUN_0026172c(uint *param_1,long param_2,int param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  int iVar11;
  uint uVar12;
  
  lVar9 = 0;
  do {
    if (param_3 <= lVar9) {
      return;
    }
    uVar10 = 0;
    lVar1 = param_2 + (long)((int)lVar9 << 4) * 4;
    uVar7 = 1;
    uVar8 = 5;
    uVar12 = param_1[2];
    uVar4 = param_1[1];
    uVar5 = *param_1;
    uVar2 = param_1[3];
    for (uVar6 = 0; uVar3 = uVar5, uVar5 = uVar4, uVar4 = uVar12, uVar6 != 0x40; uVar6 = uVar6 + 1)
    {
      if ((long)uVar6 < 0x20) {
        if ((long)uVar6 < 0x10) {
          iVar11 = *(int *)(lVar1 + (uVar6 & 0xf) * 4);
          uVar12 = (uVar3 ^ uVar5) & uVar4;
LAB_0026183c:
          uVar12 = uVar12 ^ uVar3;
        }
        else {
          iVar11 = *(int *)(lVar1 + (uVar7 & 0xf) * 4);
          uVar12 = uVar3 & uVar4 | uVar5 & (uVar3 ^ 0xffffffff);
        }
      }
      else {
        if ((long)uVar6 < 0x30) {
          iVar11 = *(int *)(lVar1 + (uVar8 & 0xf) * 4);
          uVar12 = uVar5 ^ uVar4;
          goto LAB_0026183c;
        }
        iVar11 = *(int *)(lVar1 + (uVar10 & 0xf) * 4);
        uVar12 = (uVar4 | uVar3 ^ 0xffffffff) ^ uVar5;
      }
      uVar2 = (&DAT_00c510c4)[uVar6] + uVar2 + iVar11 + uVar12;
      uVar10 = uVar10 + 7;
      uVar8 = uVar8 + 3;
      uVar12 = 0x20 - (byte)(&DAT_00c510b4)[(uVar6 & 3) + (long)((int)uVar6 >> 4) * 4] & 0x1f;
      uVar7 = uVar7 + 5;
      uVar12 = (uVar2 >> uVar12 | uVar2 << 0x20 - uVar12) + uVar4;
      uVar2 = uVar3;
    }
    *param_1 = *param_1 + uVar3;
    param_1[1] = param_1[1] + uVar5;
    param_1[2] = param_1[2] + uVar4;
    param_1[3] = param_1[3] + uVar2;
    lVar9 = lVar9 + 1;
  } while( true );
}


