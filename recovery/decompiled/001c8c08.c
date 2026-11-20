/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8c08. makeKeyAndVisible */

/* Function Stack Size: 0x10 bytes */

void ToastWindow::makeKeyAndVisible(ID param_1,SEL param_2)

{
  ID local_40;
  undefined *puStack_38;
  int local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011b4c88;
  puStack_38 = PTR_ToastWindow_0114f0f0;
  local_40 = param_1;
  _objc_msgSendSuper2(&local_40,PTR_s_makeKeyAndVisible_0114b788);
  local_2c = FUN_001c984c(param_1,PTR_s_isKeyWindow_0114deb8);
  if (local_2c != 0) {
    _objc_msgSend(param_1,PTR_s_resignKeyWindow_0114dec0);
  }
  CallSupervisor(0x5907);
  return;
}


