/* Decompiled from supplied 5.2.2 arm package. VA 0xb3a0. FUN_0000b3a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_0000b3a0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  DAT_012258cc = 1;
  iVar1 = FUN_0000c3d8(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_01151060);
  if (iVar1 != 0) {
    _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,PTR_s_sharedPresence_0114ad78);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_clearPlayback_0114add0);
    _objc_release(uVar2);
  }
  (*_DAT_01225898)(param_1,param_2);
  CallSupervisor(0x84d9);
  return ZEXT816(0x1f);
}


