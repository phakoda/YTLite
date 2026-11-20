/* Decompiled from supplied 5.2.2 arm package. VA 0x246dec. FUN_00246dec */

int FUN_00246dec(int param_1,long param_2)

{
  short *psVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  
  lVar5 = 0;
  uVar3 = *(short *)(param_2 + 2) * 0x4000 + param_1 * 0x400;
  uVar7 = 0x1000000;
  while( true ) {
    uVar6 = uVar3;
    iVar2 = ((int)uVar6 >> 0x10) * param_1 +
            (((int)((uVar6 - (uVar6 & 0x10000)) * 0x8000) >> 0x10) * param_1 >> 0xf);
    if (lVar5 == 6) break;
    psVar1 = (short *)(param_2 + 4 + lVar5);
    lVar5 = lVar5 + 2;
    uVar3 = (iVar2 * 4 - uVar7) + *psVar1 * 0x4000;
    uVar7 = uVar6;
  }
  uVar3 = (iVar2 * 2 - uVar7) + *(short *)(param_2 + 10) * 0x2000;
  if ((int)uVar3 < 0x1fffc01) {
    if ((int)uVar3 < -0x2000000) {
      sVar4 = -0x8000;
    }
    else {
      sVar4 = (short)(uVar3 >> 10);
    }
  }
  else {
    sVar4 = 0x7fff;
  }
  return (int)sVar4;
}


