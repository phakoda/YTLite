/* Decompiled from supplied 5.2.2 arm package. VA 0x26e12c. _av_tx_init */

int _av_tx_init(long *param_1,undefined8 *param_2,uint param_3,undefined4 param_4,undefined4 param_5
               ,undefined8 param_6,undefined8 param_7)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long local_68;
  
  lVar3 = _av_mallocz(0x30);
  if (lVar3 == 0) {
    iVar2 = -0xc;
  }
  else {
    iVar2 = -0x16;
    local_68 = lVar3;
    if (param_3 < 6) {
      uVar1 = 1 << (ulong)(param_3 & 0x1f);
      if ((uVar1 & 3) == 0) {
        if ((uVar1 & 0xc) == 0) {
          iVar2 = _ff_tx_init_mdct_fft_int32();
        }
        else {
          iVar2 = _ff_tx_init_mdct_fft_double();
        }
      }
      else {
        iVar2 = _ff_tx_init_mdct_fft_float(lVar3,param_2,param_3,param_4,param_5,param_6,param_7);
      }
      if (iVar2 == 0) {
        *param_1 = lVar3;
        return 0;
      }
    }
    _av_tx_uninit(&local_68);
    *param_2 = 0;
  }
  return iVar2;
}


