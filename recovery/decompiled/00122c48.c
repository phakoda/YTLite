/* Decompiled from supplied 5.2.2 arm package. VA 0x122c48. timePickerForCell:indexPath: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::timePickerForCell_indexPath_
             (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  float fVar8;
  double dVar9;
  
  _objc_retain(param_3);
  puVar1 = PTR_DVNPickerView_0114ee58;
  _objc_retain(param_4);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,PTR_s_setDelegate__0114b7d8,param_1);
  _objc_msgSend(uVar2,PTR_s_setDataSource__0114b7d0,param_1);
  _objc_msgSend(0,0,0x4054000000000000,0x404e000000000000,uVar2,PTR_s_setFrame__0114b570);
  lVar3 = _objc_msgSend(param_4,PTR_s_section_0114af60);
  uVar4 = _objc_msgSend(param_4,PTR_s_row_0114af70);
  _objc_release(param_4);
  _objc_msgSend(uVar2,PTR_s_setTag__0114b858,uVar4 & 0xffff | lVar3 << 0x10);
  _objc_msgSend(param_1,PTR_s_defaults_0114d278);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_3,PTR_s_key_0114c8f8);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  fVar8 = (float)_objc_msgSend(uVar5,PTR_s_floatForKey__0114c308,uVar6);
  _objc_release(uVar6);
  _objc_release(uVar5);
  puVar1 = PTR_s_minimumValue_0114d400;
  dVar9 = (double)_objc_msgSend(param_3,PTR_s_minimumValue_0114d400);
  if ((double)fVar8 < dVar9) {
    dVar9 = (double)_objc_msgSend((&PTR_LAB_0118df50)[(double)fVar8 < dVar9] +
                                  (int)-(DAT_0118df60 ^ 0xcd2f9a53),param_3,puVar1);
    fVar8 = (float)dVar9;
  }
  _objc_msgSend(uVar2,PTR_s_selectRow_inComponent_animated__0114d520,(long)fVar8,0,0);
  _objc_release(param_3);
  IVar7 = _objc_autoreleaseReturnValue(uVar2);
  return IVar7;
}


