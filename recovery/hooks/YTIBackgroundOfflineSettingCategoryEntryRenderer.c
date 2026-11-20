// Decompiled hook evidence for YTIBackgroundOfflineSettingCategoryEntryRenderer. This is not compilable Logos source.

// -[YTIBackgroundOfflineSettingCategoryEntryRenderer isBackgroundEnabled], original IMP slot 0x01226010
/* Decompiled from supplied 5.2.2 arm package. VA 0x66600. FUN_00066600 */

uint FUN_00066600(void)

{
  uint uVar1;
  
  DAT_01226a78 = 1;
  uVar1 = _ytpBool(@"backgroundPlayback");
  return uVar1 & 1;
}


