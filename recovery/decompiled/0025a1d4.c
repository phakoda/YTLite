/* Decompiled from supplied 5.2.2 arm package. VA 0x25a1d4. FUN_0025a1d4 */

bool FUN_0025a1d4(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  
  do {
    cVar1 = *param_2;
    cVar2 = *param_1;
    if (cVar1 == '\0') {
      return cVar2 != '_' && (9 < (int)cVar2 - 0x30U && 0x19 < ((int)cVar2 & 0xffffffdfU) - 0x41);
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 == cVar2);
  return false;
}


