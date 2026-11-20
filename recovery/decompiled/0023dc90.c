/* Decompiled from supplied 5.2.2 arm package. VA 0x23dc90. subLabelForVal:style: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x20 bytes */

ID PlayerToast::subLabelForVal_style_(ID param_1,SEL param_2,double param_3,long_long param_4)

{
  ID IVar1;
  
  if (DAT_01228550 != 0) {
    DAT_01228550 = 1;
                    /* WARNING: Could not recover jumptable at 0x0023dd48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar1 = (*(code *)((&PTR_LAB_011d2a30)[param_4 == 1] + (int)-(uRam00000000011d2a40 ^ 0xc9c6a16))
            )();
    return IVar1;
  }
  s___011d2624 = (char  [2])(_DAT_011d261c ^ 0xd129);
  s___011d2626 = (char  [2])(uRam00000000011d261e ^ 0x6920);
  uRam00000000011d2628 = uRam00000000011d2620 ^ 0xd73b;
  uRam00000000011d262a = uRam00000000011d2622 ^ 0xc34d;
  s__ld___011d2616[0] = DAT_011d2610 ^ 0x70;
  s__ld___011d2616[1] = bRam00000000011d2611 ^ 0x9b;
  s__ld___011d2616[2] = bRam00000000011d2612 ^ 0xe7;
  s__ld___011d2616[3] = bRam00000000011d2613 ^ 0x40;
  s__ld___011d2616[4] = bRam00000000011d2614 ^ 0x1c;
  s__ld___011d2616[5] = bRam00000000011d2615 ^ 0xc4;
  DAT_01228550 = 1;
                    /* WARNING: Could not recover jumptable at 0x0023de60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar1 = (*(code *)((&PTR_LAB_011d2a30)[param_4 == 1] + (int)-(uRam00000000011d2a40 ^ 0xc9c6a16)))
                    ();
  return IVar1;
}


