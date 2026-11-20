/* Decompiled from supplied 5.2.2 arm package. VA 0x257940. _av_encryption_info_alloc */

long _av_encryption_info_alloc(int param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = _av_mallocz(0x40);
  if (lVar1 != 0) {
    uVar2 = _av_mallocz(param_2);
    *(undefined8 *)(lVar1 + 0x10) = uVar2;
    *(undefined4 *)(lVar1 + 0x18) = param_2;
    uVar2 = _av_mallocz(param_3);
    *(undefined8 *)(lVar1 + 0x20) = uVar2;
    *(undefined4 *)(lVar1 + 0x28) = param_3;
    lVar3 = _av_mallocz_array(param_1,8);
    *(long *)(lVar1 + 0x30) = lVar3;
    *(int *)(lVar1 + 0x38) = param_1;
    if ((*(long *)(lVar1 + 0x10) != 0) && (*(long *)(lVar1 + 0x20) != 0)) {
      if (param_1 == 0) {
        return lVar1;
      }
      if (lVar3 != 0) {
        return lVar1;
      }
    }
    _av_encryption_info_free(lVar1);
  }
  return 0;
}


