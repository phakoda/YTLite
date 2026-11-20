/* Decompiled from supplied 5.2.2 arm package. VA 0x27c7a8. FUN_0027c7a8 */

undefined8 FUN_0027c7a8(long param_1,undefined8 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  char *pcVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  
  lVar9 = *(long *)(param_1 + 0x48);
  lVar5 = *(long *)(lVar9 + 0x30);
  iVar1 = 0;
  if (param_4 != 0) {
    iVar1 = (*(int *)(lVar5 + 0x1bc) * param_3) / param_4;
  }
  iVar2 = 0;
  if (param_4 != 0) {
    iVar2 = (*(int *)(lVar5 + 0x1bc) * (param_3 + 1)) / param_4;
  }
  for (lVar12 = (long)iVar1; lVar12 < iVar2; lVar12 = lVar12 + 1) {
    lVar6 = *(long *)(*(long *)(lVar5 + 0x60) + lVar12 * 8);
    lVar8 = *(long *)(lVar9 + 0x28) + lVar12 * 0x2640;
    for (lVar16 = 0; lVar16 < *(int *)(lVar5 + 0x70); lVar16 = lVar16 + 1) {
      uVar18 = *(undefined8 *)(lVar6 + lVar16 * 8);
      uVar7 = (ulong)*(uint *)(param_1 + 0x40);
      uVar14 = 0;
      lVar10 = lVar8;
      pcVar13 = "/usr/lib/libSystem.B.dylib" + lVar8 + 0x10;
      while (uVar14 < uVar7) {
        lVar15 = *(long *)(*(long *)(*(long *)(lVar9 + uVar14 * 8 + 0x38) + 0x60) + lVar12 * 8);
        uVar14 = uVar14 + 1;
        lVar11 = -1;
        lVar3 = lVar10;
        uVar17 = uVar18;
        while ((uVar14 < uVar7 && (lVar11 = lVar11 + 1, lVar11 < *(int *)(lVar9 + 0x14)))) {
          uVar17 = FUN_0027c940(uVar17,lVar3);
          uVar7 = (ulong)*(uint *)(param_1 + 0x40);
          lVar3 = lVar3 + 0x48;
        }
        lVar11 = -1;
        pcVar4 = pcVar13;
        while ((uVar14 < uVar7 && (lVar11 = lVar11 + 1, lVar11 < *(int *)(lVar9 + 0x14)))) {
          uVar18 = FUN_0027c940(uVar18,pcVar4);
          uVar7 = (ulong)*(uint *)(param_1 + 0x40);
          pcVar4 = pcVar4 + 0x48;
        }
        *(undefined8 *)(lVar15 + lVar16 * 8) = uVar17;
        lVar10 = lVar10 + 0x120;
        pcVar13 = pcVar13 + 0x120;
      }
    }
  }
  return 0;
}


