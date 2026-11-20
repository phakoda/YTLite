/* Decompiled from supplied 5.2.2 arm package. VA 0x26c978. _av_tea_crypt */

void _av_tea_crypt(undefined8 param_1,undefined8 *param_2,long param_3,uint param_4,
                  undefined8 *param_5,int param_6)

{
  long lVar1;
  
  if (param_6 == 0) {
    while (param_4 != 0) {
      param_4 = param_4 - 1;
      if (param_5 == (undefined8 *)0x0) {
        FUN_0026ca78(param_1,param_2,param_3,0,0);
      }
      else {
        for (lVar1 = 0; lVar1 != 8; lVar1 = lVar1 + 1) {
          *(byte *)((long)param_2 + lVar1) =
               *(byte *)((long)param_5 + lVar1) ^ *(byte *)(param_3 + lVar1);
        }
        FUN_0026ca78(param_1,param_2,param_2,0,0);
        *param_5 = *param_2;
      }
      param_3 = param_3 + 8;
      param_2 = param_2 + 1;
    }
  }
  else {
    param_4 = ~param_4;
    while (param_4 = param_4 + 1, param_4 != 0) {
      FUN_0026ca78(param_1,param_2,param_3,param_6,param_5);
      param_3 = param_3 + 8;
      param_2 = param_2 + 1;
    }
  }
  return;
}


