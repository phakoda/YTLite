/* Decompiled from supplied 5.2.2 arm package. VA 0x255780. _av_get_channel_layout */

ulong _av_get_channel_layout(char *param_1)

{
  char *pcVar1;
  ulong *puVar2;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  int *piVar6;
  ulong uVar7;
  char *pcVar8;
  char *pcVar9;
  ulong *puVar10;
  char *pcVar11;
  ulong uVar12;
  undefined **ppuVar13;
  char *local_68;
  
  sVar4 = _strlen(param_1);
  uVar7 = 0;
  pcVar1 = param_1 + sVar4;
LAB_002557c4:
  pcVar11 = param_1;
  if (pcVar1 <= param_1) {
    return uVar7;
  }
  for (; ((pcVar11 < pcVar1 && (*pcVar11 != '+')) && (*pcVar11 != '|')); pcVar11 = pcVar11 + 1) {
  }
  pcVar8 = (char *)(long)((int)pcVar11 - (int)param_1);
  uVar12 = 0xffffffffffffffff;
  puVar2 = &DAT_01063768;
  do {
    puVar10 = puVar2;
    uVar12 = uVar12 + 1;
    if (0x1b < uVar12) {
      uVar12 = 0;
      ppuVar13 = &PTR_s_FL_010639f8;
      goto LAB_00255864;
    }
    pcVar9 = (char *)puVar10[-2];
    pcVar5 = (char *)_strlen(pcVar9);
    puVar2 = puVar10 + 3;
  } while ((pcVar5 != pcVar8) || (iVar3 = _memcmp(pcVar9,param_1,(size_t)pcVar8), iVar3 != 0));
  uVar12 = *puVar10;
  goto LAB_00255844;
LAB_00255864:
  if (0x23 < uVar12) goto LAB_002558ac;
  if (10 < uVar12 - 0x12) {
    pcVar9 = *ppuVar13;
    pcVar5 = (char *)_strlen(pcVar9);
    if ((pcVar5 == pcVar8) && (iVar3 = _memcmp(pcVar9,param_1,(size_t)pcVar8), iVar3 == 0)) {
      uVar12 = 1L << (uVar12 & 0x3f);
      goto LAB_002557bc;
    }
  }
  ppuVar13 = ppuVar13 + 2;
  uVar12 = uVar12 + 1;
  goto LAB_00255864;
LAB_002558ac:
  piVar6 = ___error();
  *piVar6 = 0;
  uVar12 = _strtol(param_1,&local_68,10);
  piVar6 = ___error();
  if (((*piVar6 == 0) && (local_68 + (1 - (long)param_1) == pcVar8)) && (*local_68 == 'c')) {
    uVar12 = _av_get_default_channel_layout(uVar12 & 0xffffffff);
LAB_00255844:
    if (uVar12 != 0) {
LAB_002557bc:
      uVar7 = uVar12 | uVar7;
      param_1 = pcVar11 + 1;
      goto LAB_002557c4;
    }
  }
  else {
    piVar6 = ___error();
    *piVar6 = 0;
    uVar12 = _strtoll(param_1,&local_68,0);
    piVar6 = ___error();
    if ((*piVar6 == 0) && (0 < (long)uVar12 && local_68 + -(long)param_1 == pcVar8))
    goto LAB_002557bc;
  }
  return 0;
}


