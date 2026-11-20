// Decompiled implementation evidence for SRTParser. Not compilable source.

// -[SRTParser init], 0x1fdf2c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1fdf2c. init */

/* Function Stack Size: 0x10 bytes */

ID SRTParser::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011c2778;
  puStack_38 = PTR_SRTParser_0114f138;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,@selector(init));
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableArray_0114eb90,@selector(array));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = *(undefined8 *)(IVar1 + 8);
    *(undefined8 *)(IVar1 + 8) = uVar2;
    _objc_release(uVar3);
    *(undefined8 *)(IVar1 + 0x20) = 1;
    _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,@selector(string));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uVar3 = *(undefined8 *)(IVar1 + 0x10);
    *(undefined8 *)(IVar1 + 0x10) = uVar2;
    _objc_release(uVar3);
  }
  return IVar1;
}



// -[SRTParser parseXMLFromURL:forLanguage:videoID:completion:], 0x1fe01c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1fe01c. parseXMLFromURL:forLanguage:videoID:completion: */

/* Function Stack Size: 0x30 bytes */

void SRTParser::parseXMLFromURL_forLanguage_videoID_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,
               undefined4 param_7)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *local_90;
  undefined8 local_88;
  code *local_80;
  undefined *puStack_78;
  ID local_70;
  ID local_68;
  ID local_60;
  ID local_58;
  
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_6);
  *(undefined1 *)(param_1 + 0x40) = 0;
  puVar2 = PTR__OBJC_CLASS___NSMutableArray_0114eb90;
  puVar1 = @selector(array);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = uVar3;
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,@selector(sharedSession));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(dataTaskWithURL:completionHandler:);
  local_90 = PTR___NSConcreteStackBlock_01060660;
  local_88 = DAT_00c4c228;
  local_80 = FUN_001fe1c4;
  puStack_78 = &DAT_01063030;
  local_70 = param_1;
  local_68 = param_4;
  local_60 = param_5;
  local_58 = param_6;
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_6);
  _objc_msgSend(uVar3,puVar1,param_3,&local_90);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_release(uVar3);
  _objc_msgSend(uVar4,@selector(resume));
  _objc_release(uVar4);
  _objc_release(local_60);
  _objc_release(local_68);
  _objc_release(local_58);
  _objc_release(param_5);
  _objc_release(param_4);
  _objc_release(param_6);
  CallSupervisor(0x60b5);
  return;
}



// -[SRTParser srtForLanguage:videoID:error:], 0x1fe570
/* Decompiled from supplied 5.2.2 arm package. VA 0x1fe570. srtForLanguage:videoID:error: */

/* Function Stack Size: 0x28 bytes */

ID SRTParser::srtForLanguage_videoID_error_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID *param_5)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ID IVar4;
  char acStack_f0 [32];
  undefined **local_d0;
  undefined **local_c8;
  undefined **ppuStack_c0;
  undefined **local_b0;
  undefined **ppuStack_a8;
  undefined **local_98;
  undefined **local_90;
  uint uStack_84;
  undefined **local_80;
  undefined **ppuStack_78;
  uint local_6c;
  undefined **local_68;
  
  local_68 = &PTR_LAB_011c27e8;
  local_6c = (uint)(DAT_01228078 == 0);
  local_98 = &PTR_LAB_011c2828;
  local_80 = &PTR_LAB_011c2808;
  ppuStack_78 = &PTR_LAB_011c25d0;
  local_90 = &PTR_LAB_011c25d0;
  local_b0 = &PTR_LAB_011c2848;
  ppuStack_a8 = &PTR_LAB_011c25d0;
  local_c8 = &PTR_LAB_011c25d0;
  ppuStack_c0 = &PTR_LAB_011c25d0;
  local_d0 = &PTR_LAB_011c25d0;
  DAT_01228078 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _NSTemporaryDirectory();
  uVar2 = _objc_retainAutoreleasedReturnValue();
  acStack_f0[0] = '\0';
  _objc_msgSend(PTR__OBJC_CLASS___NSFileManager_0114eb48,@selector(defaultManager));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar1 = FUN_00200be0(uVar3,@selector(fileExistsAtPath:isDirectory:),uVar2,acStack_f0);
  _objc_release(uVar3);
  uStack_84 = 0;
  if (acStack_f0[0] != '\0') {
    uStack_84 = uVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x001fecf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar4 = (*(code *)(local_80[uStack_84] + (int)-(uRam00000000011c2818 ^ 0x9a8a4cf7)))();
  return IVar4;
}



