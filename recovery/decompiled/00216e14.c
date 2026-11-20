/* Decompiled from supplied 5.2.2 arm package. VA 0x216e14. showSlimBarWithTitle:image:color:style: */

/* Function Stack Size: 0x30 bytes */

void YTPSleepTimer::showSlimBarWithTitle_image_color_style_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,unsigned_long_long param_6)

{
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_msgSend(param_1,PTR_s_cleanup_0114de90);
                    /* WARNING: Could not recover jumptable at 0x00216f00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_011ccb50)[param_5 == 0] + (int)-(DAT_011ccb60 ^ 0xb853a10d)))();
  return;
}


