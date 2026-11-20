/* Decompiled from supplied 5.2.2 arm package. VA 0x249c80. FUN_00249c80 */

void FUN_00249c80(undefined8 param_1,uint param_2,int param_3,long param_4,long param_5,int param_6,
                 int param_7,undefined8 param_8)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  ulong uVar7;
  long lVar8;
  short local_94 [7];
  short asStack_86 [8];
  short asStack_76 [7];
  long local_68;
  
  local_68 = *(long *)PTR____stack_chk_guard_01060708;
  FUN_0024a9d0(asStack_76 + param_7,param_5,(int)(short)(param_3 * 0x20000 + 0x4f0000U >> 0xf),
               param_6);
  asStack_86[(long)param_7 + 1] = (short)(param_3 << 2);
  uVar3 = param_7 + 0xffff;
  while( true ) {
    sVar1 = (short)uVar3;
    if (sVar1 < 0) break;
    uVar7 = -((ulong)(uVar3 >> 0xf) & 1) & 0xfffffffffffe0000 | ((ulong)uVar3 & 0xffff) << 1;
    sVar4 = *(short *)(param_4 + (long)*(short *)((long)asStack_76 + uVar7 + 2) * 2);
    psVar2 = asStack_86 + (long)sVar1 + 1;
    sVar6 = *(short *)((long)asStack_86 + uVar7 + 4) - sVar4;
    *psVar2 = sVar6;
    FUN_0024a9d0(asStack_76 + sVar1,param_5,(int)(short)((sVar6 + 0xa0) - sVar4),param_6);
    if (-1 < *psVar2 + -8) {
      FUN_0024b530(psVar2,param_1,param_2,param_3,(int)*psVar2,param_8,
                   (long)*(short *)(&DAT_00c4f656 + (long)sVar1 * 2));
    }
    uVar3 = uVar3 - 1;
  }
  for (lVar8 = 0; lVar8 < param_6; lVar8 = lVar8 + 1) {
    local_94[lVar8] = *(short *)(param_5 + lVar8 * 2) - *(short *)(param_4 + lVar8 * 2);
  }
  iVar5 = param_7 * 2;
  while (sVar1 = (short)param_7 + 1, sVar1 <= iVar5) {
    param_7 = (int)sVar1;
    FUN_0024a9d0(asStack_76 + param_7,local_94,(int)(short)(asStack_86[param_7] + 0xa0),param_6);
    sVar1 = *(short *)(param_4 + (long)asStack_76[param_7] * 2) + asStack_86[param_7];
    asStack_86[(long)param_7 + 1] = sVar1;
    if (sVar1 + 0x148 < (int)(-(param_2 >> 0xd & 1) & 0xffff0000 | (param_2 & 0x3fff) << 2)) {
      FUN_0024b530(asStack_86 + (long)param_7 + 1,param_1,param_2,param_3,(int)sVar1,param_8,
                   (long)*(short *)(&DAT_00c4f656 + (long)(iVar5 - param_7) * 2));
    }
  }
  if (*(long *)PTR____stack_chk_guard_01060708 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return;
}


