/* Decompiled from supplied 5.2.2 arm package. VA 0x8e70c. FUN_0008e70c */

undefined1  [16]
FUN_0008e70c(undefined8 param_1,double param_2,double param_3,double param_4,undefined8 param_5,
            undefined8 param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined1 auVar9 [16];
  
  puVar2 = PTR_s_mainScreen_0114b768;
  DAT_01226d3c = 1;
  dVar5 = param_3;
  dVar7 = param_4;
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,PTR_s_mainScreen_0114b768);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_bounds_0114b568;
  _objc_msgSend(uVar4,PTR_s_bounds_0114b568);
  dVar6 = dVar5;
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,puVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,puVar1);
  dVar8 = dVar7;
  _objc_release(uVar4);
  if (dVar7 <= dVar5) {
    dVar5 = dVar7;
  }
  if ((dVar5 < param_3) &&
     (iVar3 = FUN_000e09c0((&PTR_LAB_0117e2e8)[dVar5 < param_3] + (int)-(DAT_0117e2f8 ^ 0x594cb6eb),
                           &PTR____CFConstantStringClassReference_01169130),
     puVar2 = PTR_s_superview_0114c820, iVar3 != 0)) {
    _objc_msgSend(param_5,PTR_s_superview_0114c820);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_safeAreaInsets_0114b538);
    _objc_release(uVar4);
    _objc_msgSend(param_5,puVar2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar1);
    _objc_release(uVar4);
    param_2 = ((dVar8 - dVar6) - param_4) + -10.0;
  }
  (*DAT_012264c8)(param_1,param_2,param_3,param_4,param_5,param_6);
  CallSupervisor(0x3054);
  auVar9._8_8_ = 0x1f;
  auVar9._0_8_ = 0x1a;
  return auVar9;
}


