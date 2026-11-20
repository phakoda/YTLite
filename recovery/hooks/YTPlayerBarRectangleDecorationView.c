// Decompiled hook evidence for YTPlayerBarRectangleDecorationView. This is not compilable Logos source.

// -[YTPlayerBarRectangleDecorationView applyGradientColorForRect:withOverallGradient:], original IMP slot 0x01225c48
/* Decompiled from supplied 5.2.2 arm package. VA 0x21598. FUN_00021598 */

undefined1  [16] FUN_00021598(undefined8 param_1)

{
  undefined1 auVar1 [16];
  
  (*DAT_01225c48)();
  _objc_msgSend(PTR_SBPlayerDecorator_0114eb60,@selector(drawSegmentsDecorationView:),param_1);
  CallSupervisor(0x8b87);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTPlayerBarRectangleDecorationView drawProgressRect:withColor:], original IMP slot 0x01225c50
/* Decompiled from supplied 5.2.2 arm package. VA 0x215f0. FUN_000215f0 */

undefined1  [16] FUN_000215f0(undefined8 param_1)

{
  undefined1 auVar1 [16];
  
  (*DAT_01225c50)();
  _objc_msgSend(PTR_SBPlayerDecorator_0114eb60,@selector(drawSegmentsDecorationView:),param_1);
  CallSupervisor(0xed7f);
  auVar1._8_8_ = 0x1f;
  auVar1._0_8_ = 0x1a;
  return auVar1;
}



// -[YTPlayerBarRectangleDecorationView isStateActive], original IMP slot 0x01225c58
/* Decompiled from supplied 5.2.2 arm package. VA 0x21648. FUN_00021648 */

void FUN_00021648(undefined8 param_1,undefined8 param_2)

{
  _objc_msgSend(PTR_SBPlayerDecorator_0114eb60,@selector(drawSegmentsDecorationView:),param_1);
                    /* WARNING: Could not recover jumptable at 0x0002168c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_01225c58)(param_1,param_2);
  return;
}



// -[YTPlayerBarRectangleDecorationView applyGradientForRect:], original IMP slot 0x01226540
/* Decompiled from supplied 5.2.2 arm package. VA 0x9125c. FUN_0009125c */

void FUN_0009125c(undefined8 param_1)

{
  long lVar1;
  
  DAT_01226d80 = 1;
  (*DAT_01226540)(param_1);
  lVar1 = _ytpInt(@"progressBarIndex");
                    /* WARNING: Could not recover jumptable at 0x000919d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117e760)[lVar1 == 0] + (int)-(DAT_0117e770 ^ 0x3143f12c)))();
  return;
}



// -[YTPlayerBarRectangleDecorationView drawProgressRect:withColor:], original IMP slot 0x01226548
/* Decompiled from supplied 5.2.2 arm package. VA 0x92210. FUN_00092210 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
FUN_00092210(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,undefined8 param_6,long param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined1 auVar6 [16];
  
  DAT_01226d84 = 1;
  _objc_retain(param_7);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,@selector(objectForKey:),@"progressMainColor");
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  puVar1 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar2 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(class));
  _objc_msgSend(puVar1,@selector(unarchivedObjectOfClass:fromData:error:),uVar2,uVar3,0);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  lVar5 = _ytpInt(@"progressBarIndex");
  if (lVar5 != 0 && lVar4 != 0) {
    _objc_retain((&PTR_LAB_0117e8e8)[lVar5 != 0 && lVar4 != 0] + (int)-(DAT_0117e8f8 ^ 0xd7fe6dd5),
                 lVar4);
    _objc_release(param_7);
    param_7 = lVar4;
  }
  (*_DAT_01226548)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  _objc_release(lVar4);
  _objc_release(uVar3);
  _objc_release(param_7);
  CallSupervisor(0xaf64);
  auVar6._8_8_ = 0x1f;
  auVar6._0_8_ = 0x1a;
  return auVar6;
}



// -[YTPlayerBarRectangleDecorationView applyGradientColorForRect:withOverallGradient:], original IMP slot 0x01226550
/* Decompiled from supplied 5.2.2 arm package. VA 0x92648. FUN_00092648 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00092648(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined **local_d8;
  undefined **ppuStack_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **local_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  uint local_94;
  undefined **local_90;
  long local_88;
  
  local_88 = *(long *)PTR____stack_chk_guard_01060708;
  local_90 = &PTR_LAB_0117e908;
  local_94 = (uint)(DAT_01226d88 == 0);
  local_a8 = &PTR_LAB_0117e928;
  local_c0 = &PTR_LAB_0117e948;
  local_a0 = &PTR_LAB_01175340;
  local_b8 = &PTR_LAB_01175340;
  local_d8 = &PTR_LAB_01175340;
  ppuStack_d0 = &PTR_LAB_01175340;
  DAT_01226d88 = 1;
  local_e8 = param_5;
  uStack_e0 = param_6;
  _objc_retain(param_7);
  puVar1 = @selector(standardUserDefaults);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,@selector(standardUserDefaults));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(objectForKey:);
  _objc_msgSend(uVar4,@selector(objectForKey:),@"progressMainColor");
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar2,@"progressGradientColor");
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  puVar3 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  puVar1 = @selector(class);
  uVar4 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,@selector(class));
  puVar2 = @selector(unarchivedObjectOfClass:fromData:error:);
  _objc_msgSend(puVar3,@selector(unarchivedObjectOfClass:fromData:error:),uVar4,uVar5,0);
  lVar7 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR__OBJC_CLASS___NSKeyedUnarchiver_0114ec50;
  uVar4 = _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,puVar1);
  _objc_msgSend(puVar3,puVar2,uVar4,uVar6,0);
  lVar8 = _objc_retainAutoreleasedReturnValue();
  lVar9 = _ytpInt(@"progressBarIndex");
  uStack_ac = (uint)(lVar9 == 1 && lVar7 != 0);
  if (lVar9 == 1 && lVar7 != 0) {
    uVar4 = _objc_retainAutorelease(local_a8[uStack_ac] + (int)-(DAT_0117e938 ^ 0xf943391c),lVar7);
    puVar1 = @selector(CGColor);
    uStack_100 = _objc_msgSend(uVar4,@selector(CGColor));
    uVar4 = _objc_retainAutorelease(lVar7);
    uStack_f8 = _objc_msgSend(uVar4,puVar1);
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  &uStack_100,2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    lVar9 = _ytpInt(@"progressBarIndex");
    uStack_c4 = (uint)((lVar7 != 0 && lVar8 != 0) && lVar9 == 2);
    if ((lVar7 == 0 || lVar8 == 0) || lVar9 != 2) goto LAB_00092cf4;
    uVar4 = _objc_retainAutorelease
                      (local_c0[uStack_c4] + (int)-(uRam000000000117e958 ^ 0xc6098c14),lVar7);
    puVar1 = @selector(CGColor);
    uStack_110 = _objc_msgSend(uVar4,@selector(CGColor));
    uVar4 = _objc_retainAutorelease(lVar8);
    uStack_108 = _objc_msgSend(uVar4,puVar1);
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(arrayWithObjects:count:),
                  &uStack_110,2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
  }
  _objc_msgSend(param_7,@selector(setColors:),uVar4);
  _objc_release(uVar4);
LAB_00092cf4:
  (*_DAT_01226550)(param_1,param_2,param_3,param_4,local_e8,uStack_e0,param_7);
  _objc_release(lVar8);
  _objc_release(lVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(param_7);
  CallSupervisor(0x6b50);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_88) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


