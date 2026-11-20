/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee158. resetUserDefaults */

/* Function Stack Size: 0x10 bytes */

void YTLUserDefaults::resetUserDefaults(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  
  _objc_msgSend(param_1,PTR_s_standardUserDefaults_0114afa0);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_reset_0114e178);
  _objc_release(uVar1);
  CallSupervisor(0x4d7f);
  return;
}


