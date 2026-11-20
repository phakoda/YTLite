/* Decompiled from supplied 5.2.2 arm package. VA 0x778f0. FUN_000778f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000778f0(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined *puVar9;
  double dVar10;
  
  DAT_01226bc4 = 1;
  uVar2 = FUN_000dba7c(&PTR____CFConstantStringClassReference_01164ee0);
  puVar9 = (&PTR_LAB_0117c0b8)[uVar2] + (int)-(uRam000000000117c0c8 ^ 0xc5838616);
  if (uVar2 == 0) {
LAB_0007816c:
    uVar2 = FUN_000dbc9c(puVar9,&PTR____CFConstantStringClassReference_01164de0);
    if ((uVar2 == 0) &&
       (iVar3 = FUN_000db9f8((&PTR_LAB_0117c0e8)[uVar2] + (int)-(uRam000000000117c0f8 ^ 0x837d19c),
                             &PTR____CFConstantStringClassReference_01164da0), iVar3 == 0))
    goto LAB_00078210;
  }
  else {
    lVar4 = _ytpInt(puVar9,&PTR____CFConstantStringClassReference_01164e20);
    puVar9 = (&PTR_LAB_0117c0d0)[lVar4 == 0] + (int)-(uRam000000000117c0e0 ^ 0xa50aea73);
    if (lVar4 == 0) goto LAB_0007816c;
  }
  _objc_msgSend(param_1,PTR_s_ytlButtons_0114bc98);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend((double)(param_3 & 0xffffffff),uVar5,PTR_s_setAlpha__0114b698);
  _objc_release(uVar5);
LAB_00078210:
  iVar3 = FUN_000dbc54(&PTR____CFConstantStringClassReference_01164ea0);
  if (iVar3 != 0) {
    _objc_msgSend(param_1,PTR_s_speedControls_0114bc88);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend((double)(param_3 & 0xffffffff),uVar5,PTR_s_setAlpha__0114b698);
    _objc_release(uVar5);
    _objc_msgSend(param_1,PTR_s_speedValue_0114bcc8);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
    puVar9 = PTR__OBJC_CLASS___NSNumber_0114eb00;
    dVar10 = (double)_objc_msgSend(PTR_YTPSpeedMaster_0114eca0,PTR_s_currentPlaybackRate_0114c6c0);
    _objc_msgSend((float)dVar10,puVar9,PTR_s_numberWithFloat__0114c6c8);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_000dbbf8(puVar1,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_01164e60,uVar6);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_setTitle_forState__0114b6a8,uVar7,0);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
  }
  (*_DAT_01226240)(param_1,param_2,param_3);
  uVar8 = FUN_000dbc78(&PTR____CFConstantStringClassReference_01164d60);
                    /* WARNING: Could not recover jumptable at 0x00078380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0117c140)[uVar8 & 0xffffffff] + (int)-(uRam000000000117c150 ^ 0xf9f3b793)))()
  ;
  return;
}


