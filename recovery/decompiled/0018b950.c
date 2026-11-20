/* Decompiled from supplied 5.2.2 arm package. VA 0x18b950. modelWithTitle:header:footer:sections: */

/* Function Stack Size: 0x30 bytes */

ID DVNTableModel::modelWithTitle_header_footer_sections_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  _objc_retain(param_6);
  puVar1 = PTR_DVNTableModel_0114ee88;
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,PTR_s_setTitle__0114afc0,param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,PTR_s_setHeader__0114d7b8,param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,PTR_s_setFooter__0114d6f0,param_5);
  _objc_release(param_5);
  if (param_6 != 0) {
    _objc_msgSend(uVar2,PTR_s_setSections__0114d968,param_6);
  }
  _objc_release(param_6);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return IVar3;
}


