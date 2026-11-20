/* Decompiled from supplied 5.2.2 arm package. VA 0x7ff20. FUN_0007ff20 */

bool FUN_0007ff20(undefined1 param_1 [16],double param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined *puVar1;
  undefined8 uVar2;
  double dVar3;
  
  puVar1 = PTR_s_view_0114b090;
  _objc_retain(param_5);
  _objc_msgSend(param_3,puVar1);
  uVar2 = _objc_retainAutoreleasedReturnValue();
  dVar3 = (double)_objc_msgSend(param_5,PTR_s_velocityInView__0114c880,uVar2);
  _objc_release(param_5);
  _objc_release(uVar2);
  return ABS(param_2) < ABS(dVar3);
}


