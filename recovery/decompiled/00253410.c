/* Decompiled from supplied 5.2.2 arm package. VA 0x253410. FUN_00253410 */

ulong FUN_00253410(long *param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  byte local_21;
  
  lVar3 = param_1[1];
  lVar4 = param_1[2];
  lVar1 = (lVar4 - lVar3) + param_1[6];
  if ((param_1[5] == 0) || (lVar1 < param_1[5])) {
    param_1[2] = lVar3 + *param_1;
    param_1[3] = lVar3 + *param_1;
    lVar3 = (*(code *)param_1[8])(param_1,&local_21,1);
    uVar2 = (uint)local_21;
    if (lVar3 != 1) {
      uVar2 = 0xffffffff;
    }
    if (-1 < (int)uVar2) {
      lVar3 = param_1[3];
      if (param_1[5] == 0) {
        lVar4 = param_1[2];
      }
      else {
        lVar4 = param_1[2];
        lVar5 = param_1[5] - (lVar1 + 1);
        if (lVar5 < lVar3 - lVar4) {
          lVar3 = lVar4 + lVar5;
        }
      }
      param_1[4] = lVar3;
      param_1[6] = (param_1[1] + lVar1 + 1) - lVar4;
      if (*(byte *)(lVar4 + -1) == uVar2) {
        return (ulong)local_21;
      }
      *(char *)(lVar4 + -1) = (char)uVar2;
      return (ulong)local_21;
    }
    lVar3 = param_1[1];
    lVar4 = param_1[2];
  }
  param_1[4] = 0;
  param_1[6] = (lVar3 + lVar1) - lVar4;
  return 0xffffffff;
}


