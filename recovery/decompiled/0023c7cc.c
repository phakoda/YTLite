/* Decompiled from supplied 5.2.2 arm package. VA 0x23c7cc. setupConstraints */

/* Function Stack Size: 0x10 bytes */

void PlayerToast::setupConstraints(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  undefined8 uVar38;
  undefined8 uVar39;
  undefined8 uVar40;
  undefined8 uVar41;
  undefined8 uVar42;
  undefined8 uVar43;
  undefined8 uVar44;
  undefined8 uVar45;
  undefined8 uVar46;
  undefined8 uVar47;
  undefined8 uVar48;
  long lVar49;
  undefined8 uVar50;
  long lVar51;
  long lVar52;
  long lVar53;
  undefined8 uVar54;
  undefined8 uVar55;
  undefined8 uVar56;
  undefined8 uVar57;
  undefined8 uVar58;
  undefined8 uVar59;
  undefined8 uVar60;
  undefined8 uVar61;
  undefined8 uVar62;
  undefined8 uVar63;
  undefined8 uVar64;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  long local_a0;
  
  local_a0 = *(long *)PTR____stack_chk_guard_01060708;
  lVar53 = (long)_isCompact;
  uVar64 = 0x4039000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar64 = 0x402e000000000000;
  }
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_toastView),PTR_s_layer_0114ae60);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar64,uVar10,PTR_s_setCornerRadius__0114ae68);
  _objc_release(uVar10);
  lVar49 = (long)_toastLabel;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar49),PTR_s_setHidden__0114bfc0,
                *(undefined1 *)(param_1 + lVar53));
  puVar9 = PTR__OBJC_CLASS___NSMutableArray_0114eb90;
  puVar4 = PTR_s_heightAnchor_0114b638;
  _objc_msgSend(param_1,PTR_s_heightAnchor_0114b638);
  uVar64 = _objc_retainAutoreleasedReturnValue();
  puVar5 = PTR_s_constraintEqualToConstant__0114b640;
  uVar10 = 0x4049000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar10 = 0x403e000000000000;
  }
  _objc_msgSend(uVar10);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  puVar6 = PTR_s_widthAnchor_0114b648;
  local_130 = uVar10;
  _objc_msgSend(param_1,PTR_s_widthAnchor_0114b648);
  uVar11 = _objc_retainAutoreleasedReturnValue();
  puVar8 = PTR_s_constraintGreaterThanOrEqualToCo_0114dd40;
  uVar54 = 0x4069000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar54 = 0x4059000000000000;
  }
  _objc_msgSend(uVar54);
  uVar12 = _objc_retainAutoreleasedReturnValue();
  puVar7 = PTR_s_centerYAnchor_0114b7f8;
  lVar51 = (long)_toastImage;
  local_128 = uVar12;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),PTR_s_centerYAnchor_0114b7f8);
  uVar13 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar7);
  uVar14 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar13,PTR_s_constraintEqualToAnchor__0114b5a0,uVar14);
  uVar15 = _objc_retainAutoreleasedReturnValue();
  local_120 = uVar15;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),PTR_s_centerXAnchor_0114b628);
  uVar16 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_leadingAnchor_0114b5b8;
  _objc_msgSend(param_1,PTR_s_leadingAnchor_0114b5b8);
  uVar17 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_constraintEqualToAnchor_constant_0114b630;
  uVar54 = DAT_00c4c360;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar54 = 0x4034000000000000;
  }
  _objc_msgSend(uVar54,uVar16,PTR_s_constraintEqualToAnchor_constant_0114b630,uVar17);
  uVar54 = _objc_retainAutoreleasedReturnValue();
  local_118 = uVar54;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),puVar4);
  uVar18 = _objc_retainAutoreleasedReturnValue();
  uVar55 = 0x4039000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar55 = 0x402e000000000000;
  }
  _objc_msgSend(uVar55,uVar18,puVar5);
  uVar55 = _objc_retainAutoreleasedReturnValue();
  local_110 = uVar55;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),puVar6);
  uVar19 = _objc_retainAutoreleasedReturnValue();
  uVar56 = 0x4039000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar56 = 0x402e000000000000;
  }
  _objc_msgSend(uVar56,uVar19,puVar5);
  uVar56 = _objc_retainAutoreleasedReturnValue();
  local_108 = uVar56;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar49),puVar1);
  uVar20 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_trailingAnchor_0114b5c0;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),PTR_s_trailingAnchor_0114b5c0);
  uVar21 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4024000000000000,uVar20,puVar3,uVar21);
  uVar22 = _objc_retainAutoreleasedReturnValue();
  local_100 = uVar22;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar49),puVar2);
  uVar23 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar24 = _objc_retainAutoreleasedReturnValue();
  uVar57 = 0xc044000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar57 = 0xc039000000000000;
  }
  _objc_msgSend(uVar57,uVar23,puVar3,uVar24);
  uVar57 = _objc_retainAutoreleasedReturnValue();
  local_f8 = uVar57;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar49),puVar7);
  uVar25 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar7);
  uVar26 = _objc_retainAutoreleasedReturnValue();
  uVar58 = 0xc024000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar58 = 0;
  }
  _objc_msgSend(uVar58,uVar25,puVar3,uVar26);
  uVar58 = _objc_retainAutoreleasedReturnValue();
  lVar52 = (long)_toastSubLabel;
  local_f0 = uVar58;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar1);
  uVar27 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),puVar2);
  uVar28 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4024000000000000,uVar27,puVar3,uVar28);
  uVar29 = _objc_retainAutoreleasedReturnValue();
  local_e8 = uVar29;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar2);
  uVar30 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar31 = _objc_retainAutoreleasedReturnValue();
  uVar59 = 0xc044000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar59 = 0xc039000000000000;
  }
  _objc_msgSend(uVar59,uVar30,puVar3,uVar31);
  uVar59 = _objc_retainAutoreleasedReturnValue();
  local_e0 = uVar59;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar7);
  uVar32 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar7);
  uVar33 = _objc_retainAutoreleasedReturnValue();
  uVar60 = 0x4024000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar60 = 0;
  }
  _objc_msgSend(uVar60,uVar32,puVar3,uVar33);
  uVar60 = _objc_retainAutoreleasedReturnValue();
  lVar52 = (long)_toastProgress;
  local_d8 = uVar60;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar6);
  uVar34 = _objc_retainAutoreleasedReturnValue();
  uVar61 = 0x4059000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar61 = 0x404e000000000000;
  }
  _objc_msgSend(uVar61,uVar34,puVar8);
  uVar61 = _objc_retainAutoreleasedReturnValue();
  local_d0 = uVar61;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar6);
  uVar35 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar49),puVar6);
  uVar36 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar35,PTR_s_constraintGreaterThanOrEqualToAn_0114e8e0,uVar36);
  uVar37 = _objc_retainAutoreleasedReturnValue();
  local_c8 = uVar37;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar4);
  uVar38 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4010000000000000,uVar38,puVar5);
  uVar39 = _objc_retainAutoreleasedReturnValue();
  local_c0 = uVar39;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar1);
  uVar40 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar51),puVar2);
  uVar41 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x4024000000000000,uVar40,puVar3,uVar41);
  uVar42 = _objc_retainAutoreleasedReturnValue();
  local_b8 = uVar42;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar2);
  uVar43 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar2);
  uVar44 = _objc_retainAutoreleasedReturnValue();
  uVar62 = 0xc044000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar62 = 0xc039000000000000;
  }
  _objc_msgSend(uVar62,uVar43,puVar3,uVar44);
  uVar62 = _objc_retainAutoreleasedReturnValue();
  local_b0 = uVar62;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar52),puVar7);
  uVar45 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,puVar7);
  uVar46 = _objc_retainAutoreleasedReturnValue();
  uVar63 = 0x4024000000000000;
  if (*(char *)(param_1 + lVar53) != '\0') {
    uVar63 = 0;
  }
  _objc_msgSend(uVar63,uVar45,puVar3,uVar46);
  uVar63 = _objc_retainAutoreleasedReturnValue();
  local_a8 = uVar63;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,&local_130
                ,0x12);
  uVar47 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar9,PTR_s_arrayWithArray__0114e8e8,uVar47);
  uVar48 = _objc_retainAutoreleasedReturnValue();
  uVar50 = *(undefined8 *)(param_1 + (long)_activeConstraints);
  *(undefined8 *)(param_1 + (long)_activeConstraints) = uVar48;
  _objc_release(uVar50);
  _objc_release(uVar47);
  _objc_release(uVar63);
  _objc_release(uVar46);
  _objc_release(uVar45);
  _objc_release(uVar62);
  _objc_release(uVar44);
  _objc_release(uVar43);
  _objc_release(uVar42);
  _objc_release(uVar41);
  _objc_release(uVar40);
  _objc_release(uVar39);
  _objc_release(uVar38);
  _objc_release(uVar37);
  _objc_release(uVar36);
  _objc_release(uVar35);
  _objc_release(uVar61);
  _objc_release(uVar34);
  _objc_release(uVar60);
  _objc_release(uVar33);
  _objc_release(uVar32);
  _objc_release(uVar59);
  _objc_release(uVar31);
  _objc_release(uVar30);
  _objc_release(uVar29);
  _objc_release(uVar28);
  _objc_release(uVar27);
  _objc_release(uVar58);
  _objc_release(uVar26);
  _objc_release(uVar25);
  _objc_release(uVar57);
  _objc_release(uVar24);
  _objc_release(uVar23);
  _objc_release(uVar22);
  _objc_release(uVar21);
  _objc_release(uVar20);
  _objc_release(uVar56);
  _objc_release(uVar19);
  _objc_release(uVar55);
  _objc_release(uVar18);
  _objc_release(uVar54);
  _objc_release(uVar17);
  _objc_release(uVar16);
  _objc_release(uVar15);
  _objc_release(uVar14);
  _objc_release(uVar13);
  _objc_release(uVar12);
  _objc_release(uVar11);
  _objc_release(uVar10);
  _objc_release(uVar64);
  CallSupervisor(0x954c);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_a0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


