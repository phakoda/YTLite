/* Decompiled from supplied 5.2.2 arm package. VA 0x10b894. FUN_0010b894 */

undefined1  [16] FUN_0010b894(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  _objc_retain(param_2);
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  if (param_3 == 0) {
    _objc_msgSend(uVar2,PTR_s_hide_0114d0a0);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_shareSRT_sourceView__0114d0a8,param_2,
                  *(undefined8 *)(param_1 + 0x30));
  }
  else {
    _objc_msgSend(param_3,PTR_s_localizedDescription_0114c618);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar1,0);
    _objc_release(uVar1);
  }
  _objc_release(param_2);
  CallSupervisor(0x2839);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


