/* Decompiled from supplied 5.2.2 arm package. VA 0x215554. slimBarForStyle: */

/* Function Stack Size: 0x18 bytes */

ID YTPSleepTimer::slimBarForStyle_(ID param_1,SEL param_2,unsigned_long_long param_3)

{
  undefined **ppuVar1;
  ID IVar2;
  
  ppuVar1 = &PTR_s_playerSlimBar_0114e4d0;
  if (param_3 != 1) {
    ppuVar1 = &PTR_s_globalSlimBar_0114e4d8;
  }
  _objc_msgSend(param_1,*ppuVar1);
  _objc_retainAutoreleasedReturnValue();
  IVar2 = _objc_autoreleaseReturnValue();
  return IVar2;
}


