/* Decompiled from supplied 5.2.2 arm package. VA 0x2159b8. applyTitle:image:color:toBar: */

/* Function Stack Size: 0x30 bytes */

void YTPSleepTimer::applyTitle_image_color_toBar_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  _objc_retain(param_4);
  puVar1 = PTR_s_attributedTitle_image__0114e4e0;
  if (param_6 != 0) {
    _objc_retain(param_6);
    _objc_retain(param_5);
    _objc_msgSend(param_1,puVar1,param_3,param_4);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_6,PTR_s_statusLabel_0114e4e8);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_setAttributedText__0114b678,uVar2);
    _objc_release(uVar3);
    _objc_release(uVar2);
    _objc_msgSend(param_6,PTR_s_setBackgroundColor__0114b550,param_5);
    _objc_release(param_5);
    _objc_msgSend(param_6,PTR_s_setDisplayed__0114e4f0,1);
    _objc_msgSend(param_6,PTR_s_setDismissing__0114e4f8,0);
    _objc_release(param_6);
    _objc_storeStrong(param_1 + 0x18,param_4);
  }
  (*(code *)PTR__objc_release_01061028)(param_4);
  return;
}


