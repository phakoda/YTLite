/* Decompiled from supplied 5.2.2 arm package. VA 0x259754. FUN_00259754 */

void FUN_00259754(undefined8 param_1,long param_2,uint *param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *local_38;
  
  pcVar3 = *(char **)(param_2 + 0x10);
  cVar1 = *pcVar3;
  if (cVar1 == '-') {
    _strtod(pcVar3,&local_38);
    pcVar3 = *(char **)(param_2 + 0x10);
    if (((local_38 != pcVar3) && (*local_38 == 'd')) && (local_38[1] == 'B')) {
      *param_3 = 0;
      goto LAB_002597e8;
    }
    cVar1 = *pcVar3;
  }
  uVar2 = (uint)(cVar1 == '+') - (uint)(cVar1 == '-');
  *param_3 = uVar2;
  *(char **)(param_2 + 0x10) = pcVar3 + (uVar2 & 1);
LAB_002597e8:
  FUN_00259808(param_1,param_2);
  return;
}


