/* Decompiled from supplied 5.2.2 arm package. VA 0xbad20. FUN_000bad20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_000bad20(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  
  DAT_01226f0c = 1;
  lVar1 = _ytpInt(&PTR____CFConstantStringClassReference_01171450);
  if (lVar1 != 0) {
    lVar1 = _ytpInt((&PTR__objc_msgSend_01182268)[lVar1 == 0] +
                    (int)-(uRam0000000001182278 ^ 0x6e2676d2),
                    &PTR____CFConstantStringClassReference_01171450);
    return (ulong)(lVar1 == 1);
  }
                    /* WARNING: Could not recover jumptable at 0x000baee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*_DAT_01226808)(param_1,param_2);
  return uVar2;
}


