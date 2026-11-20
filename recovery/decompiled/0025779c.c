/* Decompiled from supplied 5.2.2 arm package. VA 0x25779c. _av_display_rotation_set */

void _av_display_rotation_set(double param_1,int *param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = DAT_00c508b8;
  dVar2 = (double)___sincos_stret((param_1 * DAT_00c508b8) / DAT_00c508c0);
  param_2[8] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  dVar1 = DAT_00c508c8;
  param_2[3] = 0;
  param_2[3] = (int)(dVar2 * 65536.0);
  param_2[4] = (int)(dVar3 * 65536.0);
  *param_2 = (int)(dVar3 * 65536.0);
  param_2[1] = (int)(dVar2 * dVar1);
  param_2[8] = 0x40000000;
  return;
}


