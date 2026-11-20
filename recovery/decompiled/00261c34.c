/* Decompiled from supplied 5.2.2 arm package. VA 0x261c34. _av_reallocp_array */

undefined4 _av_reallocp_array(long *param_1,long param_2,long param_3)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = _av_realloc_f(*param_1);
  *param_1 = lVar1;
  uVar2 = 0xfffffff4;
  if ((lVar1 != 0 || param_2 == 0) || param_3 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}


