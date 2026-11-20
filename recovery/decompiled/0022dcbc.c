/* Decompiled from supplied 5.2.2 arm package. VA 0x22dcbc. downloadDidFailureWithError: */

/* Function Stack Size: 0x18 bytes */

void YTLHelper::downloadDidFailureWithError_(ID param_1,SEL param_2,ID param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_012283bc = 1;
  _objc_retain(param_3);
  if (param_3 != 0) {
    lVar1 = _objc_msgSend(param_3,PTR_s_code_0114e598);
    if (lVar1 != -999) {
      thunk_FUN_00232c44((&PTR_LAB_011d1620)[lVar1 == -999] +
                         (int)-(uRam00000000011d1630 ^ 0x400b7b2e),
                         &PTR____CFConstantStringClassReference_011d07a0,param_3);
      uVar3 = *(undefined8 *)(param_1 + 0x18);
      _objc_msgSend(param_3,PTR_s_localizedDescription_0114c618);
      uVar2 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar3,PTR_s_showMessageWithText_isSuccess__0114c5b8,uVar2,0);
      _objc_release(uVar2);
    }
  }
  _objc_release(param_3);
  CallSupervisor(0xfe78);
  return;
}


