// Decompiled hook evidence for YTIHamplayerServerABRConfig. This is not compilable Logos source.

// -[YTIHamplayerServerABRConfig skipFilterPreferredVideoFormats], original IMP slot 0x01226758
/* Decompiled from supplied 5.2.2 arm package. VA 0xb56f0. FUN_000b56f0 */

undefined8 FUN_000b56f0(void)

{
  return 1;
}



// -[YTIHamplayerServerABRConfig fallbackOnError], original IMP slot 0x01226760
/* Decompiled from supplied 5.2.2 arm package. VA 0xb56f8. FUN_000b56f8 */

undefined8 FUN_000b56f8(void)

{
  return 1;
}



// -[YTIHamplayerServerABRConfig setFallbackOnError:], original IMP slot 0x01226768
/* Decompiled from supplied 5.2.2 arm package. VA 0xb5700. FUN_000b5700 */

undefined1  [16] FUN_000b5700(undefined8 param_1,undefined8 param_2)

{
  (*DAT_01226768)(param_1,param_2,1);
  CallSupervisor(0x2fd7);
  return ZEXT816(0x1f);
}



// -[YTIHamplayerServerABRConfig useReloadContextForFallback], original IMP slot 0x01226770
/* Decompiled from supplied 5.2.2 arm package. VA 0xb5738. FUN_000b5738 */

undefined8 FUN_000b5738(void)

{
  return 1;
}



// -[YTIHamplayerServerABRConfig setUseReloadContextForFallback:], original IMP slot 0x01226778
/* Decompiled from supplied 5.2.2 arm package. VA 0xb5740. FUN_000b5740 */

undefined1  [16] FUN_000b5740(undefined8 param_1,undefined8 param_2)

{
  undefined1 auVar1 [16];
  
  (*DAT_01226778)(param_1,param_2,1);
  CallSupervisor(0x654d);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTIHamplayerServerABRConfig maxFallbackAttempts], original IMP slot 0x01226780
/* Decompiled from supplied 5.2.2 arm package. VA 0xb5778. FUN_000b5778 */

undefined8 FUN_000b5778(void)

{
  return 0x7fffffff;
}


