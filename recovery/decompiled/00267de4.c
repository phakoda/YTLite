/* Decompiled from supplied 5.2.2 arm package. VA 0x267de4. _av_write_image_line2 */

void _av_write_image_line2
               (uint *param_1,long param_2,long param_3,long param_4,int param_5,int param_6,
               int param_7,uint param_8,int param_9)

{
  int iVar1;
  long lVar2;
  uint *puVar3;
  long lVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  byte *pbVar9;
  uint uVar10;
  ulong uVar11;
  uint uVar12;
  ushort uVar13;
  uint uVar14;
  
  lVar2 = param_4 + (long)param_7 * 0x20;
  lVar4 = (long)*(int *)(lVar2 + 0x18);
  iVar5 = *(int *)(lVar2 + 0x1c);
  uVar11 = *(ulong *)(param_4 + 0x10);
  if (((uint)uVar11 >> 2 & 1) == 0) {
    uVar10 = *(uint *)(lVar2 + 0x24);
    iVar1 = *(int *)(lVar2 + 0x28) + uVar10;
    puVar6 = (uint *)(*(long *)(param_2 + lVar4 * 8) +
                      (long)*(int *)(param_3 + lVar4 * 4) * (long)param_6 + (long)(iVar5 * param_5)
                     + (long)*(int *)(lVar2 + 0x20));
    if (iVar1 < 9) {
      param_8 = ~param_8;
      puVar7 = param_1;
      pbVar9 = (byte *)((long)puVar6 + (uVar11 & 1));
      while (param_8 = param_8 + 1, param_8 != 0) {
        if (param_9 == 4) {
          uVar12 = *param_1;
          puVar6 = puVar7;
          param_1 = param_1 + 1;
        }
        else {
          puVar6 = (uint *)((long)puVar7 + 2);
          uVar12 = (uint)(ushort)*puVar7;
        }
        *pbVar9 = *pbVar9 | (byte)(uVar12 << (ulong)(uVar10 & 0x1f));
        puVar7 = puVar6;
        pbVar9 = pbVar9 + iVar5;
      }
    }
    else {
      param_8 = ~param_8;
      puVar7 = param_1;
      while (param_8 = param_8 + 1, param_8 != 0) {
        puVar3 = (uint *)((long)puVar6 + (long)iVar5);
        if (param_9 == 4) {
          uVar12 = *param_1;
          puVar8 = puVar7;
          param_1 = param_1 + 1;
        }
        else {
          puVar8 = (uint *)((long)puVar7 + 2);
          uVar12 = (uint)(ushort)*puVar7;
        }
        puVar7 = puVar8;
        if (iVar1 < 0x11) {
          uVar13 = (ushort)*puVar6;
          if ((uVar11 & 1) == 0) {
            uVar13 = uVar13 | (ushort)(uVar12 << (ulong)(uVar10 & 0x1f));
          }
          else {
            uVar12 = (uint)(uVar13 >> 8) | (uVar13 & 0xff00ff) << 8 |
                     uVar12 << (ulong)(uVar10 & 0x1f) & 0xffff;
            uVar13 = (ushort)(uVar12 >> 8) | (ushort)((uVar12 & 0xff00ff) << 8);
          }
          *(ushort *)puVar6 = uVar13;
          puVar6 = puVar3;
        }
        else {
          uVar14 = *puVar6;
          if ((uVar11 & 1) == 0) {
            uVar14 = uVar14 | uVar12 << (ulong)(uVar10 & 0x1f);
          }
          else {
            uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
            uVar12 = uVar14 >> 0x10 | uVar14 << 0x10 | uVar12 << (ulong)(uVar10 & 0x1f);
            uVar12 = (uVar12 & 0xff00ff00) >> 8 | (uVar12 & 0xff00ff) << 8;
            uVar14 = uVar12 >> 0x10 | uVar12 << 0x10;
          }
          *puVar6 = uVar14;
          puVar6 = puVar3;
        }
      }
    }
  }
  else {
    uVar12 = *(int *)(lVar2 + 0x20) + iVar5 * param_5;
    uVar10 = (8 - *(int *)(lVar2 + 0x28)) - (uVar12 & 7);
    pbVar9 = (byte *)(*(long *)(param_2 + lVar4 * 8) +
                      (long)*(int *)(param_3 + lVar4 * 4) * (long)param_6 + (long)((int)uVar12 >> 3)
                     );
    param_8 = ~param_8;
    puVar6 = param_1;
    while (param_8 = param_8 + 1, param_8 != 0) {
      if (param_9 == 4) {
        uVar12 = *param_1;
        puVar7 = puVar6;
        param_1 = param_1 + 1;
      }
      else {
        puVar7 = (uint *)((long)puVar6 + 2);
        uVar12 = (uint)(ushort)*puVar6;
      }
      *pbVar9 = *pbVar9 | (byte)(uVar12 << (ulong)(uVar10 & 0x1f));
      pbVar9 = pbVar9 + -(long)((int)(uVar10 - iVar5) >> 3);
      uVar10 = uVar10 - iVar5 & 7;
      puVar6 = puVar7;
    }
  }
  return;
}


