/* Decompiled from supplied 5.2.2 arm package. VA 0x24e098. FUN_0024e098 */

int FUN_0024e098(short *param_1,short *param_2,int param_3,uint param_4)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  short *psVar7;
  short *psVar8;
  undefined8 uVar9;
  
  lVar5 = 0;
  iVar4 = 0;
  iVar3 = param_3 + -3;
  lVar6 = (long)iVar3;
  if (iVar3 < 1) {
    iVar3 = 0;
  }
  psVar7 = param_1;
  psVar8 = param_2;
  for (; lVar5 < lVar6; lVar5 = lVar5 + 4) {
    sVar2 = *psVar8;
    psVar1 = psVar8 + 3;
    uVar9 = NEON_sshl(CONCAT44((int)psVar8[2] * (int)psVar7[2],(int)psVar8[1] * (int)psVar7[1]),
                      CONCAT44(-param_4,-param_4),4);
    psVar8 = psVar8 + 4;
    iVar4 = ((int)sVar2 * (int)*psVar7 >> (param_4 & 0x1f)) + iVar4 + (int)uVar9 +
            (int)((ulong)uVar9 >> 0x20) + ((int)*psVar1 * (int)psVar7[3] >> (param_4 & 0x1f));
    psVar7 = psVar7 + 4;
  }
  for (lVar5 = (long)(int)(iVar3 + 3U & 0xfffffffc); lVar5 < param_3; lVar5 = lVar5 + 1) {
    iVar4 = ((int)param_2[lVar5] * (int)param_1[lVar5] >> (param_4 & 0x1f)) + iVar4;
  }
  return iVar4;
}


