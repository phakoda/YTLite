/* Decompiled from supplied 5.2.2 arm package. VA 0x286f4. FUN_000286f4 */

size_t FUN_000286f4(void *param_1,long param_2,long param_3,undefined8 *param_4)

{
  void *pvVar1;
  size_t sVar2;
  long lVar3;
  
  sVar2 = param_3 * param_2;
  pvVar1 = _realloc((void *)*param_4,sVar2 + param_4[1] + 1);
  *param_4 = pvVar1;
  if (pvVar1 == (void *)0x0) {
    sVar2 = 0;
  }
  else {
    lVar3 = param_4[1];
    _memcpy((void *)((long)pvVar1 + lVar3),param_1,sVar2);
    lVar3 = lVar3 + sVar2;
    param_4[1] = lVar3;
    *(undefined1 *)((long)pvVar1 + lVar3) = 0;
  }
  return sVar2;
}


