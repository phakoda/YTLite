/* Decompiled from supplied 5.2.2 arm package. VA 0x22fab0. FUN_0022fab0 */

undefined1  [16] FUN_0022fab0(long param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  puVar3 = PTR__OBJC_CLASS___UIImage_0114ebf8;
  puVar2 = PTR__OBJC_CLASS___NSBundle_0114eae8;
  puVar1 = PTR_s_ytl_defaultBundle_0114ae50;
  uVar8 = *(undefined8 *)(param_1 + 0x20);
  _objc_retain(param_2);
  _objc_msgSend(puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar3,PTR_s_imageNamed_inBundle_compatibleWi_0114b5c8,uVar8,uVar4,0);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  uVar4 = _objc_alloc(PTR__OBJC_CLASS___UIView_0114ec30);
  uVar4 = _objc_msgSend(0,0,0x4038000000000000,0x4038000000000000,uVar4,
                        PTR_s_initWithFrame__0114b770);
  uVar5 = _objc_alloc(PTR__OBJC_CLASS___UIImageView_0114ebf0);
  uVar5 = _objc_msgSend(uVar5,PTR_s_initWithImage__0114b5d0,uVar8);
  _objc_msgSend(uVar5,PTR_s_setContentMode__0114b728,1);
  _objc_msgSend(uVar5,PTR_s_setClipsToBounds__0114b900,1);
  _objc_msgSend(uVar4,PTR_s_bounds_0114b568);
  _objc_msgSend(uVar5,PTR_s_setFrame__0114b570);
  _objc_msgSend(uVar4,PTR_s_addSubview__0114b0a8,uVar5);
  _objc_msgSend(uVar4,PTR_s_layer_0114ae60);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar7 = _objc_msgSend(param_2,PTR_s_CGContext_0114b940);
  _objc_release(param_2);
  _objc_msgSend(uVar6,PTR_s_renderInContext__0114b948,uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  _objc_release(uVar8);
  CallSupervisor(0x268f);
  return ZEXT816(0x1f);
}


