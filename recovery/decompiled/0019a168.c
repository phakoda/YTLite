/* Decompiled from supplied 5.2.2 arm package. VA 0x19a168. getSegmentsForID: */

/* Function Stack Size: 0x18 bytes */

void SBManager::getSegmentsForID_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined *puStack_a0;
  undefined8 uStack_98;
  code *pcStack_90;
  undefined *puStack_88;
  ID IStack_80;
  ID IStack_78;
  undefined **local_70;
  uint uStack_64;
  undefined **local_60;
  undefined **ppuStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011ab640;
  local_4c = (uint)(DAT_012278a4 == 0);
  local_60 = &PTR_LAB_011ab660;
  ppuStack_58 = &PTR_LAB_011ab4e0;
  local_70 = &PTR_LAB_011ab4e0;
  DAT_012278a4 = 1;
  uVar2 = _objc_retain(param_3);
  lVar3 = _objc_msgSend(uVar2,PTR_s_length_0114b438);
  uStack_64 = (uint)(lVar3 == 0);
  if (lVar3 != 0) {
    _objc_msgSend(param_1,PTR_s_segments_0114dac0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,PTR_s_setObject_forKeyedSubscript__0114b068,0,param_3);
    _objc_release(uVar2);
    thunk_FUN_0019b414(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                       &PTR____CFConstantStringClassReference_011ab380,param_3,
                       *(undefined8 *)(param_1 + 8));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR__OBJC_CLASS___NSURLRequest_0114eed0;
    _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,uVar2);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,PTR_s_requestWithURL__0114da38,uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,PTR_s_sharedSession_0114d910);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puStack_a0 = PTR___NSConcreteStackBlock_01060660;
    uStack_98 = DAT_00c4c228;
    pcStack_90 = FUN_0019a7c8;
    puStack_88 = &UNK_010627c0;
    IStack_80 = param_1;
    _objc_retain(param_3);
    IStack_78 = param_3;
    _objc_msgSend(uVar4,PTR_s_dataTaskWithRequest_completionHa_0114db40,uVar5,&puStack_a0);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,PTR_s_resume_0114d928);
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_release(IStack_78);
    _objc_release(uVar5);
    _objc_release(uVar2);
  }
  _objc_release(param_3);
  CallSupervisor(0xa443);
  return;
}


