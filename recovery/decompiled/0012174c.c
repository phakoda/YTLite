/* Decompiled from supplied 5.2.2 arm package. VA 0x12174c. setSegment: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::setSegment_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_retain(param_3);
  uVar1 = _objc_msgSend(param_3,PTR_s_tag_0114b868);
  _objc_msgSend(param_1,PTR_s__cellForTag__0114d510,uVar1);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 != 0) {
    _objc_msgSend(param_1,PTR_s_defaults_0114d278);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    uVar3 = _objc_msgSend(param_3,PTR_s_selectedSegmentIndex_0114d550);
    _objc_msgSend(lVar2,PTR_s_key_0114c8f8);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar1,PTR_s_setInteger_forKey__0114c2d8,uVar3,uVar4);
    _objc_release(uVar4);
    _objc_release(uVar1);
  }
  _objc_release(lVar2);
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


