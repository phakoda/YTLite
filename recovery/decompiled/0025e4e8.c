/* Decompiled from supplied 5.2.2 arm package. VA 0x25e4e8. FUN_0025e4e8 */

int FUN_0025e4e8(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long local_38;
  
  if ((*(int *)(param_1 + 0x4c) < (int)*(undefined8 *)(param_2 + 0x68)) ||
     (*(int *)(param_1 + 0x50) < (int)((ulong)*(undefined8 *)(param_2 + 0x68) >> 0x20))) {
    iVar1 = -0x16;
  }
  else {
    lVar2 = _av_frame_alloc();
    if (lVar2 == 0) {
      iVar1 = -0xc;
    }
    else {
      *(undefined4 *)(lVar2 + 0x74) = *(undefined4 *)(param_2 + 0x74);
      local_38 = lVar2;
      iVar1 = FUN_0025e5ac(param_1,lVar2,param_3,1);
      if (iVar1 == 0) {
        uVar3 = *(undefined8 *)(param_2 + 0x68);
        *(int *)(lVar2 + 0x68) = (int)uVar3;
        *(int *)(lVar2 + 0x6c) = (int)((ulong)uVar3 >> 0x20);
        iVar1 = _av_frame_copy(param_2,lVar2);
      }
      _av_frame_free(&local_38);
    }
  }
  return iVar1;
}


