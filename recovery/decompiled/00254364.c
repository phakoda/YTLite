/* Decompiled from supplied 5.2.2 arm package. VA 0x254364. _av_match_list */

undefined4 _av_match_list(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  
  do {
    if ((param_1 == (char *)0x0) || (pcVar4 = param_2, *param_1 == '\0')) {
      return 0;
    }
    while ((pcVar4 != (char *)0x0 && (cVar1 = *pcVar4, cVar1 != '\0'))) {
      lVar5 = 0;
      while( true ) {
        cVar2 = param_1[lVar5];
        iVar3 = (int)cVar2;
        if ((cVar2 != cVar1) && ((cVar1 * iVar3 != 0 || (cVar1 + iVar3 != param_3)))) break;
        if (lVar5 != 0) {
          if (cVar2 == '\0') {
            return 1;
          }
          if (iVar3 == param_3) {
            return 1;
          }
        }
        cVar1 = pcVar4[lVar5 + 1];
        lVar5 = lVar5 + 1;
      }
      pcVar4 = _strchr(pcVar4,param_3);
      if (pcVar4 != (char *)0x0) {
        pcVar4 = pcVar4 + 1;
      }
    }
    param_1 = _strchr(param_1,param_3);
    if (param_1 != (char *)0x0) {
      param_1 = param_1 + 1;
    }
  } while( true );
}


