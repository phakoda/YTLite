/* Decompiled from supplied 5.2.2 arm package. VA 0xf81a8. FUN_000f81a8 */

void FUN_000f81a8(void)

{
  long lVar1;
  undefined8 uVar2;
  
  DAT_012270e8 = 1;
  lVar1 = _ytpInt(&PTR____CFConstantStringClassReference_01185560);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar2,PTR_s_setInteger_forKey__0114c2d8,lVar1 != 1,
                &PTR____CFConstantStringClassReference_01185560);
  _objc_release(uVar2);
  return;
}


