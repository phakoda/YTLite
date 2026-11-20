// Decompiled hook evidence for UIDevice. This is not compilable Logos source.

// -[UIDevice setOrientation:animated:], original IMP slot 0x01225f60
/* Decompiled from supplied 5.2.2 arm package. VA 0x4ead4. FUN_0004ead4 */

undefined1  [16] FUN_0004ead4(void)

{
  dispatch_time_t dVar1;
  
  (*DAT_01225f60)();
  dVar1 = _dispatch_time(0,300000000);
  _dispatch_after(dVar1,PTR___dispatch_main_q_01060760,&PTR___NSConcreteGlobalBlock_01061a20);
  CallSupervisor(0x7088);
  return ZEXT816(0x1f);
}



// -[UIDevice userInterfaceIdiom], original IMP slot 0x01226808
/* Decompiled from supplied 5.2.2 arm package. VA 0xbad20. FUN_000bad20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_000bad20(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  
  DAT_01226f0c = 1;
  lVar1 = _ytpInt(@"idiomIndex");
  if (lVar1 != 0) {
    lVar1 = _ytpInt((&PTR__objc_msgSend_01182268)[lVar1 == 0] +
                    (int)-(uRam0000000001182278 ^ 0x6e2676d2),
                    @"idiomIndex");
    return (ulong)(lVar1 == 1);
  }
                    /* WARNING: Could not recover jumptable at 0x000baee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*_DAT_01226808)(param_1,param_2);
  return uVar2;
}


