/* Decompiled from supplied 5.2.2 arm package. VA 0x4bf90. _autoSkipShortsLegacy */

undefined1  [16] _autoSkipShortsLegacy(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  double dVar8;
  double dVar9;
  undefined1 auVar10 [16];
  
  DAT_012269dc = 1;
  _objc_retain(param_1);
  _objc_retain(param_2);
  _objc_retain(param_3);
  lVar5 = _ytpInt(&PTR____CFConstantStringClassReference_0115dfa0);
  if (lVar5 != 1) goto LAB_0004c964;
  dVar8 = (double)_objc_msgSend(param_3,PTR_s_time_0114adc0);
  dVar9 = (double)_objc_msgSend(param_2,PTR_s_totalMediaTime_0114b978);
  puVar1 = PTR_s_parentViewController_0114ad68;
  if ((double)(long)dVar8 < (double)(long)dVar9) goto LAB_0004c964;
  _objc_msgSend(param_1,PTR_s_parentViewController_0114ad68);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  if (lRam0000000001226840 == 0) {
    lRam0000000001226840 =
         _objc_getClass((&PTR_LAB_0117a158)[lRam0000000001226840 == 0] +
                        (int)-(uRam000000000117a168 ^ 0x5c5a5278),
                        s_YTShortsPlayerViewController_0115dea0);
  }
  lVar5 = lRam0000000001226840;
  _objc_retainAutorelease(lRam0000000001226840);
  uVar3 = FUN_000d03f0(uVar6,PTR_s_isKindOfClass__0114ad70,lVar5);
  _objc_release(uVar6);
  if (uVar3 == 0) goto LAB_0004c964;
  _objc_msgSend((&PTR_LAB_0117a178)[uVar3] + (int)-(uRam000000000117a188 ^ 0xac706111),param_1,
                puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_respondsToSelector__0114af58;
  iVar4 = FUN_000d04d8(uVar6,PTR_s_respondsToSelector__0114af58,PTR_s_maybeLoopPlayback_0114b9c0);
  puVar2 = PTR_s_reelContentViewRequestsAdvanceTo_0114b9c8;
  if ((iVar4 == 0) &&
     (iVar4 = FUN_000d0548(uVar6,puVar1,PTR_s_reelContentViewRequestsAdvanceTo_0114b9c8), iVar4 != 0
     )) {
    uVar7 = _objc_msgSend(uVar6,PTR_s_class_0114ae88);
    lVar5 = _class_getInstanceVariable(uVar7,s__isEngagementPanelVisible_0115dee0);
    if (lVar5 != 0) {
      _objc_msgSend(uVar6,PTR_s_valueForKey__0114ae90,
                    &PTR____CFConstantStringClassReference_0115df60);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      iVar4 = FUN_000d0520(uVar7,PTR_s_boolValue_0114b3d8);
      _objc_release(uVar7);
      if (iVar4 != 0) goto LAB_0004c95c;
    }
    _objc_msgSend(uVar6,PTR_s_performSelector__0114b268,puVar2);
  }
LAB_0004c95c:
  _objc_release(uVar6);
LAB_0004c964:
  _objc_release(param_3);
  _objc_release(param_2);
  _objc_release(param_1);
  CallSupervisor(0xfeb);
  auVar10._8_8_ = 0x1f;
  auVar10._0_8_ = 0x1a;
  return auVar10;
}


