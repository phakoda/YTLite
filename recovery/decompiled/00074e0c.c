/* Decompiled from supplied 5.2.2 arm package. VA 0x74e0c. FUN_00074e0c */

undefined1  [16] FUN_00074e0c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  DAT_01226ba4 = 1;
  lVar2 = _objc_msgSend(param_3,PTR_s_state_0114c560);
  if ((lVar2 == 1) &&
     (iVar1 = FUN_000db0cc((&PTR_LAB_0117bd58)[lVar2 == 1] +
                           (int)-(uRam000000000117bd68 ^ 0xec8590cc),
                           &PTR____CFConstantStringClassReference_01164650), iVar1 != 0)) {
    _objc_msgSend(PTR_YTPSpeedPopupController_0114ed70,PTR_s_speedController_0114c770);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s__viewControllerForAncestor_0114ade0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_presentFromViewController__0114c778,uVar4);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  CallSupervisor(0x58c7);
  auVar5._8_8_ = 0x1f;
  auVar5._0_8_ = 0x1a;
  return auVar5;
}


