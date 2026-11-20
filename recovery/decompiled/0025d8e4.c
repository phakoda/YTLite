/* Decompiled from supplied 5.2.2 arm package. VA 0x25d8e4. _av_hwframe_transfer_data */

int _av_hwframe_transfer_data(long param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  undefined4 *local_50;
  long local_48;
  
  lVar6 = *(long *)(param_2 + 0x1e0);
  if (*(long *)(param_1 + 0x120) != 0) {
    lVar3 = *(long *)(param_1 + 0x1e0);
    if (lVar6 == 0) {
      if (lVar3 == 0) {
        return -0x4e;
      }
      lVar6 = *(long *)(lVar3 + 8);
      pcVar5 = *(code **)(**(long **)(lVar6 + 8) + 0x88);
    }
    else {
      lVar6 = *(long *)(lVar6 + 8);
      if (lVar3 == 0) {
        pcVar5 = *(code **)(**(long **)(lVar6 + 8) + 0x90);
      }
      else {
        if ((*(long **)(lVar6 + 8))[3] != 0) {
          pcVar2 = 
          "A device with a derived frame context cannot be used as the source of a HW -> HW transfer."
          ;
LAB_0025d9bc:
          _av_log(lVar6,0x10,pcVar2);
          return -0x4e;
        }
        lVar3 = *(long *)(lVar3 + 8);
        if (*(long *)(*(long *)(lVar3 + 8) + 0x18) != 0) {
          pcVar2 = 
          "A device with a derived frame context cannot be used as the destination of a HW -> HW transfer."
          ;
          goto LAB_0025d9bc;
        }
        iVar1 = (**(code **)(**(long **)(lVar6 + 8) + 0x90))(lVar6,param_1,param_2);
        if (iVar1 != -0x4e) goto LAB_0025d990;
        pcVar5 = *(code **)(**(long **)(lVar3 + 8) + 0x88);
        lVar6 = lVar3;
      }
    }
    iVar1 = (*pcVar5)(lVar6,param_1,param_2);
LAB_0025d990:
    if (-1 < iVar1) {
      return 0;
    }
    return iVar1;
  }
  lVar6 = *(long *)(lVar6 + 8);
  local_48 = _av_frame_alloc();
  if (local_48 == 0) {
    return -0xc;
  }
  if (*(int *)(param_1 + 0x74) < 0) {
    iVar1 = _av_hwframe_transfer_get_formats(*(undefined8 *)(param_2 + 0x1e0),0,&local_50);
    if (iVar1 < 0) goto LAB_0025da50;
    *(undefined4 *)(local_48 + 0x74) = *local_50;
    _av_freep(&local_50);
  }
  else {
    *(int *)(local_48 + 0x74) = *(int *)(param_1 + 0x74);
  }
  *(undefined4 *)(local_48 + 0x68) = *(undefined4 *)(lVar6 + 0x4c);
  *(undefined4 *)(local_48 + 0x6c) = *(undefined4 *)(lVar6 + 0x50);
  iVar1 = _av_frame_get_buffer(local_48,0);
  if ((-1 < iVar1) && (iVar1 = _av_hwframe_transfer_data(local_48,param_2,param_3), -1 < iVar1)) {
    uVar4 = *(undefined8 *)(param_2 + 0x68);
    *(int *)(local_48 + 0x68) = (int)uVar4;
    *(int *)(local_48 + 0x6c) = (int)((ulong)uVar4 >> 0x20);
    _av_frame_move_ref(param_1);
  }
LAB_0025da50:
  _av_frame_free(&local_48);
  return iVar1;
}


