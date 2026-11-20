/* Decompiled from supplied 5.2.2 arm package. VA 0x25b31c. _av_frame_new_side_data_from_buf */

undefined4 * _av_frame_new_side_data_from_buf(long param_1,undefined4 param_2,long param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  
  if (((param_3 != 0) && (*(uint *)(param_1 + 0x178) < 0xfffffff)) &&
     (uVar1 = *(uint *)(param_1 + 0x178) + 1,
     lVar4 = _av_realloc(*(undefined8 *)(param_1 + 0x170),
                         -(ulong)(uVar1 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar1 << 3),
     lVar4 != 0)) {
    *(long *)(param_1 + 0x170) = lVar4;
    puVar5 = (undefined4 *)_av_mallocz(0x28);
    if (puVar5 != (undefined4 *)0x0) {
      *(long *)(puVar5 + 8) = param_3;
      *(undefined8 *)(puVar5 + 2) = *(undefined8 *)(param_3 + 8);
      uVar2 = *(undefined4 *)(param_3 + 0x10);
      *puVar5 = param_2;
      puVar5[4] = uVar2;
      iVar3 = *(int *)(param_1 + 0x178);
      *(int *)(param_1 + 0x178) = iVar3 + 1;
      *(undefined4 **)(*(long *)(param_1 + 0x170) + (long)iVar3 * 8) = puVar5;
      return puVar5;
    }
  }
  return (undefined4 *)0x0;
}


