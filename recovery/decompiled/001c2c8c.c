/* Decompiled from supplied 5.2.2 arm package. VA 0x1c2c8c. bottomOffset */

/* Function Stack Size: 0x10 bytes */

double ToastView::bottomOffset(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  double dVar5;
  
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_offsetController_0114dea8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  puVar1 = PTR_s_bottomOffset_0114ddd0;
  uVar2 = FUN_001c7d94(uVar4,PTR_s_respondsToSelector__0114af58,PTR_s_bottomOffset_0114ddd0);
  if (uVar2 == 0) {
    dVar5 = 0.0;
  }
  else {
    dVar5 = (double)_objc_msgSend((&PTR_LAB_011b4580)[uVar2] + (int)-(DAT_011b4590 ^ 0xbd4e97d6),
                                  uVar4,puVar1);
  }
  _objc_release(uVar4);
  return dVar5;
}


