/* Decompiled from supplied 5.2.2 arm package. VA 0x260144. FUN_00260144 */

void FUN_00260144(long *param_1,int param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5,uint *param_6,undefined8 *param_7)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long *plVar3;
  undefined4 uVar4;
  char cVar5;
  uint uVar6;
  long *plVar7;
  long lVar8;
  
  if (param_1 == (long *)0x0) {
    lVar8 = 0;
  }
  else {
    lVar8 = *param_1;
  }
  _av_bprint_init(param_5,0,1);
  puVar1 = param_5 + 0x80;
  _av_bprint_init(puVar1,0,1);
  puVar2 = param_5 + 0x100;
  _av_bprint_init(puVar2,0,1);
  plVar3 = param_5 + 0x180;
  _av_bprint_init(plVar3,0,0x10000);
  if (param_7 != (undefined8 *)0x0) {
    *param_7 = 0x1000000010;
  }
  if ((lVar8 != 0) && (*param_6 != 0)) {
    if ((*(int *)(lVar8 + 0x20) != 0) &&
       ((plVar7 = *(long **)((long)param_1 + (long)*(int *)(lVar8 + 0x20)), plVar7 != (long *)0x0 &&
        (*plVar7 != 0)))) {
      (**(code **)(*plVar7 + 8))(plVar7);
      _av_bprintf(param_5,"[%s @ %p] ");
      if (param_7 == (undefined8 *)0x0) {
        (**(code **)(lVar8 + 8))(param_1);
        _av_bprintf(puVar1,"[%s @ %p] ");
        goto LAB_00260284;
      }
      uVar4 = FUN_00260b04(plVar7);
      *(undefined4 *)param_7 = uVar4;
    }
    (**(code **)(lVar8 + 8))(param_1);
    _av_bprintf(puVar1,"[%s @ %p] ");
    if (param_7 != (undefined8 *)0x0) {
      uVar4 = FUN_00260b04(param_1);
      *(undefined4 *)((long)param_7 + 4) = uVar4;
    }
  }
LAB_00260284:
  if (((-8 < param_2) && (*param_6 != 0)) && ((DAT_0122afe8 >> 1 & 1) != 0)) {
    _av_bprintf(puVar2,"[%s] ");
  }
  _av_vbprintf(plVar3,param_3,param_4);
  if (((*(char *)*param_5 != '\0') || (*(char *)*puVar1 != '\0')) ||
     ((*(char *)*puVar2 != '\0' || (*(char *)*plVar3 != '\0')))) {
    uVar6 = (uint)param_5[0x181];
    if ((uVar6 == 0) || ((uint)((ulong)param_5[0x181] >> 0x20) < uVar6)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = *(char *)(*plVar3 + (ulong)(uVar6 - 1));
    }
    *param_6 = (uint)(cVar5 == '\n' || cVar5 == '\r');
  }
  return;
}


