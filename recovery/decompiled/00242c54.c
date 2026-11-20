/* Decompiled from supplied 5.2.2 arm package. VA 0x242c54. FUN_00242c54 */

void FUN_00242c54(long param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  long lVar6;
  int iVar7;
  
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined8 *)(param_1 + 0x20) = 0;
    return;
  }
  lVar4 = (long)*(int *)(param_2 + 0x48);
  iVar3 = *(int *)(param_1 + 4) * 2;
  lVar6 = -1;
  piVar5 = (int *)(&_shine_scale_fact_band_index + lVar4 * 0x5c);
  do {
    iVar7 = *piVar5;
    lVar6 = lVar6 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar7 < iVar3);
  iVar7 = (&DAT_00c4d61c)[lVar6 * 2];
  if (5 < (uint)lVar6) {
    piVar5 = (int *)(&_shine_scale_fact_band_index + (long)(iVar7 + 1) * 4 + lVar4 * 0x5c);
    do {
      if (*piVar5 <= iVar3) goto LAB_00242ccc;
      iVar7 = iVar7 + -1;
      piVar5 = piVar5 + -1;
    } while (iVar7 != 0);
    iVar7 = 0;
  }
LAB_00242ccc:
  *(int *)(param_1 + 0x20) = iVar7;
  uVar1 = iVar7 + 1;
  iVar7 = (&DAT_00c4d620)[lVar6 * 2];
  *(undefined4 *)(param_1 + 0x3c) =
       *(undefined4 *)(&_shine_scale_fact_band_index + (long)(int)uVar1 * 4 + lVar4 * 0x5c);
  if (4 < (uint)lVar6) {
    piVar5 = (int *)(&_shine_scale_fact_band_index +
                    ((long)(iVar7 + 1) + (ulong)uVar1) * 4 + lVar4 * 0x5c);
    do {
      if (*piVar5 <= iVar3) goto LAB_00242d2c;
      iVar7 = iVar7 + -1;
      piVar5 = piVar5 + -1;
    } while (iVar7 != 0);
    iVar7 = 0;
  }
LAB_00242d2c:
  uVar2 = *(undefined4 *)
           (&_shine_scale_fact_band_index + (long)(iVar7 + 1) * 4 + (ulong)uVar1 * 4 + lVar4 * 0x5c)
  ;
  *(int *)(param_1 + 0x24) = iVar7;
  *(undefined4 *)(param_1 + 0x40) = uVar2;
  *(int *)(param_1 + 0x44) = iVar3;
  return;
}


