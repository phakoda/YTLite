/* Decompiled from supplied 5.2.2 arm package. VA 0x14e60. FUN_00014e60 */

undefined1  [16] FUN_00014e60(long param_1)

{
  undefined8 uVar1;
  undefined *puStack_80;
  undefined8 uStack_78;
  code *pcStack_70;
  undefined *puStack_68;
  undefined8 uStack_60;
  undefined **local_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_01155020;
  local_3c = (uint)(DAT_01225b38 == 0);
  local_48 = &PTR_LAB_01154cd0;
  DAT_01225b38 = 1;
  uVar1 = _objc_getClass(s_NSBundle_01153649);
  _MSHookMessageEx(uVar1,PTR_s_infoDictionary_0114ae78,_replaceInfoDict,&_orig_infoDictionary);
  uStack_60 = *(undefined8 *)(param_1 + 0x20);
  puStack_80 = PTR___NSConcreteStackBlock_01060660;
  uStack_78 = DAT_00c4c228;
  pcStack_70 = FUN_00015014;
  puStack_68 = &DAT_01061420;
  _objc_msgSend(uStack_60,PTR_s_dismissViewControllerAnimated_co_0114aed0,1,&puStack_80);
  CallSupervisor(0xf7c4);
  return ZEXT816(0x1f);
}


