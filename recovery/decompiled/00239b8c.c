/* Decompiled from supplied 5.2.2 arm package. VA 0x239b8c. sliderTapped: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedControlView::sliderTapped_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  long lVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  double in_d2;
  
  lVar2 = (long)_slider;
  dVar6 = (double)_objc_msgSend(param_3,PTR_s_locationInView__0114c978,
                                *(undefined8 *)(param_1 + lVar2));
  _objc_msgSend(*(undefined8 *)(param_1 + lVar2),PTR_s_bounds_0114b568);
  puVar1 = PTR_s_minimumValue_0114d400;
  fVar3 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar2),PTR_s_minimumValue_0114d400);
  fVar4 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar2),PTR_s_maximumValue_0114d408);
  fVar5 = (float)_objc_msgSend(*(undefined8 *)(param_1 + lVar2),puVar1);
  fVar3 = *(float *)(param_1 + (long)_step) *
          (float)(int)((fVar3 + (fVar4 - fVar5) * (float)(dVar6 / in_d2)) /
                      *(float *)(param_1 + (long)_step));
  _objc_msgSend(fVar3,*(undefined8 *)(param_1 + lVar2),PTR_s_setValue__0114d560);
  _objc_msgSend(fVar3,param_1,PTR_s_updateLabel__0114e888);
  CallSupervisor(0xeca0);
  return;
}


