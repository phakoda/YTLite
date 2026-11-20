/* Decompiled from supplied 5.2.2 arm package. VA 0x279628. FUN_00279628 */

int FUN_00279628(int param_1)

{
  int iVar1;
  
  iVar1 = _pthread_once((pthread_once_t *)((long)param_1 * 0x18 + 0x11d35b8),
                        (&PTR_FUN_011d35b0)[(long)param_1 * 3]);
  return iVar1;
}


