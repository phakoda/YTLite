/* Decompiled from supplied 5.2.2 arm package. VA 0xbe768. FUN_000be768 */

void FUN_000be768(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  _objc_msgSend(PTR_YTPSleepTimer_0114eaf0,PTR_s_sharedTimer_0114aed8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_itemView1_0114ba68);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_showOptions__0114aee0,uVar2);
  _objc_release(uVar2);
  _objc_release(uVar1);
  return;
}


