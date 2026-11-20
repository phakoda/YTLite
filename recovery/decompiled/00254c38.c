/* Decompiled from supplied 5.2.2 arm package. VA 0x254c38. _av_bprint_get_buffer */

void _av_bprint_get_buffer(long *param_1,uint param_2,long *param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 1);
  uVar2 = *(uint *)((long)param_1 + 0xc);
  uVar1 = uVar2;
  if (uVar4 <= uVar2) {
    uVar1 = uVar4;
  }
  if (uVar2 - uVar1 < param_2) {
    FUN_00254704(param_1);
    uVar4 = *(uint *)(param_1 + 1);
    uVar2 = *(uint *)((long)param_1 + 0xc);
  }
  uVar1 = uVar2;
  if (uVar4 <= uVar2) {
    uVar1 = uVar4;
  }
  *param_4 = uVar2 - uVar1;
  if (uVar2 - uVar1 == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = *param_1 + (ulong)*(uint *)(param_1 + 1);
  }
  *param_3 = lVar3;
  return;
}


