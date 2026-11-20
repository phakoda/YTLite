/* Decompiled from supplied 5.2.2 arm package. VA 0x2641a8. FUN_002641a8 */

void FUN_002641a8(char *param_1,ulong param_2,long param_3)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (param_2 < 0x19) {
    _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
    _abort();
  }
  pcVar4 = param_1;
  if ((param_3 < 0) && (param_3 != -0x8000000000000000)) {
    param_2 = param_2 - 1;
    pcVar4 = param_1 + 1;
    *param_1 = '-';
    param_3 = -param_3;
  }
  if (param_3 == -0x8000000000000000) {
    pcVar3 = "INT64_MIN";
  }
  else if (param_3 == 0x7fffffffffffffff) {
    pcVar3 = "INT64_MAX";
  }
  else if (param_3 < 0xd693a401) {
    if (param_3 < 0x3938701) {
      pcVar3 = "%d.%06d";
    }
    else {
      pcVar3 = "%d:%02d.%06d";
    }
  }
  else {
    pcVar3 = "%lld:%02d:%02d.%06d";
  }
  ___snprintf_chk(pcVar4,param_2,0,0xffffffffffffffff,pcVar3);
  sVar2 = _strlen(pcVar4);
  pcVar3 = pcVar4 + sVar2;
  while( true ) {
    if (pcVar3 <= pcVar4) {
      return;
    }
    cVar1 = pcVar3[-1];
    if (cVar1 != '0') break;
    pcVar3[-1] = '\0';
    pcVar3 = pcVar3 + -1;
  }
  if (cVar1 != '.') {
    return;
  }
  pcVar3[-1] = '\0';
  return;
}


