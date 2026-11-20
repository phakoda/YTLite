/* Decompiled from supplied 5.2.2 arm package. VA 0x26388c. FUN_0026388c */

undefined8
FUN_0026388c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
            undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  undefined8 uVar2;
  long local_48;
  
  lVar1 = _av_opt_find2(param_2,param_3,0,0,param_6,&local_48);
  uVar2 = 0xabafb008;
  if ((lVar1 != 0) && (local_48 != 0)) {
    if (*(char *)(lVar1 + 0x30) < '\0') {
      uVar2 = 0xffffffea;
    }
    else {
      uVar2 = FUN_00263340(param_1,param_2,lVar1,local_48 + *(int *)(lVar1 + 0x10),param_4,param_5);
    }
  }
  return uVar2;
}


