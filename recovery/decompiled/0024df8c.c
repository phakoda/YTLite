/* Decompiled from supplied 5.2.2 arm package. VA 0x24df8c. FUN_0024df8c */

int FUN_0024df8c(int param_1,uint param_2)

{
  short sVar1;
  
  if ((param_2 & 0xffff) == 0) {
    sVar1 = 0x7fff;
  }
  else {
    sVar1 = 0;
    if (param_2 != 0) {
      sVar1 = (short)(param_1 / (int)param_2);
    }
  }
  return (int)sVar1;
}


