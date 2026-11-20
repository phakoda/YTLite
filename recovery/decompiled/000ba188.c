/* Decompiled from supplied 5.2.2 arm package. VA 0xba188. FUN_000ba188 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000ba188(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined1 auVar4 [16];
  
  DAT_01226efc = 1;
  _objc_retain(param_3);
  lVar1 = _ytpInt(&PTR____CFConstantStringClassReference_011712d0);
  if (lVar1 != 0) {
    lVar1 = _ytpInt((&PTR_LAB_01182108)[lVar1 == 0] + (int)-(uRam0000000001182118 ^ 0x9b222ff1),
                    &PTR____CFConstantStringClassReference_011712d0);
    if (lVar1 != 1) {
      _objc_msgSend(param_1,PTR_s_valueForKey__0114ae90,
                    &PTR____CFConstantStringClassReference_01171290);
      uVar2 = _objc_retainAutoreleasedReturnValue();
      if (DAT_01226890 == 0) {
        DAT_01226890 = _objc_getClass((&PTR_LAB_01182140)[DAT_01226890 == 0] +
                                      (int)-(uRam0000000001182150 ^ 0x7ffe220c),
                                      s_YTMainAppVideoPlayerOverlayViewC_01171210);
      }
      lVar1 = DAT_01226890;
      _objc_retainAutorelease(DAT_01226890);
      uVar3 = FUN_000eaef4(uVar2,PTR_s_isKindOfClass__0114ad70,lVar1);
                    /* WARNING: Could not recover jumptable at 0x000ba758. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      auVar4 = (*(code *)((&PTR_LAB_01182160)[uVar3 & 0xffffffff] +
                         (int)-(uRam0000000001182170 ^ 0xb1e926e8)))();
      return auVar4;
    }
    (*_DAT_012267e8)(param_1,param_2,param_3);
  }
  _objc_release(param_3);
  CallSupervisor(0xd8ab);
  return ZEXT816(0x1f);
}


