/* Decompiled from supplied 5.2.2 arm package. VA 0x176e68. FUN_00176e68 */

undefined1  [16] FUN_00176e68(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(param_2,PTR_s_sourceView_0114d878);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_showDonationSheet__0114d8a8,uVar1);
  _objc_release(uVar1);
  CallSupervisor(0x96d5);
  return ZEXT816(0x1f);
}


