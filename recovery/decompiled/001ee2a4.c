/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee2a4. floatForKey: */

/* Function Stack Size: 0x18 bytes */

double YTLUserDefaults::floatForKey_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  float fVar3;
  
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  fVar3 = (float)_objc_msgSend(uVar2,PTR_s_floatForKey__0114c308,param_3);
  _objc_release(param_3);
  _objc_release(uVar2);
  return (double)fVar3;
}


