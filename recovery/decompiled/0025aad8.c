/* Decompiled from supplied 5.2.2 arm package. VA 0x25aad8. _av_fopen_utf8 */

FILE * _av_fopen_utf8(undefined8 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  FILE *pFVar4;
  uint uVar5;
  char *pcVar6;
  
  cVar1 = *param_2;
  pcVar6 = param_2;
  if (cVar1 == 'a') {
    uVar5 = 0x209;
  }
  else {
    uVar5 = 0;
    if (cVar1 != 'r') {
      if (cVar1 != 'w') goto LAB_0025ab44;
      uVar5 = 0x601;
    }
  }
  while( true ) {
    do {
      pcVar6 = pcVar6 + 1;
      cVar1 = *pcVar6;
    } while (cVar1 == 'b');
    if (cVar1 == '\0') {
      iVar2 = _avpriv_open(param_1,uVar5);
      if (iVar2 == -1) {
        return (FILE *)0x0;
      }
      pFVar4 = _fdopen(iVar2,param_2);
      return pFVar4;
    }
    if (cVar1 != '+') break;
    uVar5 = uVar5 & 0xfffffffc | 2;
  }
LAB_0025ab44:
  piVar3 = ___error();
  *piVar3 = 0x16;
  return (FILE *)0x0;
}


