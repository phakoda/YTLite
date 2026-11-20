/* Decompiled from supplied 5.2.2 arm package. VA 0x265ca0. _av_opt_child_class_next */

undefined8 _av_opt_child_class_next(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00265cac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(param_1 + 0x30))(param_2);
    return uVar1;
  }
  return 0;
}


