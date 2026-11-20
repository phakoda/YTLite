/* Decompiled from supplied 5.2.2 arm package. VA 0x236c0. FUN_000236c0 */

void FUN_000236c0(void)

{
  undefined8 uVar1;
  long lVar2;
  
  DAT_01225d9c = 1;
  thunk_FUN_000287c0();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00027078(&PTR____CFConstantStringClassReference_01156840,uVar1);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else {
    thunk_FUN_00027078((&PTR_LAB_011591d0)[lVar2 == 0] + (int)-(uRam00000000011591e0 ^ 0xe155d8f5),
                       &PTR____CFConstantStringClassReference_01156800,lVar2);
    uVar1 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_release(lVar2);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar1);
  return;
}


