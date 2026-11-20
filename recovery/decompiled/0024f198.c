/* Decompiled from supplied 5.2.2 arm package. VA 0x24f198. FUN_0024f198 */

void FUN_0024f198(long param_1,long param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  long lVar4;
  
  for (lVar4 = 0; (int)lVar4 < param_4; lVar4 = lVar4 + 1) {
    iVar1 = *(short *)(param_1 + lVar4 * 2) * param_3 >> (param_5 & 0x1f);
    iVar3 = iVar1;
    if (iVar1 < -0x7fff) {
      iVar3 = -0x8000;
    }
    uVar2 = 0x7fff;
    if (iVar1 < 0x8000) {
      uVar2 = (short)iVar3;
    }
    *(undefined2 *)(param_2 + lVar4 * 2) = uVar2;
  }
  return;
}


