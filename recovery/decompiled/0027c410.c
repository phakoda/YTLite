/* Decompiled from supplied 5.2.2 arm package. VA 0x27c410. FUN_0027c410 */

int FUN_0027c410(long param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  code *pcVar8;
  long local_48;
  
  lVar5 = *(long *)(param_1 + 0x10);
  lVar6 = *(long *)(lVar5 + 0x48);
  local_48 = param_2;
  for (uVar7 = 0; uVar7 < *(uint *)(lVar5 + 0x40); uVar7 = uVar7 + 1) {
    lVar4 = _ff_get_audio_buffer
                      (*(undefined8 *)(*(long *)(lVar5 + 0x38) + uVar7 * 8),
                       *(undefined4 *)(local_48 + 0x70));
    *(long *)(lVar6 + 0x38 + uVar7 * 8) = lVar4;
    if (lVar4 == 0) {
      iVar3 = -0xc;
      goto LAB_0027c504;
    }
    *(undefined8 *)(lVar4 + 0x88) = *(undefined8 *)(local_48 + 0x88);
  }
  *(long *)(lVar6 + 0x30) = local_48;
  pcVar8 = (code *)**(undefined8 **)(lVar5 + 0x60);
  iVar3 = *(int *)(param_1 + 0xc4);
  iVar1 = _ff_filter_get_nb_threads(lVar5);
  if (iVar1 < iVar3) {
    uVar2 = _ff_filter_get_nb_threads(lVar5);
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0xc4);
  }
  (*pcVar8)(lVar5,FUN_0027c7a8,0,0,uVar2);
  uVar7 = 0;
  iVar3 = 0;
  do {
    if (*(uint *)(lVar5 + 0x40) <= uVar7) break;
    iVar3 = _ff_filter_frame(*(undefined8 *)(*(long *)(lVar5 + 0x38) + uVar7 * 8),
                             *(undefined8 *)(lVar6 + 0x38 + uVar7 * 8));
    *(undefined8 *)(lVar6 + 0x38 + uVar7 * 8) = 0;
    uVar7 = uVar7 + 1;
  } while (-1 < iVar3);
LAB_0027c504:
  uVar7 = 0xffffffffffffffff;
  lVar4 = lVar6 + 0x38;
  while( true ) {
    uVar7 = uVar7 + 1;
    if (*(uint *)(lVar5 + 0x40) <= uVar7) break;
    _av_frame_free(lVar4);
    lVar4 = lVar4 + 8;
  }
  _av_frame_free(&local_48);
  *(undefined8 *)(lVar6 + 0x30) = 0;
  return iVar3;
}


