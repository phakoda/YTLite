/* Decompiled from supplied 5.2.2 arm package. VA 0x2573ec. _av_dict_copy */

undefined8 _av_dict_copy(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)0x0;
  do {
    puVar2 = (undefined8 *)_av_dict_get(param_2,"",puVar2,2);
    if (puVar2 == (undefined8 *)0x0) {
      return 0;
    }
    uVar1 = _av_dict_set(param_1,*puVar2,puVar2[1],param_3);
  } while (-1 < (int)uVar1);
  return uVar1;
}


