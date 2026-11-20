/* Decompiled from supplied 5.2.2 arm package. VA 0x262d64. FUN_00262d64 */

undefined8 FUN_00262d64(char *param_1,undefined8 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  size_t sVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  _av_freep(param_2);
  uVar4 = 0;
  *(undefined4 *)(param_2 + 1) = 0;
  if (param_1 != (char *)0x0) {
    sVar5 = _strlen(param_1);
    iVar1 = (int)sVar5;
    if (iVar1 == 0) {
      uVar4 = 0;
    }
    else if ((sVar5 & 1) == 0) {
      if (iVar1 < 0) {
        iVar1 = iVar1 + 1;
      }
      pbVar6 = (byte *)_av_malloc((long)(iVar1 >> 1));
      pbVar7 = pbVar6;
      if (pbVar6 == (byte *)0x0) {
        uVar4 = 0xfffffff4;
      }
      else {
        for (; *param_1 != '\0'; param_1 = param_1 + 2) {
          uVar2 = FUN_00266920((int)*param_1);
          uVar3 = FUN_00266920((int)param_1[1]);
          if ((int)(uVar3 | uVar2) < 0) {
            _av_free(pbVar6);
            goto LAB_00262e04;
          }
          *pbVar7 = (byte)uVar3 | (byte)(uVar2 << 4);
          pbVar7 = pbVar7 + 1;
        }
        uVar4 = 0;
        *param_2 = pbVar6;
        *(int *)(param_2 + 1) = iVar1 >> 1;
      }
    }
    else {
LAB_00262e04:
      uVar4 = 0xffffffea;
    }
  }
  return uVar4;
}


