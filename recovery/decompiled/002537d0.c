/* Decompiled from supplied 5.2.2 arm package. VA 0x2537d0. _av_stristr */

char * _av_stristr(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  
  if (*param_2 != '\0') {
    do {
      iVar2 = _av_stristart(param_1,param_2,0);
      if (iVar2 != 0) {
        return param_1;
      }
      cVar1 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    param_1 = (char *)0x0;
  }
  return param_1;
}


