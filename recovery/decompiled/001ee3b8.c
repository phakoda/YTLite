/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee3b8. setInteger:forKey: */

/* Function Stack Size: 0x20 bytes */

void YTLUserDefaults::setInteger_forKey_(ID param_1,SEL param_2,long_long param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_retain(param_4);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setInteger_forKey__0114c2d8,param_3,param_4);
  _objc_release(param_4);
  _objc_release(uVar2);
  return;
}


