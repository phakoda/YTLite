/* Decompiled from supplied 5.2.2 arm package. VA 0x263bb8. FUN_00263bb8 */

undefined4
FUN_00263bb8(undefined8 param_1,undefined8 param_2,int param_3,undefined4 param_4,int param_5,
            undefined8 param_6,int param_7)

{
  long lVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  long local_48;
  
  lVar1 = _av_opt_find2(param_1,param_2,0,0,param_4,&local_48);
  uVar2 = 0xabafb008;
  if ((lVar1 != 0) && (local_48 != 0)) {
    if (*(int *)(lVar1 + 0x14) == param_5) {
      dVar3 = *(double *)(lVar1 + 0x20);
      if (dVar3 <= -1.0) {
        dVar3 = -1.0;
      }
      dVar4 = (double)(param_7 + -1);
      if (*(double *)(lVar1 + 0x28) <= (double)(param_7 + -1)) {
        dVar4 = *(double *)(lVar1 + 0x28);
      }
      if (param_3 < (int)dVar3 || (int)dVar4 < param_3) {
        _av_log(param_1,0x10,"Value %d for parameter \'%s\' out of %s format range [%d - %d]\n");
        uVar2 = 0xffffffde;
      }
      else {
        uVar2 = 0;
        *(int *)(local_48 + *(int *)(lVar1 + 0x10)) = param_3;
      }
    }
    else {
      _av_log(param_1,0x10,"The value set by option \'%s\' is not a %s format");
      uVar2 = 0xffffffea;
    }
  }
  return uVar2;
}


