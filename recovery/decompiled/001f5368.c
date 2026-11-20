/* Decompiled from supplied 5.2.2 arm package. VA 0x1f5368. FUN_001f5368 */

undefined1  [16] FUN_001f5368(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_01227fe8 = 1;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_setActive_0114e278);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_hide_0114d0a0);
  uVar1 = _objc_alloc_init(PTR_ToastView_0114ec98);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x18);
  *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x18) = uVar1;
  _objc_release(uVar2);
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x18);
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_localizedStringForKey_value_tabl_0114b278,
                &PTR____CFConstantStringClassReference_011be0e0,0,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0,uVar3,PTR_s_showProgressWithText_progress_wi_0114e280,uVar2,1,
                &PTR___NSConcreteGlobalBlock_01062f30);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0xb51e);
  return ZEXT816(0x1f);
}


