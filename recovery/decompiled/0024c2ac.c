/* Decompiled from supplied 5.2.2 arm package. VA 0x24c2ac. FUN_0024c2ac */

int FUN_0024c2ac(long param_1,long param_2,long param_3,int param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  for (lVar3 = 0; lVar3 != 0xa0; lVar3 = lVar3 + 2) {
    *(short *)(param_1 + lVar3) = (short)(*(short *)(param_3 + lVar3) * param_4 + 0x400U >> 0xb);
  }
  iVar2 = 0;
  for (lVar3 = 0; lVar3 != 0xa0; lVar3 = lVar3 + 2) {
    iVar1 = (int)*(short *)(param_2 + lVar3) - (int)*(short *)(param_1 + lVar3) >> 3;
    iVar2 = iVar2 + iVar1 * iVar1;
  }
  return iVar2;
}


