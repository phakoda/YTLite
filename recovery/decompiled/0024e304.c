/* Decompiled from supplied 5.2.2 arm package. VA 0x24e304. FUN_0024e304 */

void FUN_0024e304(long param_1,undefined2 *param_2,long param_3,int param_4,int param_5)

{
  undefined2 uVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  short *psVar6;
  
  for (lVar3 = 0; lVar3 < param_5; lVar3 = lVar3 + 1) {
    iVar4 = 0;
    psVar6 = (short *)(param_1 + lVar3 * 2);
    for (lVar5 = 0; (int)lVar5 < param_4; lVar5 = lVar5 + 1) {
      iVar4 = iVar4 + (int)*psVar6 * (int)*(short *)(param_3 + lVar5 * 2);
      psVar6 = psVar6 + -1;
    }
    iVar2 = -0x8000000;
    if (-0x8000001 < iVar4) {
      iVar2 = iVar4;
    }
    uVar1 = 0x7fff;
    if (iVar4 < 0x7fff800) {
      uVar1 = (short)(iVar2 + 0x800U >> 0xc);
    }
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}


