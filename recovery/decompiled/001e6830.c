/* Decompiled from supplied 5.2.2 arm package. VA 0x1e6830. FUN_001e6830 */

undefined1  [16] FUN_001e6830(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  DAT_01227e9c = 1;
  uVar1 = _objc_alloc(*(undefined8 *)(param_1 + 0x20));
  uVar2 = _objc_msgSend(uVar1,PTR_s_initWithSuiteName__0114ce10,
                        &PTR____CFConstantStringClassReference_011baa00);
  uVar1 = uRam0000000001227e90;
  uRam0000000001227e90 = uVar2;
  _objc_release(uVar1);
  _objc_msgSend(uRam0000000001227e90,PTR_s_registerDefaults_0114e120);
  CallSupervisor(0xf1de);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


