/* Decompiled from supplied 5.2.2 arm package. VA 0x239d48. plusTapped */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedControlView::plusTapped(ID param_1,SEL param_2)

{
  long lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  lVar1 = (long)_slider;
  fVar2 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar1),PTR_s_maximumValue_0114d408);
  fVar3 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar1),PTR_s_value_0114cdf0);
  fVar4 = *(float *)(param_1 + (long)_step);
  if (fVar3 + fVar4 <= fVar2) {
    fVar2 = fVar3 + fVar4;
  }
  fVar4 = fVar4 * (float)(int)(fVar2 / fVar4);
  _objc_msgSend(fVar4,*(undefined8 *)(param_1 + lVar1),PTR_s_setValue__0114d560);
  _objc_msgSend(fVar4,param_1,PTR_s_updateLabel__0114e888);
  return;
}


