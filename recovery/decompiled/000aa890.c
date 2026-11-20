/* Decompiled from supplied 5.2.2 arm package. VA 0xaa890. FUN_000aa890 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000aa890(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  double dVar1;
  undefined *puVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  float fVar6;
  
  DAT_01226e34 = 1;
  _objc_retain(param_3);
  puVar2 = PTR_s_verticalPanGestureRecognizerDele_0114cc20;
  _objc_msgSend(param_1,PTR_s_verticalPanGestureRecognizerDele_0114cc20);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226838 == 0) {
    DAT_01226838 = _objc_getClass((&PTR_LAB_01181150)[DAT_01226838 == 0] +
                                  (int)-(DAT_01181160 ^ 0x1e30322a),
                                  s_YTMainAppVideoPlayerOverlayView_0116e230);
  }
  lVar3 = DAT_01226838;
  _objc_retainAutorelease(DAT_01226838);
  uVar4 = FUN_000e7958(uVar5,PTR_s_isKindOfClass__0114ad70,lVar3);
  _objc_release(uVar5);
  if (uVar4 == 0) {
    uVar5 = (*_DAT_01226670)(param_1,param_2,param_3);
    _objc_release(param_3);
    return uVar5;
  }
  _objc_msgSend((&PTR_FUN_01181170)[uVar4] + (int)-(uRam0000000001181180 ^ 0x294dd1da),param_1,
                puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  dVar1 = (double)_objc_msgSend(param_3,PTR_s_locationInView__0114c978,uVar5);
  _objc_msgSend(uVar5,PTR_s_bounds_0114b568);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  fVar6 = (float)_objc_msgSend(uVar5,PTR_s_floatForKey__0114c308,
                               &PTR____CFConstantStringClassReference_0116e2f0);
  _objc_release(uVar5);
                    /* WARNING: Could not recover jumptable at 0x000aafc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*(code *)((&PTR_LAB_01181190)[(double)fVar6 < dVar1] +
                    (int)-(uRam00000000011811a0 ^ 0x72beb18d)))();
  return uVar5;
}


