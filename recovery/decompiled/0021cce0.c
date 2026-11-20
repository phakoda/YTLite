/* Decompiled from supplied 5.2.2 arm package. VA 0x21cce0. FUN_0021cce0 */

undefined1  [16] FUN_0021cce0(long param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  puVar1 = PTR_s_media_0114ad90;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_media_0114ad90);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_videoID_0114c960);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_0021f214(uVar4,PTR_s_isEqualToString__0114ae48,
                       *(undefined8 *)(*(long *)(param_1 + 0x20) + 8));
  _objc_release(uVar4);
  _objc_release(uVar3);
  if (uVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011cdde0)[uVar2] + (int)-(DAT_011cddf0 ^ 0x169dc72),
                  *(undefined8 *)(param_1 + 0x20),puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_setIsPaused__0114ad98,0);
    _objc_release(uVar3);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_sendBody_0114e5d0);
  }
  CallSupervisor(0x9db7);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


