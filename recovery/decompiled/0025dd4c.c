/* Decompiled from supplied 5.2.2 arm package. VA 0x25dd4c. _av_hwdevice_get_hwframe_constraints */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long _av_hwdevice_get_hwframe_constraints(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long local_38;
  
  lVar4 = *(long *)(param_1 + 8);
  lVar5 = **(long **)(lVar4 + 8);
  if ((*(long *)(lVar5 + 0x60) != 0) &&
     (lVar3 = _av_mallocz(0x20), uVar1 = _DAT_00c50e30, lVar3 != 0)) {
    *(undefined8 *)(lVar3 + 0x18) = _UNK_00c50e38;
    *(undefined8 *)(lVar3 + 0x10) = uVar1;
    local_38 = lVar3;
    iVar2 = (**(code **)(lVar5 + 0x60))(lVar4,param_2,lVar3);
    if (-1 < iVar2) {
      return lVar3;
    }
    _av_hwframe_constraints_free(&local_38);
  }
  return 0;
}


