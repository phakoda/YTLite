/* Decompiled from supplied 5.2.2 arm package. VA 0x26265c. _av_murmur3_final */

void _av_murmur3_final(ulong *param_1,long *param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar3 = *param_1;
  uVar2 = param_1[1];
  _bzero((void *)((long)param_1 + (long)(int)param_1[4] + 0x10),0x10 - (long)(int)param_1[4]);
  uVar2 = param_1[5] ^ uVar2 ^
          (param_1[3] * 0x4e8b26fe00000000 | param_1[3] * 0x4cf5ad432745937f >> 0x1f) *
          -0x783c846eeebdac2b;
  uVar3 = uVar2 + (param_1[5] ^ uVar3 ^
                  (param_1[2] * -0x775ed61580000000 | param_1[2] * -0x783c846eeebdac2b >> 0x21) *
                  0x4cf5ad432745937f);
  uVar2 = uVar3 + uVar2;
  uVar4 = (uVar3 ^ uVar3 >> 0x21) * -0xae502812aa7333;
  uVar3 = (uVar2 ^ uVar2 >> 0x21) * -0xae502812aa7333;
  uVar2 = (uVar4 ^ uVar4 >> 0x21) * -0x3b314601e57a13ad;
  uVar3 = (uVar3 ^ uVar3 >> 0x21) * -0x3b314601e57a13ad;
  uVar3 = uVar3 ^ uVar3 >> 0x21;
  lVar1 = uVar3 + (uVar2 ^ uVar2 >> 0x21);
  *param_2 = lVar1;
  param_2[1] = lVar1 + uVar3;
  return;
}


