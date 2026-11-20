/* Decompiled from supplied 5.2.2 arm package. VA 0x258214. _av_strtod */

double _av_strtod(char *param_1,long *param_2)

{
  char cVar1;
  ulong uVar2;
  double dVar3;
  char *local_38;
  
  if ((*param_1 == '0') && ((byte)(param_1[1] | 0x20U) == 0x78)) {
    uVar2 = _strtoul(param_1,&local_38,0x10);
    dVar3 = (double)uVar2;
  }
  else {
    dVar3 = _strtod(param_1,&local_38);
  }
  if (local_38 == param_1) goto LAB_00258354;
  cVar1 = *local_38;
  if ((long)cVar1 == 100) {
    if (local_38[1] == 'B') {
      dVar3 = (double)_exp2((dVar3 / 20.0) * DAT_00c508d0);
      local_38 = local_38 + 2;
    }
    else {
LAB_002582c8:
      uVar2 = (long)cVar1 - 0x45;
      if ((0x310b4ad0308945U >> (uVar2 & 0x3f) & 1) != 0) {
        if (local_38[1] == 'i') {
          dVar3 = dVar3 * *(double *)(&DAT_00c50910 + uVar2 * 0x18);
          local_38 = local_38 + 2;
        }
        else {
          dVar3 = dVar3 * *(double *)(&DAT_00c50918 + uVar2 * 0x18);
          local_38 = local_38 + 1;
        }
      }
    }
  }
  else if ((byte)(cVar1 + 0xbbU) < 0x36) goto LAB_002582c8;
  if (*local_38 == 'B') {
    local_38 = local_38 + 1;
    dVar3 = dVar3 * 8.0;
  }
LAB_00258354:
  if (param_2 != (long *)0x0) {
    *param_2 = (long)local_38;
  }
  return dVar3;
}


