/* Decompiled from supplied 5.2.2 arm package. VA 0x2690bc. FUN_002690bc */

undefined4 FUN_002690bc(undefined8 *param_1)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  uVar4 = param_1[2];
  if (((uint)uVar4 >> 1 & 1) == 0) {
    bVar1 = *(byte *)(param_1 + 1);
    if (bVar1 - 1 < 2) {
      return 1;
    }
    pcVar3 = (char *)*param_1;
    if (pcVar3 != (char *)0x0) {
      iVar2 = _strncmp(pcVar3,"yuvj",4);
      if (iVar2 == 0) {
        return 3;
      }
      iVar2 = _strncmp(pcVar3,"xyz",3);
      if (iVar2 == 0) {
        return 4;
      }
    }
    if (((uint)uVar4 >> 5 & 1) == 0) {
      if (bVar1 == 0) {
        return 0xffffffff;
      }
      return 2;
    }
  }
  return 0;
}


