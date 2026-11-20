/* Decompiled from supplied 5.2.2 arm package. VA 0x17998. FUN_00017998 */

undefined8 FUN_00017998(void)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  DAT_01225b78 = 1;
  uVar2 = (*DAT_012259f0)();
  puVar1 = PTR_s_setValue_forKey__0114b208;
  _objc_msgSend(uVar2,PTR_s_setValue_forKey__0114b208,
                &PTR____CFConstantStringClassReference_01153fb0,
                &PTR____CFConstantStringClassReference_01153f70);
  _objc_msgSend(uVar2,puVar1,&PTR____CFConstantStringClassReference_01153f30,
                &PTR____CFConstantStringClassReference_01153ef0);
  return uVar2;
}


