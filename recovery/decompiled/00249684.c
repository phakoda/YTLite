/* Decompiled from supplied 5.2.2 arm package. VA 0x249684. FUN_00249684 */

void FUN_00249684(long param_1,long param_2,int param_3,int param_4)

{
  long lVar1;
  
  lVar1 = param_2 + (long)param_3 * 2;
  thunk_FUN_0024de70(lVar1,0,4);
  thunk_FUN_0024de70(param_2 + -8,0,4);
  thunk_FUN_0024de70(param_1,0,param_3 - param_4);
  FUN_0024e304(lVar1 + 8 + (long)param_4 * -2,param_1 + (long)param_3 * 2 + (long)param_4 * -2,
               &DAT_00c4f528,8,param_4);
  return;
}


