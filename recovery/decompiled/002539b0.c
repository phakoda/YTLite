/* Decompiled from supplied 5.2.2 arm package. VA 0x2539b0. _av_asprintf */

long _av_asprintf(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  undefined8 in_x6;
  undefined8 in_x7;
  long local_38;
  
  local_38 = 0;
  iVar1 = ___vsnprintf_chk(0,0,0,0,param_1,&stack0x00000000,in_x6,in_x7,&stack0x00000000);
  lVar2 = 0;
  if (-1 < iVar1) {
    lVar2 = _av_malloc((long)(iVar1 + 1));
    if (lVar2 == 0) {
      lVar2 = 0;
    }
    else {
      local_38 = lVar2;
      iVar1 = ___vsnprintf_chk(lVar2,(long)(iVar1 + 1),0,0xffffffffffffffff,param_1,&stack0x00000000
                               ,in_x6,in_x7,&stack0x00000000);
      if (iVar1 < 0) {
        _av_freep(&local_38);
        lVar2 = local_38;
      }
    }
  }
  return lVar2;
}


