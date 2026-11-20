/* Decompiled from supplied 5.2.2 arm package. VA 0x263340. FUN_00263340 */

ulong FUN_00263340(double param_1,undefined8 param_2,long param_3,double *param_4,float param_5,
                  long param_6)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  double dVar4;
  double dVar5;
  
  if (*(int *)(param_3 + 0x14) == 0) {
    dVar4 = ((double)param_6 * param_1) / (double)(int)param_5;
    if (((dVar4 < -1.5) || (DAT_00c511e8 < dVar4)) ||
       (uVar2 = _llrint(dVar4 * DAT_00c511f0), (uVar2 & 0xff) != 0)) {
      pcVar3 = "Value %f for parameter \'%s\' is not a valid set of 32bit integer flags\n";
      goto LAB_00263458;
    }
switchD_002634a0_caseD_1:
switchD_002634a0_caseD_c:
    iVar1 = _llrint(param_1 / (double)(int)param_5,uVar2);
    *(int *)param_4 = iVar1 * (int)param_6;
    return 0;
  }
  if (param_5 != 0.0) {
    dVar4 = (double)(int)param_5;
    dVar5 = (double)param_6 * param_1;
    if ((dVar5 <= dVar4 * *(double *)(param_3 + 0x28)) &&
       (dVar4 * *(double *)(param_3 + 0x20) <= dVar5)) {
      uVar2 = 0xffffffea;
      switch(*(int *)(param_3 + 0x14)) {
      case 1:
      case 0x12:
        goto switchD_002634a0_caseD_1;
      case 2:
      case 0xf:
      case 0x11:
        if ((param_6 == 1) && (param_1 / dVar4 == DAT_00c511d8)) {
          dVar4 = NAN;
        }
        else {
LAB_002635a0:
          uVar2 = _llrint(0xffffffea);
LAB_002635ac:
          dVar4 = (double)(uVar2 * param_6);
        }
        break;
      case 3:
        *param_4 = dVar5 / dVar4;
        return 0;
      case 4:
        *(float *)param_4 = (float)(dVar5 / dVar4);
        return 0;
      default:
        goto switchD_002634a0_caseD_5;
      case 6:
      case 0xe:
        if ((double)(int)param_1 == param_1) {
          *(int *)param_4 = (int)dVar5;
          *(float *)((long)param_4 + 4) = param_5;
          return 0;
        }
        dVar4 = (double)_av_d2q(dVar5 / dVar4,0x1000000);
        break;
      case 9:
        param_1 = param_1 / dVar4;
        if ((param_6 != 1) || (param_1 != DAT_00c511d0)) {
          if (param_1 <= DAT_00c511d8) goto LAB_002635a0;
          uVar2 = _llrint(param_1 + DAT_00c511e0,0xffffffea);
          uVar2 = uVar2 ^ 0x8000000000000000;
          goto LAB_002635ac;
        }
        dVar4 = -NAN;
        break;
      case 0xc:
      case 0xd:
        goto switchD_002634a0_caseD_c;
      }
      uVar2 = 0;
      *param_4 = dVar4;
switchD_002634a0_caseD_5:
      return uVar2;
    }
  }
  pcVar3 = "Value %f for parameter \'%s\' out of range [%g - %g]\n";
LAB_00263458:
  _av_log(param_2,0x10,pcVar3);
  return 0xffffffde;
}


