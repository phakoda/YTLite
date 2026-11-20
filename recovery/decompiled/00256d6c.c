/* Decompiled from supplied 5.2.2 arm package. VA 0x256d6c. FUN_00256d6c */

ulong FUN_00256d6c(undefined8 param_1,long param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  undefined *puVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  
  uVar4 = 0xf;
  if (param_3 == 0) {
    uVar4 = 0;
  }
  uVar3 = FUN_00256d3c(param_1,&DAT_00c50740,0x40);
  for (uVar11 = 0; uVar11 != 0x10; uVar11 = uVar11 + 1) {
    uVar5 = 0;
    uVar6 = *(ulong *)(param_2 + (long)(int)(uVar11 ^ uVar4) * 8);
    puVar8 = &DAT_00c50860;
    uVar7 = (uint)uVar3 >> 0x1f | (uint)uVar3 << 1;
    lVar9 = 8;
    while (lVar9 = lVar9 + -1, -1 < lVar9) {
      uVar10 = (ulong)uVar7;
      pbVar1 = puVar8 + ((uVar10 ^ uVar6) >> 1 & 0x1f);
      uVar7 = uVar7 >> 4 | uVar7 << 0x1c;
      puVar8 = puVar8 + -0x20;
      bVar2 = *pbVar1;
      if (((uVar10 ^ uVar6) & 1) != 0) {
        bVar2 = *pbVar1 >> 4;
      }
      uVar5 = ((ulong)bVar2 << 0x20 | uVar5) >> 4 & 0xffffffff;
      uVar6 = uVar6 >> 6;
    }
    uVar5 = FUN_00256d3c(uVar5,&DAT_00c50880,0x20);
    uVar3 = uVar5 & 0xffffffff ^ (uVar3 >> 0x20 | uVar3 << 0x20);
  }
  uVar5 = 0;
  uVar3 = uVar3 >> 0x20 | uVar3 << 0x20;
  for (lVar9 = 0x3f; (int)lVar9 != -1; lVar9 = lVar9 + -1) {
    uVar6 = uVar3 & 1;
    uVar3 = uVar3 >> 1;
    uVar5 = uVar6 << ((ulong)(byte)(&DAT_00c50740)[lVar9] & 0x3f) | uVar5;
  }
  return uVar5;
}


