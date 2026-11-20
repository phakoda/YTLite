/* Decompiled from supplied 5.2.2 arm package. VA 0x27bd68. FUN_0027bd68 */

undefined8 FUN_0027bd68(long param_1)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x44) - 3U < 7) {
    switch(*(int *)(param_1 + 0x44)) {
    case 3:
      pcVar1 = FUN_0027bde8;
      break;
    case 4:
      pcVar1 = FUN_0027be94;
      break;
    default:
      goto switchD_0027bd90_caseD_5;
    case 8:
      pcVar1 = FUN_0027bf38;
      break;
    case 9:
      pcVar1 = FUN_0027bff4;
    }
    *(code **)(*(long *)(*(long *)(param_1 + 0x10) + 0x48) + 0x10) = pcVar1;
  }
switchD_0027bd90_caseD_5:
  return 0;
}


