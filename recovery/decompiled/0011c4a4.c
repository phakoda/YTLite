/* Decompiled from supplied 5.2.2 arm package. VA 0x11c4a4. tableView:willDisplayFooterView:forSection: */

/* Function Stack Size: 0x28 bytes */

void DVNTableViewController::tableView_willDisplayFooterView_forSection_
               (ID param_1,SEL param_2,ID param_3,ID param_4,long_long param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  _objc_retain(param_4);
  puVar2 = PTR__OBJC_CLASS___UIFont_0114ec08;
  puVar1 = PTR_s_systemFontOfSize_weight__0114d330;
  uVar4 = *(undefined8 *)PTR__UIFontWeightLight_01060568;
  _objc_retain(param_3);
  _objc_msgSend(0x402a000000000000,uVar4,puVar2,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_textLabel_0114b8e0;
  _objc_msgSend(param_4,PTR_s_textLabel_0114b8e0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setFont__0114b5e8,uVar4);
  _objc_release(uVar3);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___UIColor_0114eb18,PTR_s_secondaryLabelColor_0114d0e8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_4,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setTextColor__0114b5d8,uVar4);
  _objc_release(uVar3);
  _objc_release(uVar4);
  _objc_msgSend(param_1,PTR_s_tableView_titleForFooterInSectio_0114d360,param_3,param_5);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_release(param_3);
  _objc_msgSend(param_4,puVar1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setText__0114b388,uVar4);
  _objc_release(uVar3);
  _objc_release(uVar4);
  _objc_msgSend(param_4,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setTextAlignment__0114b5f8,4);
  _objc_release(uVar4);
  _objc_msgSend(param_4,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_setNumberOfLines__0114b5f0,0);
  _objc_release(uVar4);
  _objc_release(param_4);
  return;
}


