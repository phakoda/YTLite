/* Decompiled from supplied 5.2.2 arm package. VA 0x2624b4. _av_murmur3_update */

void _av_murmur3_update(ulong *param_1,long *param_2,uint param_3)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  long *plVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  
  if (0 < (int)param_3) {
    uVar7 = *param_1;
    uVar6 = param_1[1];
    iVar8 = (int)param_1[4];
    param_1[5] = param_1[5] + (long)(int)param_3;
    if (0 < iVar8) {
      while (iVar8 < 0x10) {
        lVar3 = *param_2;
        *(int *)(param_1 + 4) = iVar8 + 1;
        *(char *)((long)param_1 + (long)iVar8 + 0x10) = (char)lVar3;
        if ((int)param_3 < 2) {
          return;
        }
        param_3 = param_3 - 1;
        param_2 = (long *)((long)param_2 + 1);
        iVar8 = (int)param_1[4];
      }
      *(undefined4 *)(param_1 + 4) = 0;
      uVar7 = (param_1[2] * -0x775ed61580000000 | param_1[2] * -0x783c846eeebdac2b >> 0x21) *
              0x4cf5ad432745937f ^ uVar7;
      uVar5 = (param_1[3] * 0x4e8b26fe00000000 | param_1[3] * 0x4cf5ad432745937f >> 0x1f) *
              -0x783c846eeebdac2b ^ uVar6;
      uVar7 = ((uVar7 >> 0x25 | uVar7 << 0x1b) + uVar6) * 5 + 0x52dce729;
      uVar6 = (uVar7 + (uVar5 >> 0x21 | uVar5 << 0x1f)) * 5 + 0x38495ab5;
    }
    plVar1 = (long *)((long)param_2 + (long)(int)(param_3 & 0xfffffff0));
    plVar2 = param_2;
    if (param_2 <= plVar1) {
      plVar2 = plVar1;
    }
    for (plVar4 = param_2; plVar4 < plVar1; plVar4 = plVar4 + 2) {
      uVar7 = (*plVar4 * -0x775ed61580000000 | (ulong)(*plVar4 * -0x783c846eeebdac2b) >> 0x21) *
              0x4cf5ad432745937f ^ uVar7;
      uVar5 = (plVar4[1] * 0x4e8b26fe00000000 | (ulong)(plVar4[1] * 0x4cf5ad432745937f) >> 0x1f) *
              -0x783c846eeebdac2b ^ uVar6;
      uVar7 = ((uVar7 >> 0x25 | uVar7 << 0x1b) + uVar6) * 5 + 0x52dce729;
      uVar6 = (uVar7 + (uVar5 >> 0x21 | uVar5 << 0x1f)) * 5 + 0x38495ab5;
    }
    *param_1 = uVar7;
    param_1[1] = uVar6;
    param_3 = param_3 & 0xf;
    if (param_3 != 0) {
      _memcpy(param_1 + 2,
              (void *)((long)param_2 + ((long)plVar2 + (0xf - (long)param_2) & 0xfffffffffffffff0U))
              ,(ulong)param_3);
      *(uint *)(param_1 + 4) = param_3;
    }
  }
  return;
}


