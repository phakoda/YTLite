/* Decompiled from supplied 5.2.2 arm package. VA 0x1ee328. setBool:forKey: */

/* Function Stack Size: 0x1c bytes */

void YTLUserDefaults::setBool_forKey_(ID param_1,SEL param_2,bool param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  puVar1 = PTR_s_standardUserDefaults_0114afa0;
  _objc_retain(param_4);
  _objc_msgSend(param_1,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setBool_forKey__0114add8,param_3,param_4);
  _objc_release(param_4);
  _objc_release(uVar2);
  CallSupervisor(0xa961);
  return;
}


