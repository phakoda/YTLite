/* Decompiled from supplied 5.2.2 arm package. VA 0x250d60. _av_aes_ctr_crypt */

void _av_aes_ctr_crypt(undefined8 *param_1,byte *param_2,byte *param_3,int param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  
  pbVar1 = param_3 + param_4;
  while (param_3 < pbVar1) {
    iVar3 = *(int *)(param_1 + 5);
    if (iVar3 == 0) {
      _av_aes_crypt(*param_1,param_1 + 3,param_1 + 1,1,0,0);
      FUN_00250d3c(param_1 + 2);
      iVar3 = *(int *)(param_1 + 5);
    }
    pbVar4 = param_3 + (0x10 - (long)iVar3);
    iVar5 = (int)pbVar1;
    pbVar2 = pbVar1;
    if (pbVar4 <= pbVar1) {
      iVar5 = (int)pbVar4;
      pbVar2 = pbVar4;
    }
    *(uint *)(param_1 + 5) = (iVar3 - (int)param_3) + iVar5 & 0xf;
    pbVar4 = (byte *)((long)param_1 + (long)iVar3 + 0x18);
    for (; param_3 < pbVar2; param_3 = param_3 + 1) {
      *param_2 = *pbVar4 ^ *param_3;
      pbVar4 = pbVar4 + 1;
      param_2 = param_2 + 1;
    }
  }
  return;
}


