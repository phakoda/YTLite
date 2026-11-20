/* Decompiled from supplied 5.2.2 arm package. VA 0x266578. FUN_00266578 */

undefined8 FUN_00266578(long param_1,double *param_2,double *param_3,float *param_4,double *param_5)

{
  undefined8 uVar1;
  double dVar2;
  
  uVar1 = 0xffffffea;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0:
    dVar2 = (double)(ulong)(uint)*(float *)param_2;
    break;
  case 1:
  case 0xc:
  case 0xd:
  case 0x12:
    dVar2 = (double)(long)(int)*(float *)param_2;
    break;
  case 2:
  case 9:
  case 0xf:
  case 0x11:
    dVar2 = *param_2;
    break;
  case 3:
    dVar2 = *param_2;
    goto LAB_002665f8;
  case 4:
    *param_3 = (double)*(float *)param_2;
    return 0;
  default:
    goto switchD_0026659c_caseD_5;
  case 6:
    *param_5 = (double)(long)(int)*(float *)param_2;
    *param_4 = *(float *)((long)param_2 + 4);
    return 0;
  case 10:
    dVar2 = *(double *)(param_1 + 0x18);
LAB_002665f8:
    uVar1 = 0;
    *param_3 = dVar2;
switchD_0026659c_caseD_5:
    return uVar1;
  }
  *param_5 = dVar2;
  return 0;
}


