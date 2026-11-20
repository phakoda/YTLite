/* Decompiled from supplied 5.2.2 arm package. VA 0x239c94. minusTapped */

/* Function Stack Size: 0x10 bytes */

void YTPSpeedControlView::minusTapped(ID param_1,SEL param_2)

{
  long lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar1 = (long)_slider;
  fVar2 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar1),PTR_s_minimumValue_0114d400);
  fVar3 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar1),PTR_s_value_0114cdf0);
  fVar5 = *(float *)(param_1 + (long)_step);
  fVar4 = fVar3 - fVar5;
  if (fVar3 - fVar5 <= fVar2) {
    fVar4 = fVar2;
  }
  fVar5 = fVar5 * (float)(int)(fVar4 / fVar5);
  _objc_msgSend(fVar5,*(undefined8 *)(param_1 + lVar1),PTR_s_setValue__0114d560);
  _objc_msgSend(fVar5,param_1,PTR_s_updateLabel__0114e888);
  CallSupervisor(0xbe77);
  return;
}


