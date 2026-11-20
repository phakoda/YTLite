/* Decompiled from supplied 5.2.2 arm package. VA 0x255160. FUN_00255160 */

void FUN_00255160(long *param_1,long *param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined8 *local_28;
  
  puVar5 = (undefined8 *)*param_1;
  puVar7 = (undefined8 *)*puVar5;
  if (param_2 != (long *)0x0) {
    puVar6 = (undefined8 *)*param_2;
    puVar5[2] = puVar6[2];
    uVar8 = *puVar6;
    puVar5[1] = puVar6[1];
    *puVar5 = uVar8;
    param_1 = param_2;
  }
  local_28 = puVar7;
  _av_freep(param_1);
  piVar1 = (int *)((long)puVar7 + 0xc);
  do {
    iVar2 = *piVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (iVar2 + -1 == 0) {
    (*(code *)local_28[2])(local_28[3],*local_28);
    _av_freep(&local_28);
  }
  return;
}


