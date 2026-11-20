/* Decompiled from supplied 5.2.2 arm package. VA 0xad54. FUN_0000ad54 */

undefined1  [16] FUN_0000ad54(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_012258c0 = 1;
  iVar1 = FUN_0000c1e0(PTR_YTLUserDefaults_0114ead8,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_01150f40);
  if (iVar1 != 0) {
    _objc_msgSend(PTR_YTPDiscordRPC_0114eac8,PTR_s_sharedPresence_0114ad78);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_media_0114ad90);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_setIsPaused__0114ad98,0);
    _objc_release(uVar3);
    _objc_msgSend(uVar2,PTR_s_updateState_0114adc8);
    _objc_release(uVar2);
  }
  (*pcRam0000000001225880)(param_1,param_2);
  CallSupervisor(0x77f4);
  return ZEXT816(0x1f);
}


