// Decompiled hook evidence for YTPivotBarView. This is not compilable Logos source.

// -[YTPivotBarView itemView1], original IMP slot 0x01225fd0
/* Decompiled from supplied 5.2.2 arm package. VA 0x51fe8. FUN_00051fe8 */

void FUN_00051fe8(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  (*DAT_01225fd0)();
  uVar1 = _objc_retainAutoreleasedReturnValue();
  uVar2 = _objc_alloc(PTR__OBJC_CLASS___UIContextMenuInteraction_0114ecd8);
  uVar2 = _objc_msgSend(uVar2,@selector(initWithDelegate:),param_1);
  _objc_msgSend(uVar1,@selector(setUserInteractionEnabled:),1);
  _objc_msgSend(uVar1,@selector(addInteraction:),uVar2);
  _objc_release(uVar2);
  _objc_autoreleaseReturnValue(uVar1);
  return;
}



// -[YTPivotBarView contextMenuInteraction:configurationForMenuAtLocation:], original IMP slot None
/* Decompiled from supplied 5.2.2 arm package. VA 0x52070. FUN_00052070 */

void FUN_00052070(undefined8 param_1)

{
  undefined *local_38;
  undefined8 local_30;
  code *local_28;
  undefined *puStack_20;
  undefined8 local_18;
  
  local_38 = PTR___NSConcreteStackBlock_01060660;
  local_30 = DAT_00c4c230;
  local_28 = FUN_000bcd7c;
  puStack_20 = &DAT_01061ae0;
  local_18 = param_1;
  _objc_msgSend(PTR__OBJC_CLASS___UIContextMenuConfiguration_0114ece0,
                @selector(configurationWithIdentifier:previewProvider:actionProvider:),0,0,&local_38);
  _objc_retainAutoreleasedReturnValue();
  _objc_autoreleaseReturnValue();
  return;
}


