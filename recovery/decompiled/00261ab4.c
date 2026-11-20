/* Decompiled from supplied 5.2.2 arm package. VA 0x261ab4. _av_reallocp */

undefined8 _av_reallocp(long *param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    _av_freep(param_1);
    uVar2 = 0;
  }
  else {
    lVar1 = _av_realloc(*param_1);
    if (lVar1 == 0) {
      _av_freep(param_1);
      uVar2 = 0xfffffff4;
    }
    else {
      uVar2 = 0;
      *param_1 = lVar1;
    }
  }
  return uVar2;
}


