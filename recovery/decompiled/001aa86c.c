/* Decompiled from supplied 5.2.2 arm package. VA 0x1aa86c. pageStyle */

/* Function Stack Size: 0x10 bytes */

long_long YTPMedia::pageStyle(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long_long lVar7;
  
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_delegate_0114b530);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  puVar3 = PTR_s_responderRoot_0114dc98;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  uVar4 = FUN_001b7254(uVar6,PTR_s_respondsToSelector__0114af58,PTR_s_responderRoot_0114dc98);
  lVar7 = 0xffffffffffffffff;
  if (uVar4 != 0) {
    _objc_msgSend((&PTR_LAB_011b25d0)[uVar4] + (int)-(DAT_011b25e0 ^ 0xf6833f2a),uVar6,puVar3);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_pageStyle_0114c698;
    uVar4 = FUN_001b729c(uVar5,puVar1,PTR_s_pageStyle_0114c698);
    _objc_release(uVar5);
    lVar7 = 0xffffffffffffffff;
    if (uVar4 != 0) {
      _objc_msgSend((&PTR_LAB_011b25e8)[uVar4] + (int)-(uRam00000000011b25f8 ^ 0x2c5eead0),uVar6,
                    puVar3);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      lVar7 = _objc_msgSend(uVar5,puVar2);
      _objc_release(uVar5);
    }
  }
  _objc_release(uVar6);
  return lVar7;
}


