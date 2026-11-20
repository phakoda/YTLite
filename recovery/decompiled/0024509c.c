/* Decompiled from supplied 5.2.2 arm package. VA 0x24509c. _shine_initialise */

int * _shine_initialise(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  double dVar8;
  double dVar9;
  
  iVar4 = _samplerates;
  iVar3 = param_1[1];
  if (_samplerates == iVar3) {
    uVar6 = 0;
  }
  else if (DAT_00c4d7b4 == iVar3) {
    uVar6 = 1;
  }
  else if (DAT_00c4d7b8 == iVar3) {
    uVar6 = 2;
  }
  else if (DAT_00c4d7bc == iVar3) {
    uVar6 = 3;
  }
  else if (DAT_00c4d7c0 == iVar3) {
    uVar6 = 4;
  }
  else if (DAT_00c4d7c4 == iVar3) {
    uVar6 = 5;
  }
  else if (DAT_00c4d7c8 == iVar3) {
    uVar6 = 6;
  }
  else if (DAT_00c4d7cc == iVar3) {
    uVar6 = 7;
  }
  else {
    if (DAT_00c4d7d0 != iVar3) {
      return (int *)0x0;
    }
    uVar6 = 8;
  }
  iVar3 = 3;
  if (2 < uVar6) {
    iVar3 = (uint)(uVar6 < 6) << 1;
  }
  iVar3 = _shine_find_bitrate_index(param_1[3],iVar3);
  if (iVar3 < 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = _calloc(1,0x17698);
    if (piVar5 != (int *)0x0) {
      _shine_subband_initialise(piVar5);
      _shine_mdct_initialise(piVar5);
      _shine_loop_initialise(piVar5);
      iVar7 = 0;
      *piVar5 = *param_1;
      iVar3 = param_1[1];
      piVar5[1] = iVar3;
      piVar5[5] = param_1[2];
      iVar1 = param_1[3];
      piVar5[6] = iVar1;
      piVar5[7] = param_1[4];
      piVar5[0x16] = param_1[5];
      iVar2 = param_1[6];
      piVar5[10] = 8;
      piVar5[0x17] = iVar2;
      piVar5[0x21af] = 0;
      piVar5[0x13] = 0;
      piVar5[0x14] = 0;
      piVar5[0x15] = 0;
      piVar5[0x21ae] = 0;
      piVar5[3] = 1;
      if (iVar4 != iVar3) {
        if (DAT_00c4d7b4 == iVar3) {
          iVar7 = 1;
        }
        else if (DAT_00c4d7b8 == iVar3) {
          iVar7 = 2;
        }
        else if (DAT_00c4d7bc == iVar3) {
          iVar7 = 3;
        }
        else if (DAT_00c4d7c0 == iVar3) {
          iVar7 = 4;
        }
        else if (DAT_00c4d7c4 == iVar3) {
          iVar7 = 5;
        }
        else if (DAT_00c4d7c8 == iVar3) {
          iVar7 = 6;
        }
        else if (DAT_00c4d7cc == iVar3) {
          iVar7 = 7;
        }
        else {
          iVar7 = 8;
          if (DAT_00c4d7d0 != iVar3) {
            iVar7 = -1;
          }
        }
      }
      piVar5[0x12] = iVar7;
      uVar6 = 3;
      if (2 < iVar7) {
        uVar6 = (uint)(iVar7 < 6) << 1;
      }
      piVar5[2] = uVar6;
      iVar4 = _shine_find_bitrate_index(iVar1,uVar6);
      piVar5[0x11] = iVar4;
      dVar9 = (double)iVar1 * DAT_00c4c4a0;
      dVar8 = (double)*(int *)(&UNK_00c4d718 + (ulong)uVar6 * 4) * DAT_00c4d710;
      piVar5[4] = *(int *)(&UNK_00c4d718 + (ulong)uVar6 * 4);
      dVar8 = (dVar8 / (double)iVar3) * dVar9 * 0.125;
      iVar3 = (int)dVar8;
      piVar5[0x10] = iVar3;
      dVar8 = dVar8 - (double)iVar3;
      *(double *)(piVar5 + 0xc) = dVar8;
      *(double *)(piVar5 + 0xe) = -dVar8;
      if (dVar8 == 0.0) {
        piVar5[8] = 0;
      }
      _shine_open_bit_stream(piVar5 + 0x18,0x1000);
      _bzero(piVar5 + 0x1e,0x198);
      if (piVar5[4] == 2) {
        iVar4 = 0x120;
        iVar3 = 0xa8;
      }
      else {
        iVar4 = 0xa8;
        iVar3 = 0x68;
      }
      if (*piVar5 != 1) {
        iVar3 = iVar4;
      }
      piVar5[0x84] = iVar3;
    }
  }
  return piVar5;
}


