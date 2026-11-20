/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee42c. setFloat:forKey: */

/* Function Stack Size: 0x20 bytes */

void YTLUserDefaults::setFloat_forKey_(ID param_1,SEL param_2,double param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_retain(param_4);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend((float)param_3,uVar2,PTR_s_setFloat_forKey__0114d518,param_4);
  _objc_release(param_4);
  _objc_release(uVar2);
  CallSupervisor(0xec62);
  return;
}


