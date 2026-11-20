/* Decompiled from supplied 5.2.2 arm package. VA 0x1e3c1c. FUN_001e3c1c */

undefined1  [16] FUN_001e3c1c(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  if (*(long *)(param_1 + 0x28) != 0x7fffffffffffffff) {
    *(long *)(*(long *)(param_1 + 0x20) + (long)TranslatorVC::_langIndex) =
         *(long *)(param_1 + 0x28);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_tableView_0114d120);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSIndexSet_0114ee80,PTR_s_indexSetWithIndex__0114d698,0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_reloadSections_withRowAnimation__0114d6a0,uVar2,5);
    _objc_release(uVar2);
    _objc_release(uVar1);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_translateText_0114e0d0);
  }
  CallSupervisor(0x4000);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


