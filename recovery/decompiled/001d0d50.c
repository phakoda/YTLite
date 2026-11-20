/* Decompiled from supplied 5.2.2 arm package. VA 0x1d0d50. createTempDirectoryIfNeeded */

/* Function Stack Size: 0x10 bytes */

ID YTPDownloader::createTempDirectoryIfNeeded(ID param_1,SEL param_2)

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
  
  local_58 = &PTR_LAB_011b7658;
  local_5c = (uint)(DAT_01227d68 == 0);
  local_70 = &PTR_LAB_011b7678;
  local_80 = &PTR_LAB_011b7690;
  local_68 = &PTR__objc_msgSend_011b7210;
  local_98 = &PTR__objc_msgSend_011b7210;
  ppuStack_90 = &PTR__objc_msgSend_011b7210;
  DAT_01227d68 = 1;
  _NSTemporaryDirectory();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  acStack_b0[0] = '\0';
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_001d55d0(uVar3,PTR_s_fileExistsAtPath_isDirectory__0114d048,uVar2,acStack_b0);
  _objc_release(uVar3);
  uStack_74 = 0;
  if (acStack_b0[0] != '\0') {
    uStack_74 = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x001d116c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar4 = (*(code *)(local_70[uStack_74] + (int)-(DAT_011b7688 ^ 0xcbb4b3e4)))();
  return IVar4;
}


