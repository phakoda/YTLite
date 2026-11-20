/* Decompiled from supplied 5.2.2 arm package. VA 0x1dc1a8. FUN_001dc1a8 */

undefined1  [16] FUN_001dc1a8(long param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  puVar1 = PTR__OBJC_CLASS___UIView_0114ec30;
  _objc_retain(param_2);
  uVar2 = _objc_alloc(puVar1);
  uVar2 = _objc_msgSend(0,0,0x4038000000000000,0x4038000000000000,uVar2,
                        PTR_s_initWithFrame__0114b770);
  uVar3 = _objc_alloc(PTR__OBJC_CLASS___UIImageView_0114ebf0);
  uVar3 = _objc_msgSend(uVar3,PTR_s_initWithImage__0114b5d0,*(undefined8 *)(param_1 + 0x20));
  _objc_msgSend(uVar3,PTR_s_setContentMode__0114b728,1);
  _objc_msgSend(uVar3,PTR_s_setClipsToBounds__0114b900,1);
  _objc_msgSend(uVar2,PTR_s_bounds_0114b568);
  _objc_msgSend(uVar3,PTR_s_setFrame__0114b570);
  puVar1 = PTR_s_layer_0114ae60;
  _objc_msgSend(uVar3,PTR_s_layer_0114ae60);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4028000000000000,uVar4,PTR_s_setCornerRadius__0114ae68);
  _objc_release(uVar4);
  _objc_msgSend(uVar3,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3ff0000000000000,uVar4,PTR_s_setBorderWidth__0114d0c8);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3fd0000000000000,uVar4,PTR_s_colorWithAlphaComponent__0114b548);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  uVar6 = _objc_retainAutorelease();
  uVar6 = _objc_msgSend(uVar6,PTR_s_CGColor_0114c8c0);
  _objc_msgSend(uVar3,puVar1);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar7,PTR_s_setBorderColor__0114d0d0,uVar6);
  _objc_release(uVar7);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_msgSend(uVar2,PTR_s_addSubview__0114b0a8,uVar3);
  _objc_msgSend(uVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_msgSend(param_2,PTR_s_CGContext_0114b940);
  _objc_release(param_2);
  _objc_msgSend(uVar4,PTR_s_renderInContext__0114b948,uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0x5cdc);
  return ZEXT816(0x1f);
}


