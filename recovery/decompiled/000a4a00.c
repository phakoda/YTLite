/* Decompiled from supplied 5.2.2 arm package. VA 0xa4a00. FUN_000a4a00 */

undefined1  [16] FUN_000a4a00(undefined8 param_1)

{
  undefined8 uVar1;
  
  DAT_01226e08 = 1;
  _objc_msgSend(param_1,PTR_s_valueForKey__0114ae90,&PTR____CFConstantStringClassReference_0116d380)
  ;
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_showFullScreen_0114cb70);
  _objc_release(uVar1);
  CallSupervisor(0x4afd);
  return ZEXT816(0x1f);
}


