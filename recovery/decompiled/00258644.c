/* Decompiled from supplied 5.2.2 arm package. VA 0x258644. FUN_00258644 */

bool FUN_00258644(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    bVar1 = true;
    switch(*param_1) {
    case 0:
    case 1:
      goto switchD_00258678_caseD_0;
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x2d:
      iVar2 = FUN_00258644(*(undefined8 *)(param_1 + 8));
      if (iVar2 != 0) {
        lVar3 = *(long *)(param_1 + 10);
LAB_0025868c:
        return lVar3 == 0;
      }
      break;
    default:
      iVar2 = FUN_00258644(*(undefined8 *)(param_1 + 8));
      if ((iVar2 != 0) && (iVar2 = FUN_00258644(*(undefined8 *)(param_1 + 10)), iVar2 != 0)) {
        lVar3 = *(long *)(param_1 + 0xc);
        goto LAB_0025868c;
      }
      break;
    case 0x19:
    case 0x24:
    case 0x25:
      iVar2 = FUN_00258644(*(undefined8 *)(param_1 + 8));
      if ((iVar2 != 0) && (iVar2 = FUN_00258644(*(undefined8 *)(param_1 + 10)), iVar2 != 0)) {
        lVar3 = *(long *)(param_1 + 0xc);
joined_r0x0025870c:
        if (lVar3 == 0) {
          return true;
        }
LAB_00258710:
        iVar2 = FUN_00258644(lVar3);
        return iVar2 != 0;
      }
      break;
    case 0x26:
      iVar2 = FUN_00258644(*(undefined8 *)(param_1 + 8));
      if (iVar2 != 0) {
        lVar3 = *(long *)(param_1 + 10);
        goto joined_r0x0025870c;
      }
      break;
    case 0x29:
    case 0x2a:
    case 0x2c:
      iVar2 = FUN_00258644(*(undefined8 *)(param_1 + 8));
      if ((iVar2 != 0) && (iVar2 = FUN_00258644(*(undefined8 *)(param_1 + 10)), iVar2 != 0)) {
        lVar3 = *(long *)(param_1 + 0xc);
        goto LAB_00258710;
      }
    }
  }
  bVar1 = false;
switchD_00258678_caseD_0:
  return bVar1;
}


