/* Decompiled from supplied 5.2.2 arm package. VA 0x24e8e4. FUN_0024e8e4 */

int FUN_0024e8e4(short *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = -1;
  if ((param_1 != (short *)0x0) && (0 < param_2)) {
    iVar2 = 0;
    for (; param_2 != 0; param_2 = param_2 + -1) {
      sVar1 = *param_1;
      iVar3 = -(int)sVar1;
      if (-1 < sVar1) {
        iVar3 = (int)sVar1;
      }
      if (iVar3 <= iVar2) {
        iVar3 = iVar2;
      }
      param_1 = param_1 + 1;
      iVar2 = iVar3;
    }
    iVar3 = 0x7fff;
    if (iVar2 < 0x8000) {
      iVar3 = iVar2;
    }
    sVar1 = (short)iVar3;
  }
  return (int)sVar1;
}


