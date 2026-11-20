/* Decompiled from supplied 5.2.2 arm package. VA 0x24e008. FUN_0024e008 */

int FUN_0024e008(uint param_1,uint param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_2 & 0xffff) == 0) {
    param_2 = 0;
    iVar3 = -1;
  }
  else {
    sVar1 = 0;
    if (param_2 != 0) {
      sVar1 = (short)(0x1fffffff / (int)param_2);
    }
    iVar3 = (int)sVar1;
  }
  uVar2 = (iVar3 * param_2 + (iVar3 * param_3 >> 0xf)) * -2 + 0x7fffffff;
  iVar3 = ((int)uVar2 >> 0x10) * iVar3 +
          (((int)((uVar2 - (uVar2 & 0x10000)) * 0x8000) >> 0x10) * iVar3 >> 0xf);
  uVar2 = iVar3 * 2;
  iVar3 = iVar3 * 2 >> 0x10;
  return (iVar3 * ((int)param_1 >> 0x10) +
          (iVar3 * ((int)((param_1 - (param_1 & 0x10000)) * 0x8000) >> 0x10) >> 0xf) +
         (((int)((uVar2 - (uVar2 & 0x10000)) * 0x8000) >> 0x10) * ((int)param_1 >> 0x10) >> 0xf)) *
         8;
}


