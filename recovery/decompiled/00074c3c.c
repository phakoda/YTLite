/* Decompiled from supplied 5.2.2 arm package. VA 0x74c3c. FUN_00074c3c */

undefined1  [16] FUN_00074c3c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  DAT_01226ba0 = 1;
  _objc_msgSend(param_3,PTR_s_object_0114c760);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar5 = _objc_msgSend(uVar2,PTR_s_floatValue_0114c768);
  _objc_release(uVar2);
  _objc_msgSend(param_1,PTR_s_speedValue_0114bcc8);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR__OBJC_CLASS___NSString_0114eb38;
  _objc_msgSend(uVar5,PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithFloat__0114c6c8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  thunk_FUN_000daff0(puVar1,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011645f0,uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setTitle_forState__0114b6a8,uVar4,0);
  _objc_release(uVar4);
  _objc_release(uVar3);
  _objc_release(uVar2);
  CallSupervisor(0xce24);
  return ZEXT816(0x1f);
}


