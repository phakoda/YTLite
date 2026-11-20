/* Decompiled from supplied 5.2.2 arm package. VA 0x1c8fb4. initialize */

/* Function Stack Size: 0x10 bytes */

void ToastWindow::initialize(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined **ppuStack_90;
  undefined **ppuStack_88;
  undefined **ppuStack_80;
  undefined **ppuStack_78;
  undefined **ppuStack_70;
  undefined **local_60;
  uint local_54;
  undefined **local_50;
  long local_48;
  
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  local_50 = &PTR_LAB_011b4d40;
  local_54 = (uint)(DAT_01227c74 == 0);
  local_60 = &PTR_LAB_011b49f0;
  DAT_01227c74 = 1;
  ppuStack_90 = &PTR____CFConstantStringClassReference_011b49d0;
  ppuStack_88 = &PTR____CFConstantStringClassReference_011b4990;
  ppuStack_80 = &PTR____CFConstantStringClassReference_011b4910;
  ppuStack_78 = &PTR____CFConstantStringClassReference_011b48d0;
  ppuStack_70 = &PTR____CFConstantStringClassReference_011b4890;
  _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,PTR_s_arrayWithObjects_count__0114b600,
                &ppuStack_90,5);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_componentsJoinedByString__0114ded0,&cf___);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  uVar3 = _NSSelectorFromString(uVar4);
  uVar5 = _class_getInstanceMethod(param_1,PTR_s_shouldAffectStatusBarAppearance_0114ded8);
  uVar6 = _method_getImplementation();
  uVar5 = _method_getTypeEncoding(uVar5);
  FUN_001c9a18(param_1,uVar3,uVar6,uVar5);
  puVar2 = PTR__OBJC_CLASS___NSString_0114eb38;
  puVar1 = PTR_s_canBecomeKeyWindow_0114dee0;
  _NSStringFromSelector(PTR_s_canBecomeKeyWindow_0114dee0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_001c9a4c(puVar2,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011b4950,uVar3);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  uVar3 = _NSSelectorFromString(uVar5);
  uVar6 = _class_getInstanceMethod(param_1,puVar1);
  uVar7 = _method_getImplementation();
  uVar6 = _method_getTypeEncoding(uVar6);
  FUN_001c9b08(param_1,uVar3,uVar7,uVar6);
  _objc_release(uVar5);
  _objc_release(uVar4);
  CallSupervisor(0xdb6a);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


