/* Decompiled from supplied 5.2.2 arm package. VA 0x19c600. shouldDrawRoundedForBarView: */

/* Function Stack Size: 0x18 bytes */

bool SBPlayerDecorator::shouldDrawRoundedForBarView_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  DAT_012278d4 = 1;
  uVar6 = _objc_retain(param_3);
  puVar1 = PTR_s__viewControllerForAncestor_0114ade0;
  _objc_msgSend(uVar6,PTR_s__viewControllerForAncestor_0114ade0);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar7 = _NSClassFromString(&PTR____CFConstantStringClassReference_011abad0);
  puVar2 = PTR_s_isKindOfClass__0114ad70;
  uVar3 = FUN_001a1720(uVar6,PTR_s_isKindOfClass__0114ad70,uVar7);
  _objc_release(uVar6);
  if (uVar3 == 0) {
    bVar5 = 0;
  }
  else {
    _objc_msgSend((&PTR_LAB_011ac790)[uVar3] + (int)-(uRam00000000011ac7a0 ^ 0x1df4e042),param_3,
                  puVar1);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_parentViewController_0114ad68;
    _objc_msgSend(uVar6,PTR_s_parentViewController_0114ad68);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    uVar8 = _NSClassFromString(&PTR____CFConstantStringClassReference_011aba90);
    uVar3 = FUN_001a17a8(uVar7,puVar2,uVar8);
    _objc_release(uVar7);
    if (uVar3 == 0) {
      bVar5 = 0;
    }
    else {
      _objc_msgSend((&PTR_LAB_011ac7a8)[uVar3] + (int)-(uRam00000000011ac7b8 ^ 0xd4387563),uVar6,
                    puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar7,puVar1);
      uVar8 = _objc_retainAutoreleasedReturnValue();
      uVar9 = _objc_getClass(s_YTWatchViewController_011ab9b0);
      uVar3 = FUN_001a1830(uVar8,puVar2,uVar9);
      _objc_release(uVar8);
      if (uVar3 == 0) {
        bVar5 = 0;
      }
      else {
        _objc_msgSend((&PTR_LAB_011ac7c0)[uVar3] + (int)-(uRam00000000011ac7d0 ^ 0xd6d85d10),uVar7,
                      puVar1);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        iVar4 = FUN_001a18a0(uVar8,PTR_s_respondsToSelector__0114af58,PTR_s_fullscreen_0114db58);
        if (iVar4 == 0) {
          bVar5 = 0;
        }
        else {
          bVar5 = FUN_001a1858(uVar8,PTR_s_isFullscreen_0114c730);
        }
        _objc_release(uVar8);
      }
      _objc_release(uVar7);
    }
    _objc_release(uVar6);
  }
  _objc_release(param_3);
  return bVar5;
}


