/* Decompiled from supplied 5.2.2 arm package. VA 0xcce50. FUN_000cce50 */

void FUN_000cce50(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  double dVar3;
  
  puVar1 = PTR_s_playbackOverlay_0114cc80;
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_playbackOverlay_0114cc80);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(0x3ff0000000000000,uVar2,PTR_s_setAlpha__0114b698);
  _objc_release(uVar2);
  _objc_msgSend(*(undefined8 *)(param_1 + 0x20),puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  dVar3 = (double)_objc_msgSend(uVar2,PTR_s_alpha_0114c9d8);
  DAT_0115cd38 = dVar3 != 0.0;
  _objc_release(uVar2);
  return;
}


