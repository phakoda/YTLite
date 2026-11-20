/* Decompiled from supplied 5.2.2 arm package. VA 0x24fa74. _oggpack_look1 */

ulong _oggpack_look1(long *param_1)

{
  if (*param_1 < param_1[4]) {
    return (ulong)(*(byte *)param_1[3] >> (ulong)(*(uint *)(param_1 + 1) & 0x1f) & 1);
  }
  return 0xffffffffffffffff;
}


