/* Decompiled from supplied 5.2.2 arm package. VA 0x250d3c. FUN_00250d3c */

void FUN_00250d3c(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1 + 7;
  do {
    if (pcVar2 < param_1) {
      return;
    }
    cVar1 = *pcVar2;
    *pcVar2 = cVar1 + '\x01';
    pcVar2 = pcVar2 + -1;
  } while ((char)(cVar1 + '\x01') == '\0');
  return;
}


