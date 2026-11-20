/* Decompiled from supplied 5.2.2 arm package. VA 0x122b2c. FUN_00122b2c */

undefined1  [16] FUN_00122b2c(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  uVar1 = _objc_msgSend(param_2,PTR_s_CGContext_0114b940);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_blackColor_0114c400);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3fd0000000000000,uVar2,PTR_s_colorWithAlphaComponent__0114b548);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_retainAutorelease();
  uVar4 = _objc_msgSend(uVar4,PTR_s_CGColor_0114c8c0);
  _CGContextSetShadowWithColor(0,0x3fe0000000000000,0x3ff0000000000000,uVar1,uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_whiteColor_0114b080);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setFill_0114d5a8);
  _objc_release(uVar2);
  _CGContextAddArc(0x4018000000000000,0x401e000000000000,0x4018000000000000,0,DAT_00c4c370,uVar1,1);
  _CGContextFillPath(uVar1);
  CallSupervisor(0xdb6f);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


