/* Decompiled from supplied 5.2.2 arm package. VA 0x253ac0. _av_get_token */

char * _av_get_token(undefined8 *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  long lVar8;
  
  sVar3 = _strlen((char *)*param_1);
  pcVar4 = (char *)_av_malloc(sVar3 + 1);
  if (pcVar4 == (char *)0x0) {
    return (char *)0x0;
  }
  pcVar5 = (char *)*param_1;
  sVar3 = _strspn(pcVar5," \n\t\r");
  pcVar5 = pcVar5 + sVar3;
  pcVar6 = pcVar4;
  pcVar7 = pcVar4;
LAB_00253b34:
  lVar8 = 0;
  do {
    pcVar1 = pcVar5 + lVar8;
    cVar2 = *pcVar1;
    if ((cVar2 == '\0') || (sVar3 = _strspn(pcVar1,param_2), sVar3 != 0)) {
      pcVar5 = pcVar6 + lVar8;
      goto LAB_00253be0;
    }
    if (cVar2 == '\\') {
      if (pcVar5[lVar8 + 1] != '\0') {
        pcVar7 = pcVar6 + lVar8;
        pcVar6 = pcVar7 + 1;
        *pcVar7 = pcVar5[lVar8 + 1];
        pcVar5 = pcVar5 + lVar8 + 2;
        pcVar7 = pcVar6;
        goto LAB_00253b34;
      }
    }
    else if (cVar2 == '\'') break;
    pcVar6[lVar8] = cVar2;
    lVar8 = lVar8 + 1;
  } while( true );
  pcVar6 = pcVar6 + lVar8;
  pcVar1 = pcVar5 + lVar8;
  while( true ) {
    pcVar5 = pcVar1 + 1;
    cVar2 = *pcVar5;
    if ((cVar2 == '\'') || (cVar2 == '\0')) break;
    *pcVar6 = cVar2;
    pcVar6 = pcVar6 + 1;
    pcVar1 = pcVar5;
  }
  if (cVar2 != '\0') {
    pcVar5 = pcVar1 + 2;
    pcVar7 = pcVar6;
  }
  goto LAB_00253b34;
  while (sVar3 = _strspn(pcVar6," \n\t\r"), pcVar5 = pcVar6, sVar3 != 0) {
LAB_00253be0:
    pcVar6 = pcVar5 + -1;
    *pcVar5 = '\0';
    if (pcVar6 < pcVar7) break;
  }
  *param_1 = pcVar1;
  return pcVar4;
}


