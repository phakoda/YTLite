/* Decompiled from supplied 5.2.2 arm package. VA 0x213554. FUN_00213554 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16] FUN_00213554(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_01228148 = 1;
  uVar5 = *(undefined8 *)(param_1 + 0x20);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),uVar5,PTR_s_formattedTime__0114e400);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSBundle_0114eae8,PTR_s_ytl_defaultBundle_0114ae50);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_imageWithName__0114c5b0,&PTR____CFConstantStringClassReference_011cb660)
  ;
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(DAT_00c4c458,_UNK_00c4c4b0,DAT_00c4c4b8,0x3ff0000000000000,
                PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_colorWithRed_green_blue_alpha__0114c5f8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_showSlimBarWithTitle_image_color_0114e408,uVar1,uVar3,uVar4,
                *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x28));
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uVar1);
  CallSupervisor(0x96ec);
  return ZEXT816(0x1f);
}


