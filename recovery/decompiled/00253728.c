/* Decompiled from supplied 5.2.2 arm package. VA 0x253728. FUN_00253728 */

bool FUN_00253728(char *param_1,char *param_2,undefined8 *param_3)

{
  char cVar1;
  
  for (; cVar1 = *param_2, cVar1 != '\0'; param_2 = param_2 + 1) {
    if (cVar1 != *param_1) goto LAB_00253758;
    param_1 = param_1 + 1;
  }
  cVar1 = '\0';
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = param_1;
    cVar1 = *param_2;
  }
LAB_00253758:
  return cVar1 == '\0';
}


