/* Decompiled from supplied 5.2.2 arm package. VA 0x265764. _av_opt_get_key_value */

undefined4
_av_opt_get_key_value
          (long *param_1,char *param_2,undefined8 param_3,uint param_4,undefined8 *param_5,
          long *param_6)

{
  byte bVar1;
  size_t sVar2;
  char *pcVar3;
  void *pvVar4;
  long lVar5;
  undefined4 uVar6;
  byte *pbVar7;
  byte *pbVar8;
  size_t sVar9;
  byte *local_68;
  
  pbVar7 = (byte *)*param_1;
  local_68 = pbVar7;
  sVar2 = _strspn((char *)pbVar7," \n\t\r");
  pbVar7 = pbVar7 + sVar2;
  pbVar8 = pbVar7 + -1;
  do {
    do {
      pbVar8 = pbVar8 + 1;
      bVar1 = *pbVar8;
    } while ((bVar1 & 0xfe) == 0x2e);
  } while ((bVar1 == 0x5f) ||
          ((bVar1 == 0x2d || (int)(char)bVar1 - 0x30U < 10) ||
           ((int)(char)bVar1 | 0x20U) - 0x61 < 0x1a));
  sVar2 = _strspn((char *)pbVar8," \n\t\r");
  if (((char)pbVar8[sVar2] == 0) ||
     (pcVar3 = _strchr(param_2,(int)(char)pbVar8[sVar2]), pcVar3 == (char *)0x0)) {
    pvVar4 = (void *)0x0;
  }
  else {
    sVar9 = (long)pbVar8 - (long)pbVar7;
    pvVar4 = (void *)_av_malloc(sVar9 + 1);
    if (pvVar4 != (void *)0x0) {
      _memcpy(pvVar4,pbVar7,sVar9);
      *(undefined1 *)((long)pvVar4 + sVar9) = 0;
      local_68 = pbVar8 + sVar2 + 1;
      goto LAB_00265864;
    }
  }
  if ((param_4 & 1) == 0) {
    return 0xffffffea;
  }
LAB_00265864:
  lVar5 = _av_get_token(&local_68,param_3);
  if (lVar5 == 0) {
    _av_free(pvVar4);
    uVar6 = 0xfffffff4;
  }
  else {
    uVar6 = 0;
    *param_1 = (long)local_68;
    *param_5 = pvVar4;
    *param_6 = lVar5;
  }
  return uVar6;
}


