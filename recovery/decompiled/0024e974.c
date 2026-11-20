/* Decompiled from supplied 5.2.2 arm package. VA 0x24e974. FUN_0024e974 */

int FUN_0024e974(short *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  
  sVar2 = -0x8000;
  if ((param_1 != (short *)0x0) && (0 < param_2)) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      sVar1 = *param_1;
      if (*param_1 <= sVar2) {
        sVar1 = sVar2;
      }
      sVar2 = sVar1;
      param_1 = param_1 + 1;
    }
  }
  return (int)sVar2;
}


