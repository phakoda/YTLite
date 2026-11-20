/* Decompiled from supplied 5.2.2 arm package. VA 0x1d3924. URLSession:dataTask:didReceiveData: */

/* Function Stack Size: 0x28 bytes */

void YTPDownloader::URLSession_dataTask_didReceiveData_
               (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auStack_140 [48];
  undefined1 *puStack_110;
  ID IStack_108;
  ID IStack_100;
  ID IStack_f8;
  undefined *puStack_f0;
  undefined **local_e8;
  undefined **local_d8;
  undefined **local_d0;
  undefined **ppuStack_c8;
  undefined **local_b8;
  undefined **ppuStack_b0;
  uint uStack_a4;
  undefined **local_a0;
  undefined **local_98;
  uint local_8c;
  undefined **local_88;
  undefined8 local_80;
  
  local_80 = *(undefined8 *)PTR____stack_chk_guard_01060708;
  local_88 = &PTR_LAB_011b7930;
  local_8c = (uint)(DAT_01227d80 == 0);
  local_a0 = &PTR_LAB_011b7950;
  local_98 = &PTR__objc_msgSend_011b7210;
  local_b8 = &PTR_LAB_011b7970;
  ppuStack_b0 = &PTR__objc_msgSend_011b7210;
  local_d0 = &PTR__objc_msgSend_011b7210;
  ppuStack_c8 = &PTR__objc_msgSend_011b7210;
  local_d8 = &PTR_LAB_011b7998;
  local_e8 = &PTR__objc_msgSend_011b7210;
  DAT_01227d80 = 1;
  puStack_110 = auStack_140;
  _objc_retain(param_3);
  _objc_retain(param_4);
  _objc_retain(param_5);
  uVar3 = *(undefined8 *)(param_1 + 0x38);
  uVar2 = *(undefined8 *)(param_1 + 0x18);
  _objc_retain(uVar2);
  _objc_sync_enter();
  _objc_msgSend(*(undefined8 *)(param_1 + 0x18),PTR_s_seekToFileOffset__0114df70,uVar3);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x18),PTR_s_writeData__0114df78,param_5);
  IStack_100 = param_4;
  IStack_f8 = param_3;
  _objc_sync_exit(uVar2);
  _objc_release(uVar2);
  lVar1 = _objc_msgSend(param_5,PTR_s_length_0114b438);
  uVar2 = *(undefined8 *)(param_1 + 0x40);
  *(long *)(param_1 + 0x38) = *(long *)(param_1 + 0x38) + lVar1;
  puStack_f0 = PTR_s_numberWithLongLong__0114e030;
  _objc_msgSend(PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithLongLong__0114e030,uVar3);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_objectForKeyedSubscript__0114ae80,uVar3);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  _objc_release(uVar3);
  uStack_a4 = (uint)(lVar1 == 0);
  IStack_108 = param_5;
                    /* WARNING: Could not recover jumptable at 0x001d3e90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_a0[uStack_a4] + (int)-(uRam00000000011b7960 ^ 0x79965837)))();
  return;
}


