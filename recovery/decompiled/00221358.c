/* Decompiled from supplied 5.2.2 arm package. VA 0x221358. adjustScrollViewInsets */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::adjustScrollViewInsets(ID param_1,SEL param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  long lVar5;
  double dVar6;
  double in_d1;
  double in_d2;
  double in_d3;
  
  puVar2 = PTR_s_image_0114aeb8;
  lVar5 = (long)_imageView;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar5),PTR_s_image_0114aeb8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_size_0114e6b8;
  dVar6 = (double)_objc_msgSend(uVar4,PTR_s_size_0114e6b8);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar5),puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar3);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar5),PTR_s_frame_0114c8b0);
  in_d2 = in_d2 / (dVar6 / in_d1);
  dVar6 = (dVar6 / in_d1) * in_d3;
  if (in_d2 <= in_d3) {
    dVar6 = in_d2;
  }
  ppuVar1 = &PTR_s_adjustHorizontalInsetsWithImageW_0114e6c8;
  if (in_d2 <= in_d3) {
    ppuVar1 = &PTR_s_adjustVerticalInsetsWithImageHei_0114e6c0;
  }
  _objc_msgSend(dVar6,param_1,*ppuVar1);
  CallSupervisor(0x5eda);
  return;
}


