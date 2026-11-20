/* Decompiled from supplied 5.2.2 arm package. VA 0x22156c. adjustVerticalInsetsWithImageHeight: */

/* Function Stack Size: 0x18 bytes */

void DVNImageViewController::adjustVerticalInsetsWithImageHeight_
               (ID param_1,SEL param_2,double param_3)

{
  undefined *puVar1;
  long lVar2;
  double in_d1;
  double in_d3;
  double dVar3;
  
  lVar2 = (long)_scrollView;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar2),PTR_s_contentSize_0114e680);
  puVar1 = PTR_s_frame_0114c8b0;
  dVar3 = (in_d1 - param_3) * 0.5;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar2),PTR_s_frame_0114c8b0);
  if (param_3 < in_d3) {
    _objc_msgSend((&PTR_LAB_011ce360)[param_3 < in_d3] + (int)-(DAT_011ce370 ^ 0xa0aa92b),
                  *(undefined8 *)(param_1 + lVar2),puVar1);
    dVar3 = dVar3 + (in_d3 - param_3) * -0.5;
  }
  _objc_msgSend(-dVar3,0,-dVar3,0,*(undefined8 *)(param_1 + lVar2),PTR_s_setContentInset__0114b810);
  CallSupervisor(0xdec9);
  return;
}


