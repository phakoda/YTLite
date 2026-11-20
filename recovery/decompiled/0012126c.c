/* Decompiled from supplied 5.2.2 arm package. VA 0x12126c. _cellsForSection: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableViewController::_cellsForSection_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  long lVar2;
  ID IVar3;
  undefined8 uVar4;
  
  puVar1 = PTR_s_cellsProvider_0114d530;
  _objc_retain(param_3);
  _objc_msgSend(param_3,puVar1);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 == 0) {
    _objc_msgSend(param_3,PTR_s_cells_0114d290);
    uVar4 = _objc_retainAutoreleasedReturnValue();
  }
  else {
    _objc_msgSend((&PTR_LAB_0118dcd8)[lVar2 == 0] + (int)-(DAT_0118dce8 ^ 0xedf822d5),param_3,puVar1
                 );
    IVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_3);
    (**(code **)(IVar3 + 0x10))(IVar3);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    param_3 = IVar3;
  }
  _objc_release(param_3);
  _objc_release(lVar2);
  IVar3 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
  return IVar3;
}


