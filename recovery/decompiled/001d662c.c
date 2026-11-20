/* Decompiled from supplied 5.2.2 arm package. VA 0x1d662c. init */

/* Function Stack Size: 0x10 bytes */

ID SbWhitelistVC::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  ID local_50;
  undefined *puStack_48;
  uint local_3c;
  undefined **local_38;
  undefined8 uStack_30;
  long local_28;
  
  local_28 = *(long *)PTR____stack_chk_guard_01060708;
  local_38 = &PTR_LAB_011b8ef0;
  puStack_48 = PTR_SbWhitelistVC_0114f118;
  local_50 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_50,PTR_s_initWithStyle__0114b790,1);
  local_3c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    uVar2 = _objc_msgSend(*(undefined8 *)PTR____NSArray0___01060670,PTR_s_mutableCopy_0114b010);
    lVar4 = (long)_channels;
    uVar3 = *(undefined8 *)(IVar1 + lVar4);
    *(undefined8 *)(IVar1 + lVar4) = uVar2;
    _objc_release(uVar3);
    uStack_30 = *(undefined8 *)(IVar1 + lVar4);
    _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                  &uStack_30,1);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = *(undefined8 *)(IVar1 + (long)_sections);
    *(undefined8 *)(IVar1 + (long)_sections) = uVar2;
    _objc_release(uVar3);
    _objc_msgSend(IVar1,PTR_s_setupWhitelist_0114e050);
  }
  if (*(long *)PTR____stack_chk_guard_01060708 != local_28) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return IVar1;
}


