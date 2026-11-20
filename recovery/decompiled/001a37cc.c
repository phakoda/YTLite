/* Decompiled from supplied 5.2.2 arm package. VA 0x1a37cc. FUN_001a37cc */

undefined1  [16] FUN_001a37cc(void)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  puVar1 = PTR_ToastManager_0114ecd0;
  DAT_0122794c = 1;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011ad070,PTR_s_ytl_localized_0114d190);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar2,0);
  _objc_release(uVar2);
  CallSupervisor(0xbfa4);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


