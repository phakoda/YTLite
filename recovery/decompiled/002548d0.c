/* Decompiled from supplied 5.2.2 arm package. VA 0x2548d0. _av_vbprintf */

void _av_vbprintf(long *param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  
  while( true ) {
    uVar1 = *(uint *)(param_1 + 1);
    uVar2 = *(uint *)((long)param_1 + 0xc);
    uVar3 = uVar2;
    if (uVar1 <= uVar2) {
      uVar3 = uVar1;
    }
    uVar2 = uVar2 - uVar3;
    if (uVar2 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = *param_1 + (ulong)uVar1;
    }
    uVar3 = ___vsnprintf_chk(lVar5,uVar2,0,0xffffffffffffffff,param_2);
    if ((int)uVar3 < 1) break;
    if ((uVar3 < uVar2) || (iVar4 = FUN_00254704(param_1,uVar3), iVar4 != 0)) {
      FUN_00254898(param_1,uVar3);
      return;
    }
  }
  return;
}


