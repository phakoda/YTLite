/* Decompiled from supplied 5.2.2 arm package. VA 0x1be4a4. FUN_001be4a4 */

undefined1  [16] FUN_001be4a4(long param_1)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined *puStack_a0;
  undefined8 uStack_98;
  code *pcStack_90;
  undefined *puStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined **local_70;
  uint uStack_64;
  undefined **local_60;
  undefined **ppuStack_58;
  uint local_4c;
  undefined **local_48;
  
  local_48 = &PTR_LAB_011b4218;
  local_4c = (uint)(DAT_01227b00 == 0);
  local_60 = &PTR_LAB_011b4238;
  ppuStack_58 = &PTR_LAB_011b39f0;
  local_70 = &PTR_LAB_011b39f0;
  DAT_01227b00 = 1;
  bVar2 = *(long *)(param_1 + 0x20) == 0;
  uStack_64 = (uint)bVar2;
  if (!bVar2) {
    _objc_msgSend(*(undefined8 *)(*(long *)(param_1 + 0x28) + (long)ToastView::_sourceView),
                  PTR_s_bringSubviewToFront__0114b7e8);
  }
  _objc_msgSend(PTR__OBJC_CLASS___CABasicAnimation_0114ee20,PTR_s_animationWithKeyPath__0114d2f0,
                &PTR____CFConstantStringClassReference_011b3780);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  puVar1 = PTR_s_numberWithDouble__0114c310;
  _objc_msgSend(*(double *)(param_1 + 0x40) - *(double *)(param_1 + 0x48),
                PTR__OBJC_CLASS___NSNumber_0114eb00,PTR_s_numberWithDouble__0114c310);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setFromValue__0114d2f8,uVar4);
  _objc_release(uVar4);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x40),PTR__OBJC_CLASS___NSNumber_0114eb00,puVar1);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setToValue__0114d300,uVar4);
  _objc_release(uVar4);
  _objc_msgSend(0x3fd0000000000000,uVar3,PTR_s_setDuration__0114d318);
  _objc_msgSend(PTR__OBJC_CLASS___CAMediaTimingFunction_0114ef68,PTR_s_functionWithName__0114dd78,
                *(undefined8 *)PTR__kCAMediaTimingFunctionEaseInEaseOut_01060bc8);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar3,PTR_s_setTimingFunction__0114dd80,uVar4);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,PTR_s_begin_0114c468);
  puVar1 = PTR__OBJC_CLASS___CATransaction_0114ed20;
  puStack_a0 = PTR___NSConcreteStackBlock_01060660;
  uStack_98 = DAT_00c4c228;
  pcStack_90 = FUN_001be884;
  puStack_88 = &DAT_01061f70;
  uStack_80 = *(undefined8 *)(param_1 + 0x28);
  uStack_78 = _objc_retain(*(undefined8 *)(param_1 + 0x30));
  _objc_msgSend(puVar1,PTR_s_setCompletionBlock__0114c498,&puStack_a0);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_layer_0114ae60);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar4,PTR_s_addAnimation_forKey__0114d320,uVar3,
                &PTR____CFConstantStringClassReference_011b3740);
  _objc_release(uVar4);
  _objc_msgSend(PTR__OBJC_CLASS___CATransaction_0114ed20,PTR_s_commit_0114c478);
  _objc_release(uStack_78);
  _objc_release(uVar3);
  CallSupervisor(0x9814);
  return ZEXT816(0x1f);
}


