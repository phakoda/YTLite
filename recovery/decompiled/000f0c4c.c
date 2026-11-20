/* Decompiled from supplied 5.2.2 arm package. VA 0xf0c4c. FUN_000f0c4c */

undefined1  [16] FUN_000f0c4c(void)

{
  undefined8 uVar1;
  
  DAT_01227080 = 1;
  uVar1 = _objc_getClass(s_ELMPBShowActionSheetCommand_01183de0);
  _MSHookMessageEx(uVar1,PTR_s_executeWithCommandContext_handle_0114ce00,FUN_000f10e8,0x1227058);
  uVar1 = _objc_getClass(s_YTShareEntityEndpointCommandHand_01183d90);
  _MSHookMessageEx(uVar1,PTR_s_executeWithCommand_entry_fromVie_0114ce08,FUN_000f1890,0x1227060);
  CallSupervisor(0xa36e);
  return ZEXT816(0x1f);
}


