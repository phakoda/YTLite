/* Decompiled from supplied 5.2.2 arm package. VA 0x24c41c. FUN_0024c41c */

/* WARNING: Removing unreachable block (ram,0x0024c630) */

void FUN_0024c41c(int param_1,long param_2,long param_3,long param_4,uint param_5)

{
  short sVar1;
  undefined2 *puVar2;
  long lVar3;
  short *psVar4;
  short *psVar5;
  long lVar6;
  undefined1 auStack_262 [232];
  undefined1 auStack_17a [20];
  short local_166 [116];
  undefined2 auStack_7e [15];
  
  puVar2 = auStack_7e;
  for (lVar3 = 0x14; lVar3 != -2; lVar3 = lVar3 + -2) {
    *puVar2 = *(undefined2 *)(param_3 + lVar3);
    puVar2 = puVar2 + 1;
  }
  sVar1 = *(short *)(&DAT_00c4f4a8 + (long)param_1 * 2);
  lVar3 = (long)(int)param_5 + -1;
  psVar5 = (short *)(param_2 + lVar3 * 2);
  if (param_1 < 0x25) {
    for (lVar6 = 0; (int)lVar6 < (int)param_5; lVar6 = lVar6 + 1) {
      local_166[lVar6] =
           (short)((int)*(short *)(&DAT_00c4f316 + (long)*psVar5 * 2) * (int)sVar1 + 0x200000 >>
                  0x16);
      psVar5 = psVar5 + -1;
    }
  }
  else if (param_1 < 0x3b) {
    for (lVar6 = 0; (int)lVar6 < (int)param_5; lVar6 = lVar6 + 1) {
      local_166[lVar6] =
           (short)((int)*(short *)(&DAT_00c4f316 + (long)*psVar5 * 2) * (int)sVar1 + 0x40000 >> 0x13
                  );
      psVar5 = psVar5 + -1;
    }
  }
  else {
    for (lVar6 = 0; (int)lVar6 < (int)param_5; lVar6 = lVar6 + 1) {
      local_166[lVar6] =
           (short)((int)*(short *)(&DAT_00c4f316 + (long)*psVar5 * 2) * (int)sVar1 + 0x10000 >> 0x11
                  );
      psVar5 = psVar5 + -1;
    }
  }
  psVar5 = local_166 + (long)(int)param_5 * 2;
  thunk_FUN_0024de70(local_166 + (int)param_5,0,param_5);
  thunk_FUN_0024de70(auStack_17a,0,10);
  FUN_0024e304(local_166,auStack_262,auStack_7e,0xb,(int)(short)(param_5 + 10));
  thunk_FUN_0024de70(auStack_262 + (long)(int)(param_5 + 10) * 2,0,param_5 - 10);
  FUN_0024e20c(auStack_262,local_166,param_3,0xb,
               -(param_5 >> 0xe & 1) & 0xffff0000 | (param_5 & 0x7fff) << 1);
  psVar4 = local_166 + lVar3;
  for (lVar6 = 0; psVar5 = psVar5 + -1, (int)lVar6 < (int)param_5; lVar6 = lVar6 + 1) {
    *(short *)(param_4 + lVar6 * 2) = *psVar5 + *psVar4;
    psVar4 = psVar4 + -1;
  }
  return;
}


