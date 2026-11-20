/* Decompiled from supplied 5.2.2 arm package. VA 0x1ebdbc. sbPrivateUserID */

/* Function Stack Size: 0x10 bytes */

ID YTLUserDefaults::sbPrivateUserID(ID param_1,SEL param_2)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID IVar7;
  long lVar8;
  byte abStack_e0 [52];
  undefined4 uStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **ppuStack_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011bd048;
  local_74 = (uint)(DAT_01227eac == 0);
  local_88 = &PTR_LAB_011bd068;
  ppuStack_80 = &PTR_LAB_011bce10;
  local_a0 = &PTR_LAB_011bce10;
  ppuStack_98 = &PTR_LAB_011bce10;
  local_a8 = &PTR_LAB_011bd090;
  DAT_01227eac = 1;
  uVar5 = _SecRandomCopyBytes(*(undefined8 *)PTR__kSecRandomDefault_01060d88,0x24,abStack_e0);
  bVar4 = (int)uVar5 == 0;
  uStack_8c = (uint)bVar4;
  if (bVar4) {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,PTR_s_stringWithCapacity__0114b488,0x24
                 );
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar3 = PTR_s_characterAtIndex__0114e140;
    puVar2 = PTR_s_appendFormat__0114b490;
    lVar8 = 0;
    while( true ) {
      bVar1 = abStack_e0[lVar8];
      uVar6 = _objc_msgSend(&PTR____CFConstantStringClassReference_011bc9a0,puVar3,
                            (uint)bVar1 + ((bVar1 >> 1) / 0x1f) * -0x3e & 0xff);
      thunk_FUN_001eeeb0(uVar5,puVar2,&PTR____CFConstantStringClassReference_011bc960,uVar6);
      lVar8 = lVar8 + 1;
      if (lVar8 == 0x24) break;
      uStack_ac = 0;
    }
    uStack_ac = 1;
  }
  else {
    thunk_FUN_001eee64(local_88[uStack_8c] + (int)-(DAT_011bd078 ^ 0x4a96c68d),
                       &PTR____CFConstantStringClassReference_011bc9e0,uVar5);
    uVar5 = 0;
  }
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    IVar7 = _objc_autoreleaseReturnValue(uVar5);
    return IVar7;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


