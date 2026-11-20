/* Decompiled from supplied 5.2.2 arm package. VA 0x25bbd8. FUN_0025bbd8 */

undefined8 FUN_0025bbd8(long param_1,long param_2,int param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  int *piVar4;
  undefined8 local_48;
  
  uVar2 = *(undefined8 *)(param_2 + 0x78);
  *(int *)(param_1 + 0x78) = (int)uVar2;
  *(int *)(param_1 + 0x7c) = (int)((ulong)uVar2 >> 0x20);
  *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(param_2 + 0x80);
  *(undefined8 *)(param_1 + 0x1f0) = *(undefined8 *)(param_2 + 0x1f0);
  *(undefined8 *)(param_1 + 0x1f8) = *(undefined8 *)(param_2 + 0x1f8);
  *(undefined8 *)(param_1 + 0x200) = *(undefined8 *)(param_2 + 0x200);
  *(undefined8 *)(param_1 + 0x208) = *(undefined8 *)(param_2 + 0x208);
  *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(param_2 + 0x88);
  uVar2 = *(undefined8 *)(param_2 + 0xf8);
  *(int *)(param_1 + 0xf8) = (int)uVar2;
  *(int *)(param_1 + 0xfc) = (int)((ulong)uVar2 >> 0x20);
  uVar2 = *(undefined8 *)(param_2 + 0x100);
  *(int *)(param_1 + 0x100) = (int)uVar2;
  *(int *)(param_1 + 0x104) = (int)((ulong)uVar2 >> 0x20);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(param_2 + 0x110);
  *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_2 + 0xb0);
  *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(param_2 + 0x90);
  *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(param_2 + 0x98);
  *(undefined8 *)(param_1 + 0x1a0) = *(undefined8 *)(param_2 + 0x1a0);
  *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_2 + 0x1c0);
  *(undefined8 *)(param_1 + 0x1a8) = *(undefined8 *)(param_2 + 0x1a8);
  *(undefined8 *)(param_1 + 0x108) = *(undefined8 *)(param_2 + 0x108);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_2 + 0xa8);
  *(undefined8 *)(param_1 + 0x198) = *(undefined8 *)(param_2 + 0x198);
  uVar2 = *(undefined8 *)(param_2 + 0xa0);
  *(int *)(param_1 + 0xa0) = (int)uVar2;
  *(int *)(param_1 + 0xa4) = (int)((ulong)uVar2 >> 0x20);
  *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_2 + 0x17c);
  *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_2 + 0x1b8);
  *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_2 + 0x184);
  uVar2 = *(undefined8 *)(param_2 + 0x188);
  *(int *)(param_1 + 0x188) = (int)uVar2;
  *(int *)(param_1 + 0x18c) = (int)((ulong)uVar2 >> 0x20);
  *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_2 + 0x180);
  *(undefined4 *)(param_1 + 400) = *(undefined4 *)(param_2 + 400);
  _av_dict_copy(param_1 + 0x1b0,*(undefined8 *)(param_2 + 0x1b0),0);
  uVar2 = *(undefined8 *)(param_2 + 0xe8);
  *(undefined8 *)(param_1 + 0xf0) = *(undefined8 *)(param_2 + 0xf0);
  *(undefined8 *)(param_1 + 0xe8) = uVar2;
  uVar2 = *(undefined8 *)(param_2 + 0xd8);
  *(undefined8 *)(param_1 + 0xe0) = *(undefined8 *)(param_2 + 0xe0);
  *(undefined8 *)(param_1 + 0xd8) = uVar2;
  uVar2 = *(undefined8 *)(param_2 + 200);
  *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(param_2 + 0xd0);
  *(undefined8 *)(param_1 + 200) = uVar2;
  uVar2 = *(undefined8 *)(param_2 + 0xb8);
  *(undefined8 *)(param_1 + 0xc0) = *(undefined8 *)(param_2 + 0xc0);
  *(undefined8 *)(param_1 + 0xb8) = uVar2;
  for (lVar3 = 0; lVar3 < *(int *)(param_2 + 0x178); lVar3 = lVar3 + 1) {
    piVar4 = *(int **)(*(long *)(param_2 + 0x170) + lVar3 * 8);
    if ((*piVar4 != 0) ||
       ((int)*(undefined8 *)(param_2 + 0x68) == (int)*(undefined8 *)(param_1 + 0x68) &&
        (int)((ulong)*(undefined8 *)(param_2 + 0x68) >> 0x20) ==
        (int)((ulong)*(undefined8 *)(param_1 + 0x68) >> 0x20))) {
      if (param_3 == 0) {
        local_48 = _av_buffer_ref(*(undefined8 *)(piVar4 + 8));
        lVar1 = _av_frame_new_side_data_from_buf(param_1,*piVar4,local_48);
        if (lVar1 == 0) {
          _av_buffer_unref(&local_48);
          goto LAB_0025be5c;
        }
      }
      else {
        lVar1 = _av_frame_new_side_data(param_1,*piVar4,piVar4[4]);
        if (lVar1 == 0) {
LAB_0025be5c:
          FUN_0025c0a4(param_1);
          goto LAB_0025be64;
        }
        _memcpy(*(void **)(lVar1 + 8),*(void **)(piVar4 + 2),(long)piVar4[4]);
      }
      _av_dict_copy(lVar1 + 0x18,*(undefined8 *)(piVar4 + 6),0);
    }
  }
  *(undefined8 *)(param_1 + 0x1c8) = 0;
  *(undefined8 *)(param_1 + 0x1d0) = 0;
  _av_buffer_unref((long *)(param_1 + 0x1d8));
  if (*(long *)(param_2 + 0x1d8) != 0) {
    lVar3 = _av_buffer_ref();
    *(long *)(param_1 + 0x1d8) = lVar3;
    if (lVar3 != 0) {
      *(undefined8 *)(param_1 + 0x1c8) = *(undefined8 *)(lVar3 + 8);
      uVar2 = *(undefined8 *)(param_2 + 0x1d0);
      *(int *)(param_1 + 0x1d0) = (int)uVar2;
      *(int *)(param_1 + 0x1d4) = (int)((ulong)uVar2 >> 0x20);
    }
  }
  _av_buffer_unref((long *)(param_1 + 0x1e8));
  _av_buffer_unref((long *)(param_1 + 0x210));
  if (*(long *)(param_2 + 0x1e8) == 0) {
LAB_0025be38:
    if (*(long *)(param_2 + 0x210) != 0) {
      lVar3 = _av_buffer_ref();
      *(long *)(param_1 + 0x210) = lVar3;
      if (lVar3 == 0) goto LAB_0025be64;
    }
    uVar2 = 0;
  }
  else {
    lVar3 = _av_buffer_ref();
    *(long *)(param_1 + 0x1e8) = lVar3;
    if (lVar3 != 0) goto LAB_0025be38;
LAB_0025be64:
    uVar2 = 0xfffffff4;
  }
  return uVar2;
}


