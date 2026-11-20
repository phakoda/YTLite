/* Decompiled from supplied 5.2.2 arm package. VA 0x309c0. FUN_000309c0 */

undefined1  [16] FUN_000309c0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  DAT_01225e30 = 1;
  _objc_retain(param_3);
  thunk_FUN_00028954(&PTR____CFConstantStringClassReference_01158880,param_2,param_3);
  thunk_FUN_00034544(param_1,PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_01158840);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00028954(&PTR____CFConstantStringClassReference_01158800,uVar1,param_3);
  _objc_release(param_3);
  _objc_release(uVar1);
  CallSupervisor(0x7d36);
  return ZEXT816(0x1f);
}


