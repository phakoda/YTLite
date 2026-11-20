/* Decompiled from supplied 5.2.2 arm package. VA 0x13858. FUN_00013858 */

void FUN_00013858(undefined8 param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  DAT_012259a4 = 1;
  _objc_msgSend(param_1,PTR_s_valueForKey__0114ae90,&PTR____CFConstantStringClassReference_01153150)
  ;
  uVar3 = _objc_retainAutoreleasedReturnValue();
  if (lRam0000000001225988 == 0) {
    lRam0000000001225988 =
         _objc_getClass((&PTR_LAB_011534a0)[lRam0000000001225988 == 0] +
                        (int)-(uRam00000000011534b0 ^ 0x6a85064a),s_YTIIcon_011530a2);
  }
  uVar4 = _objc_retainAutorelease();
  uVar4 = _objc_msgSend(uVar4,PTR_s_new_0114b030);
  _objc_msgSend(uVar4,PTR_s_setIconType__0114b038,0x212);
  puVar1 = PTR_s_setSectionItems_forCategory_titl_0114b040;
  uVar2 = FUN_000147b4(uVar3,PTR_s_respondsToSelector__0114af58,
                       PTR_s_setSectionItems_forCategory_titl_0114b040);
  if (uVar2 == 0) {
    _objc_msgSend(uVar3,PTR_s_setSectionItems_forCategory_titl_0114b048,0,0x315,
                  &PTR____CFConstantStringClassReference_01153110,0,0);
  }
  else {
    _objc_msgSend((&PTR_LAB_011534c0)[uVar2] + (int)-(uRam00000000011534d0 ^ 0x7753c9f4),uVar3,
                  puVar1,0,0x315,&PTR____CFConstantStringClassReference_01153110,uVar4,0,0);
  }
  _objc_release(uVar4);
  (*(code *)PTR__objc_release_01061028)(uVar3);
  return;
}


