/* Decompiled from supplied 5.2.2 arm package. VA 0x1fe570. srtForLanguage:videoID:error: */

/* Function Stack Size: 0x28 bytes */

ID SRTParser::srtForLanguage_videoID_error_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID *param_5)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  char acStack_f0 [32];
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  undefined **local_b0;
  undefined **ppuStack_a8;
  undefined **local_98;
  undefined **local_90;
  uint uStack_84;
  undefined **local_80;
  undefined **ppuStack_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_011c27e8;
  local_6c = (uint)(DAT_01228078 == 0);
  local_98 = &PTR_LAB_011c2828;
  local_80 = &PTR_LAB_011c2808;
  ppuStack_78 = &PTR_LAB_011c25d0;
  local_90 = &PTR_LAB_011c25d0;
  local_b0 = &PTR_LAB_011c2848;
  ppuStack_a8 = &PTR_LAB_011c25d0;
  local_c8 = &PTR_LAB_011c25d0;
  ppuStack_c0 = &PTR_LAB_011c25d0;
  local_d0 = &PTR_LAB_011c25d0;
  DAT_01228078 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _NSTemporaryDirectory();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  acStack_f0[0] = '\0';
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_00200be0(uVar3,PTR_s_fileExistsAtPath_isDirectory__0114d048,uVar2,acStack_f0);
  _objc_release(uVar3);
  uStack_84 = 0;
  if (acStack_f0[0] != '\0') {
    uStack_84 = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x001fecf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar4 = (*(code *)(local_80[uStack_84] + (int)-(uRam00000000011c2818 ^ 0x9a8a4cf7)))();
  return IVar4;
}


