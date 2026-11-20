/* Decompiled from supplied 5.2.2 arm package. VA 0x248a04. FUN_00248a04 */

void FUN_00248a04(long param_1,int param_2)

{
  undefined2 uVar1;
  long lVar2;
  short sVar3;
  
  for (lVar2 = 0; (int)lVar2 < param_2; lVar2 = lVar2 + 1) {
    sVar3 = *(short *)(param_1 + lVar2 * 2);
    if (sVar3 < 0x4001) {
      sVar3 = 0x4000;
    }
    *(short *)(param_1 + lVar2 * 2) = sVar3;
  }
  for (lVar2 = 0; (int)lVar2 < param_2; lVar2 = lVar2 + 1) {
    uVar1 = FUN_0024df78(0x1fffffff,(long)*(short *)(param_1 + lVar2 * 2));
    *(undefined2 *)(param_1 + lVar2 * 2) = uVar1;
  }
  return;
}


