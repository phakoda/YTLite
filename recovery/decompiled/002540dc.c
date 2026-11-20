/* Decompiled from supplied 5.2.2 arm package. VA 0x2540dc. _av_match_name */

bool _av_match_name(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  size_t sVar5;
  size_t sVar6;
  
  if ((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) {
    sVar3 = _strlen(param_1);
    while (cVar1 = *param_2, cVar1 != '\0') {
      pcVar4 = _strchr(param_2,0x2c);
      if (pcVar4 == (char *)0x0) {
        sVar5 = _strlen(param_2);
        pcVar4 = param_2 + sVar5;
      }
      if (cVar1 == '-') {
        param_2 = param_2 + 1;
      }
      sVar6 = (long)pcVar4 - (long)param_2;
      sVar5 = sVar6;
      if ((long)sVar6 <= (long)(int)sVar3) {
        sVar5 = (long)(int)sVar3;
      }
      iVar2 = _av_strncasecmp(param_1,param_2,(long)(int)sVar5);
      if (iVar2 == 0) {
LAB_0025419c:
        return cVar1 != '-';
      }
      sVar5 = 3;
      if (2 < (long)sVar6) {
        sVar5 = sVar6;
      }
      iVar2 = _strncmp("ALL",param_2,sVar5);
      if (iVar2 == 0) goto LAB_0025419c;
      param_2 = pcVar4;
      if (*pcVar4 == ',') {
        param_2 = pcVar4 + 1;
      }
    }
  }
  return false;
}


