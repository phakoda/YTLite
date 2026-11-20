/* Decompiled from supplied 5.2.2 arm package. VA 0x266c3c. _av_parse_ratio */

undefined8
_av_parse_ratio(int *param_1,char *param_2,int param_3,undefined4 param_4,undefined8 param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_50 [2];
  
  iVar1 = _sscanf(param_2,"%d:%d%c");
  if (iVar1 == 2) {
    _av_reduce(param_1,param_1 + 1,(long)*param_1,(long)param_1[1],(long)param_3);
    uVar2 = 0;
  }
  else {
    uVar2 = _av_expr_parse_and_eval(local_50,param_2,0,0,0,0,0,0,0,param_4,param_5);
    if (-1 < (int)uVar2) {
      uVar3 = _av_d2q(local_50[0],param_3);
      uVar2 = 0;
      *(undefined8 *)param_1 = uVar3;
    }
  }
  return uVar2;
}


