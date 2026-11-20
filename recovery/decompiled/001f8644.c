/* Decompiled from supplied 5.2.2 arm package. VA 0x1f8644. FUN_001f8644 */

undefined1  [16] FUN_001f8644(long param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  undefined *puStack_a0;
  undefined8 uStack_98;
  code *pcStack_90;
  undefined *puStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined4 uStack_68;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  puVar1 = PTR_MobileFFmpeg_0114eff0;
  local_48 = &PTR_LAB_011c1ac8;
  local_4c = (uint)(DAT_01228028 == 0);
  local_58 = &PTR_LAB_011c1600;
  DAT_01228028 = 1;
  thunk_FUN_001fd950(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011be910,*(undefined8 *)(param_1 + 0x20)
                     ,*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x28));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_msgSend(puVar1,PTR_s_execute__0114e290,uVar3);
  _objc_release(uVar3);
  puStack_a0 = PTR___NSConcreteStackBlock_01060660;
  uStack_98 = DAT_00c4c228;
  pcStack_90 = FUN_001f8b00;
  puStack_88 = &DAT_01062f50;
  uStack_80 = *(undefined8 *)(param_1 + 0x30);
  uStack_68 = uVar2;
  uStack_70 = _objc_retain(*(undefined8 *)(param_1 + 0x38));
  uStack_78 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
  _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_a0);
  _objc_release(uStack_78);
  _objc_release(uStack_70);
  CallSupervisor(0xc79c);
  auVar4._8_8_ = 0x1f;
  auVar4._0_8_ = 0x1a;
  return auVar4;
}


