/* Decompiled from supplied 5.2.2 arm package. VA 0x274e20. FUN_00274e20 */

int FUN_00274e20(int param_1)

{
  int iVar1;
  
  iVar1 = _pthread_once((pthread_once_t *)((long)param_1 * 0x18 + 0x11d3408),
                        (&PTR_FUN_011d3400)[(long)param_1 * 3]);
  return iVar1;
}


