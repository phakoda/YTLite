/* Decompiled from supplied 5.2.2 arm package. VA 0xa51f0. FUN_000a51f0 */

void FUN_000a51f0(undefined8 param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = *(long *)PTR____stack_chk_guard_01060708;
  DAT_01226e10 = 1;
  _objc_msgSend(param_1,PTR_s_parentViewController_0114ad68);
  uVar4 = _objc_retainAutoreleasedReturnValue();
  if (DAT_01226908 == 0) {
    DAT_01226908 = _objc_getClass((&PTR_LAB_011805e0)[DAT_01226908 == 0] +
                                  (int)-(DAT_011805f0 ^ 0x7c824290),s_YTWatchViewController_0116d4c0
                                 );
  }
  lVar5 = DAT_01226908;
  _objc_retainAutorelease(DAT_01226908);
  iVar2 = FUN_000e61e4(uVar4,PTR_s_isKindOfClass__0114ad70,lVar5);
  _objc_release(uVar4);
  puVar1 = PTR_s_activeVideo_0114c788;
  if (iVar2 != 0) {
    _objc_msgSend(param_1,PTR_s_activeVideo_0114c788);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    if (lVar5 != 0) {
      uVar3 = FUN_000e69e0(param_1,PTR_s_isMDXActive_0114cb78);
      _objc_release(lVar5);
      if (uVar3 == 0) {
        _objc_msgSend((&PTR_LAB_01180630)[uVar3] + (int)-(uRam0000000001180640 ^ 0x9a0c3819),param_1
                      ,puVar1);
        uVar4 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar4,PTR_s_availableCaptionTracks_0114cb80);
        lVar6 = _objc_retainAutoreleasedReturnValue();
        _objc_release();
        _objc_release(uVar4);
                    /* WARNING: Could not recover jumptable at 0x000a5aa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((&PTR_LAB_01180648)[lVar6 == 0] + (int)-(uRam0000000001180658 ^ 0x4f4fd53e)))();
        return;
      }
    }
  }
  CallSupervisor(0xb717);
  if (*(long *)PTR____stack_chk_guard_01060708 != lVar6) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(0x1a,0x1f,0,0);
  }
  return;
}


