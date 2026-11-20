/* Decompiled from supplied 5.2.2 arm package. VA 0x27ef30. FUN_0027ef30 */

void FUN_0027ef30(uint *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 4);
  while (param_2 != 0) {
    uVar1 = param_1[1];
    if (uVar1 < *param_1) {
      uVar2 = *param_1 - uVar1;
      if (param_2 <= uVar2) {
        uVar2 = param_2;
      }
      uVar3 = -(ulong)(uVar2 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar2 << 2;
      _memcpy((void *)(lVar4 + (ulong)uVar1 * 4),param_3,uVar3);
      _bzero(param_4,uVar3);
      param_1[1] = param_1[1] + uVar2;
      param_2 = param_2 - uVar2;
      param_4 = param_4 + (int)uVar2;
      param_3 = param_3 + (int)uVar2;
    }
    else {
      *param_4 = *(undefined4 *)(lVar4 + (ulong)param_1[2] * 4);
      *(undefined4 *)(lVar4 + (ulong)param_1[2] * 4) = *param_3;
      param_2 = param_2 - 1;
      uVar1 = 0;
      if (param_1[2] + 1 < *param_1) {
        uVar1 = param_1[2] + 1;
      }
      param_1[2] = uVar1;
      param_4 = param_4 + 1;
      param_3 = param_3 + 1;
    }
  }
  return;
}


