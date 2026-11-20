/* Decompiled from supplied 5.2.2 arm package. VA 0x263a20. _av_opt_set_image_size */

undefined4
_av_opt_set_image_size
          (undefined8 param_1,undefined8 param_2,uint param_3,uint param_4,undefined8 param_5)

{
  long lVar1;
  char *pcVar2;
  undefined4 uVar3;
  long local_38;
  
  lVar1 = _av_opt_find2(param_1,param_2,0,0,param_5,&local_38);
  uVar3 = 0xabafb008;
  if ((lVar1 != 0) && (local_38 != 0)) {
    if (*(int *)(lVar1 + 0x14) == 0xb) {
      if (-1 < (int)(param_4 | param_3)) {
        *(uint *)(local_38 + *(int *)(lVar1 + 0x10)) = param_3;
        *(uint *)(local_38 + *(int *)(lVar1 + 0x10) + 4) = param_4;
        return 0;
      }
      pcVar2 = "Invalid negative size value %dx%d for size \'%s\'\n";
    }
    else {
      pcVar2 = "The value set by option \'%s\' is not an image size.\n";
    }
    _av_log(param_1,0x10,pcVar2);
    uVar3 = 0xffffffea;
  }
  return uVar3;
}


