/* Decompiled from supplied 5.2.2 arm package. VA 0x26695c. FUN_0026695c */

undefined4
FUN_0026695c(undefined8 param_1,long param_2,char *param_3,uint *param_4,uint param_5,code *param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  char *local_58;
  
  uVar3 = 0xffffffff;
  if (param_3 != (char *)0x0) {
    iVar2 = _strcmp(param_3,"none");
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = (*param_6)(param_3);
      if (uVar3 == 0xffffffff) {
        lVar4 = _strtol(param_3,&local_58,0);
        uVar3 = (uint)lVar4;
        if ((param_5 <= uVar3) || (*local_58 != '\0')) {
          _av_log(param_1,0x10,"Unable to parse option value \"%s\" as %s\n");
          return 0xffffffea;
        }
      }
    }
  }
  dVar6 = *(double *)(param_2 + 0x20);
  dVar7 = (double)(int)(param_5 - 1);
  if (dVar6 <= -1.0) {
    dVar6 = -1.0;
  }
  if (*(double *)(param_2 + 0x28) <= dVar7) {
    dVar7 = *(double *)(param_2 + 0x28);
  }
  iVar2 = param_5 - 1;
  iVar1 = -1;
  if ((int)dVar7 != 0 || (int)dVar6 != 0) {
    iVar2 = (int)dVar7;
    iVar1 = (int)dVar6;
  }
  if ((int)uVar3 < iVar1 || iVar2 < (int)uVar3) {
    _av_log(param_1,0x10,"Value %d for parameter \'%s\' out of %s format range [%d - %d]\n");
    uVar5 = 0xffffffde;
  }
  else {
    uVar5 = 0;
    *param_4 = uVar3;
  }
  return uVar5;
}


