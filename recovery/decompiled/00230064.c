/* Decompiled from supplied 5.2.2 arm package. VA 0x230064. isConnectedToWiFi */

/* Function Stack Size: 0x10 bytes */

bool YTLHelper::isConnectedToWiFi(ID param_1,SEL param_2)

{
  int iVar1;
  undefined8 uVar2;
  uint local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  local_28 = *(long *)PTR____stack_chk_guard_01060708;
  uStack_30 = 0;
  local_38 = 0x210;
  uVar2 = _SCNetworkReachabilityCreateWithAddress(0,&local_38);
  iVar1 = _SCNetworkReachabilityGetFlags(uVar2,&local_3c);
  _CFRelease(uVar2);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_28) {
    return (bool)(iVar1 != 0 && (local_3c & 0x40002) == 2);
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


