/* Decompiled from supplied 5.2.2 arm package. VA 0x28280. FUN_00028280 */

void FUN_00028280(void)

{
  undefined8 uVar1;
  
  DAT_01225dfc = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSNotificationCenter_0114eb88,PTR_s_defaultCenter_0114b3e0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_postNotificationName_object__0114b3e8,
                &PTR____CFConstantStringClassReference_01157500,0);
  _objc_release(uVar1);
  if (lRam0000000001225d50 == 0) {
    lRam0000000001225d50 =
         _objc_getClass((&PTR_LAB_011596e0)[lRam0000000001225d50 == 0] +
                        (int)-(uRam00000000011596f0 ^ 0x66c21c4f),
                        s_YTHeaderContentComboViewControll_01157470);
  }
  _objc_retainAutorelease();
  uVar1 = _objc_alloc_init();
  _objc_msgSend(uVar1,PTR_s_refreshPivotBar_0114b470);
  (*(code *)PTR__objc_release_01061028)(uVar1);
  return;
}


