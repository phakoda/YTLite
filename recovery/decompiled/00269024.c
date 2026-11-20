/* Decompiled from supplied 5.2.2 arm package. VA 0x269024. FUN_00269024 */

undefined8 FUN_00269024(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  long lVar4;
  int *piVar5;
  int iVar6;
  
  if (((param_3 < 0xc6) && (lVar4 = (long)(int)param_3, lVar4 * 0xa0 != -0x1065540)) &&
     (bVar3 = (&DAT_01065548)[lVar4 * 0xa0], bVar3 != 0)) {
    *param_1 = 0x7fffffff;
    *param_2 = -0x7fffffff;
    iVar6 = bVar3 + 1;
    piVar5 = &DAT_01065568 + lVar4 * 0x28;
    while (iVar6 = iVar6 + -1, iVar6 != 0) {
      iVar2 = *piVar5;
      iVar1 = *param_1;
      if (iVar2 <= *param_1) {
        iVar1 = iVar2;
      }
      *param_1 = iVar1;
      if (iVar2 <= *param_2) {
        iVar2 = *param_2;
      }
      *param_2 = iVar2;
      piVar5 = piVar5 + 8;
    }
    return 0;
  }
  *param_2 = 0;
  *param_1 = 0;
  return 0xffffffea;
}


