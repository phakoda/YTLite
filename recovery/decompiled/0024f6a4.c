/* Decompiled from supplied 5.2.2 arm package. VA 0x24f6a4. _oggpackB_writealign */

void _oggpackB_writealign(long param_1)

{
  if (0 < *(int *)(param_1 + 8)) {
    _oggpackB_write(param_1,0,8 - *(int *)(param_1 + 8));
    return;
  }
  return;
}


