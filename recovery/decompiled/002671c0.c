/* Decompiled from supplied 5.2.2 arm package. VA 0x2671c0. _av_small_strptime */

byte * _av_small_strptime(byte *param_1,byte *param_2,int *param_3)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  size_t sVar7;
  byte *pbVar8;
  undefined4 uVar9;
  undefined *puVar10;
  long lVar11;
  undefined4 uVar12;
  byte *local_68;
  
  local_68 = param_1;
LAB_00267214:
  pbVar2 = local_68;
  pbVar8 = param_2 + 1;
  bVar3 = *param_2;
  if (bVar3 != 0x25) {
    if (bVar3 == 0) {
      return local_68;
    }
    param_2 = pbVar8;
    if (((int)(char)bVar3 - 9U < 0x18) &&
       ((0x80001fU >> (ulong)((int)(char)bVar3 - 9U & 0x1f) & 1) != 0)) {
      do {
        local_68 = pbVar2;
        if ((*local_68 == 0) || (uVar4 = *local_68 - 9, 0x17 < uVar4)) break;
        pbVar2 = local_68 + 1;
      } while ((0x80001fU >> (ulong)(uVar4 & 0x1f) & 1) != 0);
    }
    else {
      if (*local_68 != bVar3) {
        return (byte *)0x0;
      }
      local_68 = local_68 + 1;
    }
    goto LAB_00267214;
  }
  bVar3 = param_2[1];
  param_2 = param_2 + 2;
  if ('S' < (char)bVar3) {
    if ((char)bVar3 < 'd') {
      if (bVar3 == 0x54) {
        local_68 = (byte *)_av_small_strptime(local_68,"%H:%M:%S",param_3);
        if (local_68 == (byte *)0x0) {
          return (byte *)0x0;
        }
      }
      else {
        if (bVar3 != 0x59) {
          if (bVar3 != 0x62) {
            return (byte *)0x0;
          }
          goto LAB_00267344;
        }
        iVar6 = FUN_002674f4(&local_68,0,&DAT_0000270f,4);
        if (iVar6 == -1) {
          return (byte *)0x0;
        }
        param_3[5] = iVar6 + -0x76c;
      }
    }
    else if (bVar3 == 100) {
      iVar6 = FUN_002674f4(&local_68,1,0x1f,2);
      if (iVar6 == -1) {
        return (byte *)0x0;
      }
      param_3[3] = iVar6;
    }
    else if (bVar3 == 0x6d) {
      iVar6 = FUN_002674f4(&local_68,1,0xc,2);
      if (iVar6 == -1) {
        return (byte *)0x0;
      }
      param_3[4] = iVar6 + -1;
    }
    else {
      if (bVar3 != 0x68) {
        return (byte *)0x0;
      }
LAB_00267344:
      lVar11 = 0;
      while( true ) {
        if (0xb < lVar11) {
          return (byte *)0x0;
        }
        puVar10 = (&PTR_s_january_010654e0)[lVar11];
        iVar6 = _av_strncasecmp(pbVar2,puVar10,3);
        if (iVar6 == 0) break;
        lVar11 = lVar11 + 1;
      }
      pcVar1 = puVar10 + 3;
      sVar7 = _strlen(pcVar1);
      pbVar2 = pbVar2 + 3;
      iVar6 = (int)sVar7;
      local_68 = pbVar2;
      if (0 < iVar6) {
        iVar5 = _av_strncasecmp(pbVar2,pcVar1,(long)iVar6);
        if (iVar5 == 0) {
          local_68 = pbVar2 + iVar6;
        }
      }
      if ((int)lVar11 == -1) {
        return (byte *)0x0;
      }
      param_3[4] = (int)lVar11;
    }
    goto LAB_00267214;
  }
  if ((char)bVar3 < 'J') {
    if (bVar3 == 0x25) {
      bVar3 = *local_68;
      local_68 = local_68 + 1;
      if (bVar3 != 0x25) {
        return (byte *)0x0;
      }
      goto LAB_00267214;
    }
    if (bVar3 == 0x42) goto LAB_00267344;
    if (bVar3 != 0x48) {
      return (byte *)0x0;
    }
  }
  else if (bVar3 != 0x4a) {
    if (bVar3 == 0x4d) {
      iVar6 = FUN_002674f4(&local_68,0,0x3b,2);
      if (iVar6 == -1) {
        return (byte *)0x0;
      }
      param_3[1] = iVar6;
    }
    else {
      if (bVar3 != 0x53) {
        return (byte *)0x0;
      }
      iVar6 = FUN_002674f4(&local_68,0,0x3b,2);
      if (iVar6 == -1) {
        return (byte *)0x0;
      }
      *param_3 = iVar6;
    }
    goto LAB_00267214;
  }
  uVar9 = 0x17;
  if (bVar3 != 0x48) {
    uVar9 = 0x7fffffff;
  }
  uVar12 = 2;
  if (bVar3 != 0x48) {
    uVar12 = 4;
  }
  iVar6 = FUN_002674f4(&local_68,0,uVar9,uVar12);
  if (iVar6 == -1) {
    return (byte *)0x0;
  }
  param_3[2] = iVar6;
  goto LAB_00267214;
}


