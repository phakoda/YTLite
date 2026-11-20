/* Decompiled from supplied 5.2.2 arm package. VA 0x265c88. _av_opt_child_next */

undefined8 _av_opt_child_next(long *param_1)

{
  undefined8 uVar1;
  
  if (*(code **)(*param_1 + 0x28) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00265c94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*param_1 + 0x28))();
    return uVar1;
  }
  return 0;
}


