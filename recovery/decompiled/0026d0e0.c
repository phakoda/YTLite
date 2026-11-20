/* Decompiled from supplied 5.2.2 arm package. VA 0x26d0e0. _av_timecode_adjust_ntsc_framenum2 */

ulong _av_timecode_adjust_ntsc_framenum2(ulong param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  
  if (param_2 == 0x1e) {
    puVar7 = &UNK_0000463e;
    iVar4 = 2;
  }
  else {
    if (param_2 != 0x3c) {
      return param_1;
    }
    puVar7 = (undefined *)0x8c7c;
    iVar4 = 4;
  }
  iVar1 = 0;
  iVar5 = (int)puVar7;
  iVar3 = (int)param_1;
  if (iVar5 != 0) {
    iVar1 = iVar3 / iVar5;
  }
  iVar2 = 0;
  iVar6 = (int)((ulong)puVar7 / 10);
  if (iVar6 != 0) {
    iVar2 = ((iVar3 - iVar1 * iVar5) - iVar4) / iVar6;
  }
  return (ulong)(uint)(iVar3 + (iVar2 + iVar1 * 9) * iVar4);
}


