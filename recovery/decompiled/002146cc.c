/* Decompiled from supplied 5.2.2 arm package. VA 0x2146cc. FUN_002146cc */

void FUN_002146cc(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = _objc_msgSend(PTR__OBJC_CLASS___NSDateComponentsFormatter_0114ee40,PTR_s_new_0114b030);
  uVar1 = DAT_012280f0;
  DAT_012280f0 = uVar2;
  _objc_release(uVar1);
  _objc_msgSend(DAT_012280f0,PTR_s_setUnitsStyle__0114d500,2);
  _objc_msgSend(DAT_012280f0,PTR_s_setAllowedUnits__0114db50,0xe0);
  _objc_msgSend(DAT_012280f0,PTR_s_setMaximumUnitCount__0114e3a8,2);
  _objc_msgSend(DAT_012280f0,PTR_s_setZeroFormattingBehavior__0114db48,0xe);
  return;
}


