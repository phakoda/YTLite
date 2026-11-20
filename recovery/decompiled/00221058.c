/* Decompiled from supplied 5.2.2 arm package. VA 0x221058. viewDidLayoutSubviews */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::viewDidLayoutSubviews(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  double dVar4;
  double in_d1;
  double dVar5;
  double in_d2;
  double in_d3;
  double dVar6;
  ID local_60;
  undefined *puStack_58;
  
  puStack_58 = PTR_DVNImageViewController_0114f140;
  local_60 = param_1;
  _objc_msgSendSuper2(&local_60,PTR_s_viewDidLayoutSubviews_0114e670);
  _objc_msgSend(param_1,PTR_s_adjustScrollViewInsets_0114e678);
  puVar2 = PTR_s_contentSize_0114e680;
  lVar3 = (long)_scrollView;
  dVar4 = (double)_objc_msgSend(*(undefined8 *)(param_1 + lVar3),PTR_s_contentSize_0114e680);
  puVar1 = PTR_s_bounds_0114b568;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar3),PTR_s_bounds_0114b568);
  dVar6 = (dVar4 - in_d2) * 0.5;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar3),puVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + lVar3),puVar1);
  dVar5 = (in_d1 - in_d3) * 0.5;
  dVar4 = 0.0;
  if (0.0 <= dVar6) {
    dVar4 = dVar6;
  }
  dVar6 = 0.0;
  if (0.0 <= dVar5) {
    dVar6 = dVar5;
  }
  _objc_msgSend(dVar4,dVar6,*(undefined8 *)(param_1 + lVar3),PTR_s_setContentOffset__0114e688);
  CallSupervisor(0x9d1f);
  return;
}


