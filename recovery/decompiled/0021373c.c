/* Decompiled from supplied 5.2.2 arm package. VA 0x21373c. FUN_0021373c */

undefined1  [16] FUN_0021373c(long param_1)

{
  undefined8 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  long lVar4;
  double dVar5;
  undefined1 auVar6 [16];
  undefined *puStack_d8;
  undefined8 uStack_d0;
  code *pcStack_c8;
  undefined *puStack_c0;
  long lStack_b8;
  double dStack_b0;
  undefined *puStack_a8;
  undefined8 uStack_a0;
  code *pcStack_98;
  undefined *puStack_90;
  long lStack_88;
  double dStack_80;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011cc5a0;
  lVar4 = _objc_loadWeakRetained(param_1 + 0x20);
  local_4c = (uint)(lVar4 == 0);
  if (lVar4 != 0) {
    if (*(long *)(lVar4 + 0x20) == 2) {
      _objc_msgSend(lVar4,PTR_s_getPlayerIfAvailable_0114c838);
      lVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_release();
                    /* WARNING: Could not recover jumptable at 0x00213854. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      auVar6 = (*(code *)((&PTR_LAB_011cc5d0)[lVar4 == 0] +
                         (int)-(uRam00000000011cc5e0 ^ 0xefd0cde6)))();
      return auVar6;
    }
    dVar5 = (double)_objc_msgSend(lVar4,PTR_s_remainingSeconds_0114e3f8);
    puVar2 = PTR___NSConcreteStackBlock_01060660;
    uVar1 = DAT_00c4c228;
    puStack_a8 = PTR___NSConcreteStackBlock_01060660;
    uStack_a0 = DAT_00c4c228;
    pcStack_98 = FUN_002139d4;
    puStack_90 = &DAT_01061810;
    lStack_88 = lVar4;
    dStack_80 = dVar5;
    _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_a8);
    puVar3 = PTR___dispatch_main_q_01060760;
    if (dVar5 <= 10.0) {
      puStack_d8 = puVar2;
      uStack_d0 = uVar1;
      pcStack_c8 = FUN_00213ab0;
      puStack_c0 = &DAT_01061810;
      lStack_b8 = lVar4;
      dStack_b0 = dVar5;
      _dispatch_async(PTR___dispatch_main_q_01060760,&puStack_d8);
      _objc_release(puVar3);
    }
  }
  _objc_release(lVar4);
  CallSupervisor(0x4873);
  return ZEXT816(0x1f);
}


