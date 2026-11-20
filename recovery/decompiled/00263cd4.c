/* Decompiled from supplied 5.2.2 arm package. VA 0x263cd4. _av_opt_set_channel_layout */

undefined8
_av_opt_set_channel_layout
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  undefined8 uVar2;
  long local_28;
  
  lVar1 = _av_opt_find2(param_1,param_2,0,0,param_4,&local_28);
  uVar2 = 0xabafb008;
  if ((lVar1 != 0) && (local_28 != 0)) {
    if (*(int *)(lVar1 + 0x14) == 0x11) {
      uVar2 = 0;
      *(undefined8 *)(local_28 + *(int *)(lVar1 + 0x10)) = param_3;
    }
    else {
      _av_log(param_1,0x10,"The value set by option \'%s\' is not a channel layout.\n");
      uVar2 = 0xffffffea;
    }
  }
  return uVar2;
}


