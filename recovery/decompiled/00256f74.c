/* Decompiled from supplied 5.2.2 arm package. VA 0x256f74. _av_dict_set */

undefined8 _av_dict_set(undefined8 *param_1,void *param_2,char *param_3,uint param_4)

{
  undefined8 *puVar1;
  void *pvVar2;
  char *pcVar3;
  long lVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  int iVar8;
  int *piVar9;
  undefined8 *puVar10;
  char *pcVar11;
  undefined8 uVar12;
  char *local_68;
  void *local_60;
  char *local_58;
  
  puVar10 = (undefined8 *)0x0;
  piVar9 = (int *)*param_1;
  local_60 = (void *)0x0;
  local_58 = (char *)0x0;
  local_68 = (char *)0x0;
  if ((param_4 >> 6 & 1) == 0) {
    puVar10 = (undefined8 *)_av_dict_get(piVar9,param_2,0,param_4);
  }
  pvVar2 = param_2;
  if ((param_4 >> 2 & 1) == 0) {
    pvVar2 = (void *)_av_strdup(param_2);
  }
  pcVar3 = param_3;
  pcVar11 = param_3;
  local_60 = pvVar2;
  if ((param_4 >> 3 & 1) == 0) {
    if (pvVar2 == (void *)0x0) {
      pcVar3 = (char *)0x0;
      pcVar11 = local_68;
    }
    else {
      pcVar3 = (char *)_av_strdup(param_3);
      pcVar11 = pcVar3;
    }
  }
  local_68 = pcVar11;
  if (piVar9 == (int *)0x0) {
    piVar9 = (int *)_av_mallocz(0x10);
    *param_1 = piVar9;
    if (piVar9 == (int *)0x0) goto LAB_0025718c;
  }
  if (((param_2 == (void *)0x0) || (pcVar11 = pcVar3, pvVar2 != (void *)0x0)) &&
     ((param_3 == (char *)0x0 || (pcVar11 = (char *)0x0, pcVar3 != (char *)0x0)))) {
    if (puVar10 == (undefined8 *)0x0) {
      if (pcVar3 != (char *)0x0) {
        lVar4 = _av_realloc_array(*(undefined8 *)(piVar9 + 2),(long)*piVar9 + 1,0x10);
        pcVar11 = pcVar3;
        if (lVar4 == 0) goto LAB_00257174;
        *(long *)(piVar9 + 2) = lVar4;
      }
    }
    else {
      if ((param_4 >> 4 & 1) != 0) {
        _av_free(pvVar2);
        _av_free(pcVar3);
        return 0;
      }
      pcVar3 = (char *)puVar10[1];
      if ((param_4 >> 5 & 1) == 0) {
        _av_free((char *)puVar10[1]);
        pcVar3 = local_58;
      }
      local_58 = pcVar3;
      _av_free((void *)*puVar10);
      iVar8 = *piVar9;
      *piVar9 = (int)((long)iVar8 + -1);
      puVar1 = (undefined8 *)(*(long *)(piVar9 + 2) + ((long)iVar8 + -1) * 0x10);
      uVar12 = *puVar1;
      puVar10[1] = puVar1[1];
      *puVar10 = uVar12;
    }
    pcVar3 = local_58;
    if (local_68 == (char *)0x0) {
      _av_freep(&local_60);
      iVar8 = *piVar9;
      goto LAB_002571b0;
    }
    iVar8 = *piVar9;
    puVar10 = (undefined8 *)(*(long *)(piVar9 + 2) + (long)iVar8 * 0x10);
    *puVar10 = local_60;
    puVar10[1] = local_68;
    if (((param_4 >> 5 & 1) != 0) && (local_58 != (char *)0x0)) {
      sVar5 = _strlen(local_58);
      pcVar11 = local_68;
      sVar6 = _strlen(local_68);
      lVar4 = sVar5 + sVar6 + 1;
      lVar7 = _av_mallocz(lVar4);
      if (lVar7 == 0) goto LAB_00257174;
      _av_strlcat(lVar7,pcVar3,lVar4);
      _av_freep(&local_58);
      _av_strlcat(lVar7,pcVar11,lVar4);
      *(long *)(*(long *)(piVar9 + 2) + (long)*piVar9 * 0x10 + 8) = lVar7;
      _av_freep(&local_68);
      iVar8 = *piVar9;
    }
    iVar8 = iVar8 + 1;
    *piVar9 = iVar8;
LAB_002571b0:
    if (iVar8 == 0) {
      _av_freep(piVar9 + 2);
      _av_freep(param_1);
    }
    return 0;
  }
LAB_00257174:
  pcVar3 = pcVar11;
  if (*piVar9 == 0) {
    _av_freep(piVar9 + 2);
    _av_freep(param_1);
  }
LAB_0025718c:
  _av_free(local_60);
  _av_free(pcVar3);
  return 0xfffffff4;
}


