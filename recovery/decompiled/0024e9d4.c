/* Decompiled from supplied 5.2.2 arm package. VA 0x24e9d4. FUN_0024e9d4 */

int FUN_0024e9d4(short *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  
  sVar2 = 0x7fff;
  if ((param_1 != (short *)0x0) && (0 < param_2)) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      sVar1 = *param_1;
      if (sVar2 <= *param_1) {
        sVar1 = sVar2;
      }
      param_1 = param_1 + 1;
      sVar2 = sVar1;
    }
  }
  return (int)sVar2;
}


