/* Decompiled from supplied 5.2.2 arm package. VA 0x250c88. _av_aes_ctr_init */

undefined8 _av_aes_ctr_init(long *param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = _av_aes_alloc();
  *param_1 = lVar1;
  if (lVar1 == 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    _av_aes_init(lVar1,param_2,0x80,0);
    uVar2 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    *(undefined4 *)(param_1 + 5) = 0;
  }
  return uVar2;
}


