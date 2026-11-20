/* Decompiled from supplied 5.2.2 arm package. VA 0x1be9d8. calculateToastParametersWithKeyboardHeight:bottomOffset:topOffset:scale: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x30 bytes */

void ToastView::calculateToastParametersWithKeyboardHeight_bottomOffset_topOffset_scale_
               (ID param_1,SEL param_2,double param_3,double *param_4,double *param_5,
               double *param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  undefined *puVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  dVar6 = (double)_objc_msgSend(*(undefined8 *)(param_1 + (long)_sourceView),
                                PTR_s_safeAreaInsets_0114b538);
  _objc_msgSend(PTR_ToastManager_0114ecd0,PTR_s_sharedManager_0114c320);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_toasts_0114dda8);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  lVar3 = _objc_msgSend(uVar2,PTR_s_indexOfObject__0114b020,param_1);
  uVar4 = _objc_msgSend(uVar2,PTR_s_count_0114b840);
  _objc_msgSend(PTR__OBJC_CLASS___UIScreen_0114ec60,PTR_s_mainScreen_0114b768);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_bounds_0114b568);
  dVar7 = (double)_CGRectGetWidth();
  _objc_release(uVar1);
  puVar5 = PTR_s_bottomOffset_0114ddd0;
  dVar8 = (double)_objc_msgSend(param_1,PTR_s_bottomOffset_0114ddd0);
  *param_6 = 1.0;
  *param_5 = dVar6 + 15.0;
  if (0.0 < param_3) {
    dVar6 = *(double *)(param_1 + (long)__goodHeight) + param_3 + 15.0;
    *param_4 = dVar6;
    puVar5 = (&PTR_LAB_011b42a0)[uVar4 == 1] + (int)-(uRam00000000011b42b0 ^ 0xd3c8ba4c);
  }
  else {
    dVar6 = 0.0;
    if (dVar7 != _UNK_00c4c3c8) {
      dVar6 = 30.0;
    }
    if (dVar8 != 0.0) {
      dVar6 = 0.0;
    }
    dVar7 = *(double *)(param_1 + (long)__goodHeight) + -30.0;
    if (*(double *)(param_1 + (long)__goodHeight) <= 0.0) {
      dVar7 = 0.0;
    }
    dVar8 = (double)_objc_msgSend(param_1,puVar5);
    dVar6 = dVar6 + dVar8 + dVar7 + 15.0;
    *param_4 = dVar6;
    puVar5 = (&PTR_LAB_011b42a0)[uVar4 == 1] + (int)-(uRam00000000011b42b0 ^ 0xd3c8ba4c);
  }
  if (uVar4 == 1) goto LAB_001bedcc;
  if (lVar3 == uVar4 - 1) {
    puVar5 = (&PTR_LAB_011b42d0)[uVar4 == 2] + (int)-(uRam00000000011b42e0 ^ 0x9d2ba2d6);
    if (uVar4 == 2) {
LAB_001bedac:
      dVar7 = 5.0;
    }
    else {
      puVar5 = (&PTR_LAB_011b42f0)[2 < uVar4] + (int)-(uRam00000000011b4300 ^ 0xa383896e);
      if (uVar4 < 3) goto LAB_001bedcc;
      dVar7 = 10.0;
    }
  }
  else {
    if (lVar3 != uVar4 - 2) {
      puVar5 = (undefined *)0x3feccccccccccccd;
      *param_6 = 0.9;
      goto LAB_001bedcc;
    }
    *param_6 = 0.95;
    dVar6 = *param_4;
    puVar5 = (&PTR_LAB_011b4328)[uVar4 == 2] + (int)-(uRam00000000011b4338 ^ 0x37569626);
    if (uVar4 != 2) goto LAB_001bedac;
    dVar7 = 0.0;
  }
  *param_4 = dVar6 + dVar7;
  *param_5 = *param_5 + dVar7;
LAB_001bedcc:
  _objc_release(puVar5,uVar2);
  CallSupervisor(0xa0e3);
  return;
}


