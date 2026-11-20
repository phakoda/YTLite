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
  iVar3 = FUN_00200fcc(param_4,PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_011c2050);
  puVar1 = PTR_s_objectForKeyedSubscript__0114ae80;
  if (iVar3 != 0) {
    _objc_msgSend(param_7,PTR_s_objectForKeyedSubscript__0114ae80,
                  &PTR____CFConstantStringClassReference_011c2010);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    puVar2 = PTR_s_doubleValue_0114b3f0;
    uVar5 = _objc_msgSend(uVar4,PTR_s_doubleValue_0114b3f0);
    *(undefined8 *)(param_1 + 0x28) = uVar5;
    _objc_release(uVar4);
    _objc_msgSend(param_7,puVar1,&PTR____CFConstantStringClassReference_011c1fd0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    uVar5 = _objc_msgSend(uVar4,puVar2);
    *(undefined8 *)(param_1 + 0x38) = uVar5;
    _objc_release(uVar4);
    *(double *)(param_1 + 0x30) = *(double *)(param_1 + 0x28) + *(double *)(param_1 + 0x38);
    _objc_msgSend(*(undefined8 *)(param_1 + 0x10),PTR_s_setString__0114b8a8,&cf___);
  }
  _objc_release(param_7);
  CallSupervisor(0x7d54);
  return;
}


