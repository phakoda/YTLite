/* Decompiled from supplied 5.2.2 arm package. VA 0xcb100. FUN_000cb100 */

undefined8 FUN_000cb100(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  
  DAT_0122702c = 1;
  uVar6 = _objc_retain(param_2);
  puVar3 = PTR_s_controller_0114c8f0;
  _objc_msgSend(uVar6,PTR_s_controller_0114c8f0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar4 = PTR_s_children_0114cad8;
  _objc_msgSend(uVar6,PTR_s_children_0114cad8);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_description_0114af00;
  _objc_msgSend(uVar7,PTR_s_description_0114af00);
  uVar8 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_containsString__0114af08;
  uVar5 = FUN_000ef9fc(uVar8,PTR_s_containsString__0114af08,
                       &PTR____CFConstantStringClassReference_01174ab0);
  _objc_release(uVar8);
  _objc_release(uVar7);
  _objc_release(uVar6);
  if (uVar5 == 0) {
    _objc_msgSend(param_2,puVar3);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,puVar4);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,puVar1);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    uVar5 = FUN_000efca4(uVar8,puVar2,&PTR____CFConstantStringClassReference_011749b0);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    if (uVar5 == 0) {
      _objc_msgSend(param_2,puVar3);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,puVar4);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,puVar1);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      uVar5 = FUN_000efdd8(uVar8,puVar2,&PTR____CFConstantStringClassReference_011748f0);
      _objc_release(uVar8);
      _objc_release(uVar7);
      _objc_release(uVar6);
      if (uVar5 == 0) {
        _objc_msgSend(param_2,puVar3);
        uVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,puVar4);
        uVar7 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar7,puVar1);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        uVar5 = FUN_000efd2c(uVar8,puVar2,&PTR____CFConstantStringClassReference_01174970);
        _objc_release(uVar8);
        _objc_release(uVar7);
        _objc_release(uVar6);
        if (uVar5 == 0) {
          _objc_msgSend(param_2,PTR_s_yogaChildren_0114c570);
          uVar6 = _objc_retainAutoreleasedReturnValue();
          lVar9 = _objc_msgSend(uVar6,PTR_s_count_0114b840);
          _objc_release(uVar6);
                    /* WARNING: Could not recover jumptable at 0x000cc3f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar6 = (*(code *)((&PTR_LAB_01183898)[lVar9 == 1] +
                            (int)-(uRam00000000011838a8 ^ 0x4c153cb3)))();
          return uVar6;
        }
        uVar6 = FUN_000efdfc((&PTR_LAB_01183878)[uVar5] + (int)-(DAT_01183888 ^ 0x3c8bc060),
                             &PTR____CFConstantStringClassReference_011748b0);
      }
      else {
        uVar6 = FUN_000efd50((&PTR_LAB_01183858)[uVar5] + (int)-(uRam0000000001183868 ^ 0x7b3d31bb),
                             &PTR____CFConstantStringClassReference_01174930);
      }
    }
    else {
      uVar6 = FUN_000efbdc((&PTR_LAB_01183838)[uVar5] + (int)-(DAT_01183848 ^ 0x4009ff45),
                           &PTR____CFConstantStringClassReference_011749f0);
    }
  }
  else {
    uVar6 = FUN_000efaec((&PTR_LAB_01183818)[uVar5] + (int)-(DAT_01183828 ^ 0xa7ce0186),
                         &PTR____CFConstantStringClassReference_01174a30);
  }
  _objc_release(param_2);
  return uVar6;
}


