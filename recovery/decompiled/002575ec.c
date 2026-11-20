/* Decompiled from supplied 5.2.2 arm package. VA 0x2575ec. _avpriv_dict_set_timestamp */

undefined4 _avpriv_dict_set_timestamp(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  tm *ptVar2;
  size_t sVar3;
  long lVar4;
  tm tStack_a8;
  long local_70;
  char acStack_68 [32];
  long local_48;
  
  lVar4 = *(long *)PTR____stack_chk_guard_01060708;
  uVar1 = 0xdfaba7bb;
  local_70 = param_3 / 1000000;
  local_48 = lVar4;
  ptVar2 = _gmtime_r(&local_70,&tStack_a8);
  if ((ptVar2 != (tm *)0x0) &&
     (sVar3 = _strftime(acStack_68,0x20,"%Y-%m-%dT%H:%M:%S",ptVar2), sVar3 != 0)) {
    _av_strlcatf(acStack_68,0x20,".%06dZ");
    uVar1 = _av_dict_set(param_1,param_2,acStack_68,0);
  }
  if (lVar4 != local_48) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail();
  }
  return uVar1;
}


