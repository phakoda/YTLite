/* Decompiled from supplied 5.2.2 arm package. VA 0xfc90. FUN_0000fc90 */

undefined1  [16] FUN_0000fc90(undefined8 param_1,undefined8 param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined1 auVar7 [16];
  
  DAT_01225944 = 1;
  uVar3 = _objc_msgSend(param_1,PTR_s_class_0114ae88);
  lVar4 = _class_getInstanceVariable(uVar3,s__controller_01152523);
  puVar1 = PTR_s_valueForKey__0114ae90;
  if (lVar4 == 0) {
    (*pcRam0000000001225908)(param_1,param_2);
    CallSupervisor(0xbc9c);
    auVar7._8_8_ = 0x1f;
    auVar7._0_8_ = 0x1a;
    return auVar7;
  }
  _objc_msgSend(param_1,PTR_s_valueForKey__0114ae90,&PTR____CFConstantStringClassReference_011525d0)
  ;
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_node_0114ae98);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar3);
  _objc_msgSend(uVar5,puVar1,&PTR____CFConstantStringClassReference_01152650);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar2 = FUN_00011820(uVar3,PTR_s_hasPrefix__0114aea0,
                       &PTR____CFConstantStringClassReference_01152610);
  if (uVar2 != 0) {
    _objc_msgSend(uVar5,PTR_s_subnodes_0114aea8);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar3,PTR_s_objectAtIndexedSubscript__0114aeb0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    if (lRam0000000001225910 == 0) {
      lRam0000000001225910 =
           _objc_getClass((&PTR_LAB_01152be0)[lRam0000000001225910 == 0] +
                          (int)-(uRam0000000001152bf0 ^ 0x81ae77c7),s_ASNetworkImageNode_01152480);
    }
    lVar4 = lRam0000000001225910;
    _objc_retainAutorelease(lRam0000000001225910);
    uVar6 = FUN_000118e8(uVar5,PTR_s_isKindOfClass__0114ad70,lVar4);
    _objc_release(uVar5);
    _objc_release(uVar3);
                    /* WARNING: Could not recover jumptable at 0x00010d58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar7 = (*(code *)((&PTR_LAB_01152c00)[uVar6 & 0xffffffff] +
                       (int)-(uRam0000000001152c10 ^ 0xdc413d94)))();
    return auVar7;
  }
  uVar6 = FUN_000119e0((&PTR_LAB_01152bc8)[uVar2] + (int)-(DAT_01152bd8 ^ 0x2209a5cb),uVar3,
                       PTR_s_isEqualToString__0114ae48,
                       &PTR____CFConstantStringClassReference_01152590);
                    /* WARNING: Could not recover jumptable at 0x00010e5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  auVar7 = (*(code *)((&PTR_LAB_01152c60)[uVar6 & 0xffffffff] + (int)-(DAT_01152c70 ^ 0x5b196a37)))
                     ();
  return auVar7;
}


