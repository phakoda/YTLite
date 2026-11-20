/* Decompiled from supplied 5.2.2 arm package. VA 0x1d0b6c. hashForFile:fileSize: */

/* Function Stack Size: 0x20 bytes */

ID YTPDownloader::hashForFile_fileSize_
             (ID param_1,SEL param_2,ID param_3,unsigned_long_long param_4)

{
  CC_LONG len;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  void *data;
  ID IVar4;
  uchar auStack_70 [32];
  undefined **local_50;
  uint local_44;
  undefined **local_40;
  long local_38;
  
  local_38 = *(long *)PTR____stack_chk_guard_01060708;
  local_40 = &PTR_LAB_011b7638;
  local_44 = (uint)(DAT_01227d64 == 0);
  local_50 = &PTR__objc_msgSend_011b7210;
  DAT_01227d64 = 1;
  thunk_FUN_001d541c(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithFormat__0114b378,
                     &PTR____CFConstantStringClassReference_011b6730,param_3,param_4);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar1,PTR_s_dataUsingEncoding__0114b460,4);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  uVar3 = _objc_retainAutorelease();
  data = (void *)_objc_msgSend(uVar3,PTR_s_bytes_0114b440);
  len = _objc_msgSend(uVar2,PTR_s_length_0114b438);
  _CC_SHA256(data,len,auStack_70);
  _objc_msgSend(PTR__OBJC_CLASS___NSData_0114eb98,PTR_s_dataWithBytes_length__0114b448,auStack_70,
                0x20);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_release(uVar2);
  _objc_release(uVar1);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_38) {
    IVar4 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar3);
    return IVar4;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


