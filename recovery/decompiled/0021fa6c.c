/* Decompiled from supplied 5.2.2 arm package. VA 0x21fa6c. viewDidLoad */

/* Function Stack Size: 0x10 bytes */

void DVNImageViewController::viewDidLoad(ID param_1,SEL param_2)

{
  ID local_30;
  undefined *puStack_28;
  
  puStack_28 = PTR_DVNImageViewController_0114f140;
  local_30 = param_1;
  _objc_msgSendSuper2(&local_30,PTR_s_viewDidLoad_0114b070);
  _objc_msgSend(param_1,PTR_s_setupNavbar_0114e600);
  _objc_msgSend(param_1,PTR_s_setupViewer_0114e608);
  CallSupervisor(0xc08d);
  return;
}


