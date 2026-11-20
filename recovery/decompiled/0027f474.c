/* Decompiled from supplied 5.2.2 arm package. VA 0x27f474. FUN_0027f474 */

undefined8 FUN_0027f474(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  long lVar5;
  
  lVar3 = *(long *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x44);
  lVar5 = *(long *)(lVar3 + 0x48);
  switch(iVar1) {
  case 6:
    pcVar4 = FUN_0027f644;
    break;
  case 7:
    pcVar4 = FUN_0027f5ec;
    break;
  case 8:
    pcVar4 = FUN_0027f53c;
    break;
  case 9:
    pcVar4 = FUN_0027f594;
    break;
  default:
    goto switchD_0027f4a8_default;
  }
  *(code **)(lVar5 + 0x10) = pcVar4;
switchD_0027f4a8_default:
  iVar2 = _strcmp((char *)**(undefined8 **)(lVar3 + 8),"aintegral");
  if (iVar2 == 0) {
    if (iVar1 == 9) {
      pcVar4 = FUN_0027f6f4;
    }
    else {
      if (iVar1 != 8) {
        return 0;
      }
      pcVar4 = FUN_0027f69c;
    }
    *(code **)(lVar5 + 0x10) = pcVar4;
  }
  return 0;
}


