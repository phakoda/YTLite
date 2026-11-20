/* Decompiled from supplied 5.2.2 arm package. VA 0xc8ed8. FUN_000c8ed8 */

undefined1  [16] FUN_000c8ed8(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined *puStack_c0;
  undefined8 uStack_b8;
  code *pcStack_b0;
  undefined *puStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined **local_78;
  undefined **ppuStack_70;
  uint uStack_64;
  undefined **local_60;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_01183488;
  local_4c = (uint)(DAT_01226ffc == 0);
  local_60 = &PTR_LAB_011834a8;
  local_58 = &PTR_LAB_01175340;
  local_78 = &PTR_LAB_01175340;
  ppuStack_70 = &PTR_LAB_01175340;
  DAT_01226ffc = 1;
  bVar3 = *(char *)(param_1 + 0x38) == '\0';
  uStack_64 = (uint)bVar3;
  if (bVar3) {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableDictionary_0114ed80,PTR_s_dictionary_0114c7f8);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_setObject_forKeyedSubscript__0114b068;
    _objc_msgSend(uVar4,PTR_s_setObject_forKeyedSubscript__0114b068,*(undefined8 *)(param_1 + 0x30),
                  &PTR____CFConstantStringClassReference_01174220);
    thunk_FUN_000eea9c(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_011741e0,
                       *(undefined8 *)(param_1 + 0x28));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar1,uVar5,&PTR____CFConstantStringClassReference_011741a0);
    _objc_release(uVar5);
    puVar2 = PTR__OBJC_CLASS___NSNumber_0114eb00;
    _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,PTR_s_date_0114b4d0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,PTR_s_timeIntervalSince1970_0114b4d8);
    _objc_msgSend(puVar2,PTR_s_numberWithDouble__0114c310);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,puVar1,uVar6,&PTR____CFConstantStringClassReference_01174160);
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar2 = PTR_YTPAPIHelper_0114ed88;
    puStack_c0 = PTR___NSConcreteStackBlock_01060660;
    uStack_b8 = DAT_00c4c228;
    pcStack_b0 = FUN_000c95d4;
    puStack_a8 = &UNK_01061f10;
    uVar5 = *(undefined8 *)(param_1 + 0x28);
    uStack_a0 = uVar4;
    uStack_98 = _objc_retain(*(undefined8 *)(param_1 + 0x20));
    uStack_90 = _objc_retain(*(undefined8 *)(param_1 + 0x28));
    puVar1 = PTR_s_fetchChannelImageWithChannelID_c_0114c818;
    _objc_retain(uVar4);
    _objc_msgSend(puVar2,puVar1,uVar5,&puStack_c0);
    _objc_release(uStack_90);
    _objc_release(uStack_98);
    _objc_release(uStack_a0);
  }
  else {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_removeObjectForKey__0114c810,
                  *(undefined8 *)(param_1 + 0x28));
    _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_setObject_forKey__0114c2b8,*(undefined8 *)(param_1 + 0x20),
                  &PTR____CFConstantStringClassReference_01174260);
  }
  _objc_release(uVar4);
  CallSupervisor(0x4a9b);
  return ZEXT816(0x1f);
}


