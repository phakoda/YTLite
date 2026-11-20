/* Decompiled from supplied 5.2.2 arm package. VA 0x22e998. cleanup */

/* Function Stack Size: 0x10 bytes */

void YTLHelper::cleanup(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  puVar1 = PTR__OBJC_CLASS___NSURL_0114eb78;
  DAT_012283d8 = 1;
  _NSTemporaryDirectory();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_00233138(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011d08f0,*(undefined8 *)(param_1 + 0x28)
                    );
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_stringByAppendingPathComponent__0114b6e8,uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(puVar1,PTR_s_fileURLWithPath__0114c430,uVar4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,PTR_s_defaultManager_0114b240);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  FUN_002331d8(uVar2,PTR_s_removeItemAtURL_error__0114dc60,uVar5,0);
  _objc_release(uVar2);
  _objc_release(uVar5);
  CallSupervisor(0x1622);
  return;
}


