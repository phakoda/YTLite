/* Decompiled from supplied 5.2.2 arm package. VA 0x8b680. FUN_0008b680 */

void FUN_0008b680(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  ulong uVar14;
  undefined *puVar15;
  float fVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  
  DAT_01226d20 = 1;
  _objc_retain(param_3);
  iVar8 = FUN_000dfffc(&PTR____CFConstantStringClassReference_01168950);
  if (iVar8 == 0) goto LAB_0008c1f8;
  _objc_msgSend(param_1,PTR_s_playerBarController_0114c980);
  uVar9 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar9,PTR_s_playerBar_0114b9b0);
  uVar10 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar9);
  puVar5 = PTR_s_fineScrubberDidStartSeeking_0114c988;
  puVar15 = PTR_s_respondsToSelector__0114af58;
  iVar8 = FUN_000e0064(uVar10,PTR_s_respondsToSelector__0114af58,
                       PTR_s_fineScrubberDidStartSeeking_0114c988);
  puVar6 = PTR_s_fineScrubberDidSeekToTime__0114c990;
  if (((iVar8 != 0) &&
      (iVar8 = FUN_000dfea4(uVar10,puVar15,PTR_s_fineScrubberDidSeekToTime__0114c990),
      puVar7 = PTR_s_fineScrubberDidEndSeekingWithSee_0114c998, iVar8 != 0)) &&
     (iVar8 = FUN_000dff18(uVar10,puVar15,PTR_s_fineScrubberDidEndSeekingWithSee_0114c998),
     puVar4 = PTR_s_mediaTime_0114c890, iVar8 != 0)) {
    dVar17 = (double)_objc_msgSend(param_1,PTR_s_mediaTime_0114c890);
    dVar18 = (double)_objc_msgSend(param_1,PTR_s_maximumSeekableTime_0114c9a0);
    puVar2 = PTR_s_view_0114b090;
    _objc_msgSend(param_1,PTR_s_view_0114b090);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,PTR_s_bounds_0114b568);
    dVar19 = (double)_CGRectGetWidth();
    _objc_release(uVar9);
    puVar3 = PTR_s_state_0114c560;
    lVar11 = _objc_msgSend(param_3,PTR_s_state_0114c560);
    if (lVar11 == 1) {
      dVar17 = (double)_objc_msgSend((&PTR_LAB_0117df30)[lVar11 == 1] +
                                     (int)-(uRam000000000117df40 ^ 0x1b06245a),param_1,puVar4);
      _objc_msgSend(uVar10,puVar5);
    }
    else {
      dVar17 = (double)(long)dVar17;
    }
    lVar11 = _objc_msgSend(param_3,puVar3);
    if (lVar11 == 2) {
      dVar18 = (double)(long)dVar18;
      _objc_msgSend(param_1,puVar2);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      dVar20 = (double)_objc_msgSend(param_3,PTR_s_translationInView__0114c898,uVar9);
      _objc_release(uVar9);
      _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
      uVar9 = _objc_retainAutoreleasedReturnValue();
      fVar16 = (float)_objc_msgSend(uVar9,PTR_s_floatForKey__0114c308,
                                    &PTR____CFConstantStringClassReference_011688d0);
      _objc_release(uVar9);
      dVar20 = dVar20 * ((double)fVar16 / 10.0);
      lVar11 = _ytpInt(&PTR____CFConstantStringClassReference_01168890);
      if (lVar11 == 0) {
        dVar20 = (dVar18 / dVar19) * dVar20;
      }
      if (dVar17 + dVar20 <= dVar18) {
        dVar18 = dVar17 + dVar20;
      }
      if (dVar18 <= 0.0) {
        dVar18 = 0.0;
      }
      _objc_msgSend((&PTR_LAB_0117df68)[lVar11 == 0] + (int)-(DAT_0117df78 ^ 0x115fc05f),dVar18,
                    uVar10,puVar6);
      puVar5 = PTR_s_currentTimeLabel_0114c9a8;
      iVar8 = FUN_000dfe5c(uVar10,puVar15,PTR_s_currentTimeLabel_0114c9a8);
      if (iVar8 != 0) {
        uVar14 = (ulong)dVar18;
        iVar8 = (int)uVar14 +
                ((int)(SUB168(SEXT816((long)uVar14) * SEXT816(0x48d159e26af37c05),8) >> 10) -
                (SUB164(SEXT816((long)uVar14) * SEXT816(0x48d159e26af37c05),0xc) >> 0x1f)) * -0xe10;
        uVar1 = iVar8 + ((uint)((short)iVar8 * -0x7777) >> 0x10);
        if ((long)uVar14 < 0xe10) {
          thunk_FUN_000dfed8(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                             &PTR____CFConstantStringClassReference_01168910,
                             (long)(int)(((int)(uVar1 * 0x10000) >> 0x15) +
                                        ((uVar1 & 0x8000) >> 0xf)),(long)uVar14 % 0x3c);
          uVar9 = _objc_retainAutoreleasedReturnValue();
        }
        else {
          thunk_FUN_000e00b8(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                             &PTR____CFConstantStringClassReference_01168850,uVar14 / 0xe10);
          uVar9 = _objc_retainAutoreleasedReturnValue();
        }
        _objc_msgSend(uVar10,puVar5);
        uVar12 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar12,PTR_s_setText__0114b388,uVar9);
        _objc_release(uVar12);
        _objc_msgSend(uVar10,puVar5);
        uVar12 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar12,PTR_s_sizeToFit_0114b390);
        _objc_release(uVar12);
        _objc_msgSend(uVar10,puVar5);
        uVar12 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar12,PTR_s_superview_0114c820);
        uVar13 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(0x3ff0000000000000,uVar13,PTR_s_setAlpha__0114b698);
        _objc_release(uVar13);
        _objc_release(uVar12);
        _objc_release(uVar9);
      }
    }
    lVar11 = _objc_msgSend(param_3,puVar3);
    puVar15 = (&PTR_LAB_0117dfd0)[lVar11 == 3] + (int)-(DAT_0117dfe0 ^ 0x304febfa);
    if (lVar11 != 3) {
      lVar11 = _objc_msgSend(puVar15,param_3,puVar3);
      puVar15 = (&PTR_LAB_0117dfe8)[lVar11 == 4] + (int)-(uRam000000000117dff8 ^ 0x1b10e511);
      if (lVar11 != 4) goto LAB_0008c1f0;
    }
    _objc_msgSend(puVar15,uVar10,puVar7,0x19);
  }
LAB_0008c1f0:
  _objc_release(uVar10);
LAB_0008c1f8:
  (*(code *)PTR__objc_release_01061028)(param_3);
  return;
}


