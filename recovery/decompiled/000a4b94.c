/* Decompiled from supplied 5.2.2 arm package. VA 0xa4b94. FUN_000a4b94 */

void FUN_000a4b94(undefined8 param_1)

{
  undefined *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  float fVar13;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined **local_b0;
  int iStack_a4;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_01180560;
  local_74 = (uint)(DAT_01226e0c == 0);
  local_88 = &PTR_LAB_01180580;
  ppuStack_80 = &PTR_LAB_01175340;
  local_a0 = &PTR_LAB_011805a0;
  ppuStack_98 = &PTR_LAB_01175340;
  local_b0 = &PTR_LAB_01175340;
  DAT_01226e0c = 1;
  _objc_msgSend(param_1,PTR_s_parentViewController_0114ad68);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uStack_8c = (uint)(DAT_01226908 == 0);
  if (DAT_01226908 == 0) {
    DAT_01226908 = _objc_getClass(local_88[uStack_8c] + (int)-(DAT_01180590 ^ 0xf7153a06),
                                  s_YTWatchViewController_0116d3e0);
  }
  lVar2 = DAT_01226908;
  _objc_retainAutorelease(DAT_01226908);
  iVar3 = FUN_000e5df4(uVar4,PTR_s_isKindOfClass__0114ad70,lVar2);
  _objc_release(uVar4);
  puVar1 = PTR_s_numberWithDouble__0114c310;
  iStack_a4 = iVar3;
  if (iVar3 != 0) {
    uStack_b8 = param_1;
    _objc_msgSend(0x3fd0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,
                  PTR_s_numberWithDouble__0114c310);
    uStack_130 = _objc_retainAutoreleasedReturnValue();
    uStack_c0 = uStack_130;
    _objc_msgSend(0x3fe0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uStack_128 = _objc_retainAutoreleasedReturnValue();
    uStack_c8 = uStack_128;
    _objc_msgSend(0x3fe8000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uStack_120 = _objc_retainAutoreleasedReturnValue();
    uStack_d0 = uStack_120;
    _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uStack_118 = uVar4;
    _objc_msgSend(0x3ff4000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uStack_110 = uVar5;
    _objc_msgSend(0x3ff8000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uStack_108 = uVar6;
    _objc_msgSend(0x3ffc000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uStack_100 = uVar7;
    _objc_msgSend(0x4000000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uStack_f8 = uVar8;
    _objc_msgSend(0x4008000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uStack_f0 = uVar9;
    _objc_msgSend(0x4010000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    uStack_e8 = uVar10;
    _objc_msgSend(0x4014000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    uStack_e0 = uVar11;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &uStack_130,0xb);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(uVar4);
    _objc_release(uStack_d0);
    _objc_release(uStack_c8);
    _objc_release(uStack_c0);
    puVar1 = PTR_YTPSpeedMaster_0114eca0;
    uVar4 = _ytpInt(&PTR____CFConstantStringClassReference_0116d420);
    _objc_msgSend(uVar12,PTR_s_objectAtIndexedSubscript__0114aeb0,uVar4);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    fVar13 = (float)_objc_msgSend(uVar4,PTR_s_floatValue_0114c768);
    _objc_msgSend((double)fVar13,puVar1,PTR_s_setPlaybackRate_forPlayer__0114c750,uStack_b8);
    _objc_release(uVar4);
    _objc_release(uVar12);
  }
  CallSupervisor(0x764f);
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1f,0,0,0);
  }
  return;
}


