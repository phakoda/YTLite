/* Decompiled from supplied 5.2.2 arm package. VA 0x26070c. FUN_0026070c */

ulong FUN_0026070c(ulong param_1,int param_2,char *param_3)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  FILE *pFVar5;
  uint uVar6;
  
  if (*param_3 != '\0') {
    uVar2 = DAT_011d31f8;
    if ((int)DAT_011d31f8 < 0) {
      pcVar3 = _getenv("TERM");
      pcVar4 = _getenv("AV_LOG_FORCE_NOCOLOR");
      if (pcVar4 == (char *)0x0) {
        pcVar4 = _getenv("AV_LOG_FORCE_COLOR");
        if (pcVar4 == (char *)0x0) {
          if (pcVar3 == (char *)0x0) {
            DAT_011d31f8 = 0;
          }
          else {
            iVar1 = _isatty(2);
            DAT_011d31f8 = (uint)(iVar1 != 0);
          }
          uVar6 = DAT_011d31f8 << 8;
        }
        else {
          DAT_011d31f8 = 1;
          uVar6 = 0x100;
        }
      }
      else {
        uVar6 = 0;
        DAT_011d31f8 = 0;
      }
      uVar2 = DAT_011d31f8;
      pcVar4 = _getenv("AV_LOG_FORCE_256COLOR");
      if ((pcVar4 != (char *)0x0) ||
         ((pcVar3 != (char *)0x0 && (pcVar3 = _strstr(pcVar3,"256color"), pcVar3 != (char *)0x0))))
      {
        uVar2 = uVar6;
        DAT_011d31f8 = uVar6;
      }
    }
    uVar6 = 0;
    if ((int)param_1 != 4) {
      uVar6 = uVar2;
    }
    if (uVar6 == 1) {
      pFVar5 = *(FILE **)PTR____stderrp_01060710;
      pcVar3 = "\x1b[%u;3%um%s\x1b[0m";
    }
    else if ((param_2 == 0) || (uVar2 != 0x100)) {
      pFVar5 = *(FILE **)PTR____stderrp_01060710;
      if (uVar6 != 0x100) {
        uVar2 = _fputs(param_3,pFVar5);
        return (ulong)uVar2;
      }
      pcVar3 = "\x1b[48;5;%um\x1b[38;5;%um%s\x1b[0m";
    }
    else {
      pFVar5 = *(FILE **)PTR____stderrp_01060710;
      pcVar3 = "\x1b[48;5;%um\x1b[38;5;%dm%s\x1b[0m";
    }
    uVar2 = _fprintf(pFVar5,pcVar3);
    param_1 = (ulong)uVar2;
  }
  return param_1;
}


