/* Decompiled from supplied 5.2.2 arm package. VA 0x1bfa0c. goodHeightDidChange: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x18 bytes */

void ToastView::goodHeightDidChange_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  float fVar3;
  
  DAT_01227b48 = 1;
  _objc_msgSend(param_3,PTR_s_userInfo_0114ddf8);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_objectForKeyedSubscript__0114ae80,
                &PTR____CFConstantStringClassReference_011b38d0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  fVar3 = (float)_objc_msgSend(uVar2,PTR_s_floatValue_0114c768);
  *(double *)(param_1 + (long)__goodHeight) = (double)fVar3;
  _objc_release(uVar2);
  _objc_msgSend(param_1,PTR_s_updateLayout_0114ddb0);
  _objc_release(uVar1);
  CallSupervisor(0x810f);
  return;
}


