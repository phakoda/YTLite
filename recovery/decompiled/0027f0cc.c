/* Decompiled from supplied 5.2.2 arm package. VA 0x27f0cc. FUN_0027f0cc */

void FUN_0027f0cc(uint *param_1,uint param_2,undefined8 *param_3,undefined8 *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 4);
  while (param_2 != 0) {
    uVar1 = *param_1;
    uVar2 = param_1[1];
    if (uVar2 < uVar1) {
      uVar3 = uVar1 - uVar2;
      if (param_2 <= uVar1 - uVar2) {
        uVar3 = param_2;
      }
      uVar4 = -(ulong)(uVar3 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar3 << 3;
      _memcpy((void *)(lVar5 + (ulong)uVar2 * 8),param_3,uVar4);
      _bzero(param_4,uVar4);
      param_1[1] = param_1[1] + uVar3;
      param_2 = param_2 - uVar3;
      param_4 = param_4 + (int)uVar3;
      param_3 = param_3 + (int)uVar3;
    }
    else {
      uVar3 = param_1[2];
      param_2 = param_2 - 1;
      *param_4 = *(undefined8 *)(lVar5 + (ulong)uVar3 * 8);
      uVar2 = 0;
      if (uVar3 + 1 < uVar1) {
        uVar2 = uVar3 + 1;
      }
      *(undefined8 *)(lVar5 + (ulong)uVar3 * 8) = *param_3;
      param_1[2] = uVar2;
      param_4 = param_4 + 1;
      param_3 = param_3 + 1;
    }
  }
  return;
}


