/* Decompiled from supplied 5.2.2 arm package. VA 0x2593c4. _av_expr_parse_and_eval */

ulong _av_expr_parse_and_eval
                (double *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                undefined8 param_9,undefined4 param_10,undefined8 param_11)

{
  undefined8 uVar1;
  ulong uVar2;
  uint uVar3;
  double dVar4;
  undefined8 local_38;
  
  local_38 = 0;
  uVar2 = _av_expr_parse(&local_38,param_2,param_3,param_5,param_6,param_7,param_8,param_10,param_11
                        );
  uVar1 = local_38;
  if ((int)uVar2 < 0) {
    *param_1 = NAN;
  }
  else {
    dVar4 = (double)_av_expr_eval(local_38,param_4,param_9);
    *param_1 = dVar4;
    _av_expr_free(uVar1);
    uVar3 = 0xffffffea;
    if (!NAN(*param_1)) {
      uVar3 = 0;
    }
    uVar2 = (ulong)uVar3;
  }
  return uVar2;
}


