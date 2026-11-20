/* Decompiled from supplied 5.2.2 arm package. VA 0x24f2ac. _oggpack_writecheck */

int _oggpack_writecheck(long param_1)

{
  if (*(long *)(param_1 + 0x18) != 0) {
    return -(uint)(*(long *)(param_1 + 0x20) == 0);
  }
  return -1;
}


