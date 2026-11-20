/* Decompiled from supplied 5.2.2 arm package. VA 0x120fbc. FUN_00120fbc */

undefined1  [16] FUN_00120fbc(long param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 auVar6 [16];
  
  puVar1 = PTR__OBJC_CLASS___UIView_0114ec30;
  _objc_retain(param_2);
  uVar2 = _objc_alloc(puVar1);
  uVar2 = _objc_msgSend(0,0,0x4034000000000000,0x4034000000000000,uVar2,
                        PTR_s_initWithFrame__0114b770);
  uVar3 = _objc_alloc(PTR__OBJC_CLASS___UIImageView_0114ebf0);
  uVar3 = _objc_msgSend(uVar3,PTR_s_initWithImage__0114b5d0,*(undefined8 *)(param_1 + 0x20));
  _objc_msgSend(uVar3,PTR_s_setContentMode__0114b728,1);
  _objc_msgSend(uVar3,PTR_s_setClipsToBounds__0114b900,1);
  _objc_msgSend(uVar2,PTR_s_bounds_0114b568);
  _objc_msgSend(uVar3,PTR_s_setFrame__0114b570);
  _objc_msgSend(uVar2,PTR_s_addSubview__0114b0a8,uVar3);
  _objc_msgSend(uVar2,PTR_s_layer_0114ae60);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_msgSend(param_2,PTR_s_CGContext_0114b940);
  _objc_release(param_2);
  _objc_msgSend(uVar4,PTR_s_renderInContext__0114b948,uVar5);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0xa2b2);
  auVar6._8_8_ = 0x1f;
  auVar6._0_8_ = 0x1a;
  return auVar6;
}


