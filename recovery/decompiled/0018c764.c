/* Decompiled from supplied 5.2.2 arm package. VA 0x18c764. cellsMatchingRecursive: */

/* Function Stack Size: 0x18 bytes */

ID DVNTableModel::cellsMatchingRecursive_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID IVar5;
  
  puVar2 = PTR__OBJC_CLASS___NSMutableArray_0114eb90;
  puVar1 = PTR_s_array_0114c388;
  _objc_retain(param_3,param_2,param_3,param_4);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSHashTable_0114eeb8,PTR_s_weakObjectsHashTable_0114d988);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s__collectMatching_into_visited__0114d990,param_3,uVar3,uVar4);
  _objc_release(param_3);
  _objc_release(uVar4);
  IVar5 = _objc_autoreleaseReturnValue(uVar3);
  return IVar5;
}


