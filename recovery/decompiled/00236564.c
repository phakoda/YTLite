/* Decompiled from supplied 5.2.2 arm package. VA 0x236564. calculateWidth */

/* Function Stack Size: 0x10 bytes */

double YTPSpeedPopupController::calculateWidth(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  double dVar5;
  double in_d2;
  double in_d3;
  
  puVar2 = PTR_s_mainScreen_0114b768;
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,PTR_s_mainScreen_0114b768);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_bounds_0114b568;
  _objc_msgSend(uVar4,PTR_s_bounds_0114b568);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar1);
  _objc_release(uVar4);
  if (in_d3 <= in_d2) {
    in_d2 = in_d3;
  }
  iVar3 = FUN_00237c94(param_1,PTR_s_isiPad_0114e828);
  dVar5 = 0.5;
  if (iVar3 == 0) {
    dVar5 = DAT_00c4c3b8;
  }
  return in_d2 * dVar5;
}