// -[SRTParser parseTranscriptFromURL:completion:], 0x1fefb8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1fefb8. parseTranscriptFromURL:completion: */

/* Function Stack Size: 0x20 bytes */

void SRTParser::parseTranscriptFromURL_completion_
               (ID param_1,SEL param_2,ID param_3,ID param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *local_70;
  undefined8 local_68;
  code *local_60;
  undefined *puStack_58;
  ID local_50;
  ID local_48;
  
  _objc_retain(param_4);
  *(undefined1 *)(param_1 + 0x40) = 1;
  puVar2 = PTR__OBJC_CLASS___NSMutableArray_0114eb90;
  puVar1 = @selector(array);
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(param_1 + 8) = uVar3;
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___NSURLSession_0114eeb0,@selector(sharedSession));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(dataTaskWithURL:completionHandler:);
  local_70 = PTR___NSConcreteStackBlock_01060660;
  local_68 = DAT_00c4c228;
  local_60 = FUN_001ff110;
  puStack_58 = &DAT_01063060;
  local_50 = param_1;
  local_48 = param_4;
  _objc_retain(param_4);
  _objc_msgSend(uVar3,puVar1,param_3,&local_70);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_release(uVar3);
  _objc_msgSend(uVar4,@selector(resume));
  _objc_release(uVar4);
  _objc_release(local_48);
  _objc_release(param_4);
  CallSupervisor(0xdbf9);
  return;
}



// -[SRTParser parser:didStartElement:namespaceURI:qualifiedName:attributes:], 0x1ff5b4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ff5b4. parser:didStartElement:namespaceURI:qualifiedName:attributes: */

/* Function Stack Size: 0x38 bytes */

void SRTParser::parser_didStartElement_namespaceURI_qualifiedName_attributes_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,ID param_7)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_01228090 = 1;
  _objc_retain(param_7);
  iVar3 = FUN_00200fcc(param_4,@selector(isEqualToString:),
                       @"text");
  puVar1 = @selector(objectForKeyedSubscript:);
  if (iVar3 != 0) {
    _objc_msgSend(param_7,@selector(objectForKeyedSubscript:),
                  @"start");
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = @selector(doubleValue);
    uVar5 = _objc_msgSend(uVar4,@selector(doubleValue));
    *(undefined8 *)(param_1 + 0x28) = uVar5;
    _objc_release(uVar4);
    _objc_msgSend(param_7,puVar1,@"dur");
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uVar5 = _objc_msgSend(uVar4,puVar2);
    *(undefined8 *)(param_1 + 0x38) = uVar5;
    _objc_release(uVar4);
    *(double *)(param_1 + 0x30) = *(double *)(param_1 + 0x28) + *(double *)(param_1 + 0x38);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x10),@selector(setString:),&cf___);
  }
  _objc_release(param_7);
  CallSupervisor(0x7d54);
  return;
}



// -[SRTParser parser:foundCharacters:], 0x1ff874
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ff874. parser:foundCharacters: */

/* Function Stack Size: 0x20 bytes */

void SRTParser::parser_foundCharacters_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  _objc_msgSend(*(undefined8 *)(param_1 + 0x10),@selector(appendString:),param_4);
  CallSupervisor(0xbdf);
  return;
}



// -[SRTParser parser:didEndElement:namespaceURI:qualifiedName:], 0x1ff8b0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ff8b0. parser:didEndElement:namespaceURI:qualifiedName: */

/* Function Stack Size: 0x30 bytes */

void SRTParser::parser_didEndElement_namespaceURI_qualifiedName_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined **ppuVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_01228098 = 1;
  iVar2 = FUN_00201134(param_4,@selector(isEqualToString:),
                       @"text");
  if (iVar2 == 0) {
    return;
  }
  _objc_msgSend(param_1,@selector(decodeHTMLСhars:),*(undefined8 *)(param_1 + 0x10));
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,
                @selector(whitespaceAndNewlineCharacterSet));
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,@selector(stringByTrimmingCharactersInSet:),uVar4);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar4);
  ppuVar1 = &@selector(generateSRTWithText:);
  if (*(char *)(param_1 + 0x40) != '\0') {
    ppuVar1 = &@selector(generateTranscriptWithText:);
  }
  _objc_msgSend(param_1,*ppuVar1,uVar5);
  _objc_release(uVar5);
  _objc_release(uVar3);
  return;
}



// -[SRTParser generateSRTWithText:], 0x1ffa9c
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ffa9c. generateSRTWithText: */

/* Function Stack Size: 0x18 bytes */

