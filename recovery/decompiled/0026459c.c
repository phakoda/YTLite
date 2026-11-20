/* Decompiled from supplied 5.2.2 arm package. VA 0x26459c. _av_opt_get_image_size */

undefined8
_av_opt_get_image_size
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4,
          undefined4 *param_5)

{
  undefined4 *puVar1;
  long lVar2;
  undefined8 uVar3;
  long local_38;
  
  lVar2 = _av_opt_find2(param_1,param_2,0,0,param_3,&local_38);
  uVar3 = 0xabafb008;
  if ((lVar2 != 0) && (local_38 != 0)) {
    if (*(int *)(lVar2 + 0x14) == 0xb) {
      puVar1 = (undefined4 *)(local_38 + *(int *)(lVar2 + 0x10));
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *puVar1;
      }
      if (param_5 == (undefined4 *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
        *param_5 = puVar1[1];
      }
    }
    else {
      _av_log(param_1,0x10,"The value for option \'%s\' is not an image size.\n");
      uVar3 = 0xffffffea;
    }
  }
  return uVar3;
}


