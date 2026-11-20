/* Decompiled from supplied 5.2.2 arm package. VA 0x260f8c. FUN_00260f8c */

uint FUN_00260f8c(long *param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  
  param_2 = param_3 & param_2;
  if (param_2 == 0) {
    iVar1 = 0;
    pbVar3 = (byte *)*param_1;
    while (pbVar3 < (byte *)param_1[1]) {
      *param_1 = (long)(pbVar3 + 1);
      uVar2 = (uint)*pbVar3;
      if (*pbVar3 != 0) goto LAB_00260ff4;
      if (0x7ffffc16 < iVar1) {
        uVar2 = 0;
        *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) | 8;
        goto LAB_00260ff4;
      }
      iVar1 = iVar1 + 0xff;
      pbVar3 = pbVar3 + 1;
    }
    *(uint *)(param_1 + 5) = *(uint *)(param_1 + 5) | 1;
    uVar2 = 1;
LAB_00260ff4:
    param_2 = uVar2 + param_3 + iVar1;
  }
  return param_2;
}


