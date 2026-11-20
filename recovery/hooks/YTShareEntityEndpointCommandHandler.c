// Decompiled hook evidence for YTShareEntityEndpointCommandHandler. This is not compilable Logos source.

// -[YTShareEntityEndpointCommandHandler executeWithCommand:entry:fromView:sender:], original IMP slot 0x1227060
/* Decompiled from supplied 5.2.2 arm package. VA 0xf1890. FUN_000f1890 */

void FUN_000f1890(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  DAT_01227088 = 1;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  _objc_retain(param_6);
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___NSUserDefaults_0114ede0);
  uVar2 = _objc_msgSend(uVar2,@selector(initWithSuiteName:),
                        @"com.dvntm.ytlite");
  iVar1 = FUN_000f4bd4(uVar2,@selector(boolForKey:),
                       @"nativeShare");
  _objc_release(uVar2);
  if (iVar1 == 0) {
    (*pcRam0000000001227060)(param_1,param_2,param_3,param_4,param_5,param_6);
    _objc_release(param_6);
    _objc_release(param_5);
    _objc_release(param_4);
    (*(code *)PTR__objc_release_01061028)(param_3);
    return;
  }
  _objc_msgSend(param_3,@selector(description));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSRegularExpression_0114ecb8,
                @selector(regularExpressionWithPattern:options:error:),
                @"serialized_share_entity: \"([^\"]+)\"",0,0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_msgSend(uVar2,@selector(length));
  _objc_msgSend(uVar3,@selector(firstMatchInString:options:range:),uVar2,0,0,uVar4);
  lVar5 = _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x000f1ea4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_01184a50)[lVar5 == 0] + (int)-(uRam0000000001184a60 ^ 0xbd04770c)))();
  return;
}


