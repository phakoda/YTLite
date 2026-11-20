/* Decompiled from supplied 5.2.2 arm package. VA 0x1ec5dc. sbPublicUserID: */

/* Function Stack Size: 0x18 bytes */

ID YTLUserDefaults::sbPublicUserID_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  CC_LONG len;
  undefined8 uVar4;
  undefined8 uVar5;
  void *data;
  ID IVar6;
  undefined **ppuVar7;
  long lVar8;
  int iVar9;
  uchar auStack_d0 [36];
  uint uStack_ac;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **ppuStack_90;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011bd0a8;
  local_74 = (uint)(DAT_01227eb0 == 0);
  local_88 = &PTR_LAB_011bce10;
  ppuStack_80 = &PTR_LAB_011bce10;
  local_98 = &PTR_LAB_011bd0d8;
  ppuStack_90 = &PTR_LAB_011bce10;
  local_a8 = &PTR_LAB_011bd0f0;
  DAT_01227eb0 = 1;
  _objc_msgSend(param_3,PTR_s_dataUsingEncoding__0114b460,4);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_dataWithBytes_length__0114b448;
  puVar2 = PTR_s_bytes_0114b440;
  puVar1 = PTR_s_length_0114b438;
  ppuVar7 = &PTR_s_setTintColor__0114b000;
  iVar9 = 4999;
  while( true ) {
    uVar5 = _objc_retainAutorelease(ppuVar7,uVar4);
    data = (void *)_objc_msgSend(uVar5,puVar2);
    len = _objc_msgSend(uVar4,puVar1);
    _CC_SHA256(data,len,auStack_d0);
    _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,puVar3,auStack_d0,0x20);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    uStack_9c = (uint)(iVar9 == 0);
    ppuVar7 = (undefined **)(local_98[uStack_9c] + (int)-(uRam00000000011bd0e8 ^ 0xcfc83ed7));
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    uStack_9c = 0;
    uVar4 = uVar5;
  }
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,PTR_s_stringWithCapacity__0114b488,0x40);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_appendFormat__0114b490;
  lVar8 = 0;
  ppuVar7 = &PTR_s_setTintColor__0114b000;
  while( true ) {
    thunk_FUN_001eef7c(ppuVar7,uVar4,puVar1,&PTR____CFConstantStringClassReference_011bca30,
                       auStack_d0[lVar8]);
    uStack_ac = (uint)(lVar8 == 0x1f);
    ppuVar7 = (undefined **)(local_a8[uStack_ac] + (int)-(uRam00000000011bd100 ^ 0xfb58273d));
    if (lVar8 == 0x1f) break;
    lVar8 = lVar8 + 1;
    uStack_ac = 0;
  }
  _objc_release(uVar5);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    IVar6 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar4);
    return IVar6;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


