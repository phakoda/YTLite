/* Decompiled from supplied 5.2.2 arm package. VA 0x1cd9f8. getFilePath */

/* Function Stack Size: 0x10 bytes */

ID Downloader::getFilePath(ID param_1,SEL param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  char acStack_b0 [24];
  undefined **local_98;
  undefined **ppuStack_90;
  undefined **local_80;
  uint uStack_74;
  undefined **local_70;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011b60e8;
  local_5c = (uint)(DAT_01227cf4 == 0);
  local_70 = &PTR_LAB_011b6108;
  local_80 = &PTR_LAB_011b6120;
  local_68 = &PTR_LAB_011b5f00;
  local_98 = &PTR_LAB_011b5f00;
  ppuStack_90 = &PTR_LAB_011b5f00;
  DAT_01227cf4 = 1;
  _NSTemporaryDirectory();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  acStack_b0[0] = '\0';
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_001cea98(uVar3,PTR_s_fileExistsAtPath_isDirectory__0114d048,uVar2,acStack_b0);
  _objc_release(uVar3);
  uStack_74 = 0;
  if (acStack_b0[0] != '\0') {
    uStack_74 = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x001cde10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar4 = (*(code *)(local_70[uStack_74] + (int)-(DAT_011b6118 ^ 0xf683adcc)))();
  return IVar4;
}


