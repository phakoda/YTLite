/* Decompiled from supplied 5.2.2 arm package. VA 0x253e7c. _av_basename */

char * _av_basename(char *param_1)

{
  char *pcVar1;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    param_1 = ".";
  }
  else {
    pcVar1 = _strrchr(param_1,0x2f);
    if (pcVar1 != (char *)0x0) {
      param_1 = pcVar1 + 1;
    }
  }
  return param_1;
}


