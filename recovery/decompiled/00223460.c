/* Decompiled from supplied 5.2.2 arm package. VA 0x223460. setHighlighted: */

/* Function Stack Size: 0x14 bytes */

void BlurButton::setHighlighted_(ID param_1,SEL param_2,bool param_3)

{
  undefined8 uVar1;
  ID local_30;
  undefined *puStack_28;
  
  puStack_28 = PTR_BlurButton_0114f148;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,PTR_s_setHighlighted__0114e6d0);
  uVar1 = 0x3fd0000000000000;
  if (param_3 == 0) {
    uVar1 = 0x3ff0000000000000;
  }
  _objc_msgSend(uVar1,*(undefined8 *)(param_1 + (long)_buttonImageView),PTR_s_setAlpha__0114b698);
  return;
}


