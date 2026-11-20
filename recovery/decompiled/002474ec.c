/* Decompiled from supplied 5.2.2 arm package. VA 0x2474ec. FUN_002474ec */

void FUN_002474ec(long param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  void *pvVar2;
  void *pvVar3;
  long lVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  ushort uVar8;
  short sVar9;
  int iVar10;
  
  lVar1 = param_1 + 0x2d8;
  pvVar2 = (void *)(param_1 + 0x6a);
  sVar6 = 0x50 - *(short *)(param_1 + 0xe);
  sVar9 = 0;
  if (*(short *)(param_2 + 0x4a) != 1) {
    sVar9 = sVar6;
  }
  uVar8 = (sVar9 + *(short *)(param_2 + 0xc2) * 0x28) - 0x28;
  FUN_0024c41c((long)*(short *)(param_2 + 0x48),param_2 + 0x4c,
               param_4 + ((long)*(short *)(param_2 + 0xc2) * 0xb00000000 + -0xb00000000 >> 0x1f),
               param_3 + ((long)((ulong)uVar8 << 0x30) >> 0x2f));
  sVar9 = *(short *)(param_1 + 0xe);
  if (*(short *)(param_2 + 0x4a) == 0) {
    lVar4 = param_3 + (long)(int)(short)uVar8 * 2;
    FUN_0024de90(param_1 + 0x18e,lVar4,(int)sVar9);
    thunk_FUN_0024de70(pvVar2,0,(int)(short)(0x93 - sVar9));
    FUN_00245b34(lVar1,param_2 + 0xc,param_2 + 0x2a,param_1 + 0xe6,0x55,(int)sVar6);
    FUN_0024de90(lVar4 + -2,lVar1,(int)sVar6);
  }
  else {
    thunk_FUN_0024de70(pvVar2,0,(int)(short)(0x93 - sVar9));
    _memcpy((void *)(param_1 + (long)*(short *)(param_1 + 0xe) * -2 + 400),
            (void *)(param_3 + (long)(int)(short)uVar8 * 2),(long)*(short *)(param_1 + 0xe) << 1);
    FUN_00245b34(param_3 + (long)((int)*(short *)(param_1 + 0xe) + (int)(short)uVar8) * 2,
                 param_2 + 0xc,param_2 + 0x2a,param_1 + 0xe6,0x55,(int)sVar6);
  }
  uVar8 = *(ushort *)(param_2 + 0xc2);
  iVar7 = ((uint)*(ushort *)(param_1 + 4) - (uint)uVar8) * 0x10000 + -0x10000;
  if (iVar7 < 1) {
    sVar9 = 1;
  }
  else {
    thunk_FUN_0024de70(pvVar2,0,0x43);
    _memcpy((void *)(param_1 + 0xf0),
            (void *)(param_3 +
                    ((long)*(short *)(param_2 + 0xc2) * 0x2800000000 + -0x2800000000 >> 0x1f)),0xa0)
    ;
    iVar10 = 0;
    sVar9 = 1;
    while( true ) {
      uVar8 = *(ushort *)(param_2 + 0xc2);
      if (iVar7 >> 0x10 <= (int)(short)iVar10) break;
      iVar10 = (short)iVar10 + 1;
      lVar4 = param_2 + ((long)sVar9 * 0x300000000 >> 0x1f);
      FUN_00245b34(param_3 + (long)((iVar10 + (short)uVar8) * 0x28) * 2,lVar4 + 0xc,lVar4 + 0x2a,
                   pvVar2,0x93,0x28);
      _memmove(pvVar2,(void *)(param_1 + 0xba),0xd6);
      _memcpy((void *)(param_1 + 0x140),
              (void *)(param_3 + (long)((iVar10 + *(short *)(param_2 + 0xc2)) * 0x28) * 2),0x50);
      sVar9 = sVar9 + 1;
    }
  }
  iVar7 = (short)uVar8 + -1;
  if (iVar7 * 0x10000 < 1) {
    return;
  }
  iVar5 = ((1 - (short)uVar8) + (int)*(short *)(param_1 + 4)) * 0x280000;
  iVar10 = 0x93;
  if (iVar5 < 0x930001) {
    iVar10 = iVar5 >> 0x10;
  }
  FUN_0024de90(param_1 + 0x18e,param_3 + (long)(iVar7 * 0x28) * 2,iVar10);
  thunk_FUN_0024de70(pvVar2,0,(int)(short)(0x93 - (short)iVar10));
  for (iVar10 = 0; iVar10 = (int)(short)iVar10, iVar10 < (short)iVar7; iVar10 = iVar10 + 1) {
    pvVar3 = (void *)(param_1 + (long)iVar10 * 0x50 + 0x2d8);
    lVar4 = param_2 + ((long)sVar9 * 0x300000000 >> 0x1f);
    FUN_00245b34(pvVar3,lVar4 + 0xc,lVar4 + 0x2a,pvVar2,0x93,0x28);
    _memmove(pvVar2,(void *)(param_1 + 0xba),0xd6);
    _memcpy((void *)(param_1 + 0x140),pvVar3,0x50);
    sVar9 = sVar9 + 1;
  }
  FUN_0024de90(param_3 + (long)((short)iVar7 * 0x28) * 2 + -2,lVar1);
  return;
}


