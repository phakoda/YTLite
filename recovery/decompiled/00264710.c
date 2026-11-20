/* Decompiled from supplied 5.2.2 arm package. VA 0x264710. FUN_00264710 */

undefined8
FUN_00264710(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4,
            int param_5)

{
  long lVar1;
  undefined8 uVar2;
  long local_48;
  
  lVar1 = _av_opt_find2(param_1,param_2,0,0,param_3,&local_48);
  uVar2 = 0xabafb008;
  if ((lVar1 != 0) && (local_48 != 0)) {
    if (*(int *)(lVar1 + 0x14) == param_5) {
      uVar2 = 0;
      *param_4 = *(undefined4 *)(local_48 + *(int *)(lVar1 + 0x10));
    }
    else {
      _av_log(param_1,0x10,"The value for option \'%s\' is not a %s format.\n");
      uVar2 = 0xffffffea;
    }
  }
  return uVar2;
}


