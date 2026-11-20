/* Decompiled from supplied 5.2.2 arm package. VA 0x25f418. _av_image_copy_to_buffer */

void _av_image_copy_to_buffer
               (void *param_1,int param_2,long param_3,long param_4,undefined4 param_5,
               undefined4 param_6,int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  long lVar8;
  int iVar9;
  void *pvVar10;
  int local_78 [4];
  long local_68;
  
  lVar8 = *(long *)PTR____stack_chk_guard_01060708;
  local_68 = lVar8;
  iVar2 = _av_image_get_buffer_size(param_5,param_6,param_7,param_8);
  lVar4 = _av_pix_fmt_desc_get(param_5);
  iVar3 = -0x16;
  if (((-1 < iVar2) && (iVar2 <= param_2)) && (lVar4 != 0)) {
    iVar3 = *(byte *)(lVar4 + 8) + 1;
    piVar7 = (int *)(lVar4 + 0x18);
    iVar1 = 0;
    while (iVar9 = iVar1, iVar3 = iVar3 + -1, iVar3 != 0) {
      piVar6 = piVar7 + 8;
      iVar1 = *piVar7;
      piVar7 = piVar6;
      if (iVar1 <= iVar9) {
        iVar1 = iVar9;
      }
    }
    iVar3 = _av_image_fill_linesizes(local_78,param_5,param_6);
    if (iVar3 < 0) {
      _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
      _abort();
    }
    for (lVar8 = 0; lVar8 <= iVar9; lVar8 = lVar8 + 1) {
      if ((int)lVar8 - 1U < 2) {
        uVar5 = (uint)*(byte *)(lVar4 + 10);
      }
      else {
        uVar5 = 0;
      }
      pvVar10 = *(void **)(param_3 + lVar8 * 8);
      iVar3 = -1;
      while (iVar3 = iVar3 + 1,
            iVar3 < param_7 + -1 + (1 << (ulong)(uVar5 & 0x1f)) >> (uVar5 & 0x1f)) {
        _memcpy(param_1,pvVar10,(long)local_78[lVar8]);
        param_1 = (void *)((long)param_1 + (long)(param_8 + -1 + local_78[lVar8] & -param_8));
        pvVar10 = (void *)((long)pvVar10 + (long)*(int *)(param_4 + lVar8 * 4));
      }
    }
    iVar3 = iVar2;
    if ((*(byte *)(lVar4 + 0x10) >> 1 & 1) == 0) {
      lVar8 = *(long *)PTR____stack_chk_guard_01060708;
    }
    else {
      lVar8 = *(long *)PTR____stack_chk_guard_01060708;
      for (lVar4 = 0; lVar4 != 0x400; lVar4 = lVar4 + 4) {
        *(undefined4 *)((long)param_1 + lVar4) = *(undefined4 *)(*(long *)(param_3 + 8) + lVar4);
      }
    }
  }
  if (lVar8 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(iVar3);
  }
  return;
}


