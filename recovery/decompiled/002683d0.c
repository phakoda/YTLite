/* Decompiled from supplied 5.2.2 arm package. VA 0x2683d0. _av_pix_fmt_count_planes */

void _av_pix_fmt_count_planes(uint param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int *piVar5;
  int local_28 [4];
  long local_18;
  
  lVar3 = *(long *)PTR____stack_chk_guard_01060708;
  iVar4 = -0x16;
  local_18 = lVar3;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  if ((param_1 < 0xc6) && ((long)(int)param_1 * 0xa0 != -0x1065540)) {
    lVar2 = (long)(int)param_1 * 0xa0;
    piVar5 = (int *)(&DAT_01065558 + lVar2);
    iVar4 = (byte)(&DAT_01065548)[lVar2] + 1;
    while (iVar4 = iVar4 + -1, iVar4 != 0) {
      iVar1 = *piVar5;
      piVar5 = piVar5 + 8;
      local_28[iVar1] = 1;
    }
    iVar4 = 0;
    for (lVar2 = 0; lVar2 != 0x10; lVar2 = lVar2 + 4) {
      iVar4 = *(int *)((long)local_28 + lVar2) + iVar4;
    }
  }
  if (lVar3 == local_18) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(iVar4);
}


