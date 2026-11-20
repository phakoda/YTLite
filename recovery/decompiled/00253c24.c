/* Decompiled from supplied 5.2.2 arm package. VA 0x253c24. _av_strtok */

char * _av_strtok(char *param_1,char *param_2,long *param_3)

{
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  
  if ((param_1 == (char *)0x0) && (param_1 = (char *)*param_3, param_1 == (char *)0x0)) {
    param_1 = (char *)0x0;
  }
  else {
    sVar2 = _strspn(param_1,param_2);
    param_1 = param_1 + sVar2;
    if (*param_1 == '\0') {
      param_1 = (char *)0x0;
      *param_3 = 0;
    }
    else {
      sVar2 = _strcspn(param_1 + 1,param_2);
      pcVar1 = param_1 + 1 + sVar2;
      if (*pcVar1 == '\0') {
        pcVar3 = (char *)0x0;
      }
      else {
        pcVar3 = pcVar1 + 1;
        *pcVar1 = '\0';
      }
      *param_3 = (long)pcVar3;
    }
  }
  return param_1;
}


