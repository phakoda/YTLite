/* Decompiled from supplied 5.2.2 arm package. VA 0x2538e4. _av_strlcat */

long _av_strlcat(char *param_1,char *param_2,ulong param_3)

{
  size_t sVar1;
  size_t sVar2;
  
  sVar1 = _strlen(param_1);
  if (sVar1 + 1 < param_3) {
    sVar2 = _av_strlcpy(param_1 + sVar1,param_2,param_3 - sVar1);
  }
  else {
    sVar2 = _strlen(param_2);
  }
  return sVar2 + sVar1;
}


