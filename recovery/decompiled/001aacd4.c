/* Decompiled from supplied 5.2.2 arm package. VA 0x1aacd4. oledForColor: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x18 bytes */

ID YTPMedia::oledForColor_(ID param_1,SEL param_2,ID param_3)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  ID IVar4;
  undefined *puVar5;
  double dStack_60;
  double dStack_58;
  double dStack_50;
  double dStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011b2670;
  _objc_retain(param_3);
  lVar3 = _objc_msgSend(param_1,PTR_s_pageStyle_0114c698);
  bVar1 = lVar3 == 1;
  local_3c = (uint)bVar1;
  puVar5 = local_38[bVar1] + (int)-(DAT_011b2680 ^ 0x4f39ca87);
  if (bVar1) {
    uVar2 = FUN_001b740c(param_3,PTR_s_getRed_green_blue_alpha__0114dca0,&dStack_48,&dStack_50,
                         &dStack_58,&dStack_60);
    puVar5 = (&PTR_LAB_011b2690)[uVar2] + (int)-(uRam00000000011b26a0 ^ 0xd7fae96);
    if (uVar2 != 0) {
      if ((ABS(dStack_48 - _UNK_00c4c3a0) < DAT_00c4c398) &&
         (ABS(dStack_50 - _UNK_00c4c3a0) < DAT_00c4c398)) {
        uVar2 = (uint)(DAT_00c4c398 <= ABS(dStack_58 - _UNK_00c4c3a0));
        if (DAT_00c4c398 <= ABS(dStack_60 + -1.0)) {
          uVar2 = 1;
        }
                    /* WARNING: Could not recover jumptable at 0x001aaecc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        IVar4 = (*(code *)((&PTR_LAB_011b26e8)[uVar2] + (int)-(uRam00000000011b26f8 ^ 0x71014bf9)))
                          ();
        return IVar4;
      }
                    /* WARNING: Could not recover jumptable at 0x001aaf00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      IVar4 = (*(code *)(PTR_LAB_011b2708 + (int)-(uRam00000000011b2710 ^ 0xf455bd71)))();
      return IVar4;
    }
  }
  _objc_retain(puVar5,param_3);
  _objc_release(param_3);
  IVar4 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(param_3);
  return IVar4;
}


