/* Decompiled from supplied 5.2.2 arm package. VA 0x86048. FUN_00086048 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1  [16]
FUN_00086048(double param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined1 auVar7 [16];
  
  DAT_01226c68 = 1;
  uVar2 = _objc_msgSend(param_2,PTR_s_class_0114ae88);
  lVar3 = _class_getInstanceVariable(uVar2,s__snappedZoomFactor_011675a0);
  if ((lVar3 != 0) &&
     (iVar1 = FUN_000df088((&PTR_LAB_0117d5a0)[lVar3 == 0] + (int)-(DAT_0117d5b0 ^ 0x1ff8b68a),
                           &PTR____CFConstantStringClassReference_01167620), iVar1 != 0)) {
    _objc_msgSend(param_2,PTR_s_valueForKey__0114ae90,
                  &PTR____CFConstantStringClassReference_011675e0);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    dVar4 = (double)_objc_msgSend(uVar2,PTR_s_doubleValue_0114b3f0);
    _objc_release(uVar2);
    dVar5 = (double)_objc_msgSend(param_2,PTR_s_videoZoomFactor_0114c938);
    dVar6 = 1.0;
    if (1.0 >= param_1 || dVar4 >= dVar5) {
      dVar6 = param_1;
    }
                    /* WARNING: Could not recover jumptable at 0x0008650c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    auVar7 = (*(code *)((&PTR_thunk_FUN_000e9658_0117d5d0)
                        [1.0 < param_1 && dVar4 < dVar5 || param_1 <= 1.0] +
                       (int)-(uRam000000000117d5e0 ^ 0x938a0576)))(dVar5,dVar6);
    return auVar7;
  }
  (*_DAT_01226348)(param_1,param_2,param_3,param_4);
  CallSupervisor(0xe4f3);
  return ZEXT816(0x1f);
}


