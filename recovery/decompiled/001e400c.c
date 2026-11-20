/* Decompiled from supplied 5.2.2 arm package. VA 0x1e400c. translateText */

/* Function Stack Size: 0x10 bytes */

void TranslatorVC::translateText(ID param_1,SEL param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined *puStack_90;
  undefined8 uStack_88;
  code *pcStack_80;
  undefined *puStack_78;
  ID IStack_70;
  undefined **local_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011ba938;
  local_4c = (uint)(DAT_01227e64 == 0);
  local_58 = &PTR_LAB_011ba600;
  DAT_01227e64 = 1;
  _objc_msgSend(&PTR____CFConstantStringClassReference_011ba580,PTR_s_ytl_localized_0114d190);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  lVar4 = (long)_textView;
  _objc_msgSend(*(undefined8 *)(param_1 + lVar4),PTR_s_setText__0114b388,uVar2);
  _objc_release(uVar2);
  _objc_msgSend(param_1,PTR_s_tableView_0114d120);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_tintColor_0114d1b8);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(*(undefined8 *)(param_1 + lVar4),PTR_s_setTextColor__0114b5d8,uVar3);
  _objc_release(uVar3);
  _objc_release(uVar2);
  puVar1 = PTR_YTPTranslator_0114efc0;
  uVar3 = *(undefined8 *)(param_1 + (long)_sourceText);
  _objc_msgSend(PTR_YTPDB_0114ecc0,PTR_s_langCodeForIndex__0114cbd0,
                *(undefined8 *)(param_1 + (long)_langIndex));
  uVar2 = _objc_retainAutoreleasedReturnValue();
  puStack_90 = PTR___NSConcreteStackBlock_01060660;
  uStack_88 = DAT_00c4c228;
  pcStack_80 = FUN_001e431c;
  puStack_78 = &DAT_010623d0;
  IStack_70 = param_1;
  _objc_msgSend(puVar1,PTR_s_translateText_fromLanguage_toLan_0114e118,uVar3,
                &PTR____CFConstantStringClassReference_011ba540,uVar2,&puStack_90);
  _objc_release(uVar2);
  CallSupervisor(0x6543);
  return;
}


