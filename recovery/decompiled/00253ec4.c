/* Decompiled from supplied 5.2.2 arm package. VA 0x253ec4. _av_dirname */

char * _av_dirname(char *param_1)

{
  char *pcVar1;
  
  if ((param_1 == (char *)0x0) || (pcVar1 = _strrchr(param_1,0x2f), pcVar1 == (char *)0x0)) {
    param_1 = ".";
  }
  else {
    *pcVar1 = '\0';
  }
  return param_1;
}


