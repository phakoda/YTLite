/* Decompiled from supplied 5.2.2 arm package. VA 0x1ca6dc. fetchChannelImageWithChannelID:completion: */

/* Function Stack Size: 0x20 bytes */

void YTPAPIHelper::fetchChannelImageWithChannelID_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined **ppuVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 uVar10;
  ID IVar11;
  undefined8 auStack_190 [6];
  long alStack_160 [2];
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **appuStack_130 [2];
  undefined1 auStack_120 [16];
  undefined **ppuStack_110;
  undefined **ppuStack_108;
  undefined8 uStack_100;
  ID IStack_f8;
  undefined8 *puStack_e8;
  undefined ***pppuStack_e0;
  undefined1 *puStack_d8;
  long *plStack_d0;
  undefined ***pppuStack_c8;
  undefined8 *puStack_c0;
  undefined8 uStack_b8;
  ID local_b0;
  ID IStack_a8;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011b5a30;
  local_74 = (uint)(DAT_01227cd4 == 0);
  local_88 = &PTR_LAB_011b5a50;
  local_80 = &PTR_LAB_011b59b0;
  local_a0 = &PTR_LAB_011b59b0;
  ppuStack_98 = &PTR_LAB_011b59b0;
  DAT_01227cd4 = 1;
  puStack_c0 = &uStack_100;
  pppuStack_e0 = &ppuStack_110;
  puStack_d8 = auStack_120;
  plStack_d0 = alStack_160;
  puStack_e8 = auStack_190;
  pppuStack_c8 = pppuStack_e0;
  local_b0 = param_4;
  IStack_a8 = param_3;
  _objc_retain(param_3);
  _objc_retain(local_b0);
  _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                &PTR____CFConstantStringClassReference_011b5470);
  uStack_b8 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_dictionaryWithObjects_forKeys_co_0114b420;
  ppuStack_110 = &PTR____CFConstantStringClassReference_011b53f0;
  appuStack_130[0] = &PTR____CFConstantStringClassReference_011b53b0;
  ppuStack_150 = &PTR____CFConstantStringClassReference_011b5370;
  ppuStack_148 = &PTR____CFConstantStringClassReference_011b5430;
  ppuStack_140 = &PTR____CFConstantStringClassReference_011b52f0;
  ppuStack_138 = &PTR____CFConstantStringClassReference_011b5270;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                PTR_s_dictionaryWithObjects_forKeys_co_0114b420,&ppuStack_140,&ppuStack_150,2);
  ppuVar4 = (undefined **)_objc_retainAutoreleasedReturnValue();
  puVar3 = puStack_d8;
  pppuStack_e0[-2] = ppuVar4;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puVar3,appuStack_130,1);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  ppuStack_108 = &PTR____CFConstantStringClassReference_011b51f0;
  uStack_100 = uVar5;
  IStack_f8 = param_3;
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,puVar1,puStack_c0,pppuStack_c8,2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar5);
  _objc_release(ppuVar4);
  alStack_160[0] = 0;
  _objc_msgSend(PTR__OBJC_CLASS___NSJSONSerialization_0114ebb0,
                PTR_s_dataWithJSONObject_options_error_0114b4f0,uVar6,0,plStack_d0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  lVar9 = alStack_160[0];
  _objc_retain(alStack_160[0]);
  uVar5 = uStack_b8;
  puVar1 = PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80;
  uStack_8c = (uint)(lVar9 == 0);
  if (lVar9 == 0) {
    _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_URLWithString__0114b3d0,uStack_b8);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,PTR_s_requestWithURL__0114da38,uVar8);
    lVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar8);
    _objc_msgSend(lVar9,PTR_s_setHTTPMethod__0114dee8,
                  &PTR____CFConstantStringClassReference_011b52b0);
    _objc_msgSend(lVar9,PTR_s_setValue_forHTTPHeaderField__0114def0,
                  &PTR____CFConstantStringClassReference_011b5230,
                  &PTR____CFConstantStringClassReference_011b5330);
    _objc_msgSend(lVar9,PTR_s_setHTTPBody__0114def8,uVar7);
    _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,PTR_s_sharedSession_0114d910);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puVar2 = puStack_e8;
    *puStack_e8 = PTR___NSConcreteStackBlock_01060660;
    puVar2[1] = DAT_00c4c228;
    puVar2[2] = FUN_001cb938;
    puVar2[3] = &DAT_01062cf0;
    IVar11 = local_b0;
    _objc_retain(local_b0);
    puVar2[4] = IVar11;
    _objc_msgSend(uVar8,PTR_s_dataTaskWithRequest_completionHa_0114db40,lVar9,puVar2);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar8);
    _objc_msgSend(uVar10,PTR_s_resume_0114d928);
    _objc_release(uVar10);
    _objc_release(puVar2[4]);
    _objc_release(0);
  }
  else {
    _objc_msgSend(lVar9,PTR_s_localizedDescription_0114c618);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    thunk_FUN_001cc9c0(&PTR____CFConstantStringClassReference_011b51b0,uVar5);
    _objc_release(uVar5);
    IVar11 = local_b0;
    (**(code **)(local_b0 + 0x10))(local_b0,0);
    uVar5 = uStack_b8;
  }
  _objc_release(lVar9);
  _objc_release(uVar7);
  _objc_release(uVar6);
  _objc_release(uVar5);
  _objc_release(IVar11);
  _objc_release(IStack_a8);
  CallSupervisor(0x613f);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_68) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


