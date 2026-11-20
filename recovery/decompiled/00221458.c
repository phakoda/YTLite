/* Decompiled from supplied 5.2.2 arm package. VA 0x221458. adjustHorizontalInsetsWithImageWidth: */

/* Function Stack Size: 0x18 bytes */

void __thiscall
DVNImageViewController::adjustHorizontalInsetsWithImageWidth_
          (DVNImageViewController *this,ID param_1,SEL param_2,double param_3)

{
  undefined *puVar1;
  long lVar2;
  double dVar3;
  double in_d2;
  
  lVar2 = (long)_scrollView;
  dVar3 = (double)_objc_msgSend(*(undefined8 *)(this + lVar2),PTR_s_contentSize_0114e680);
  puVar1 = PTR_s_frame_0114c8b0;
  dVar3 = (dVar3 - param_3) * 0.5;
  _objc_msgSend(*(undefined8 *)(this + lVar2),PTR_s_frame_0114c8b0);
  if (param_3 < in_d2) {
    _objc_msgSend((&PTR_LAB_011ce340)[param_3 < in_d2] + (int)-(DAT_011ce350 ^ 0xb33326ec),
                  *(undefined8 *)(this + lVar2),puVar1);
    dVar3 = dVar3 + (in_d2 - param_3) * -0.5;
  }
  _objc_msgSend(0,-dVar3,0,-dVar3,*(undefined8 *)(this + lVar2),PTR_s_setContentInset__0114b810);
  CallSupervisor(0x8ba8);
  return;
}


