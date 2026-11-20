/* Decompiled from supplied 5.2.2 arm package. VA 0x21b744. FUN_0021b744 */

undefined1  [16] FUN_0021b744(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  undefined *puVar1;
  long lVar2;
  undefined1 auVar3 [16];
  undefined *puStack_88;
  undefined8 uStack_80;
  code *pcStack_78;
  undefined *puStack_70;
  undefined8 uStack_68;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011cdb90;
  _objc_retain(param_2);
  _objc_retain(param_3);
  _objc_retain(param_4);
  puVar1 = PTR_s_code_0114e598;
  local_5c = (uint)(param_4 == 0);
  uStack_60 = 1;
  uStack_5f = true;
  if (param_4 != 0) {
    lVar2 = _objc_msgSend(param_4,PTR_s_code_0114e598);
    uStack_60 = 0;
    uStack_5f = false;
    if (lVar2 != -0x3f1) {
      lVar2 = _objc_msgSend((&PTR_LAB_011cdba8)[lVar2 == -0x3f1] +
                            (int)-(uRam00000000011cdbb8 ^ 0xe1997df),param_4,puVar1);
      uStack_5f = lVar2 != -0x3ec;
      uStack_60 = 1;
    }
  }
  puStack_88 = PTR___NSConcreteStackBlock_01060660;
  uStack_80 = DAT_00c4c228;
  pcStack_78 = FUN_0021b8f4;
  puStack_70 = &DAT_010630e0;
  uStack_68 = _objc_retain(*(undefined8 *)(param_1 + 0x20));
  _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_88);
  _objc_release(uStack_68);
  _objc_release(param_4);
  _objc_release(param_3);
  _objc_release(param_2);
  CallSupervisor(0xc6d8);
  auVar3._8_8_ = 0x1f;
  auVar3._0_8_ = 0x1a;
  return auVar3;
}


