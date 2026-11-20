/* Decompiled from supplied 5.2.2 arm package. VA 0x24f34. FUN_00024f34 */

void FUN_00024f34(void)

{
  void *pvVar1;
  undefined8 uVar2;
  size_t asStack_60 [3];
  undefined **local_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_01159338;
  local_3c = (uint)(DAT_01225dc0 == 0);
  local_48 = &PTR_LAB_01158940;
  DAT_01225dc0 = 1;
  asStack_60[0] = 0;
  _sysctlbyname(s_hw_machine_01156c9b,(void *)0x0,asStack_60,(void *)0x0,0);
  pvVar1 = _malloc(asStack_60[0]);
  _sysctlbyname(s_hw_machine_01156c9b,pvVar1,asStack_60,(void *)0x0,0);
  _objc_msgSend(PTR__OBJC_CLASS___NSString_0114eb38,PTR_s_stringWithUTF8String__0114b220,pvVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  _free(pvVar1);
  (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar2);
  return;
}


