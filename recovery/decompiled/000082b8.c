/* Decompiled from supplied 5.2.2 arm package. VA 0x82b8. FUN_000082b8 */

char * FUN_000082b8(void)

{
  char *pcVar1;
  int iVar2;
  
  iVar2 = _access("/var/LIY",0);
  pcVar1 = "/var/jb";
  if (iVar2 != 0) {
    pcVar1 = "";
  }
  return pcVar1;
}


