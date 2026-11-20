/* Decompiled from supplied 5.2.2 arm package. VA 0xb3ef0. FUN_000b3ef0 */

void FUN_000b3ef0(undefined8 param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  DAT_01226ea4 = 1;
  (*DAT_01226748)(param_1);
  uVar3 = 0x3ff0000000000000;
  if (DAT_0115cd38 == '\0') {
    uVar3 = 0;
  }
  _objc_msgSend(param_1,PTR_s_playbackOverlay_0114cc80);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,uVar1,PTR_s_setAlpha__0114b698);
  _objc_release(uVar1);
  uVar2 = FUN_000e9194(&PTR____CFConstantStringClassReference_011702f0);
                    /* WARNING: Could not recover jumptable at 0x000b4200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01181900)[uVar2 & 0xffffffff] + (int)-(DAT_01181910 ^ 0x65a85f33)))();
  return;
}


