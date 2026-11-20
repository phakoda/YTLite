/* Decompiled from supplied 5.2.2 arm package. VA 0x1ed464. FUN_001ed464 */

undefined1  [16]
FUN_001ed464(long param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  uVar4 = *(undefined8 *)(param_1 + 0x20);
  _objc_retain(param_3);
  _objc_retain(param_2);
  _objc_msgSend(uVar4,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setObject_forKey__0114c2b8,param_3,param_2);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_objectForKey__0114b238,param_2);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_2);
  iVar2 = FUN_001ef224(uVar3,PTR_s_isEqual__0114b060,param_3);
  _objc_release(param_3);
  _objc_release(uVar3);
  _objc_release(uVar4);
  if (iVar2 == 0) {
    **(undefined1 **)(param_1 + 0x28) = 0;
    *param_4 = 1;
  }
  CallSupervisor(0xeeef);
  return ZEXT816(0x1f);
}


