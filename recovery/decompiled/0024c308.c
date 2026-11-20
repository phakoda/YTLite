/* Decompiled from supplied 5.2.2 arm package. VA 0x24c308. FUN_0024c308 */

void FUN_0024c308(short *param_1,undefined2 *param_2,int param_3,short *param_4,int param_5)

{
  long lVar1;
  short sVar2;
  long lVar3;
  
  sVar2 = *param_4;
  if (sVar2 < param_3) {
    lVar3 = -1;
    while (lVar1 = lVar3 + 1, sVar2 < param_3 && lVar1 < (long)param_5 + -1) {
      param_4 = param_4 + 1;
      lVar3 = lVar1;
      sVar2 = *param_4;
    }
    if (param_3 <= (int)param_4[-1] + (int)sVar2 + 1 >> 1) {
      *param_2 = (short)lVar3;
      sVar2 = param_4[-1];
      goto LAB_0024c370;
    }
    *param_2 = (short)lVar1;
  }
  else {
    *param_2 = 0;
  }
  sVar2 = *param_4;
LAB_0024c370:
  *param_1 = sVar2;
  return;
}


