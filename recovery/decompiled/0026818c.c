/* Decompiled from supplied 5.2.2 arm package. VA 0x26818c. _av_get_padded_bits_per_pixel */

int _av_get_padded_bits_per_pixel(long param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  int *piVar10;
  int local_28 [4];
  long local_18;
  
  lVar6 = *(long *)PTR____stack_chk_guard_01060708;
  iVar7 = 0;
  local_18 = lVar6;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  piVar10 = (int *)(param_1 + 0x1c);
  uVar2 = (uint)*(byte *)(param_1 + 10) + (uint)*(byte *)(param_1 + 9);
  for (uVar8 = (uint)*(byte *)(param_1 + 8); uVar8 != 0; uVar8 = uVar8 - 1) {
    uVar5 = iVar7 - 1;
    iVar4 = *piVar10;
    piVar1 = piVar10 + -1;
    iVar7 = iVar7 + 1;
    piVar10 = piVar10 + 8;
    uVar3 = 0;
    if (1 < uVar5) {
      uVar3 = uVar2;
    }
    local_28[*piVar1] = iVar4 << (ulong)(uVar3 & 0x1f);
  }
  iVar7 = 0;
  for (lVar9 = 0; lVar9 != 0x10; lVar9 = lVar9 + 4) {
    iVar7 = *(int *)((long)local_28 + lVar9) + iVar7;
  }
  iVar4 = iVar7 << 3;
  if ((*(ulong *)(param_1 + 0x10) & 4) != 0) {
    iVar4 = iVar7;
  }
  if (lVar6 == local_18) {
    return iVar4 >> (uVar2 & 0x1f);
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


