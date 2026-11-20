/* Decompiled from supplied 5.2.2 arm package. VA 0x30ee4. FUN_00030ee4 */

void FUN_00030ee4(void)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  int aiStack_d0 [4];
  undefined **local_c0;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **ppuStack_90;
  uint uStack_84;
  undefined **local_80;
  uint uStack_74;
  undefined **local_70;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_01159fe8;
  local_5c = (uint)(DAT_01225e40 == 0);
  local_70 = &PTR_LAB_0115a008;
  local_68 = &PTR_LAB_01158940;
  local_80 = &PTR_LAB_0115a020;
  local_98 = &PTR_FUN_0115a040;
  ppuStack_90 = &PTR_LAB_01158940;
  local_a8 = &PTR_LAB_0115a058;
  local_c0 = &PTR_LAB_01158940;
  ppuStack_b8 = &PTR_LAB_01158940;
  DAT_01225e40 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_mainBundle_0114adf8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_executablePath_0114b520);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_retainAutorelease();
  uVar5 = _objc_msgSend(uVar5,PTR_s_UTF8String_0114b498);
  _objc_release(uVar4);
  _objc_release(uVar3);
  aiStack_d0[0] = 0;
  puVar6 = (undefined8 *)_objc_copyClassNamesForImage(uVar5,aiStack_d0);
  iVar1 = aiStack_d0[0];
  uStack_74 = (uint)(puVar6 == (undefined8 *)0x0);
  if (puVar6 != (undefined8 *)0x0) {
    uStack_84 = (uint)(aiStack_d0[0] == 0);
    if (aiStack_d0[0] != 0) {
      iVar2 = _strcmp((char *)*puVar6,s_YTAppDelegate_0115892e);
      uStack_ac = (uint)(iVar2 == 0);
      if (iVar2 != 0) {
        uStack_9c = (uint)(iVar1 == 1);
                    /* WARNING: Could not recover jumptable at 0x000311d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(local_98[uStack_9c] + (int)-(uRam000000000115a050 ^ 0x7c83acdf)))();
        return;
      }
      uRam0000000001225d80 = 1;
    }
    _free(puVar6);
  }
  return;
}


