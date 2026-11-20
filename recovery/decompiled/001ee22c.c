/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee22c. integerForKey: */

/* Function Stack Size: 0x18 bytes */

long_long YTLUserDefaults::integerForKey_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long_long lVar3;
  
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  lVar3 = _objc_msgSend(uVar2,PTR_s_integerForKey__0114b3a8,param_3);
  _objc_release(param_3);
  _objc_release(uVar2);
  return lVar3;
}


