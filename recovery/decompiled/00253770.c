/* Decompiled from supplied 5.2.2 arm package. VA 0x253770. FUN_00253770 */

bool FUN_00253770(char *param_1,char *param_2,undefined8 *param_3)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  
  for (; cVar3 = *param_2, cVar3 != '\0'; param_2 = param_2 + 1) {
    uVar4 = (uint)cVar3;
    cVar2 = *param_1;
    uVar1 = uVar4 ^ 0x20;
    if (0x19 < uVar4 - 0x61) {
      uVar1 = uVar4;
    }
    uVar4 = (int)cVar2 ^ 0x20;
    if (0x19 < (int)cVar2 - 0x61U) {
      uVar4 = (uint)cVar2;
    }
    if (uVar1 != uVar4) goto LAB_002537c4;
    param_1 = param_1 + 1;
  }
  cVar3 = '\0';
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = param_1;
    cVar3 = *param_2;
  }
LAB_002537c4:
  return cVar3 == '\0';
}


