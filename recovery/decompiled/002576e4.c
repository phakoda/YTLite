/* Decompiled from supplied 5.2.2 arm package. VA 0x2576e4. _av_display_rotation_get */

undefined1  [16] _av_display_rotation_get(int *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  undefined1 auVar4 [16];
  double dVar5;
  double dVar6;
  
  dVar3 = DAT_00c508a0;
  dVar5 = (double)*param_1 * DAT_00c508a0;
  dVar1 = (double)_hypot(dVar5,(double)param_1[3] * DAT_00c508a0);
  dVar6 = (double)param_1[1] * dVar3;
  dVar2 = (double)_hypot(dVar6,(double)param_1[4] * dVar3);
  dVar3 = DAT_00c502d8;
  if ((dVar1 != 0.0) && (dVar2 != 0.0)) {
    dVar3 = (double)_atan2(dVar6 / dVar2,dVar5 / dVar1);
    dVar3 = (dVar3 * DAT_00c508a8) / DAT_00c508b0;
  }
  auVar4._8_8_ = 0;
  auVar4._0_8_ = dVar3;
  return auVar4;
}


