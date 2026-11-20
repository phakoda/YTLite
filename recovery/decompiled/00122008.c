/* Decompiled from supplied 5.2.2 arm package. VA 0x122008. titleValue: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::titleValue_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  
  _objc_retain(param_3);
  uVar3 = _objc_msgSend(param_3,PTR_s_tag_0114b868);
  _objc_msgSend(param_1,PTR_s__cellForTag__0114d510,uVar3);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_text_0114b370;
  if (lVar4 != 0) {
    _objc_msgSend(param_3,PTR_s_text_0114b370);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_length_0114b438;
    lVar4 = _objc_msgSend(uVar3,PTR_s_length_0114b438);
    if (lVar4 == 0) {
      uVar8 = 0;
    }
    else {
      _objc_msgSend((&PTR_LAB_0118ddf8)[lVar4 == 0] + (int)-(uRam000000000118de08 ^ 0x1479c3ea),
                    param_3,puVar1);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,PTR_s_whitespaceCharacterSet_0114d570)
      ;
      uVar6 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar6,PTR_s_invertedSet_0114d578);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      lVar4 = _objc_msgSend(uVar5,PTR_s_rangeOfCharacterFromSet__0114d580,uVar7);
      uVar8 = (uint)(lVar4 == 0x7fffffffffffffff);
      _objc_release(uVar7);
      _objc_release(uVar6);
      _objc_release(uVar5);
    }
    _objc_release(uVar3);
    _objc_msgSend(param_3,puVar1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    lVar4 = _objc_msgSend(uVar3,puVar2);
    if (lVar4 == 0) {
      uVar8 = 1;
    }
    _objc_release(uVar3);
    _objc_msgSend(param_1,PTR_s_defaults_0114d278);
    _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x0012223c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&PTR_LAB_0118de18)[uVar8] + (int)-(uRam000000000118de28 ^ 0x759810ad)))();
    return;
  }
  _objc_release((&PTR__objc_msgSend_0118dde0)[lVar4 == 0] + (int)-(DAT_0118ddf0 ^ 0xeaf9694e),0);
  _objc_release(param_3);
  CallSupervisor(0xb47b);
  return;
}


