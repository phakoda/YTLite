// Decompiled hook evidence for YTReelHeaderView. This is not compilable Logos source.

// -[YTReelHeaderView setTitleLabelVisible:animated:], original IMP slot 0x012266f0
/* Decompiled from supplied 5.2.2 arm package. VA 0xb0b64. FUN_000b0b64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_000b0b64(undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  
  DAT_01226e74 = 1;
  uVar1 = FUN_000e8444(@"hideShortsLogo");
  (*_DAT_012266f0)(param_1,param_2,param_3 & (uVar1 ^ 0xffffffff),param_4);
  CallSupervisor(0xddf8);
  return ZEXT816(0x1f);
}



// -[YTReelHeaderView addView:toStackView:withSize:], original IMP slot 0x012266f8
/* Decompiled from supplied 5.2.2 arm package. VA 0xb0d2c. FUN_000b0d2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000b0d2c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  long lVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined **local_e8;
  undefined **ppuStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  undefined **local_c8;
  int iStack_bc;
  undefined **local_b8;
  undefined **local_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  long local_80;
  
  local_80 = *(long *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011814a0;
  local_8c = (uint)(DAT_01226e78 == 0);
  local_a0 = &PTR_LAB_011814c0;
  local_b8 = &PTR_LAB_011814e0;
  local_d0 = &PTR__objc_msgSend_01181500;
  local_98 = &PTR_LAB_01175340;
  local_b0 = &PTR_LAB_01175340;
  local_c8 = &PTR_LAB_01175340;
  local_e8 = &PTR_LAB_01175340;
  ppuStack_e0 = &PTR_LAB_01175340;
  DAT_01226e78 = 1;
  _objc_retain(param_5);
  _objc_retain(param_6);
  uStack_a4 = (uint)(lRam0000000001226918 == 0);
  if (lRam0000000001226918 == 0) {
    lRam0000000001226918 =
         _objc_getClass(local_a0[uStack_a4] + (int)-(uRam00000000011814d0 ^ 0x4dd7417c),
                        s_YTQTMButton_0116fabd);
  }
  lVar4 = lRam0000000001226918;
  _objc_retainAutorelease(lRam0000000001226918);
  iStack_bc = FUN_000e846c(param_5,@selector(isKindOfClass:),lVar4);
  puVar1 = @selector(numberWithInt:);
  if (iStack_bc != 0) {
    uStack_108 = param_3;
    uStack_100 = param_4;
    _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,@selector(numberWithInt:),0x415);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR__OBJC_CLASS___NSNumber_0114eb00;
    uStack_150 = uVar6;
    uStack_f0 = param_5;
    uVar7 = FUN_000e84d0(@"hideShortsSearch");
    puVar2 = @selector(numberWithBool:);
    _objc_msgSend(puVar3,@selector(numberWithBool:),uVar7);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uStack_130 = uVar8;
    _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0x416);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR__OBJC_CLASS___NSNumber_0114eb00;
    uStack_148 = uVar7;
    uVar9 = FUN_000e8534(@"hideShortsCamera");
    _objc_msgSend(puVar3,puVar2,uVar9);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uStack_128 = uVar9;
    _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1,0x417);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR__OBJC_CLASS___NSNumber_0114eb00;
    uStack_140 = uVar10;
    uStack_f8 = param_6;
    uVar11 = FUN_000e8598(@"hideShortsMore");
    _objc_msgSend(puVar1,puVar2,uVar11);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    uStack_120 = uVar11;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  @selector(dictionaryWithObjects:forKeys:count:),&uStack_130,&uStack_150,3);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar7);
    uVar7 = uStack_f0;
    _objc_release(uVar8);
    _objc_release(uVar6);
    puVar1 = PTR__OBJC_CLASS___NSNumber_0114eb00;
    _objc_msgSend(uVar7,@selector(buttonRenderer));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(icon));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar8 = _objc_msgSend(uVar6,@selector(iconType));
    _objc_msgSend(puVar1,@selector(numberWithUnsignedInt:),uVar8);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar12,@selector(objectForKeyedSubscript:),uVar8);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uVar5 = FUN_000e86a0(uVar9,@selector(boolValue));
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar6);
    _objc_release(uVar7);
    uStack_d4 = uVar5;
                    /* WARNING: Could not recover jumptable at 0x000b14e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(local_d0[uVar5] + (int)-(uRam0000000001181510 ^ 0x6ff6beb0)))();
    return;
  }
  (*_DAT_012266f8)(param_1,param_2,param_3,param_4,param_5,param_6);
  _objc_release(param_6);
  _objc_release(param_5);
  CallSupervisor(0xd421);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_80) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


