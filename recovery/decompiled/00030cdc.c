/* Decompiled from supplied 5.2.2 arm package. VA 0x30cdc. FUN_00030cdc */

undefined1  [16] FUN_00030cdc(void)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  
  DAT_01225e3c = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,PTR_s_defaultCenter_0114b3e0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_postNotificationName_object__0114b3e8,
                &PTR____CFConstantStringClassReference_01158900,0);
  _objc_release(uVar1);
  CallSupervisor(0xf373);
  auVar2._8_8_ = 0x1f;
  auVar2._0_8_ = 0x1a;
  return auVar2;
}


