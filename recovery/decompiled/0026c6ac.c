/* Decompiled from supplied 5.2.2 arm package. VA 0x26c6ac. FUN_0026c6ac */

bool FUN_0026c6ac(long param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  bool bVar7;
  
  iVar4 = *(int *)(param_1 + 0xc);
  uVar5 = *(uint *)(param_1 + 0x10);
  puVar1 = (uint *)(param_1 + 0x14);
  do {
    uVar2 = *puVar1;
    cVar6 = '\x01';
    bVar7 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar7) {
      *puVar1 = uVar2 + 1;
      cVar6 = ExclusiveMonitorsStatus();
    }
  } while (cVar6 != '\0');
  puVar1 = (uint *)(param_1 + 0x18);
  uVar3 = uVar2;
  do {
    (**(code **)(param_1 + 0xa0))(*(undefined8 *)(param_1 + 0x98),uVar3,uVar2,uVar5,iVar4);
    do {
      uVar3 = *puVar1;
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar7) {
        *puVar1 = uVar3 + 1;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
  } while (uVar3 < uVar5);
  return uVar3 == (uVar5 + iVar4) - 1;
}


