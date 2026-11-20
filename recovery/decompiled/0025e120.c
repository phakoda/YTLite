/* Decompiled from supplied 5.2.2 arm package. VA 0x25e120. _av_hwframe_ctx_create_derived */

int _av_hwframe_ctx_create_derived
              (long *param_1,undefined4 param_2,long param_3,long param_4,uint param_5)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long local_48;
  
  local_48 = 0;
  lVar8 = *(long *)(param_4 + 8);
  lVar2 = *(long *)(*(long *)(lVar8 + 8) + 0x18);
  if ((lVar2 == 0) || (*(long *)(*(long *)(lVar2 + 8) + 0x18) != *(long *)(param_3 + 8))) {
    local_48 = _av_hwframe_ctx_alloc(param_3);
    if (local_48 != 0) {
      lVar7 = *(long *)(local_48 + 8);
      *(undefined4 *)(lVar7 + 0x44) = param_2;
      uVar3 = *(undefined8 *)(lVar8 + 0x48);
      *(int *)(lVar7 + 0x48) = (int)uVar3;
      *(int *)(lVar7 + 0x4c) = (int)((ulong)uVar3 >> 0x20);
      *(undefined4 *)(lVar7 + 0x50) = *(undefined4 *)(lVar8 + 0x50);
      lVar2 = _av_buffer_ref(param_4);
      plVar4 = *(long **)(lVar7 + 8);
      plVar4[3] = lVar2;
      if (lVar2 == 0) {
        iVar6 = -0xc;
      }
      else {
        *(uint *)(plVar4 + 4) = param_5 & 0xf;
        pcVar5 = *(code **)(**(long **)(lVar8 + 8) + 0xb0);
        if (pcVar5 == (code *)0x0) {
LAB_0025e1e8:
          if (*(code **)(*plVar4 + 0xa8) == (code *)0x0) goto LAB_0025e210;
          iVar1 = (**(code **)(*plVar4 + 0xa8))(lVar7,lVar8,param_5);
        }
        else {
          iVar1 = (*pcVar5)(lVar7,lVar8,param_5);
          if (iVar1 == -0x4e) {
            plVar4 = *(long **)(lVar7 + 8);
            goto LAB_0025e1e8;
          }
        }
        iVar6 = 0;
        if (iVar1 != -0x4e) {
          iVar6 = iVar1;
        }
        if (iVar6 == 0) {
LAB_0025e210:
          *param_1 = local_48;
          return 0;
        }
      }
      if (lVar7 != 0) {
        _av_buffer_unref(*(long *)(lVar7 + 8) + 0x18);
      }
      goto LAB_0025e254;
    }
  }
  else {
    lVar2 = _av_buffer_ref(lVar2);
    *param_1 = lVar2;
    if (lVar2 != 0) {
      return 0;
    }
  }
  iVar6 = -0xc;
LAB_0025e254:
  _av_buffer_unref(&local_48);
  return iVar6;
}