void SRTParser::generateSRTWithText_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  puVar1 = @selector(formatTime:);
  DAT_0122809c = 1;
  uVar6 = *(undefined8 *)(param_1 + 0x28);
  _objc_retain(param_3);
  _objc_msgSend(uVar6,param_1,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x30),param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = @selector(stringWithFormat:);
  uVar5 = *(undefined8 *)(param_1 + 8);
  thunk_FUN_00201188(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                     @"%ld",*(undefined8 *)(param_1 + 0x20)
                    );
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = @selector(addObject:);
  _objc_msgSend(uVar5,@selector(addObject:),uVar4);
  _objc_release(uVar4);
  uVar5 = *(undefined8 *)(param_1 + 8);
  thunk_FUN_002011d4(PTR__OBJC_CLASS___NSString_0114eb38,puVar1,
                     @"%@ --> %@",uVar6,uVar3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,puVar2,uVar4);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + 8),puVar2,param_3);
  _objc_release(param_3);
  _objc_msgSend(*(undefined8 *)(param_1 + 8),puVar2,&cf___);
  *(long *)(param_1 + 0x20) = *(long *)(param_1 + 0x20) + 1;
  _objc_release(uVar3);
  _objc_release(uVar6);
  CallSupervisor(0x7ae6);
  return;
}



// -[SRTParser generateTranscriptWithText:], 0x1ffd74
/* Decompiled from supplied 5.2.2 arm package. VA 0x1ffd74. generateTranscriptWithText: */

/* Function Stack Size: 0x18 bytes */

void SRTParser::generateTranscriptWithText_(ID param_1,SEL param_2,ID param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  DAT_012280a0 = 1;
  _objc_msgSend(param_3,@selector(stringByReplacingOccurrencesOfString:withString:),
                @"\n",
                @" ");
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSCharacterSet_0114eb70,
                @selector(whitespaceAndNewlineCharacterSet));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,@selector(stringByTrimmingCharactersInSet:),uVar2);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar1);
  _objc_release(uVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + 8),@selector(addObject:),uVar3);
  _objc_release(uVar3);
  CallSupervisor(0xe35a);
  return;
}



// -[SRTParser formatTime:], 0x1fff08
/* Decompiled from supplied 5.2.2 arm package. VA 0x1fff08. formatTime: */

/* Function Stack Size: 0x18 bytes */

ID SRTParser::formatTime_(ID param_1,SEL param_2,double param_3)

{
  ID IVar1;
  long lVar2;
  double dVar3;
  
  DAT_012280a4 = 1;
  dVar3 = param_3 - (double)((long)(param_3 / DAT_00c4c380) * 0xe10);
  lVar2 = (long)(dVar3 / 60.0);
  IVar1 = FUN_002012e0(PTR__OBJC_CLASS___NSString_0114eb38,@selector(stringWithFormat:),
                       @"%02ld:%02ld:%02ld,%03ld",
                       (long)(param_3 / DAT_00c4c380),lVar2,(long)(dVar3 - (double)(lVar2 * 0x3c)),
                       (long)((param_3 - (double)(long)param_3) * DAT_00c4c4a0));
  return IVar1;
}



// -[SRTParser decodeHTMLСhars:], 0x200164
/* Decompiled from supplied 5.2.2 arm package. VA 0x200164. decodeHTML��hars: */

/* Function Stack Size: 0x18 bytes */

