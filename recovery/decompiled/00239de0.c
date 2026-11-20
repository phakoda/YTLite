/* Decompiled from supplied 5.2.2 arm package. VA 0x239de0. presetTapped: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedControlView::presetTapped_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  
  lVar1 = _objc_msgSend(param_3,PTR_s_tag_0114b868);
  _objc_msgSend((float)((double)lVar1 / 100.0),*(undefined8 *)(param_1 + (long)_slider),
                PTR_s_setValue__0114d560);
  _objc_msgSend((float)((double)lVar1 / 100.0),param_1,PTR_s_updateLabel__0114e888);
  CallSupervisor(0x8e87);
  return;
}


