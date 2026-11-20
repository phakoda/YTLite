/* Decompiled from supplied 5.2.2 arm package. VA 0x84d50. FUN_00084d50 */

undefined1  [16] FUN_00084d50(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  DAT_01226c58 = 1;
  _objc_retain(param_3);
  puVar1 = PTR_s_parentResponder_0114aef0;
  _objc_msgSend(param_1,PTR_s_parentResponder_0114aef0);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (DAT_012268c8 == 0) {
    DAT_012268c8 = _objc_getClass((&PTR_LAB_0117d428)[DAT_012268c8 == 0] +
                                  (int)-(uRam000000000117d438 ^ 0x8ab84cee),
                                  s_YTReelPlayerViewController_01167360);
  }
  lVar2 = DAT_012268c8;
  _objc_retainAutorelease(DAT_012268c8);
  uVar3 = FUN_000de990(uVar4,PTR_s_isKindOfClass__0114ad70,lVar2);
  _objc_release(uVar4);
  if (uVar3 != 0) {
    _objc_msgSend((&PTR_LAB_0117d448)[uVar3] + (int)-(DAT_0117d458 ^ 0x91dce70a),param_1,puVar1);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_player_0114c920);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR_DownloadMenuHelper_0114ed78,PTR_s_showDownloadSheetShorts_withSend_0114c928,
                  uVar5,param_3);
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_release(param_3);
  CallSupervisor(0x2385);
  return ZEXT816(0x1f);
}


