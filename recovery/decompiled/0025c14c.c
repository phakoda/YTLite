/* Decompiled from supplied 5.2.2 arm package. VA 0x25c14c. _av_frame_is_writable */

byte _av_frame_is_writable(long param_1)

{
  int iVar1;
  byte bVar2;
  long lVar3;
  
  if (*(long *)(param_1 + 0x120) == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = 1;
    for (lVar3 = 0; lVar3 != 0x40; lVar3 = lVar3 + 8) {
      if (*(long *)(param_1 + 0x120 + lVar3) != 0) {
        iVar1 = _av_buffer_is_writable();
        bVar2 = iVar1 != 0 & bVar2;
      }
    }
    for (lVar3 = 0; lVar3 < *(int *)(param_1 + 0x168); lVar3 = lVar3 + 1) {
      iVar1 = _av_buffer_is_writable(*(undefined8 *)(*(long *)(param_1 + 0x160) + lVar3 * 8));
      bVar2 = iVar1 != 0 & bVar2;
    }
  }
  return bVar2;
}


