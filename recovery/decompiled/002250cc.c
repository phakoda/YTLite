/* Decompiled from supplied 5.2.2 arm package. VA 0x2250cc. speedArray */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x10 bytes */

ID YTPSpeedMaster::speedArray(ID param_1,SEL param_2)

{
  double dVar1;
  double dVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  ID IVar17;
  char *pcVar18;
  double dVar19;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  long local_90;
  
  puVar3 = PTR_s_numberWithDouble__0114c310;
  local_90 = *(long *)PTR____stack_chk_guard_01060708;
  if (*(long *)(param_1 + 0x10) == 2) {
    _objc_msgSend(0x3fd0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,
                  PTR_s_numberWithDouble__0114c310);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uStack_e8 = uVar6;
    _objc_msgSend(0x3fe0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uStack_e0 = uVar7;
    _objc_msgSend(0x3fe8000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uStack_d8 = uVar8;
    _objc_msgSend(0x3ff0000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    uStack_d0 = uVar9;
    _objc_msgSend(0x3ff4000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    uStack_c8 = uVar10;
    _objc_msgSend(0x3ff8000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar11 = _objc_retainAutoreleasedReturnValue();
    uStack_c0 = uVar11;
    _objc_msgSend(0x3ffc000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    uStack_b8 = uVar12;
    _objc_msgSend(0x4000000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar13 = _objc_retainAutoreleasedReturnValue();
    uStack_b0 = uVar13;
    _objc_msgSend(0x4008000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar14 = _objc_retainAutoreleasedReturnValue();
    uStack_a8 = uVar14;
    _objc_msgSend(0x4010000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar15 = _objc_retainAutoreleasedReturnValue();
    uStack_a0 = uVar15;
    _objc_msgSend(0x4014000000000000,PTR__OBJC_CLASS___NSNumber_0114eb00,puVar3);
    uVar16 = _objc_retainAutoreleasedReturnValue();
    uStack_98 = uVar16;
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &uStack_e8,0xb);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar16);
    _objc_release(uVar15);
    _objc_release(uVar14);
    _objc_release(uVar13);
    _objc_release(uVar12);
    _objc_release(uVar11);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
  }
  else {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,PTR_s_array_0114c388);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar4 = PTR_s_numberWithDouble__0114c310;
    puVar3 = PTR_s_addObject__0114b3a0;
    dVar2 = _UNK_00c4c4e0;
    dVar1 = DAT_00c4c260;
    dVar19 = 0.25;
    pcVar18 = "ex limits [%i -> %i]\n";
    do {
      _objc_msgSend(pcVar18,(double)(long)(dVar19 * 100.0) / 100.0,
                    PTR__OBJC_CLASS___NSNumber_0114eb00,puVar4);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,puVar3,uVar6);
      _objc_release(uVar6);
      dVar19 = dVar19 + dVar1;
      pcVar18 = (&PTR_LAB_011cef10)[dVar2 < dVar19] + (int)-(uRam00000000011cef20 ^ 0x2e6f010a);
    } while (dVar19 <= dVar2);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_90) {
    IVar17 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
    return IVar17;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


