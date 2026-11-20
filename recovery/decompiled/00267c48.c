/* Decompiled from supplied 5.2.2 arm package. VA 0x267c48. _av_read_image_line2 */

void _av_read_image_line2
               (uint *param_1,long param_2,long param_3,long param_4,int param_5,int param_6,
               int param_7,int param_8,undefined8 param_9)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  byte *pbVar9;
  uint *puVar10;
  uint uVar11;
  ulong uVar12;
  
  lVar2 = param_4 + (long)param_7 * 0x20;
  lVar3 = (long)*(int *)(lVar2 + 0x18);
  iVar4 = *(int *)(lVar2 + 0x1c);
  uVar8 = *(uint *)(lVar2 + 0x28);
  uVar12 = *(ulong *)(param_4 + 0x10);
  uVar5 = (int)(1L << ((ulong)uVar8 & 0x3f)) - 1;
  if (((uint)uVar12 >> 2 & 1) != 0) {
    uVar11 = *(int *)(lVar2 + 0x20) + iVar4 * param_5;
    pbVar9 = (byte *)(*(long *)(param_2 + lVar3 * 8) +
                      (long)*(int *)(param_3 + lVar3 * 4) * (long)param_6 + (long)((int)uVar11 >> 3)
                     );
    uVar8 = (8 - uVar8) - (uVar11 & 7);
    puVar7 = param_1;
    do {
      param_8 = -param_8;
      while( true ) {
        param_8 = param_8 + 1;
        if (param_8 == 1) {
          return;
        }
        uVar11 = *pbVar9 >> (ulong)(uVar8 & 0x1f) & uVar5;
        if ((int)param_9 != 0) {
          uVar11 = (uint)*(byte *)(*(long *)(param_2 + 8) + (long)(int)(param_7 + uVar11 * 4));
        }
        uVar6 = uVar8 - iVar4;
        uVar8 = uVar6 & 7;
        pbVar9 = pbVar9 + -(long)((int)uVar6 >> 3);
        if (param_9._4_4_ == 4) break;
        *(short *)param_1 = (short)uVar11;
        param_1 = (uint *)((long)param_1 + 2);
      }
      *puVar7 = uVar11;
      param_8 = -param_8;
      puVar7 = puVar7 + 1;
    } while( true );
  }
  uVar11 = *(uint *)(lVar2 + 0x24);
  iVar1 = uVar8 + uVar11;
  puVar7 = (uint *)(*(long *)(param_2 + lVar3 * 8) +
                    (long)*(int *)(param_3 + lVar3 * 4) * (long)param_6 + (long)(iVar4 * param_5) +
                   (long)*(int *)(lVar2 + 0x20));
  puVar10 = (uint *)((long)puVar7 + (uVar12 & 1));
  if (8 < iVar1) {
    puVar10 = puVar7;
  }
  puVar7 = param_1;
  do {
    param_8 = -param_8;
    while( true ) {
      param_8 = param_8 + 1;
      if (param_8 == 1) {
        return;
      }
      if (iVar1 < 9) {
        uVar8 = (uint)(byte)*puVar10;
      }
      else if (iVar1 < 0x11) {
        uVar8 = (uint)(ushort)*puVar10;
        if ((uVar12 & 1) != 0) {
          uVar8 = (uint)(ushort)((ushort)*puVar10 >> 8) | (uVar8 & 0xff00ff) << 8;
        }
      }
      else {
        uVar8 = *puVar10;
        if ((uVar12 & 1) != 0) {
          uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
          uVar8 = uVar8 >> 0x10 | uVar8 << 0x10;
        }
      }
      uVar8 = uVar8 >> (ulong)(uVar11 & 0x1f) & uVar5;
      if ((int)param_9 != 0) {
        uVar8 = (uint)*(byte *)(*(long *)(param_2 + 8) + (ulong)(param_7 + uVar8 * 4));
      }
      puVar10 = (uint *)((long)puVar10 + (long)iVar4);
      if (param_9._4_4_ == 4) break;
      *(short *)param_1 = (short)uVar8;
      param_1 = (uint *)((long)param_1 + 2);
    }
    *puVar7 = uVar8;
    param_8 = -param_8;
    puVar7 = puVar7 + 1;
  } while( true );
}


