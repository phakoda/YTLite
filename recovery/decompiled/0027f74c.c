/* Decompiled from supplied 5.2.2 arm package. VA 0x27f74c. FUN_0027f74c */

undefined8 FUN_0027f74c(long param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  float fVar12;
  int local_38;
  int local_34;
  
  lVar11 = *(long *)(param_1 + 0x48);
  pcVar8 = *(char **)(lVar11 + 0x10);
  if ((pcVar8 != (char *)0x0) && (pcVar6 = *(char **)(lVar11 + 0x18), pcVar6 != (char *)0x0)) {
    iVar7 = 1;
    local_34 = 1;
    do {
      if (*pcVar8 == '|') {
        iVar7 = iVar7 + 1;
        local_34 = iVar7;
      }
      else if (*pcVar8 == '\0') goto LAB_0027f7d4;
      pcVar8 = pcVar8 + 1;
    } while( true );
  }
  pcVar8 = "Missing delays and/or decays.\n";
  goto LAB_0027f7b4;
LAB_0027f7d4:
  iVar9 = 1;
  local_38 = 1;
  do {
    if (*pcVar6 == '|') {
      iVar9 = iVar9 + 1;
      local_38 = iVar9;
    }
    else if (*pcVar6 == '\0') break;
    pcVar6 = pcVar6 + 1;
  } while( true );
  uVar4 = _av_realloc_f(*(undefined8 *)(lVar11 + 0x20),(long)iVar7,4);
  *(undefined8 *)(lVar11 + 0x20) = uVar4;
  lVar5 = _av_realloc_f(*(undefined8 *)(lVar11 + 0x28),(long)iVar9,4);
  *(long *)(lVar11 + 0x28) = lVar5;
  if (lVar5 == 0) {
    return 0xfffffff4;
  }
  if (*(long *)(lVar11 + 0x20) == 0) {
    return 0xfffffff4;
  }
  FUN_0028022c(*(undefined8 *)(lVar11 + 0x10),&local_34);
  FUN_0028022c(*(undefined8 *)(lVar11 + 0x18),&local_38,*(undefined8 *)(lVar11 + 0x28));
  if (local_34 == local_38) {
    *(int *)(lVar11 + 0x30) = local_34;
    if (local_34 == 0) {
      pcVar8 = "At least one decay & delay must be set.\n";
    }
    else {
      lVar10 = (long)local_34;
      lVar5 = _av_realloc_f(*(undefined8 *)(lVar11 + 0x48),lVar10,4);
      *(long *)(lVar11 + 0x48) = lVar5;
      if (lVar5 == 0) {
        return 0xfffffff4;
      }
      lVar5 = 0;
      while( true ) {
        if (lVar10 <= lVar5) {
          *(undefined8 *)(lVar11 + 0x58) = 0x8000000000000000;
          _av_log(param_1,0x30,"nb_echoes:%d\n");
          return 0;
        }
        fVar12 = *(float *)(*(long *)(lVar11 + 0x20) + lVar5 * 4);
        if ((fVar12 <= 0.0) || (DAT_00c53824 < fVar12)) break;
        fVar12 = *(float *)(*(long *)(lVar11 + 0x28) + lVar5 * 4);
        bVar1 = false;
        bVar2 = false;
        bVar3 = false;
        if (0.0 < fVar12) {
          bVar1 = false;
          bVar2 = false;
          bVar3 = true;
          if (!NAN(fVar12)) {
            bVar1 = fVar12 < 1.0;
            bVar2 = fVar12 == 1.0;
            bVar3 = false;
          }
        }
        if (!bVar2 && bVar1 == bVar3) {
          pcVar8 = "decay[%d]: %f is out of allowed range: (0, 1]\n";
          goto LAB_0027f7b4;
        }
        lVar5 = lVar5 + 1;
      }
      pcVar8 = "delay[%d]: %f is out of allowed range: (0, 90000]\n";
    }
  }
  else {
    pcVar8 = "Number of delays %d differs from number of decays %d.\n";
  }
LAB_0027f7b4:
  _av_log(param_1,0x10,pcVar8);
  return 0xffffffea;
}


