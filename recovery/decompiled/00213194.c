/* Decompiled from supplied 5.2.2 arm package. VA 0x213194. FUN_00213194 */

undefined1  [16] FUN_00213194(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_date_0114b4d0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_secondsForDate__0114e3e0,uVar2);
  _objc_msgSend(uVar1,PTR_s_startForSeconds__0114e3b0);
  _objc_release(uVar2);
  CallSupervisor(0x948c);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


