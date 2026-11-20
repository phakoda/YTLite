/* Decompiled from supplied 5.2.2 arm package. VA 0x17dfe4. FUN_0017dfe4 */

undefined1  [16] FUN_0017dfe4(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  DAT_01227544 = 1;
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_011a6af0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_openURL__0114d828,uVar2);
  _objc_release(uVar2);
  CallSupervisor(0x3853);
  return ZEXT816(0x1f);
}


