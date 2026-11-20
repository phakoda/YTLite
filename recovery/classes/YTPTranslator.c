// Decompiled implementation evidence for YTPTranslator. Not compilable source.

// +[YTPTranslator translateText:fromLanguage:toLanguage:completion:], 0x1de550
/* Decompiled from supplied 5.2.2 arm package. VA 0x1de550. translateText:fromLanguage:toLanguage:completion: */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Function Stack Size: 0x30 bytes */

void YTPTranslator::translateText_fromLanguage_toLanguage_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,
               undefined4 param_7)

{
  ulong uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  long lVar11;
  undefined8 uVar12;
  dispatch_group_t group;
  undefined8 uVar13;
  undefined *puVar14;
  ulong uVar15;
  ulong uVar16;
  undefined8 auStack_220 [8];
  undefined *puStack_1e0;
  undefined8 uStack_1d8;
  code *pcStack_1d0;
  undefined *puStack_1c8;
  undefined8 uStack_1c0;
  dispatch_group_t pdStack_1b8;
  undefined8 *puStack_1b0;
  undefined8 auStack_1a0 [7];
  undefined8 *puStack_168;
  ID IStack_160;
  undefined *puStack_158;
  ID IStack_150;
  undefined *puStack_148;
  ID IStack_140;
  ID IStack_138;
  ID local_130;
  undefined8 *puStack_128;
  undefined **local_120;
  undefined **local_118;
  uint uStack_10c;
  undefined **local_108;
  undefined **ppuStack_100;
  uint uStack_f4;
  undefined **local_f0;
  undefined **ppuStack_e8;
  uint uStack_dc;
  undefined **local_d8;
  uint uStack_cc;
  undefined **local_c8;
  undefined **local_c0;
  uint uStack_b4;
  undefined **local_b0;
  undefined **local_a8;
  uint uStack_9c;
  undefined **local_98;
  undefined **local_90;
  uint local_84;
  undefined **local_80;
  
  local_80 = &PTR_LAB_011b9928;
  local_84 = (uint)(DAT_01227df4 == 0);
  local_98 = &PTR_LAB_011b9948;
  local_b0 = &PTR_LAB_011b9968;
  local_c8 = &PTR_LAB_011b9988;
  local_d8 = &PTR_LAB_011b99a0;
  local_90 = &PTR_LAB_011b97a0;
  local_a8 = &PTR_LAB_011b97a0;
  local_c0 = &PTR_LAB_011b97a0;
  local_f0 = &PTR_LAB_011b99c0;
  ppuStack_e8 = &PTR_LAB_011b97a0;
  local_108 = &PTR_LAB_011b99e0;
  ppuStack_100 = &PTR_LAB_011b97a0;
  local_118 = &PTR_LAB_011b97a0;
  local_120 = &PTR_LAB_011b97a0;
  DAT_01227df4 = 1;
  puStack_128 = auStack_1a0;
  local_130 = param_1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_6);
  puVar2 = @selector(length);
  uVar6 = _objc_msgSend(param_3,@selector(length));
  uStack_9c = (uint)(uVar6 < 0x5dd);
  if (uVar6 < 0x5dd) {
    _objc_msgSend(local_130,@selector(translateSingleText:fromLanguage:toLanguage:completion:),param_3,param_4,param_5,
                  param_6);
  }
  else {
    puStack_168 = auStack_220;
    IStack_160 = param_6;
    IStack_140 = param_5;
    IStack_138 = param_4;
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    lVar8 = _objc_msgSend(param_3,puVar2);
    puVar3 = @selector(substringWithRange:);
    uStack_b4 = (uint)(lVar8 == 0);
    IStack_150 = param_3;
    if (lVar8 != 0) {
      puStack_158 = @selector(rangeOfString:options:);
      puStack_148 = @selector(addObject:);
      puVar14 = @selector(addObject:);
      uVar6 = 0;
      do {
        lVar8 = _objc_msgSend(puVar14,param_3,puVar2);
        uVar15 = lVar8 - uVar6;
        if (0x5db < uVar15) {
          uVar15 = 0x5dc;
        }
        _objc_msgSend(param_3,puVar3,uVar6,uVar15);
        uVar9 = _objc_retainAutoreleasedReturnValue();
        uVar16 = uVar15 + uVar6;
        uVar10 = _objc_msgSend(param_3,puVar2);
        puVar14 = puStack_158;
        uStack_cc = (uint)(uVar16 < uVar10);
        if (uVar16 < uVar10) {
          lVar8 = _objc_msgSend(uVar9,puStack_158,@".",4)
          ;
          param_3 = IStack_150;
          lVar11 = _objc_msgSend(uVar9,puVar14,@"\n",4);
          uVar10 = 0;
          if (lVar8 != 0x7fffffffffffffff) {
            uVar10 = lVar8 + 1;
          }
          uVar1 = 0;
          if (lVar11 != 0x7fffffffffffffff) {
            uVar1 = lVar11 + 1;
          }
          if (uVar10 <= uVar1) {
            uVar10 = uVar1;
          }
          uStack_dc = (uint)(uVar10 != 0 && uVar10 < uVar15);
          if (uVar10 != 0 && uVar10 < uVar15) {
            _objc_msgSend(local_d8[uStack_dc] + (int)-(uRam00000000011b99b0 ^ 0x45eaeeb7),param_3,
                          puVar3,uVar6,uVar10);
            uVar12 = _objc_retainAutoreleasedReturnValue();
            _objc_release(uVar9);
            uVar16 = uVar10 + uVar6;
            uVar9 = uVar12;
          }
        }
        _objc_msgSend(uVar7,puStack_148,uVar9);
        _objc_release(uVar9);
        uVar15 = _objc_msgSend(param_3,puVar2);
        uStack_f4 = (uint)(uVar16 < uVar15);
        puVar14 = local_f0[uStack_f4] + (int)-(uRam00000000011b99d0 ^ 0x6ea0b03a);
        uVar6 = uVar16;
      } while (uVar16 < uVar15);
    }
    puVar2 = PTR__OBJC_CLASS___NSMutableArray_0114eb90;
    puVar3 = @selector(count);
    uVar9 = _objc_msgSend(uVar7,@selector(count));
    _objc_msgSend(puVar2,@selector(arrayWithCapacity:),uVar9);
    uVar12 = _objc_retainAutoreleasedReturnValue();
    puVar4 = puStack_128;
    *puStack_128 = 0;
    puVar4[1] = puVar4;
    puVar4[2] = _UNK_00c4c350;
    puVar4[3] = FUN_001dec80;
    puVar4[4] = FUN_001deca8;
    puVar4[5] = 0;
    group = _dispatch_group_create();
    puVar14 = @selector(translateSingleText:fromLanguage:toLanguage:completion:);
    puVar2 = @selector(objectAtIndexedSubscript:);
    uVar9 = DAT_00c4c228;
    uVar6 = 0;
    while( true ) {
      uVar15 = _objc_msgSend(uVar7,puVar3);
      puVar4 = puStack_168;
      uStack_10c = (uint)(uVar6 < uVar15);
      if (uVar6 >= uVar15) break;
      _dispatch_group_enter(group);
      _objc_msgSend(uVar7,puVar2,uVar6);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      puStack_1e0 = PTR___NSConcreteStackBlock_01060660;
      uStack_1d8 = uVar9;
      pcStack_1d0 = FUN_001decd8;
      puStack_1c8 = &UNK_01062da0;
      _objc_retain(uVar12);
      puStack_1b0 = puStack_128;
      uStack_1c0 = uVar12;
      _objc_retain(group);
      pdStack_1b8 = group;
      _objc_msgSend(local_130,puVar14,uVar13,IStack_138,IStack_140,&puStack_1e0);
      _objc_release(uVar13);
      _objc_release(pdStack_1b8);
      _objc_release(uStack_1c0);
      uVar6 = uVar6 + 1;
    }
    *puStack_168 = PTR___NSConcreteStackBlock_01060660;
    puVar4[1] = uVar9;
    puVar4[2] = FUN_001dee84;
    puVar4[3] = &UNK_01062dd0;
    puVar5 = puStack_128;
    puVar4[6] = puStack_128;
    param_6 = IStack_160;
    _objc_retain(IStack_160);
    puVar4[4] = uVar12;
    puVar4[5] = param_6;
    _objc_retain(uVar12);
    _dispatch_group_notify(group,PTR___dispatch_main_q_01060760,puVar4);
    _objc_release(puVar4[4]);
    _objc_release(puVar4[5]);
    _objc_release(group);
    __Block_object_dispose(puVar5,8);
    _objc_release(puVar5[5]);
    _objc_release(uVar12);
    _objc_release(uVar7);
    param_4 = IStack_138;
    param_3 = IStack_150;
    param_5 = IStack_140;
  }
  _objc_release(param_6);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_3);
  CallSupervisor(0x97bf);
  return;
}



