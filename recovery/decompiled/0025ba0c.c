/* Decompiled from supplied 5.2.2 arm package. VA 0x25ba0c. _av_frame_ref */

int _av_frame_ref(undefined8 *param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  void *pvVar4;
  undefined8 uVar5;
  ulong uVar6;
  
  *(undefined4 *)((long)param_1 + 0x74) = *(undefined4 *)((long)param_2 + 0x74);
  uVar5 = param_2[0xd];
  *(int *)(param_1 + 0xd) = (int)uVar5;
  *(int *)((long)param_1 + 0x6c) = (int)((ulong)uVar5 >> 0x20);
  *(undefined4 *)((long)param_1 + 0x1bc) = *(undefined4 *)((long)param_2 + 0x1bc);
  param_1[0x23] = param_2[0x23];
  *(undefined4 *)(param_1 + 0xe) = *(undefined4 *)(param_2 + 0xe);
  iVar2 = FUN_0025bbd8(param_1,param_2,0);
  if (iVar2 < 0) {
    return iVar2;
  }
  if (param_2[0x24] == 0) {
    iVar2 = _av_frame_get_buffer(param_1,0);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = _av_frame_copy(param_1,param_2);
    if (-1 < iVar2) {
      return iVar2;
    }
    goto LAB_0025bb78;
  }
  for (uVar6 = 0; uVar6 < 8; uVar6 = uVar6 + 1) {
    if (param_2[uVar6 + 0x24] != 0) {
      lVar3 = _av_buffer_ref();
      param_1[uVar6 + 0x24] = lVar3;
      if (lVar3 == 0) goto LAB_0025bb74;
    }
  }
  if (param_2[0x2c] == 0) {
LAB_0025bb28:
    if (param_2[0x3c] != 0) {
      lVar3 = _av_buffer_ref();
      param_1[0x3c] = lVar3;
      if (lVar3 == 0) goto LAB_0025bb74;
    }
    if ((undefined8 *)param_2[0xc] == param_2) {
      param_1[0xc] = param_1;
LAB_0025bb98:
      uVar5 = param_2[6];
      param_1[7] = param_2[7];
      param_1[6] = uVar5;
      uVar5 = param_2[4];
      param_1[5] = param_2[5];
      param_1[4] = uVar5;
      uVar5 = param_2[2];
      param_1[3] = param_2[3];
      param_1[2] = uVar5;
      uVar5 = *param_2;
      param_1[1] = param_2[1];
      *param_1 = uVar5;
      uVar5 = param_2[10];
      param_1[0xb] = param_2[0xb];
      param_1[10] = uVar5;
      uVar5 = param_2[8];
      param_1[9] = param_2[9];
      param_1[8] = uVar5;
      return 0;
    }
    iVar2 = *(int *)((long)param_2 + 0x1bc);
    if (iVar2 == 0) {
      iVar2 = -0x16;
      goto LAB_0025bb78;
    }
    pvVar4 = (void *)_av_malloc_array(8,(long)iVar2);
    param_1[0xc] = pvVar4;
    if (pvVar4 != (void *)0x0) {
      _memcpy(pvVar4,(void *)param_2[0xc],(long)iVar2 << 3);
      goto LAB_0025bb98;
    }
  }
  else {
    lVar3 = _av_mallocz_array(8,(long)*(int *)(param_2 + 0x2d));
    param_1[0x2c] = lVar3;
    if (lVar3 != 0) {
      lVar3 = 0;
      *(undefined4 *)(param_1 + 0x2d) = *(undefined4 *)(param_2 + 0x2d);
      do {
        if (*(int *)(param_2 + 0x2d) <= lVar3) goto LAB_0025bb28;
        uVar5 = _av_buffer_ref(*(undefined8 *)(param_2[0x2c] + lVar3 * 8));
        *(undefined8 *)(param_1[0x2c] + lVar3 * 8) = uVar5;
        lVar1 = lVar3 * 8;
        lVar3 = lVar3 + 1;
      } while (*(long *)(param_1[0x2c] + lVar1) != 0);
    }
  }
LAB_0025bb74:
  iVar2 = -0xc;
LAB_0025bb78:
  _av_frame_unref(param_1);
  return iVar2;
}


