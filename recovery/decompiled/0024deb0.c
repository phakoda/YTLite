/* Decompiled from supplied 5.2.2 arm package. VA 0x24deb0. FUN_0024deb0 */

void FUN_0024deb0(long param_1,int param_2,ulong param_3,void *param_4)

{
  _memcpy(param_4,(void *)(param_1 + (long)(param_2 - (int)param_3) * 2),
          -(param_3 >> 0x1f & 1) & 0xfffffffe00000000 | (param_3 & 0xffffffff) << 1);
  return;
}


