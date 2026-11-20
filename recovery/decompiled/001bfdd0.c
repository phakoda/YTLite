/* Decompiled from supplied 5.2.2 arm package. VA 0x1bfdd0. cancelButtonTapped */

/* Function Stack Size: 0x10 bytes */

void ToastView::cancelButtonTapped(ID param_1,SEL param_2)

{
  undefined *puVar1;
  long lVar2;
  
  puVar1 = PTR_s_completion_0114b0b8;
  _objc_msgSend(param_1,PTR_s_completion_0114b0b8);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar2 != 0) {
    _objc_msgSend((&PTR_LAB_011b43f8)[lVar2 == 0] + (int)-(DAT_011b4408 ^ 0xf31a9c34),param_1,puVar1
                 );
    lVar2 = _objc_retainAutoreleasedReturnValue();
    (**(code **)(lVar2 + 0x10))();
    _objc_release(lVar2);
                    /* WARNING: Could not recover jumptable at 0x001bfec4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_011b4418)[*(char *)(param_1 + (long)_ignoresPanGesture) == '\0'] +
              (int)-(uRam00000000011b4428 ^ 0x4e358d11)))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x001bff1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011b4418)[*(char *)(param_1 + (long)_ignoresPanGesture) == '\0'] +
            (int)-(uRam00000000011b4428 ^ 0x4e358d11)))();
  return;
}


