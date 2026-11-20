/* Decompiled from supplied 5.2.2 arm package. VA 0x221160. handleDoubleTap: */

/* Function Stack Size: 0x18 bytes */

void DVNImageViewController::handleDoubleTap_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  double dVar4;
  double dVar5;
  double in_d1;
  double in_d2;
  double in_d3;
  
  _objc_retain(param_3);
  lVar3 = (long)_scrollView;
  dVar4 = (double)_objc_msgSend(*(undefined8 *)(param_1 + lVar3),PTR_s_zoomScale_0114e690);
  puVar1 = PTR_s_maximumZoomScale_0114e698;
  dVar5 = (double)_objc_msgSend(*(undefined8 *)(param_1 + lVar3),PTR_s_maximumZoomScale_0114e698);
  if (dVar4 == dVar5) {
    uVar2 = *(undefined8 *)(param_1 + lVar3);
    _objc_msgSend(uVar2,PTR_s_minimumZoomScale_0114e6a8);
    _objc_msgSend(uVar2,PTR_s_setZoomScale_animated__0114e6b0,1);
  }
  else {
    dVar4 = (double)_objc_msgSend(param_3,PTR_s_locationInView__0114c978,
                                  *(undefined8 *)(param_1 + (long)_imageView));
    dVar5 = (double)_objc_msgSend(*(undefined8 *)(param_1 + lVar3),puVar1);
    _objc_msgSend(*(undefined8 *)(param_1 + lVar3),PTR_s_bounds_0114b568);
    _objc_msgSend(dVar4 - (in_d2 / dVar5) * 0.5,in_d1 - (in_d3 / dVar5) * 0.5,
                  *(undefined8 *)(param_1 + lVar3),PTR_s_zoomToRect_animated__0114e6a0,1);
  }
  _objc_release(param_3);
  CallSupervisor(0x22dd);
  return;
}


