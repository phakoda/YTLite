/* Decompiled from supplied 5.2.2 arm package. VA 0x267554. _av_timegm */

long _av_timegm(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_1[4];
  iVar1 = iVar2 + 0xd;
  if (2 < iVar2 + 1) {
    iVar1 = iVar2 + 1;
  }
  iVar4 = 0x76b;
  if (2 < iVar2 + 1) {
    iVar4 = 0x76c;
  }
  iVar4 = iVar4 + param_1[5];
  iVar2 = iVar4 + 3;
  if (-1 < iVar4) {
    iVar2 = iVar4;
  }
  iVar3 = (int)((ulong)((long)iVar4 * -0x51eb851f) >> 0x20);
  return (long)param_1[2] * 0xe10 + (long)param_1[1] * 0x3c + (long)*param_1 +
         (long)(param_1[3] + iVar4 * 0x16d + (iVar2 >> 2) + ((iVar3 >> 5) - (iVar3 >> 0x1f)) +
                iVar4 / 400 + (iVar1 * 0x99 + -0x1c9) / 5 + -0xafa6d) * 0x15180;
}


