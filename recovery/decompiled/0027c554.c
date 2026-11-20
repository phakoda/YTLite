/* Decompiled from supplied 5.2.2 arm package. VA 0x27c554. FUN_0027c554 */

undefined8 FUN_0027c554(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  char *pcVar5;
  undefined4 uVar6;
  long lVar7;
  undefined *puVar8;
  undefined *puVar9;
  long lVar10;
  float fVar11;
  double dVar12;
  undefined8 uVar13;
  undefined8 unaff_d8;
  double dVar14;
  
  iVar1 = *(int *)(param_1 + 0x40);
  lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x48);
  lVar4 = _av_calloc((long)*(int *)(param_1 + 0xc4),&DAT_00002640);
  *(long *)(lVar7 + 0x28) = lVar4;
  if (lVar4 == 0) {
    return 0xfffffff4;
  }
  iVar2 = *(int *)(lVar7 + 0x10);
  if (iVar2 == 2) {
    uVar6 = 4;
    unaff_d8 = DAT_00c53778;
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 == 0) {
        *(undefined4 *)(lVar7 + 0x14) = 1;
        unaff_d8 = 0x3fe0000000000000;
      }
      goto LAB_0027c5ec;
    }
    uVar6 = 2;
    unaff_d8 = DAT_00c51e40;
  }
  *(undefined4 *)(lVar7 + 0x14) = uVar6;
LAB_0027c5ec:
  uVar3 = DAT_00c53780;
  puVar9 = (undefined *)0x0;
  dVar14 = (double)iVar1;
  for (lVar4 = 0; lVar4 < *(int *)(param_1 + 0xc4); lVar4 = lVar4 + 1) {
    puVar8 = puVar9;
    for (lVar10 = 0; lVar10 <= *(int *)(lVar7 + 0x18); lVar10 = lVar10 + 1) {
      FUN_0027c988((double)*(float *)(*(long *)(lVar7 + 0x20) + lVar10 * 4),unaff_d8,dVar14,
                   puVar8 + *(long *)(lVar7 + 0x28));
      FUN_0027ca0c((double)*(float *)(*(long *)(lVar7 + 0x20) + lVar10 * 4),unaff_d8,dVar14,
                   "/usr/lib/libSystem.B.dylib" + (long)(puVar8 + *(long *)(lVar7 + 0x28) + 0x10));
      dVar12 = (double)*(float *)(*(long *)(lVar7 + 0x20) + lVar10 * 4);
      if (*(int *)(lVar7 + 0x10) < 2) {
        FUN_0027c988(dVar12,unaff_d8,dVar14,puVar8 + *(long *)(lVar7 + 0x28) + 0x48);
        fVar11 = *(float *)(*(long *)(lVar7 + 0x20) + lVar10 * 4);
        pcVar5 = "/Library/Frameworks/CydiaSubstrate.framework/CydiaSubstrate" +
                 (long)(puVar8 + *(long *)(lVar7 + 0x28) + 0x20);
        uVar13 = unaff_d8;
      }
      else {
        FUN_0027c988(dVar12,uVar3,dVar14,puVar8 + *(long *)(lVar7 + 0x28) + 0x48);
        FUN_0027ca0c((double)*(float *)(*(long *)(lVar7 + 0x20) + lVar10 * 4),uVar3,dVar14,
                     "/Library/Frameworks/CydiaSubstrate.framework/CydiaSubstrate" +
                     (long)(puVar8 + *(long *)(lVar7 + 0x28) + 0x20));
        FUN_0027c988((double)*(float *)(*(long *)(lVar7 + 0x20) + lVar10 * 4),unaff_d8,dVar14,
                     puVar8 + *(long *)(lVar7 + 0x28) + 0x90);
        FUN_0027ca0c((double)*(float *)(*(long *)(lVar7 + 0x20) + lVar10 * 4),unaff_d8,dVar14,
                     "/System/Library/Frameworks/AuthenticationServices.framework/AuthenticationServices"
                     + (long)(puVar8 + *(long *)(lVar7 + 0x28) + 0x10));
        FUN_0027c988((double)*(float *)(*(long *)(lVar7 + 0x20) + lVar10 * 4),uVar3,dVar14,
                     puVar8 + *(long *)(lVar7 + 0x28) + 0xd8);
        fVar11 = *(float *)(*(long *)(lVar7 + 0x20) + lVar10 * 4);
        pcVar5 = (char *)((long)&dylib_command_000013f8.cmd +
                         (long)(puVar8 + *(long *)(lVar7 + 0x28)));
        uVar13 = uVar3;
      }
      FUN_0027ca0c((double)fVar11,uVar13,dVar14,pcVar5);
      puVar8 = puVar8 + 0x120;
    }
    puVar9 = &DAT_00002640 + (long)puVar9;
  }
  return 0;
}


