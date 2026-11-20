/* Decompiled from supplied 5.2.2 arm package. VA 0x1ff504. FUN_001ff504 */

void FUN_001ff504(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x28);
  if (lVar2 != 0) {
    _objc_msgSend(*(undefined8 *)(param_1 + 0x20),PTR_s_parserError_0114e310);
    uVar1 = _objc_retainAutoreleasedReturnValue();
    (**(code **)(lVar2 + 0x10))(lVar2,0,uVar1);
    (*(code *)PTR__objc_release_01061028)(uVar1);
    return;
  }
  return;
}


