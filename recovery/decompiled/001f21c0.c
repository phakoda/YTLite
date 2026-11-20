/* Decompiled from supplied 5.2.2 arm package. VA 0x1f21c0. isTouchInSpeedZone: */

/* Function Stack Size: 0x20 bytes */

bool DVNLongPressDelegate::isTouchInSpeedZone_(ID param_1,SEL param_2,CGPoint param_3)

{
  bool bVar1;
  long lVar2;
  
  lVar2 = _objc_msgSend(param_3.field0_0x0,param_3.field1_0x8,param_1,PTR_s_mode_0114e238);
  if (lVar2 != 0) {
    _objc_msgSend(param_1,PTR_s_view_0114b090);
    lVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x001f22dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    bVar1 = (*(code *)((&PTR_LAB_011bd718)[lVar2 == 0] + (int)-(uRam00000000011bd728 ^ 0x8ec836a3)))
                      ();
    return bVar1;
  }
  return 0;
}


