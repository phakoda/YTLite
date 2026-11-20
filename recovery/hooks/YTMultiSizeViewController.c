// Decompiled hook evidence for YTMultiSizeViewController. This is not compilable Logos source.

// -[YTMultiSizeViewController helper], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x48284. FUN_00048284 */

void FUN_00048284(undefined8 param_1)

{
  _objc_getAssociatedObject(param_1,FUN_00048284);
  return;
}



// -[YTMultiSizeViewController setHelper:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x48290. FUN_00048290 */

undefined1  [16] FUN_00048290(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  
  _objc_setAssociatedObject(param_1,FUN_00048284,param_3,1);
  CallSupervisor(0xb4bc);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}


