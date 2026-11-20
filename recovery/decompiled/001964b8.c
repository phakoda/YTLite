/* Decompiled from supplied 5.2.2 arm package. VA 0x1964b8. segmentMeetsMinimumDuration: */

/* Function Stack Size: 0x18 bytes */

bool SBPlaybackController::segmentMeetsMinimumDuration_(ID param_1,SEL param_2,ID param_3)

{
  int iVar1;
  undefined8 uVar2;
  bool bVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  bVar3 = 1;
  DAT_0122783c = 1;
  _objc_retain(param_3);
  dVar4 = (double)_objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_floatForKey__0114c308,
                                &PTR____CFConstantStringClassReference_011aa150);
  if (0.0 < dVar4) {
    _objc_msgSend(param_3,PTR_s_category_0114dad0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    iVar1 = FUN_00199004(uVar2,PTR_s_isEqualToString__0114ae48,
                         &PTR____CFConstantStringClassReference_011aa110);
    _objc_release(uVar2);
    bVar3 = 1;
    if (iVar1 == 0) {
      dVar5 = (double)_objc_msgSend(param_3,PTR_s_end_0114dae0);
      dVar6 = (double)_objc_msgSend(param_3,PTR_s_start_0114b410);
      bVar3 = (bool)(dVar4 <= dVar5 - dVar6);
    }
  }
  _objc_release(param_3);
  return bVar3;
}


