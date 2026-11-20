/* Decompiled from supplied 5.2.2 arm package. VA 0x25dbe0. _av_hwframe_map */

undefined8 _av_hwframe_map(long param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  undefined8 *puVar7;
  
  lVar3 = *(long *)(param_2 + 0x1e0);
  if (lVar3 != 0) {
    if (*(long *)(param_1 + 0x1e0) != 0) {
      lVar1 = *(long *)(lVar3 + 8);
      lVar5 = *(long *)(*(long *)(param_1 + 0x1e0) + 8);
      if ((((lVar1 == lVar5) && (*(int *)(param_2 + 0x74) == *(int *)(lVar1 + 0x48))) &&
          (*(int *)(param_1 + 0x74) == *(int *)(lVar1 + 0x44))) ||
         ((lVar6 = *(long *)(*(long *)(lVar1 + 8) + 0x18), lVar6 != 0 &&
          (*(long *)(lVar6 + 8) == lVar5)))) {
        if (*(long *)(param_2 + 0x120) == 0) {
          _av_log(lVar1,0x10,"Invalid mapping found when attempting unmap.\n");
          return 0xffffffea;
        }
        puVar7 = *(undefined8 **)(*(long *)(param_2 + 0x120) + 8);
        _av_frame_unref(param_1);
        uVar2 = _av_frame_ref(param_1,*puVar7);
        return uVar2;
      }
    }
    lVar3 = *(long *)(lVar3 + 8);
    if (((*(int *)(lVar3 + 0x44) == *(int *)(param_2 + 0x74)) &&
        (pcVar4 = *(code **)(**(long **)(lVar3 + 8) + 0xa0), pcVar4 != (code *)0x0)) &&
       (uVar2 = (*pcVar4)(lVar3,param_1,param_2,param_3), (int)uVar2 != -0x4e)) {
      return uVar2;
    }
  }
  if ((((*(long *)(param_1 + 0x1e0) == 0) ||
       (lVar3 = *(long *)(*(long *)(param_1 + 0x1e0) + 8),
       *(int *)(lVar3 + 0x44) != *(int *)(param_1 + 0x74))) ||
      (pcVar4 = *(code **)(**(long **)(lVar3 + 8) + 0x98), pcVar4 == (code *)0x0)) ||
     (uVar2 = (*pcVar4)(lVar3,param_1,param_2,param_3), (int)uVar2 == -0x4e)) {
    uVar2 = 0xffffffb2;
  }
  return uVar2;
}


