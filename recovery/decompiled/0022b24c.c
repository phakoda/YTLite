/* Decompiled from supplied 5.2.2 arm package. VA 0x22b24c. init */

/* Function Stack Size: 0x10 bytes */

ID YTLHelper::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IStack_60;
  undefined *puStack_58;
  undefined **local_50;
  uint uStack_44;
  undefined **local_40;
  undefined **ppuStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011d1338;
  local_2c = (uint)(DAT_01228388 == 0);
  local_40 = &PTR__objc_msgSend_011d1358;
  ppuStack_38 = &PTR__objc_msgSend_011d0fe0;
  local_50 = &PTR__objc_msgSend_011d0fe0;
  DAT_01228388 = 1;
  puStack_58 = PTR_YTLHelper_0114f150;
  IStack_60 = param_1;
  IVar1 = _objc_msgSendSuper2(&IStack_60,PTR_s_init_0114d960);
  uStack_44 = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    uVar2 = _objc_alloc_init(PTR_ToastView_0114ec98);
    uVar3 = *(undefined8 *)(IVar1 + 0x18);
    *(undefined8 *)(IVar1 + 0x18) = uVar2;
    _objc_release(uVar3);
    _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,
                  PTR_s_characterSetWithCharactersInStri_0114e730,
                  &PTR____CFConstantStringClassReference_011d0070);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = *(undefined8 *)(IVar1 + 8);
    *(undefined8 *)(IVar1 + 8) = uVar2;
    _objc_release(uVar3);
  }
  return IVar1;
}


