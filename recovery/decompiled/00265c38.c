/* Decompiled from supplied 5.2.2 arm package. VA 0x265c38. _av_opt_child_class_iterate */

undefined8 _av_opt_child_class_iterate(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(param_1 + 0x50) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00265c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(param_1 + 0x50))(param_2);
    return uVar1;
  }
  if (*(code **)(param_1 + 0x30) == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x30))(*param_2);
    *param_2 = uVar1;
  }
  return uVar1;
}


