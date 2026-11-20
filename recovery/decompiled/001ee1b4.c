/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee1b4. boolForKey: */

/* Function Stack Size: 0x18 bytes */

bool YTLUserDefaults::boolForKey_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 uVar3;
  
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_retain(param_3);
  _objc_msgSend(param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  bVar2 = FUN_001ef6ac(uVar3,PTR_s_boolForKey__0114ada8,param_3);
  _objc_release(param_3);
  _objc_release(uVar3);
  return bVar2;
}


