// Decompiled hook evidence for YTSettings. This is not compilable Logos source.

// -[YTSettings setDisableMDXDeviceDiscovery:], original IMP slot 0x012261d0
/* Decompiled from supplied 5.2.2 arm package. VA 0x6eac4. FUN_0006eac4 */

void FUN_0006eac4(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  
  DAT_01226b64 = 1;
  uVar1 = FUN_000d8a70(@"noCast");
                    /* WARNING: Could not recover jumptable at 0x0006ebf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_012261d0)(param_1,param_2,uVar1 | param_3);
  return;
}



// -[YTSettings areHintsDisabled], original IMP slot 0x012261d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x6ebf4. FUN_0006ebf4 */

void FUN_0006ebf4(void)

{
  DAT_01226b68 = 1;
  FUN_000d8a94(@"noHints");
  return;
}



// -[YTSettings setHintsDisabled:], original IMP slot 0x012261e0
/* Decompiled from supplied 5.2.2 arm package. VA 0x6ecf4. FUN_0006ecf4 */

void FUN_0006ecf4(undefined8 param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  
  DAT_01226b6c = 1;
  uVar1 = FUN_000d8ab8(@"noHints");
                    /* WARNING: Could not recover jumptable at 0x0006ee20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_012261e0)(param_1,param_2,uVar1 | param_3);
  return;
}


