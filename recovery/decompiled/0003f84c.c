/* Decompiled from supplied 5.2.2 arm package. VA 0x3f84c. thanksButtonTapped */

/* Function Stack Size: 0x10 bytes */

void WelcomeVC::thanksButtonTapped(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  DAT_01225eb4 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_setBool_forKey__0114add8,1,
                &PTR____CFConstantStringClassReference_0115ba40);
  _objc_release(uVar1);
  _objc_msgSend(param_1,PTR_s_dismissViewControllerAnimated_co_0114aed0,1,0);
  CallSupervisor(0xfec2);
  return;
}


