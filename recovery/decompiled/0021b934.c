/* Decompiled from supplied 5.2.2 arm package. VA 0x21b934. setServerURL: */

/* Function Stack Size: 0x18 bytes */

void YTPDiscordRPC::setServerURL_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ID IVar5;
  ID IVar6;
  long lVar7;
  
  DAT_0122825c = 1;
  _objc_retain(param_3);
  uVar4 = _objc_retain();
  puVar1 = PTR_s_hasPrefix__0114aea0;
  uVar2 = FUN_0021ee4c(uVar4,PTR_s_hasPrefix__0114aea0,
                       &PTR____CFConstantStringClassReference_011ccfc0);
  if (uVar2 == 0) {
    iVar3 = FUN_0021eeb4((&PTR_LAB_011cdbe8)[uVar2] + (int)-(DAT_011cdbf8 ^ 0xdeb14243),param_3,
                         puVar1,&PTR____CFConstantStringClassReference_011ccf80);
    if (iVar3 != 0) goto LAB_0021bcf8;
    _objc_msgSend(&PTR____CFConstantStringClassReference_011ccf80,
                  PTR_s_stringByAppendingString__0114b380,param_3);
    IVar5 = _objc_retainAutoreleasedReturnValue();
    IVar6 = param_3;
  }
  else {
    _objc_msgSend(param_3,PTR_s_substringFromIndex__0114c5f0,8);
    IVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(&PTR____CFConstantStringClassReference_011ccf80,
                  PTR_s_stringByAppendingString__0114b380,IVar6);
    IVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release(param_3);
  }
  param_3 = IVar5;
  _objc_release(IVar6);
LAB_0021bcf8:
  _objc_msgSend(PTR__OBJC_CLASS___NSURLComponents_0114edc8,PTR_s_componentsWithString__0114cb20,
                param_3);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_port_0114e5a0);
  lVar7 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0021bd64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR__objc_msgSend_011cdc30)[lVar7 == 0] + (int)-(DAT_011cdc40 ^ 0x8fd12330)))();
  return;
}


