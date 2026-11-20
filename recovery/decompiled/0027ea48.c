/* Decompiled from supplied 5.2.2 arm package. VA 0x27ea48. FUN_0027ea48 */

/* WARNING: Removing unreachable block (ram,0x0027eb44) */

undefined8 FUN_0027ea48(long param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  char *pcVar7;
  code *pcVar8;
  int *piVar9;
  int *piVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  int iVar14;
  long lVar15;
  long lVar16;
  float local_7c;
  undefined8 local_78;
  
  lVar12 = *(long *)(param_1 + 0x10);
  lVar13 = *(long *)(lVar12 + 0x48);
  local_78 = 0;
  lVar4 = _av_calloc((long)*(int *)(param_1 + 0xc4),0x18);
  *(long *)(lVar13 + 0x18) = lVar4;
  if (lVar4 == 0) {
LAB_0027ecb4:
    uVar5 = 0xfffffff4;
  }
  else {
    *(undefined4 *)(lVar13 + 0x20) = *(undefined4 *)(param_1 + 0xc4);
    uVar2 = _av_get_bytes_per_sample(*(undefined4 *)(param_1 + 0x44));
    lVar16 = 0;
    *(undefined4 *)(lVar13 + 0x24) = uVar2;
    fVar1 = DAT_00c537e8;
    uVar5 = *(undefined8 *)(lVar13 + 0x10);
    lVar15 = -0x100000000;
    for (lVar4 = 0; lVar4 < *(int *)(lVar13 + 0x20); lVar4 = lVar4 + 1) {
      lVar11 = *(long *)(lVar13 + 0x18);
      lVar6 = _av_strtok(uVar5,"|",&local_78);
      if (lVar6 == 0) break;
      _av_sscanf(lVar6,"%d%c");
      iVar3 = _av_sscanf(lVar6,"%f");
      if (iVar3 != 1) {
        pcVar7 = "Invalid syntax for delay.\n";
LAB_0027ecfc:
        _av_log(lVar12,0x10,pcVar7);
        return 0xffffffea;
      }
      iVar3 = (int)((local_7c * (float)*(int *)(param_1 + 0x40)) / fVar1);
      *(int *)(lVar11 + lVar16) = iVar3;
      if (iVar3 < 0) {
        pcVar7 = "Delay must be non negative number.\n";
        goto LAB_0027ecfc;
      }
      uVar5 = 0;
      lVar15 = lVar15 + 0x100000000;
      lVar16 = lVar16 + 0x18;
    }
    lVar12 = *(long *)(lVar13 + 0x20);
    iVar14 = (int)lVar4;
    iVar3 = (int)lVar12;
    if ((iVar14 != 0) && (*(int *)(lVar13 + 8) != 0)) {
      lVar4 = (long)iVar14 + -1;
      lVar16 = (long)iVar14 * 0x18;
      while (lVar4 = lVar4 + 1, lVar4 < iVar3) {
        *(undefined4 *)(*(long *)(lVar13 + 0x18) + lVar16) =
             *(undefined4 *)(*(long *)(lVar13 + 0x18) + (lVar15 >> 0x20) * 0x18);
        lVar16 = lVar16 + 0x18;
      }
    }
    piVar9 = *(int **)(lVar13 + 0x18);
    iVar14 = *piVar9;
    lVar4 = 0;
    *(long *)(lVar13 + 0x28) = (long)iVar14;
    lVar16 = (long)iVar14;
    piVar10 = piVar9;
    while( true ) {
      piVar10 = piVar10 + 6;
      lVar4 = lVar4 + 1;
      if (iVar3 <= lVar4) break;
      lVar15 = (long)*piVar10;
      if (lVar16 <= *piVar10) {
        lVar15 = lVar16;
      }
      *(long *)(lVar13 + 0x28) = lVar15;
      lVar16 = lVar15;
    }
    if (lVar16 != 0) {
      lVar4 = -1;
      while (lVar4 = lVar4 + 1, lVar4 < iVar3) {
        *piVar9 = *piVar9 - (int)lVar16;
        piVar9 = piVar9 + 6;
      }
    }
    lVar4 = 0;
    lVar16 = -1;
    while (lVar16 = lVar16 + 1, lVar16 < (int)lVar12) {
      lVar15 = *(long *)(lVar13 + 0x18);
      if (*(int *)(lVar15 + lVar4) != 0) {
        lVar12 = _av_malloc_array((long)*(int *)(lVar15 + lVar4),lVar12 >> 0x20);
        *(long *)(lVar15 + lVar4 + 0x10) = lVar12;
        if (lVar12 == 0) goto LAB_0027ecb4;
        lVar12 = *(long *)(lVar13 + 0x30);
        if (*(long *)(lVar13 + 0x30) <= (long)*(int *)(lVar15 + lVar4)) {
          lVar12 = (long)*(int *)(lVar15 + lVar4);
        }
        *(long *)(lVar13 + 0x30) = lVar12;
      }
      lVar4 = lVar4 + 0x18;
      lVar12 = *(long *)(lVar13 + 0x20);
    }
    switch(*(undefined4 *)(param_1 + 0x44)) {
    case 5:
      pcVar8 = FUN_0027ed90;
      break;
    case 6:
      pcVar8 = FUN_0027ee68;
      break;
    case 7:
      pcVar8 = FUN_0027ef30;
      break;
    case 8:
      pcVar8 = FUN_0027f004;
      break;
    case 9:
      pcVar8 = FUN_0027f0cc;
      break;
    default:
      return 0;
    }
    uVar5 = 0;
    *(code **)(lVar13 + 0x48) = pcVar8;
  }
  return uVar5;
}


