/* Decompiled from supplied 5.2.2 arm package. VA 0x269a80. _av_rc4_crypt */

void _av_rc4_crypt(long param_1,byte *param_2,byte *param_3,int param_4)

{
  char cVar1;
  char cVar2;
  byte *pbVar3;
  uint uVar4;
  ulong uVar5;
  uint uVar6;
  byte bVar7;
  
  uVar5 = (ulong)*(uint *)(param_1 + 0x100);
  uVar6 = *(uint *)(param_1 + 0x104);
  while( true ) {
    uVar4 = (uint)uVar5;
    if (param_4 < 1) break;
    uVar6 = uVar6 & 0xff;
    cVar1 = *(char *)(param_1 + (ulong)(uVar4 & 0xff));
    cVar2 = *(char *)(param_1 + (ulong)uVar6);
    bVar7 = cVar2 + cVar1;
    *(char *)(param_1 + (ulong)uVar6) = cVar1;
    *(char *)(param_1 + (ulong)(uVar4 & 0xff)) = cVar2;
    if (param_3 == (byte *)0x0) {
      bVar7 = *(byte *)(param_1 + (ulong)bVar7);
      pbVar3 = (byte *)0x0;
    }
    else {
      pbVar3 = param_3 + 1;
      bVar7 = *(byte *)(param_1 + (ulong)bVar7) ^ *param_3;
    }
    *param_2 = bVar7;
    uVar5 = (ulong)(uVar4 + 1);
    uVar6 = *(byte *)(param_1 + (uVar5 & 0xff)) + uVar6;
    param_2 = param_2 + 1;
    param_3 = pbVar3;
    param_4 = param_4 + -1;
  }
  *(uint *)(param_1 + 0x100) = uVar4 & 0xff;
  *(uint *)(param_1 + 0x104) = uVar6 & 0xff;
  return;
}


