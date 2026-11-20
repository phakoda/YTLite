/* Decompiled from supplied 5.2.2 arm package. VA 0xbc45c. FUN_000bc45c */

void FUN_000bc45c(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined1 auStack_c0 [16];
  undefined8 auStack_b0 [3];
  undefined8 *puStack_98;
  undefined1 *puStack_90;
  uint uStack_88;
  uint uStack_84;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_01182518;
  local_74 = (uint)(DAT_01226f1c == 0);
  local_80 = &PTR_LAB_01175340;
  DAT_01226f1c = 1;
  puStack_90 = auStack_c0;
  puStack_98 = auStack_b0;
  _objc_msgSend(PTR__OBJC_CLASS___MPRemoteCommandCenter_0114ecc8,PTR_s_sharedCommandCenter_0114c2e0)
  ;
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_standardUserDefaults_0114afa0;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_boolForKey__0114ada8;
  uStack_84 = FUN_000eb4f8(uVar11,PTR_s_boolForKey__0114ada8,
                           &PTR____CFConstantStringClassReference_011719f0);
  _objc_release(uVar11);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar2);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  uStack_88 = FUN_000eb540(uVar11,puVar1,&PTR____CFConstantStringClassReference_011719b0);
  _objc_release(uVar11);
  puVar1 = PTR__OBJC_CLASS___NSNumber_0114eb00;
  puVar3 = PTR_s_floatForKey__0114c308;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_floatForKey__0114c308,
                &PTR____CFConstantStringClassReference_01171970);
  puVar4 = PTR_s_numberWithDouble__0114c310;
  _objc_msgSend(puVar1,PTR_s_numberWithDouble__0114c310);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_arrayWithObjects_count__0114b600;
  auStack_b0[0] = uVar11;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,auStack_b0
                ,1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_skipBackwardCommand_0114c2f0;
  _objc_msgSend(uVar10,PTR_s_skipBackwardCommand_0114c2f0);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  puVar5 = PTR_s_setPreferredIntervals__0114c318;
  _objc_msgSend(uVar13,PTR_s_setPreferredIntervals__0114c318,uVar12);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  puVar6 = PTR__OBJC_CLASS___NSNumber_0114eb00;
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,puVar3,&PTR____CFConstantStringClassReference_01171930)
  ;
  _objc_msgSend(puVar6,puVar4);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar7 = puStack_90;
  puStack_98[-2] = uVar11;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,puVar1,puVar7,1);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_skipForwardCommand_0114c300;
  _objc_msgSend(uVar10,PTR_s_skipForwardCommand_0114c300);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,puVar5,uVar12);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_msgSend(uVar10,puVar2);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  uVar9 = uStack_84;
  puVar1 = PTR_s_setEnabled__0114c020;
  _objc_msgSend(uVar11,PTR_s_setEnabled__0114c020,uStack_84);
  _objc_release(uVar11);
  _objc_msgSend(uVar10,puVar3);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  uVar8 = uStack_88;
  _objc_msgSend(uVar11,puVar1,uStack_88);
  _objc_release(uVar11);
  _objc_msgSend(uVar10,PTR_s_previousTrackCommand_0114c2e8);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar1,uVar9 ^ 1);
  _objc_release(uVar11);
  _objc_msgSend(uVar10,PTR_s_nextTrackCommand_0114c2f8);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar11,puVar1,uVar8 ^ 1);
  _objc_release(uVar11);
  _objc_release(uVar10);
  CallSupervisor(0xe99a);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


