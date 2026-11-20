/* Decompiled from supplied 5.2.2 arm package. VA 0x2545b4. _av_base64_encode */

char * _av_base64_encode(char *param_1,int param_2,uint *param_3,uint param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  
  if ((param_4 < 0x3fffffff) && ((int)(((int)(param_4 + 2) / 3) * 4 | 1U) <= param_2)) {
    uVar7 = param_4 << 3;
    pcVar6 = param_1;
    for (; 3 < (int)param_4; param_4 = param_4 - 3) {
      uVar4 = (*param_3 & 0xff00ff) << 8;
      uVar9 = (*param_3 & 0xff00ff00) >> 8 | uVar4;
      uVar5 = uVar9 << 0x10;
      cVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
              [uVar5 >> 0x14 & 0x3f];
      cVar2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
              [(uVar9 >> 0x10 | uVar5) >> 0xe & 0x3f];
      cVar3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
              [(uVar4 & 0x3f000000) >> 0x18];
      *pcVar6 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[uVar5 >> 0x1a];
      pcVar6[1] = cVar1;
      pcVar6[2] = cVar2;
      pcVar6[3] = cVar3;
      uVar7 = uVar7 - 0x18;
      param_3 = (uint *)((long)param_3 + 3);
      pcVar6 = pcVar6 + 4;
    }
    uVar9 = 0;
    for (lVar8 = 0; (uint)lVar8 != param_4; lVar8 = lVar8 + 1) {
      uVar9 = (uint)*(byte *)((long)param_3 + lVar8) | uVar9 << 8;
    }
    for (; 0 < (int)uVar7; uVar7 = uVar7 - 6) {
      *pcVar6 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
                [(uVar9 << 6) >> (ulong)(uVar7 & 0x1f) & 0x3f];
      pcVar6 = pcVar6 + 1;
    }
    for (; ((int)pcVar6 - (int)param_1 & 3U) != 0; pcVar6 = pcVar6 + 1) {
      *pcVar6 = '=';
    }
    *pcVar6 = '\0';
    return param_1;
  }
  return (char *)0x0;
}


