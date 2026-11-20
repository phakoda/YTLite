/* Decompiled from supplied 5.2.2 arm package. VA 0x511ac. FUN_000511ac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000511ac(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  DAT_01226a38 = 1;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  iVar2 = FUN_000d1480(uVar3,PTR_s_boolForKey__0114ada8,
                       &PTR____CFConstantStringClassReference_0115eca0);
  uVar1 = 0;
  if (iVar2 == 0) {
    uVar1 = param_3;
  }
  (*_DAT_01225fa8)(param_1,param_2,uVar1);
  _objc_release(uVar3);
  CallSupervisor(0xa02d);
  return ZEXT816(0x1f);
}


