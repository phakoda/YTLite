/* Decompiled from supplied 5.2.2 arm package. VA 0x261398. _av_compare_mod */

long _av_compare_mod(long param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  
  uVar1 = param_3 - 1 & param_1 - param_2;
  if (uVar1 <= param_3 >> 1) {
    param_3 = 0;
  }
  return uVar1 - param_3;
}


