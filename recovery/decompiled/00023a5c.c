/* Decompiled from supplied 5.2.2 arm package. VA 0x23a5c. _ytpInt */

undefined8 _ytpInt(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  _objc_retain();
  iVar1 = FUN_000314c8();
  uVar3 = 0;
  if (iVar1 != 0) {
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = _objc_msgSend(uVar2,PTR_s_integerForKey__0114b3a8,param_1);
    _objc_release(uVar2);
  }
  _objc_release(param_1);
  return uVar3;
}


