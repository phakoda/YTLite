/* Decompiled from supplied 5.2.2 arm package. VA 0x27ed90. FUN_0027ed90 */

void FUN_0027ed90(uint *param_1,uint param_2,undefined1 *param_3,undefined1 *param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 4);
  while (param_2 != 0) {
    uVar1 = param_1[1];
    if (uVar1 < *param_1) {
      uVar2 = *param_1 - uVar1;
      if (param_2 <= uVar2) {
        uVar2 = param_2;
      }
      _memcpy((void *)(lVar3 + (ulong)uVar1),param_3,(long)(int)uVar2);
      _memset(param_4,0x80,(long)(int)uVar2);
      param_1[1] = param_1[1] + uVar2;
      param_2 = param_2 - uVar2;
      param_4 = param_4 + (int)uVar2;
      param_3 = param_3 + (int)uVar2;
    }
    else {
      *param_4 = *(undefined1 *)(lVar3 + (ulong)param_1[2]);
      *(undefined1 *)(lVar3 + (ulong)param_1[2]) = *param_3;
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


