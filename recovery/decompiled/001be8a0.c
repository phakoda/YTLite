/* Decompiled from supplied 5.2.2 arm package. VA 0x1be8a0. updateLayout */

/* Function Stack Size: 0x10 bytes */

void ToastView::updateLayout(ID param_1,SEL param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  double dVar4;
  double dVar5;
  double in_d2;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011b4258;
  lVar3 = *(long *)(param_1 + (long)_sourceView);
  local_3c = (uint)(lVar3 == 0);
  if (lVar3 != 0) {
    _objc_msgSend(lVar3,PTR_s_frame_0114c8b0);
    cVar1 = *(char *)(param_1 + (long)_isiPad);
    iVar2 = FUN_001c5fbc(param_1,PTR_s_isLandscape_0114dd30);
    dVar4 = DAT_00c4c2e0;
    if (iVar2 == 0) {
      dVar4 = 0.5;
    }
    dVar5 = 0.5;
    if (iVar2 == 0) {
      dVar5 = DAT_00c4c3b8;
    }
    if (cVar1 != '\0') {
      dVar5 = dVar4;
    }
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_keyboardHeight),param_1,
                  PTR_s_calculateToastParametersWithKeyb_0114dd38,&uStack_48,&uStack_50,&uStack_58);
    _objc_msgSend(uStack_48,uStack_50,uStack_58,in_d2 * dVar5,0x3fe0000000000000,param_1,
                  PTR_s_configureToastAppearanceWithBott_0114ddc8);
  }
  CallSupervisor(0x3db5);
  return;
}


