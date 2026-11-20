/* Decompiled from supplied 5.2.2 arm package. VA 0x107a20. checkSpaceAvailabilityForMedia:completion: */

/* Function Stack Size: 0x20 bytes */

void DownloadMenuHelper::checkSpaceAvailabilityForMedia_completion_
               (ID param_1,SEL param_2,long_long param_3,ID param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  long lVar3;
  
  DAT_012271e4 = 1;
  _objc_retain(param_4);
  if (DAT_012270b0 == 0) {
    DAT_012270b0 = _objc_getClass((&PTR_LAB_0118aac0)[DAT_012270b0 == 0] +
                                  (int)-(DAT_0118aad0 ^ 0x9ff40b07),
                                  s_YTAutoOfflineController_01187550);
  }
  _objc_retainAutorelease();
  uVar2 = _objc_alloc_init();
  lVar3 = _objc_msgSend(uVar2,PTR_s_freeDeviceStorageBytes_0114d060);
  puVar1 = PTR_s_stringFromByteCount_countStyle__0114cea8;
  _objc_msgSend(PTR__OBJC_CLASS___NSByteCountFormatter_0114edf0,
                PTR_s_stringFromByteCount_countStyle__0114cea8,lVar3,0);
  _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(PTR__OBJC_CLASS___NSByteCountFormatter_0114edf0,puVar1,param_3 * 2 - lVar3,0);
  _objc_retainAutoreleasedReturnValue();
                    /* WARNING: Could not recover jumptable at 0x00107e08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((&PTR_LAB_0118aae0)[(long)(param_3 * 2) < lVar3] +
            (int)-(uRam000000000118aaf0 ^ 0x59a4dd44)))();
  return;
}