// +[YTPTranslator translateSingleText:fromLanguage:toLanguage:completion:], 0x1defc8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1defc8. translateSingleText:fromLanguage:toLanguage:completion: */

/* Function Stack Size: 0x30 bytes */

void YTPTranslator::translateSingleText_fromLanguage_toLanguage_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,
               undefined4 param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puStack_b0;
  undefined8 uStack_a8;
  code *pcStack_a0;
  undefined *puStack_98;
  ID IStack_90;
  undefined **local_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_011b9a50;
  local_6c = (uint)(DAT_01227e14 == 0);
  local_78 = &PTR_LAB_011b97a0;
  DAT_01227e14 = 1;
  _objc_retain(param_6);
  puVar1 = @selector(stringByReplacingOccurrencesOfString:withString:);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_msgSend(param_3,puVar1,&PTR____CFConstantStringClassReference_011b9720,
                @"No");
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,puVar1,&PTR____CFConstantStringClassReference_011b9620,
                @"-");
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,@selector(URLQueryAllowedCharacterSet)
               );
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(stringByAddingPercentEncodingWithAllowedCharacters:),uVar2);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  thunk_FUN_001e0408(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                     @"https://translate.googleapis.com/translate_a/single?client=gtx&sl=%@&tl=%@&dt=t&q=%@",param_4,param_5,uVar4);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,@selector(sharedSession));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,@selector(URLWithString:),uVar2);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(dataTaskWithURL:completionHandler:);
  puStack_b0 = PTR___NSConcreteStackBlock_01060660;
  uStack_a8 = DAT_00c4c228;
  pcStack_a0 = FUN_001df82c;
  puStack_98 = &DAT_01062cf0;
  IStack_90 = param_6;
  _objc_retain(param_6);
  _objc_msgSend(uVar5,puVar1,uVar6,&puStack_b0);
  uVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar6);
  _objc_msgSend(uVar7,@selector(resume));
  _objc_release(uVar7);
  _objc_release(IStack_90);
  _objc_release(param_6);
  _objc_release(uVar5);
  _objc_release(uVar2);
  _objc_release(uVar4);
  _objc_release(uVar3);
  CallSupervisor(0xb90);
  return;
}


