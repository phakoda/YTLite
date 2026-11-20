/* Decompiled from supplied 5.2.2 arm package. VA 0x7ffbc. FUN_0007ffbc */

undefined1  [16] FUN_0007ffbc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  float fVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  undefined1 auVar16 [16];
  
  DAT_01226c34 = 1;
  _objc_retain(param_3);
  iVar5 = FUN_000dd3c4(&PTR____CFConstantStringClassReference_011668a0);
  puVar1 = PTR_s_parentViewController_0114ad68;
  if (iVar5 != 0) {
    _objc_msgSend(param_1,PTR_s_parentViewController_0114ad68);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    if (DAT_01226898 == 0) {
      DAT_01226898 = _objc_getClass((&PTR_LAB_0117ce18)[DAT_01226898 == 0] +
                                    (int)-(uRam000000000117ce28 ^ 0xcf551c09),
                                    s_YTPlayerViewController_011667a0);
    }
    lVar9 = DAT_01226898;
    _objc_retainAutorelease(DAT_01226898);
    uVar6 = FUN_000dd5cc(uVar7,PTR_s_isKindOfClass__0114ad70,lVar9);
    _objc_release(uVar7);
    if (uVar6 != 0) {
      _objc_msgSend((&PTR_LAB_0117ce38)[uVar6] + (int)-(uRam000000000117ce48 ^ 0x8510a3),param_1,
                    puVar1);
      uVar7 = _objc_retainAutoreleasedReturnValue();
      puVar1 = PTR_s_seekToTime__0114ad18;
      iVar5 = FUN_000dd694(uVar7,PTR_s_respondsToSelector__0114af58,PTR_s_seekToTime__0114ad18);
      if (iVar5 != 0) {
        dVar12 = (double)_objc_msgSend(param_1,PTR_s_totalTime_0114c888);
        puVar2 = PTR_s_view_0114b090;
        _objc_msgSend(param_1,PTR_s_view_0114b090);
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,PTR_s_bounds_0114b568);
        dVar13 = (double)_CGRectGetWidth();
        _objc_release(uVar8);
        puVar3 = PTR_s_state_0114c560;
        lVar9 = _objc_msgSend(param_3,PTR_s_state_0114c560);
        puVar4 = PTR__OBJC_CLASS___NSNumber_0114eb00;
        if (lVar9 == 1) {
          _objc_msgSend(param_1,PTR_s_mediaTime_0114c890);
          _objc_msgSend(puVar4,PTR_s_numberWithDouble__0114c310);
          uVar8 = _objc_retainAutoreleasedReturnValue();
          _objc_setAssociatedObject(param_1,s_initialPanTime_0116676f,uVar8,1);
          _objc_release(uVar8);
        }
        lVar9 = _objc_msgSend(param_3,puVar3);
        if (lVar9 == 2) {
          _objc_getAssociatedObject
                    ((&PTR_LAB_0117ce88)[lVar9 == 2] + (int)-(uRam000000000117ce98 ^ 0xf6c896bd),
                     param_1,s_initialPanTime_0116676f);
          lVar9 = _objc_retainAutoreleasedReturnValue();
          if (lVar9 == 0) {
            dVar14 = (double)_objc_msgSend(param_1,PTR_s_mediaTime_0114c890);
          }
          else {
            dVar14 = (double)_objc_msgSend(lVar9,PTR_s_doubleValue_0114b3f0);
          }
          dVar12 = (double)(long)dVar12;
          _objc_msgSend(param_1,puVar2);
          uVar8 = _objc_retainAutoreleasedReturnValue();
          dVar15 = (double)_objc_msgSend(param_3,PTR_s_translationInView__0114c898,uVar8);
          _objc_release(uVar8);
          _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
          uVar8 = _objc_retainAutoreleasedReturnValue();
          fVar11 = (float)_objc_msgSend(uVar8,PTR_s_floatForKey__0114c308,
                                        &PTR____CFConstantStringClassReference_01166820);
          _objc_release(uVar8);
          dVar15 = dVar15 * ((double)fVar11 / 10.0);
          lVar10 = _ytpInt(&PTR____CFConstantStringClassReference_01166860);
          if (lVar10 == 0) {
            dVar15 = (dVar12 / dVar13) * dVar15;
          }
          if (dVar14 + dVar15 <= dVar12) {
            dVar12 = dVar14 + dVar15;
          }
          if (dVar12 <= 0.0) {
            dVar12 = 0.0;
          }
          _objc_msgSend((&PTR__MSHookMessageEx_0117cec8)[lVar10 == 0] +
                        (int)-(uRam000000000117ced8 ^ 0x89261209),dVar12,uVar7,puVar1);
          _objc_release(lVar9);
        }
      }
      _objc_release(uVar7);
    }
  }
  _objc_release(param_3);
  CallSupervisor(0x9715);
  auVar16._8_8_ = 0x1f;
  auVar16._0_8_ = 0x1a;
  return auVar16;
}