ID SRTParser::decodeHTML__hars_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  ID IVar10;
  undefined *puVar11;
  long lVar12;
  undefined8 uVar13;
  undefined1 auStack_210 [128];
  undefined8 uStack_190;
  long lStack_188;
  long *plStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined **ppuStack_150;
  undefined **ppuStack_148;
  undefined **ppuStack_140;
  undefined **ppuStack_138;
  undefined **ppuStack_130;
  undefined **ppuStack_128;
  undefined **ppuStack_120;
  undefined **ppuStack_118;
  undefined **ppuStack_110;
  undefined **ppuStack_108;
  undefined **ppuStack_100;
  undefined **ppuStack_f8;
  undefined *puStack_f0;
  undefined1 *puStack_e8;
  long lStack_e0;
  uint uStack_d4;
  undefined **local_d0;
  uint uStack_c4;
  undefined **local_c0;
  undefined **ppuStack_b8;
  uint uStack_ac;
  undefined **local_a8;
  undefined **local_a0;
  undefined **ppuStack_98;
  uint uStack_8c;
  undefined **local_88;
  undefined **local_80;
  uint local_74;
  undefined **local_70;
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  local_70 = &PTR_LAB_011c2a08;
  local_74 = (uint)(DAT_012280a8 == 0);
  local_88 = &PTR_LAB_011c2a28;
  local_80 = &PTR_LAB_011c25d0;
  local_a0 = &PTR_LAB_011c25d0;
  ppuStack_98 = &PTR_LAB_011c25d0;
  local_a8 = &PTR_LAB_011c2a50;
  local_c0 = &PTR_LAB_011c2a70;
  ppuStack_b8 = &PTR_LAB_011c25d0;
  local_d0 = &PTR_LAB_011c2a88;
  DAT_012280a8 = 1;
  _objc_msgSend(PTR__OBJC_CLASS___NSMutableString_0114eba8,@selector(stringWithString:));
  uVar5 = _objc_retainAutoreleasedReturnValue();
  ppuStack_150 = @"&lt;";
  ppuStack_148 = @"&gt;";
  ppuStack_120 = @"<";
  ppuStack_118 = @">";
  ppuStack_140 = @"&amp;";
  ppuStack_138 = @"&quot;";
  ppuStack_110 = @"&";
  ppuStack_108 = @"\"";
  ppuStack_130 = @"&#39;";
  ppuStack_128 = @"&nbsp;";
  ppuStack_100 = @"'";
  ppuStack_f8 = @" ";
  _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                @selector(dictionaryWithObjects:forKeys:count:),&ppuStack_120,&ppuStack_150,6);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  lStack_188 = 0;
  uStack_190 = 0;
  uStack_178 = 0;
  plStack_180 = (long *)0x0;
  uStack_168 = 0;
  uStack_170 = 0;
  uStack_158 = 0;
  uStack_160 = 0;
  uVar7 = _objc_retain();
  puStack_f0 = @selector(countByEnumeratingWithState:objects:count:);
  puStack_e8 = auStack_210;
  lVar8 = _objc_msgSend(uVar7,@selector(countByEnumeratingWithState:objects:count:),&uStack_190,
                        auStack_210,0x10);
  uStack_8c = (uint)(lVar8 == 0);
  puVar11 = local_88[uStack_8c] + (int)-(uRam00000000011c2a38 ^ 0x7c41b8a0);
  if (lVar8 == 0) {
LAB_00200898:
    _objc_release(puVar11,uVar6);
    _objc_release(uVar6);
    if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
      ___stack_chk_fail();
    }
    IVar10 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar5);
    return IVar10;
  }
  lStack_e0 = *plStack_180;
LAB_00200710:
  puVar3 = @selector(replaceOccurrencesOfString:withString:options:range:);
  puVar2 = @selector(length);
  puVar1 = @selector(objectForKeyedSubscript:);
  lVar12 = 0;
  uStack_ac = (uint)(*plStack_180 == lStack_e0);
  puVar11 = local_a8[uStack_ac] + (int)-(uRam00000000011c2a60 ^ 0x6b237451);
  if (*plStack_180 == lStack_e0) goto LAB_002007bc;
  do {
    _objc_enumerationMutation(puVar11,uVar6);
LAB_002007bc:
    do {
      uVar13 = *(undefined8 *)(lStack_188 + lVar12 * 8);
      _objc_msgSend(uVar6,puVar1,uVar13);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      uVar9 = _objc_msgSend(uVar5,puVar2);
      _objc_msgSend(uVar5,puVar3,uVar13,uVar7,0,0,uVar9);
      _objc_release(uVar7);
      bVar4 = lVar8 + -1 == lVar12;
      uStack_c4 = (uint)bVar4;
      if (bVar4) {
        lVar8 = _objc_msgSend(local_c0[uStack_c4] + (int)-(uRam00000000011c2a80 ^ 0x1a9a2be7),uVar6,
                              puStack_f0,&uStack_190,puStack_e8,0x10);
        uStack_d4 = (uint)(lVar8 == 0);
        puVar11 = local_d0[uStack_d4] + (int)-(uRam00000000011c2a98 ^ 0xbcc3d46b);
        if (lVar8 != 0) goto LAB_00200710;
        uStack_d4 = 1;
        goto LAB_00200898;
      }
      lVar12 = lVar12 + 1;
      uStack_ac = (uint)(*plStack_180 == lStack_e0);
      puVar11 = local_a8[uStack_ac] + (int)-(uRam00000000011c2a60 ^ 0x6b237451);
    } while (*plStack_180 == lStack_e0);
  } while( true );
}



// -[SRTParser .cxx_destruct], 0x2008e8
/* Decompiled from supplied 5.2.2 arm package. VA 0x2008e8. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void SRTParser::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_storeStrong(param_1 + 8,0);
  return;
}


