/* Decompiled from supplied 5.2.2 arm package. VA 0x25eb28. _avpriv_set_systematic_pal2 */

undefined4 _avpriv_set_systematic_pal2(long param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  
  for (lVar4 = 0; lVar4 < 0x100; lVar4 = lVar4 + 1) {
    uVar3 = 0xffffffea;
    uVar5 = (uint)lVar4;
    if (param_2 - 0x11U < 6) {
      iVar1 = (int)uVar5 >> 3;
      switch(param_2) {
      case 0x11:
        iVar1 = (int)uVar5 >> 6;
        uVar2 = uVar5 >> 3;
        uVar5 = (uVar5 & 7) * 0x24;
        uVar2 = (uVar2 & 7) * 0x24;
        uVar6 = iVar1 * 0x55;
        break;
      default:
        goto switchD_0025eb7c_caseD_12;
      case 0x13:
        uVar2 = uVar5 >> 1;
        uVar5 = -(uVar5 & 1) & 0xff;
        uVar2 = (uVar2 & 3) * 0x55;
        uVar6 = iVar1 * 0xff;
        break;
      case 0x14:
        uVar2 = uVar5 >> 2;
        uVar6 = uVar5 & 3;
        uVar5 = ((int)uVar5 >> 5) * 0x24;
        uVar2 = (uVar2 & 7) * 0x24;
        uVar6 = uVar6 * 0x55;
        break;
      case 0x16:
        uVar2 = uVar5 >> 1;
        uVar6 = uVar5 & 1;
        uVar5 = iVar1 * 0xff;
        uVar2 = (uVar2 & 3) * 0x55;
        uVar6 = -uVar6 & 0xff;
      }
    }
    else {
      uVar2 = uVar5;
      uVar6 = uVar5;
      if (param_2 != 8) {
        return 0xffffffea;
      }
    }
    *(uint *)(param_1 + lVar4 * 4) = uVar5 * 0x10000 + uVar2 * 0x100 + uVar6 + -0x1000000;
  }
  uVar3 = 0;
switchD_0025eb7c_caseD_12:
  return uVar3;
}


