/* Decompiled from supplied 5.2.2 arm package. VA 0x8b0e4. FUN_0008b0e4 */

uint FUN_0008b0e4(undefined1 param_1 [16],undefined1 param_2 [16],double param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  double dVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined *puVar7;
  float fVar8;
  double dVar9;
  
  DAT_01226d1c = 1;
  _objc_retain(param_6);
  uVar5 = _objc_msgSend(PTR__OBJC_CLASS___UIPanGestureRecognizer_0114ed90,PTR_s_class_0114ae88);
  uVar4 = FUN_000dfb94(param_6,PTR_s_isKindOfClass__0114ad70,uVar5);
  puVar2 = PTR_s_view_0114b090;
  puVar7 = (&PTR_LAB_0117de50)[uVar4] + (int)-(uRam000000000117de60 ^ 0x53a77bc8);
  if (uVar4 == 0) {
    uVar4 = 0;
    goto LAB_0008b658;
  }
  _objc_msgSend(param_4,PTR_s_view_0114b090);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  dVar1 = (double)_objc_msgSend(param_6,PTR_s_locationInView__0114c978,uVar5);
  _objc_release(uVar5);
  _objc_msgSend(param_4,puVar2);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(uVar5,PTR_s_bounds_0114b568);
  _objc_release(uVar5);
  _objc_msgSend(PTR_YTLUserDefaults_0114ead8,PTR_s_standardUserDefaults_0114afa0);
  uVar5 = _objc_retainAutoreleasedReturnValue();
  fVar8 = (float)_objc_msgSend(uVar5,PTR_s_floatForKey__0114c308,
                               &PTR____CFConstantStringClassReference_01168780);
  dVar9 = (double)fVar8;
  _objc_release(uVar5);
  param_3 = param_3 - dVar9;
  if (dVar9 < dVar1) {
    uVar4 = 0;
    puVar7 = (&PTR_LAB_0117de88)[dVar1 < param_3] + (int)-(uRam000000000117de98 ^ 0x91555b07);
    uVar3 = 0;
    if (dVar1 < param_3) goto LAB_0008b650;
LAB_0008b600:
    lVar6 = _ytpInt(puVar7,&PTR____CFConstantStringClassReference_01168700);
    puVar7 = (undefined *)(ulong)(lVar6 != 0);
  }
  else {
    lVar6 = _ytpInt((&PTR_LAB_0117de68)[dVar9 < dVar1] + (int)-(uRam000000000117de78 ^ 0x344e9842),
                    &PTR____CFConstantStringClassReference_01168740);
    uVar4 = (uint)(lVar6 != 0);
    puVar7 = (&PTR_LAB_0117de88)[dVar1 < param_3] + (int)-(uRam000000000117de98 ^ 0x91555b07);
    uVar3 = uVar4;
    if (dVar1 >= param_3) goto LAB_0008b600;
LAB_0008b650:
    uVar4 = uVar3;
    puVar7 = (undefined *)0x0;
  }
  uVar4 = uVar4 | (uint)puVar7;
LAB_0008b658:
  _objc_release(puVar7,param_6);
  return uVar4;
}


