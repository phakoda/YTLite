/* Decompiled from supplied 5.2.2 arm package. VA 0xb19c. FUN_0000b19c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0000b19c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_012258c8 = 1;
  iVar1 = FUN_0000c330(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_01151000);
  if (iVar1 != 0) {
    _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,PTR_s_sharedPresence_0114ad78);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_clearPlayback_0114add0);
    _objc_release(uVar2);
  }
  (*_DAT_01225890)(param_1,param_2,param_3);
  CallSupervisor(0x17b5);
  return ZEXT816(0x1f);
}


