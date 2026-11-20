/* Decompiled from supplied 5.2.2 arm package. VA 0x253f08. _av_append_path_component */

long _av_append_path_component(char *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  long lVar3;
  char *pcVar4;
  size_t sVar5;
  
  pcVar4 = param_2;
  if ((param_1 != (char *)0x0) && (pcVar4 = param_1, param_2 != (char *)0x0)) {
    sVar1 = _strlen(param_1);
    sVar2 = _strlen(param_2);
    if ((~sVar2 < sVar1) ||
       ((0xfffffffffffffffd < sVar2 + sVar1 || (lVar3 = _av_malloc(sVar2 + sVar1 + 2), lVar3 == 0)))
       ) {
      lVar3 = 0;
    }
    else {
      if (sVar1 == 0) {
        sVar5 = 0;
      }
      else {
        _av_strlcpy(lVar3,param_1,sVar1 + 1);
        sVar5 = sVar1;
        if (sVar2 != 0) {
          if (*(char *)(lVar3 + (sVar1 - 1)) == '/') {
            sVar5 = sVar1 - 1;
            if (*param_2 != '/') {
              sVar5 = sVar1;
            }
          }
          else if (*param_2 != '/') {
            *(undefined1 *)(lVar3 + sVar1) = 0x2f;
            sVar5 = sVar1 + 1;
          }
        }
      }
      _av_strlcpy(lVar3 + sVar5,param_2,sVar2 + 1);
      *(undefined1 *)(lVar3 + sVar5 + sVar2) = 0;
    }
    return lVar3;
  }
  lVar3 = _av_strdup(pcVar4);
  return lVar3;
}


