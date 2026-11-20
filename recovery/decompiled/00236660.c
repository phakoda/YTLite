/* Decompiled from supplied 5.2.2 arm package. VA 0x236660. isiPad */

/* Function Stack Size: 0x10 bytes */

bool YTPSpeedPopupController::isiPad(ID param_1,SEL param_2)

{
  undefined *puVar1;
  uint uVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  protocol_list_t_1_ *ppVar8;
  undefined *puVar9;
  undefined *puVar10;
  
  puVar1 = PTR_s_currentDevice_0114b2b0;
  DAT_01228488 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___UIDevice_0114eb58,PTR_s_currentDevice_0114b2b0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  lVar5 = _objc_msgSend(uVar4,PTR_s_userInterfaceIdiom_0114c290);
  if (lVar5 == 1) {
    ppVar8 = &objc::protocol_list_t::CustomHUD;
    puVar9 = PTR_s_model_0114d100;
    puVar10 = PTR_s_containsString__0114af08;
  }
  else {
    _objc_msgSend((&PTR_LAB_011d1f10)[lVar5 == 1] + (int)-(DAT_011d1f20 ^ 0x66d9b11d),
                  PTR__OBJC_CLASS___UIDevice_0114eb58,puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar9 = PTR_s_model_0114d100;
    _objc_msgSend(uVar6,PTR_s_model_0114d100);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar10 = PTR_s_containsString__0114af08;
    uVar2 = FUN_00237d24(uVar7,PTR_s_containsString__0114af08,
                         &PTR____CFConstantStringClassReference_011d1e60);
    ppVar8 = (protocol_list_t_1_ *)
             ((&PTR_LAB_011d1f30)[uVar2] + (int)-(uRam00000000011d1f40 ^ 0x56402869));
    if (uVar2 == 0) {
      _objc_release(uVar7);
      _objc_release(uVar6);
      _objc_release(uVar4);
      return 0;
    }
  }
  _objc_msgSend(ppVar8,PTR__OBJC_CLASS___UIDevice_0114eb58,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar9);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  FUN_00237dcc(uVar6,puVar10,&PTR____CFConstantStringClassReference_011d1e20);
  _objc_release(uVar6);
  _objc_release(uVar4);
                    /* WARNING: Could not recover jumptable at 0x00236950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar3 = (*(code *)((&PTR_LAB_011d1f48)[lVar5 == 1] + (int)-(DAT_011d1f58 ^ 0xce0586f8)))();
  return bVar3;
}


