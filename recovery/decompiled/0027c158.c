/* Decompiled from supplied 5.2.2 arm package. VA 0x27c158. FUN_0027c158 */

int FUN_0027c158(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 in_x6;
  undefined8 in_x7;
  long lVar6;
  ulong uVar7;
  long local_a8 [9];
  
  lVar6 = *(long *)(param_1 + 0x48);
  local_a8[8] = 0;
  lVar3 = _av_calloc(0x10,4);
  *(long *)(lVar6 + 0x20) = lVar3;
  if (lVar3 == 0) {
LAB_0027c2b8:
    iVar2 = -0xc;
  }
  else {
    uVar7 = 0;
    uVar4 = *(undefined8 *)(lVar6 + 8);
    while (((long)uVar7 < 0x10 && (lVar3 = _av_strtok(uVar4," |",local_a8 + 8), lVar3 != 0))) {
      iVar1 = _av_sscanf(lVar3,"%f");
      if (iVar1 != 1) {
        pcVar5 = "Invalid syntax for frequency[%d].\n";
LAB_0027c2f8:
        _av_log(param_1,0x10,pcVar5);
        return -0x16;
      }
      if ((float)local_a8[0] <= 0.0) {
        pcVar5 = "Frequency %f must be positive number.\n";
        goto LAB_0027c2f8;
      }
      if ((long)uVar7 < 1) {
        lVar3 = *(long *)(lVar6 + 0x20);
      }
      else {
        lVar3 = *(long *)(lVar6 + 0x20);
        if ((float)local_a8[0] <= *(float *)(lVar3 + uVar7 * 4 + -4)) {
          pcVar5 = "Frequency %f must be in increasing order.\n";
          goto LAB_0027c2f8;
        }
      }
      uVar4 = 0;
      *(float *)(lVar3 + uVar7 * 4) = (float)local_a8[0];
      uVar7 = uVar7 + 1;
    }
    iVar2 = 0;
    *(int *)(lVar6 + 0x18) = (int)uVar7;
    for (iVar1 = 0; iVar1 <= (int)uVar7; iVar1 = iVar1 + 1) {
      local_a8[6] = 0;
      local_a8[7] = 0;
      local_a8[4] = 0;
      local_a8[5] = 0;
      local_a8[2] = 0;
      local_a8[3] = 0;
      local_a8[0] = 0;
      local_a8[1] = 1;
      uVar7 = (ulong)*(uint *)(param_1 + 0x40);
      local_a8[0] = _av_asprintf("out%d");
      if (local_a8[0] == 0) goto LAB_0027c2b8;
      iVar2 = _ff_insert_pad(iVar1,(uint *)(param_1 + 0x40),8,param_1 + 0x30,param_1 + 0x38,local_a8
                             ,in_x6,in_x7,uVar7);
      if (iVar2 < 0) {
        _av_freep(local_a8);
        return iVar2;
      }
      uVar7 = (ulong)*(uint *)(lVar6 + 0x18);
    }
  }
  return iVar2;
}


