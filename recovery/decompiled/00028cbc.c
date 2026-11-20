/* Decompiled from supplied 5.2.2 arm package. VA 0x28cbc. FUN_00028cbc */

undefined1  [16] FUN_00028cbc(void)

{
  undefined8 uVar1;
  
  DAT_01225e0c = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,PTR_s_defaultCenter_0114b3e0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_postNotificationName_object__0114b3e8,
                &PTR____CFConstantStringClassReference_01157650,0);
  _objc_release(uVar1);
  CallSupervisor(0x57b2);
  return ZEXT816(0x1f);
}


