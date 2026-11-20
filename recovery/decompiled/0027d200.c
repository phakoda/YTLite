/* Decompiled from supplied 5.2.2 arm package. VA 0x27d200. FUN_0027d200 */

undefined8 FUN_0027d200(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x48);
  iVar2 = _strcmp((char *)**(undefined8 **)(param_1 + 8),"adeclip");
  pcVar1 = FUN_0027db9c;
  if (iVar2 != 0) {
    pcVar1 = FUN_0027dd5c;
  }
  *(uint *)(lVar3 + 0x38) = (uint)(iVar2 == 0);
  *(code **)(lVar3 + 0xc0) = pcVar1;
  return 0;
}


