/* Decompiled from supplied 5.2.2 arm package. VA 0x265efc. _av_opt_query_ranges */

void _av_opt_query_ranges(long *param_1,long *param_2,undefined8 param_3,uint param_4)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  code *pcVar4;
  
  if (*(int *)(*param_2 + 0x18) < 0x340b01) {
    pcVar4 = (code *)0x0;
  }
  else {
    pcVar4 = *(code **)(*param_2 + 0x48);
  }
  pcVar2 = _av_opt_query_ranges_default;
  if (pcVar4 != (code *)0x0) {
    pcVar2 = pcVar4;
  }
  iVar3 = (*pcVar2)(param_1,param_2,param_3,param_4);
  if (-1 < iVar3) {
    iVar1 = 1;
    if ((param_4 & 0x1000) != 0) {
      iVar1 = iVar3;
    }
    *(int *)(*param_1 + 0xc) = iVar1;
  }
  return;
}


