/* Decompiled from supplied 5.2.2 arm package. VA 0x260b74. _av_lzo1x_decode */

uint _av_lzo1x_decode(long param_1,int *param_2,byte *param_3,int *param_4)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *local_70;
  byte *local_68;
  long local_60;
  long local_58;
  long local_50;
  uint local_48;
  
  iVar3 = *param_4;
  iVar4 = *param_2;
  if (iVar4 < 1 || iVar3 < 1) {
    local_48 = (uint)(iVar3 < 1) | (uint)(iVar4 < 1) << 1;
  }
  else {
    local_68 = param_3 + iVar3;
    local_50 = param_1 + iVar4;
    local_70 = param_3 + 1;
    local_48 = 0;
    bVar1 = *param_3;
    uVar7 = (uint)bVar1;
    local_60 = param_1;
    local_58 = param_1;
    if (0x11 < bVar1) {
      FUN_00260e84(&local_70,bVar1 - 0x11);
      pbVar6 = local_70 + 1;
      bVar1 = *local_70;
      uVar7 = (uint)bVar1;
      local_70 = pbVar6;
      if (bVar1 < 0x10) {
        local_48 = local_48 | 8;
      }
    }
    pbVar6 = local_70;
    if (local_70 <= local_68) goto LAB_00260c3c;
    uVar9 = 0;
    local_48 = local_48 | 1;
    while (pbVar6 = local_70, local_48 == 0) {
      if (uVar7 < 0x10) {
        if (uVar9 != 0) {
          iVar4 = (uint)*local_70 * 4 + ((int)uVar7 >> 2);
          iVar3 = 2;
          local_70 = local_70 + 1;
LAB_00260d38:
          uVar9 = iVar4 + 1;
          goto LAB_00260d40;
        }
        iVar3 = FUN_00260f8c(&local_70,uVar7,0xf);
        FUN_00260e84(&local_70,iVar3 + 3);
        uVar7 = (uint)*local_70;
        pbVar6 = local_70 + 1;
        if (uVar7 < 0x10) {
          iVar4 = ((uint)local_70[1] << 2 | 0x800) + (uint)(*local_70 >> 2);
          iVar3 = 3;
          local_70 = local_70 + 2;
          goto LAB_00260d38;
        }
LAB_00260c3c:
        local_70 = pbVar6;
        uVar9 = 0;
      }
      else {
        if (uVar7 < 0x40) {
          if (0x1f < uVar7) {
            iVar3 = FUN_00260f8c(&local_70,uVar7,0x1f);
            uVar7 = (uint)*local_70;
            uVar9 = (uint)(*local_70 >> 2) | (uint)local_70[1] << 6;
            local_70 = local_70 + 2;
            goto LAB_00260cd0;
          }
          iVar3 = FUN_00260f8c(&local_70,uVar7,7);
          uVar8 = (uint)*local_70;
          pbVar6 = local_70 + 2;
          uVar9 = (uVar7 & 8) * 0x800 + 0x4000 | (uint)(*local_70 >> 2) | (uint)local_70[1] << 6;
          local_70 = pbVar6;
          if (uVar9 == 0x4000) {
            if (iVar3 != 1) {
              local_48 = local_48 | 8;
            }
            break;
          }
        }
        else {
          iVar3 = ((int)uVar7 >> 5) + -1;
          uVar9 = uVar7 >> 2 & 7 | (uint)*local_70 << 3;
          local_70 = local_70 + 1;
LAB_00260cd0:
          uVar9 = uVar9 + 1;
          uVar8 = uVar7;
        }
        if (iVar3 < -1) {
          _av_log(0,0,"Assertion %s failed at %s:%d\n");
                    /* WARNING: Subroutine does not return */
          _abort();
        }
        iVar3 = iVar3 + 2;
        uVar7 = uVar8;
LAB_00260d40:
        lVar2 = local_58;
        if (local_58 - local_60 < (long)(int)uVar9) {
          local_48 = local_48 | 4;
        }
        else {
          lVar5 = local_50 - local_58;
          if (lVar5 < iVar3) {
            iVar3 = (int)lVar5;
            if (lVar5 < 1) {
              iVar3 = 0;
            }
            local_48 = local_48 | 2;
          }
          _av_memcpy_backptr(local_58,uVar9,iVar3);
          local_58 = lVar2 + iVar3;
        }
        uVar9 = uVar7 & 3;
        FUN_00260e84(&local_70,uVar9);
        uVar7 = (uint)*local_70;
        local_70 = local_70 + 1;
      }
    }
    iVar3 = 0;
    if (pbVar6 <= local_68) {
      iVar3 = (int)local_68 - (int)pbVar6;
    }
    *param_4 = iVar3;
    *param_2 = (int)local_50 - (int)local_58;
  }
  return local_48;
}


