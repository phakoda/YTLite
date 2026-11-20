/* Decompiled from supplied 5.2.2 arm package. VA 0x239ae0. sliderChanged: */

/* Function Stack Size: 0x18 bytes */

void YTPSpeedControlView::sliderChanged_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  float fVar2;
  
  puVar1 = PTR_s_value_0114cdf0;
  _objc_retain(param_3);
  fVar2 = (float)_objc_msgSend(param_3,puVar1);
  fVar2 = *(float *)(param_1 + (long)_step) *
          (float)(int)(fVar2 / *(float *)(param_1 + (long)_step));
  _objc_msgSend(fVar2,param_3,PTR_s_setValue__0114d560);
  _objc_release(param_3);
  _objc_msgSend(fVar2,param_1,PTR_s_updateLabel__0114e888);
  CallSupervisor(0x4818);
  return;
}


