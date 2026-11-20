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
  
  puVar1 = PTR_s_formatTime__0114e338;
  DAT_0122809c = 1;
  uVar6 = *(undefined8 *)(param_1 + 0x28);
  _objc_retain(param_3);
  _objc_msgSend(uVar6,param_1,puVar1);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x30),param_1,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_stringWithFormat__0114b378;
  uVar5 = *(undefined8 *)(param_1 + 8);
  thunk_FUN_00201188(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011c2140,*(undefined8 *)(param_1 + 0x20)
                    );
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_addObject__0114b3a0;
  _objc_msgSend(uVar5,PTR_s_addObject__0114b3a0,uVar4);
  _objc_release(uVar4);
  uVar5 = *(undefined8 *)(param_1 + 8);
  thunk_FUN_002011d4(PTR__OBJC_CLASS___NSString_0114eb38,puVar1,
                     &PTR____CFConstantStringClassReference_011c2100,uVar6,uVar3);
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


