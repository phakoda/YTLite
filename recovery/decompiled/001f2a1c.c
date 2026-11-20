/* Decompiled from supplied 5.2.2 arm package. VA 0x1f2a1c. openVideoWithID: */

/* Function Stack Size: 0x18 bytes */

void YTPPlayerHelper::openVideoWithID_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  ID IVar8;
  
  DAT_01227f9c = 1;
  _objc_retain(param_3);
  puVar2 = PTR_s_class_0114ae88;
  if (param_3 == 0) goto LAB_001f2de4;
  uVar5 = _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_class_0114ae88);
  puVar1 = PTR_s_isKindOfClass__0114ad70;
  uVar3 = FUN_001f3d6c(param_3,PTR_s_isKindOfClass__0114ad70,uVar5);
  if (uVar3 == 0) {
    uVar5 = _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,puVar2);
    iVar4 = FUN_001f3db4(param_3,puVar1,uVar5);
    IVar8 = 0;
    if (iVar4 != 0) {
      _objc_msgSend(param_3,PTR_s_absoluteString_0114c580);
      IVar8 = _objc_retainAutoreleasedReturnValue();
      goto LAB_001f2cf0;
    }
  }
  else {
    _objc_retain((&PTR_LAB_011bdc28)[uVar3] + (int)-(uRam00000000011bdc38 ^ 0xfc07c4b0),param_3);
    IVar8 = param_3;
LAB_001f2cf0:
    lVar6 = _objc_msgSend(IVar8,PTR_s_length_0114b438);
    puVar2 = PTR__OBJC_CLASS___NSURL_0114eb78;
    if (lVar6 != 0) {
      thunk_FUN_001f3cac(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                         &PTR____CFConstantStringClassReference_011bd870,IVar8);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(puVar2,PTR_s_URLWithString__0114b3d0,uVar5);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      _objc_release(uVar5);
      _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
      uVar5 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar5,PTR_s_openURL_options_completionHandle_0114b878,uVar7,
                    *(undefined8 *)PTR____NSDictionary0___01060678,0);
      _objc_release(uVar5);
      _objc_release(uVar7);
    }
  }
  _objc_release(IVar8);
LAB_001f2de4:
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


