/* Decompiled from supplied 5.2.2 arm package. VA 0x249904. FUN_00249904 */

int FUN_00249904(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = -param_2;
  if (-1 < param_2) {
    iVar1 = param_2;
  }
  iVar2 = 0x666;
  if (0x665 < (short)iVar1) {
    iVar2 = (int)(short)iVar1;
  }
  return (int)(short)(*(short *)((&PTR_DAT_01063740)[param_3] + (long)param_1 * 2) * iVar2 + 0x2000U
                     >> 0xe);
}


