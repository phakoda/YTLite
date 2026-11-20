/* Decompiled from supplied 5.2.2 arm package. VA 0x43ea0. FUN_00043ea0 */

undefined1  [16] FUN_00043ea0(long param_1)

{
  undefined1 auVar1 [16];
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  _objc_msgSend(0x3ff0000000000000,*(undefined8 *)(param_1 + 0x20),PTR_s_setAlpha__0114b698);
  uStack_48 = *(undefined8 *)(PTR__CGAffineTransformIdentity_010601a8 + 8);
  local_50 = *(undefined8 *)PTR__CGAffineTransformIdentity_010601a8;
  uStack_38 = *(undefined8 *)(PTR__CGAffineTransformIdentity_010601a8 + 0x18);
  uStack_40 = *(undefined8 *)(PTR__CGAffineTransformIdentity_010601a8 + 0x10);
  uStack_28 = *(undefined8 *)(PTR__CGAffineTransformIdentity_010601a8 + 0x28);
  local_30 = *(undefined8 *)(PTR__CGAffineTransformIdentity_010601a8 + 0x20);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_setTransform__0114b910,&local_50);
  CallSupervisor(0x3fe7);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}


