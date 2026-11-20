/* Decompiled from supplied 5.2.2 arm package. VA 0x270df0. FUN_00270df0 */

int FUN_00270df0(int param_1)

{
  int iVar1;
  
  iVar1 = _pthread_once((pthread_once_t *)((long)param_1 * 0x18 + 0x11d3258),
                        (&PTR_FUN_011d3250)[(long)param_1 * 3]);
  return iVar1;
}


