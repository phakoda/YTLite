/* Decompiled from supplied 5.2.2 arm package. VA 0x1028cc. FUN_001028cc */

undefined1  [16] FUN_001028cc(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puStack_a0;
  undefined8 uStack_98;
  code *pcStack_90;
  undefined *puStack_88;
  undefined8 uStack_80;
  undefined **local_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_0118a110;
  local_5c = (uint)(DAT_01227178 == 0);
  local_68 = &PTR_LAB_011882f0;
  DAT_01227178 = 1;
  thunk_FUN_00112050(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_01186d10,*(undefined8 *)(param_1 + 0x20)
                    );
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___UIApplication_0114ebc8,PTR_s_sharedApplication_0114b528);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,uVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = *(undefined8 *)PTR____NSDictionary0___01060678;
  puStack_a0 = PTR___NSConcreteStackBlock_01060660;
  uStack_98 = DAT_00c4c228;
  pcStack_90 = FUN_00102d20;
  puStack_88 = &DAT_01061940;
  uStack_80 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  _objc_msgSend(uVar2,PTR_s_openURL_options_completionHandle_0114b878,uVar3,uVar4,&puStack_a0);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_release(uStack_80);
  _objc_release(uVar1);
  CallSupervisor(26000);
  return ZEXT816(0x1f);
}


