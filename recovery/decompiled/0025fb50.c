/* Decompiled from supplied 5.2.2 arm package. VA 0x25fb50. _av_bmg_get */

void _av_bmg_get(undefined8 param_1,double *param_2)

{
  uint uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  
  dVar2 = DAT_00c50e98;
  do {
    uVar1 = FUN_0025fbf8(param_1);
    dVar4 = (double)uVar1 * dVar2 + -1.0;
    uVar1 = FUN_0025fbf8(param_1);
    dVar5 = (double)uVar1 * dVar2 + -1.0;
    dVar3 = dVar4 * dVar4 + dVar5 * dVar5;
  } while (1.0 <= dVar3);
  dVar2 = (double)_log(dVar3);
  dVar2 = SQRT((dVar2 * -2.0) / dVar3);
  *param_2 = dVar4 * dVar2;
  param_2[1] = dVar5 * dVar2;
  return;
}


