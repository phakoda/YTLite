/* Decompiled from supplied 5.2.2 arm package. VA 0x1d2a48. continueDownloadingForURL: */

/* Function Stack Size: 0x18 bytes */

void YTPDownloader::continueDownloadingForURL_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  
  DAT_01227d7c = 1;
  _objc_retain(param_3);
  lVar7 = *(long *)(param_1 + 0x38);
  if (lVar7 < *(long *)(param_1 + 0x30)) {
    uVar13 = *(undefined8 *)(param_1 + 0x40);
    _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithLongLong__0114e030,lVar7);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_objectForKeyedSubscript__0114ae80;
    _objc_msgSend(uVar13,PTR_s_objectForKeyedSubscript__0114ae80,uVar4);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar4);
    if (lVar5 == 0) {
      uVar8 = (lVar7 + *(long *)(param_1 + 0x48)) - 1;
      uVar12 = *(long *)(param_1 + 0x30) - 1;
      if (uVar12 <= uVar8) {
        uVar8 = uVar12;
      }
      thunk_FUN_001d5d04(&PTR____CFConstantStringClassReference_011b6cd0,lVar7,uVar8);
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80,PTR_s_requestWithURL__0114da38,
                    param_3);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_001d5d50(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                         &PTR____CFConstantStringClassReference_011b6d90,lVar7,uVar8);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_setValue_forHTTPHeaderField__0114def0,uVar13,
                    &PTR____CFConstantStringClassReference_011b6d10);
      _objc_release(uVar13);
      _objc_msgSend(*(undefined8 *)(param_1 + 8),PTR_s_dataTaskWithRequest__0114e038,uVar4);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      uVar9 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(param_1 + 0x10) = uVar13;
      _objc_release(uVar9);
      _objc_msgSend(*(undefined8 *)(param_1 + 0x10),PTR_s_resume_0114d928);
    }
    else {
      _objc_msgSend((&PTR_LAB_011b7900)[lVar5 == 0] + (int)-(uRam00000000011b7910 ^ 0x3ffacb7a),
                    lVar5,puVar1,&PTR____CFConstantStringClassReference_011b6e10);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      puVar2 = PTR_s_unsignedLongLongValue_0114e008;
      lVar6 = _objc_msgSend(uVar4,PTR_s_unsignedLongLongValue_0114e008);
      lVar6 = lVar6 + lVar7;
      _objc_msgSend(lVar5,puVar1,&PTR____CFConstantStringClassReference_011b6d50);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      lVar7 = _objc_msgSend(uVar13,puVar2);
      uVar8 = _objc_msgSend(uVar4,puVar2);
      _objc_release(uVar13);
      lVar7 = ~uVar8 + lVar6 + lVar7;
      lVar11 = *(long *)(param_1 + 0x30) + -1;
      if (lVar11 <= lVar7) {
        lVar7 = lVar11;
      }
      thunk_FUN_001d5e7c(&PTR____CFConstantStringClassReference_011b6dd0,lVar6,lVar7);
      _objc_msgSend(PTR__OBJC_CLASS___NSMutableURLRequest_0114ef80,PTR_s_requestWithURL__0114da38,
                    param_3);
      uVar13 = _objc_retainAutoreleasedReturnValue();
      thunk_FUN_001d5ec8(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                         &PTR____CFConstantStringClassReference_011b6d90,lVar6,lVar7);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar13,PTR_s_setValue_forHTTPHeaderField__0114def0,uVar9,
                    &PTR____CFConstantStringClassReference_011b6d10);
      _objc_release(uVar9);
      _objc_msgSend(*(undefined8 *)(param_1 + 8),PTR_s_dataTaskWithRequest__0114e038,uVar13);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      uVar10 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(param_1 + 0x10) = uVar9;
      _objc_release(uVar10);
      _objc_msgSend(*(undefined8 *)(param_1 + 0x10),PTR_s_resume_0114d928);
      _objc_release(uVar13);
    }
  }
  else {
    _NSLog((&PTR_LAB_011b78c8)[lVar7 < *(long *)(param_1 + 0x30)] +
           (int)-(DAT_011b78d8 ^ 0xadb623b4),&PTR____CFConstantStringClassReference_011b6e50);
    _objc_msgSend(param_1,PTR_s_cleanup_0114de90);
    puVar1 = PTR_s_delegate_0114b530;
    _objc_msgSend(param_1,PTR_s_delegate_0114b530);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_downloadDidFinish_fileName__0114df80;
    uVar3 = FUN_001d5fc8(uVar4,PTR_s_respondsToSelector__0114af58,
                         PTR_s_downloadDidFinish_fileName__0114df80);
    _objc_release(uVar4);
    if (uVar3 == 0) goto LAB_001d3904;
    _objc_msgSend((&PTR_LAB_011b78e0)[uVar3] + (int)-(uRam00000000011b78f0 ^ 0xede920aa),param_1,
                  puVar1);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSURL_0114eb78,PTR_s_fileURLWithPath__0114c430,
                  *(undefined8 *)(param_1 + 0x50));
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(lVar5,puVar2,uVar4,*(undefined8 *)(param_1 + 0x20));
  }
  _objc_release(uVar4);
  _objc_release(lVar5);
LAB_001d3904:
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


