/* Decompiled from supplied 5.2.2 arm package. VA 0x8af2c. FUN_0008af2c */

undefined1  [16] FUN_0008af2c(undefined8 param_1)

{
  int iVar1;
  
  DAT_01226d18 = 1;
  iVar1 = FUN_000dfb0c(&PTR____CFConstantStringClassReference_01168630);
  if (iVar1 != 0) {
    _objc_msgSend(param_1,PTR_s_didTogglePlayPause_0114c970);
  }
  CallSupervisor(0xd0fe);
  return ZEXT816(0x1f);
}


