/* Decompiled from supplied 5.2.2 arm package. VA 0x1a7f3c. FUN_001a7f3c */

undefined1  [16] FUN_001a7f3c(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  puVar1 = PTR_s_setPlaceholder__0114d198;
  DAT_01227978 = 1;
  uVar2 = _objc_retain(param_2);
  _objc_msgSend(uVar2,puVar1,&PTR____CFConstantStringClassReference_011ae310);
  _objc_msgSend(param_2,PTR_s_setClearButtonMode__0114d600,1);
  _objc_msgSend(param_2,PTR_s_setText__0114b388,&PTR____CFConstantStringClassReference_011ae310);
  _objc_release(param_2);
  CallSupervisor(0xe6c2);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


