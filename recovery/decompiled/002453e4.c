/* Decompiled from supplied 5.2.2 arm package. VA 0x2453e4. _shine_encode_buffer */

undefined8 _shine_encode_buffer(int *param_1,undefined8 *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  
  *(undefined8 *)(param_1 + 0x222) = *param_2;
  if (*param_1 == 2) {
    *(undefined8 *)(param_1 + 0x224) = param_2[1];
  }
  dVar4 = *(double *)(param_1 + 0xc);
  if (dVar4 == 0.0) {
    uVar3 = param_1[8];
  }
  else {
    dVar5 = *(double *)(param_1 + 0xe);
    dVar6 = dVar4 + -1.0;
    uVar3 = (uint)(dVar5 <= dVar6);
    dVar7 = 1.0;
    if (dVar6 < dVar5) {
      dVar7 = 0.0;
    }
    param_1[8] = (uint)(dVar5 <= dVar6);
    *(double *)(param_1 + 0xe) = dVar5 + (dVar7 - dVar4);
  }
  iVar1 = (param_1[0x10] + uVar3) * 8;
  param_1[9] = iVar1;
  iVar2 = 0;
  if (param_1[4] != 0) {
    iVar2 = (iVar1 - param_1[0x84]) / param_1[4];
  }
  param_1[0x85] = iVar2;
  _shine_mdct_sub(param_1,1);
  _shine_iteration_loop(param_1);
  _shine_format_bitstream(param_1);
  *param_3 = param_1[0x1b];
  param_1[0x1b] = 0;
  return *(undefined8 *)(param_1 + 0x18);
}


