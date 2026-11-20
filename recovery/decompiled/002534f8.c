/* Decompiled from supplied 5.2.2 arm package. VA 0x2534f8. FUN_002534f8 */

void FUN_002534f8(undefined8 *param_1,undefined4 param_2,undefined8 param_3)

{
  if (param_1 != (undefined8 *)0x0) {
    switch(param_2) {
    case 0:
      *(int *)param_1 = (int)param_3;
      return;
    case 1:
    case 3:
      *param_1 = param_3;
      break;
    case 0xfffffffe:
      *(char *)param_1 = (char)param_3;
      return;
    case 0xffffffff:
      *(short *)param_1 = (short)param_3;
      return;
    }
  }
  return;
}


