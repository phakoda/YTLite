// Decompiled hook evidence for _UIConcretePasteboard. This is not compilable Logos source.

// -[_UIConcretePasteboard setString:], original IMP slot 0x01226628
/* Decompiled from supplied 5.2.2 arm package. VA 0xa32d0. FUN_000a32d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000a32d0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  
  DAT_01226df8 = 1;
  _objc_retain(param_3);
  uVar1 = FUN_000e5900(@"noShareChunk");
  if (uVar1 != 0) {
    thunk_FUN_000cc72c((&PTR_LAB_011802f0)[uVar1] + (int)-(uRam0000000001180300 ^ 0xf41c3a5a),
                       param_3);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_3);
    param_3 = uVar2;
  }
  (*_DAT_01226628)(param_1,param_2,param_3);
  _objc_release(param_3);
  CallSupervisor(0x2fbb);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


