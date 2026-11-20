/* Decompiled from supplied 5.2.2 arm package. VA 0x1bdc0. FUN_0001bdc0 */

void FUN_0001bdc0(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 auStack_80 [2];
  undefined **local_70;
  uint uStack_64;
  undefined **local_60;
  uint uStack_54;
  undefined **local_50;
  undefined **ppuStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_01155558;
  local_3c = (uint)(DAT_01225c18 == 0);
  local_50 = &PTR_LAB_01155578;
  ppuStack_48 = &PTR_LAB_01154cd0;
  local_60 = &PTR_LAB_01155590;
  local_70 = &PTR_LAB_01154cd0;
  DAT_01225c18 = 1;
  FUN_0001ddac(PTR__OBJC_CLASS___NSDictionary_0114eb40,PTR_s_dictionaryWithObjectsAndKeys__0114b230,
               *(undefined8 *)PTR__kSecClassGenericPassword_01060d40,
               *(undefined8 *)PTR__kSecClass_01060d38,
               &PTR____CFConstantStringClassReference_01154be0,
               *(undefined8 *)PTR__kSecAttrAccount_01060d00,&cf___,
               *(undefined8 *)PTR__kSecAttrService_01060d30,
               *(undefined8 *)PTR__kCFBooleanTrue_01060bf8,
               *(undefined8 *)PTR__kSecReturnAttributes_01060d90,0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  auStack_80[0] = 0;
  iVar1 = _SecItemCopyMatching(uVar2,auStack_80);
  uStack_54 = (uint)(iVar1 == -0x62d4);
  if (iVar1 == -0x62d4) {
    iVar1 = _SecItemAdd(local_50[uStack_54] + (int)-(DAT_01155588 ^ 0x688776af),uVar2,auStack_80);
    uStack_64 = (uint)(iVar1 == 0);
    if (iVar1 != 0) {
      uVar3 = 0;
      goto LAB_0001c060;
    }
  }
  _objc_msgSend(auStack_80[0],PTR_s_objectForKey__0114b238,
                *(undefined8 *)PTR__kSecAttrAccessGroup_01060ce8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
LAB_0001c060:
  _objc_release(uVar2);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
  return;
}


