/* Decompiled from supplied 5.2.2 arm package. VA 0x104080. FUN_00104080 */

undefined8 FUN_00104080(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined *puVar2;
  long lVar3;
  long lVar4;
  
  puVar2 = PTR_s_contentLength_0114cea0;
  _objc_retain(param_3);
  lVar3 = _objc_msgSend(param_2,puVar2);
  lVar4 = _objc_msgSend(param_3,puVar2);
  _objc_release(param_3);
  uVar1 = 1;
  if (lVar4 < lVar3) {
    uVar1 = 0xffffffffffffffff;
  }
  return uVar1;
}


