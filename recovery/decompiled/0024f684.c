/* Decompiled from supplied 5.2.2 arm package. VA 0x24f684. _oggpack_writealign */

void _oggpack_writealign(long param_1)

{
  if (0 < *(int *)(param_1 + 8)) {
    _oggpack_write(param_1,0,8 - *(int *)(param_1 + 8));
    return;
  }
  return;
}


