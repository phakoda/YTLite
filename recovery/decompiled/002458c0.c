/* Decompiled from supplied 5.2.2 arm package. VA 0x2458c0. FUN_002458c0 */

void FUN_002458c0(short *param_1,short *param_2,long param_3,long param_4,short *param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  undefined1 auStack_64 [2];
  short local_62;
  
  for (lVar5 = 0; lVar5 != 2; lVar5 = lVar5 + 1) {
    for (iVar6 = 0; iVar6 < *(short *)(param_4 + lVar5 * 2); iVar6 = iVar6 + 1) {
      FUN_0024e20c(param_1,param_1,param_3,0xb,1);
      iVar4 = (int)*param_2 - (int)*param_1;
      iVar3 = iVar4 * 4;
      iVar2 = -0x8000;
      if (-0x8001 < iVar3) {
        iVar2 = iVar3;
      }
      if (iVar4 < -0x1d99) {
        local_62 = 0;
      }
      else if (iVar4 < 0x1fd8) {
        sVar1 = 0x7fff;
        if (iVar3 < 0x8000) {
          sVar1 = (short)iVar2;
        }
        FUN_0024c308(auStack_64,&local_62,(int)sVar1,&DAT_00c4f316,8);
      }
      else {
        local_62 = 7;
      }
      *param_5 = local_62;
      *param_1 = (*param_2 - (short)iVar4) +
                 (short)((int)*(short *)(&DAT_00c4f316 + (long)local_62 * 2) + 2U >> 2);
      param_5 = param_5 + 1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
    param_3 = param_3 + 0x16;
  }
  return;
}


