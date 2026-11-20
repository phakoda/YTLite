/* Decompiled from supplied 5.2.2 arm package. VA 0x39770. FUN_00039770 */

void FUN_00039770(void)

{
  double dVar1;
  double dVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  dispatch_time_t dVar8;
  char *pcVar9;
  int iVar10;
  double dVar11;
  undefined *local_c8;
  undefined8 local_c0;
  code *local_b8;
  undefined *puStack_b0;
  undefined8 local_a8;
  double local_a0;
  undefined **local_98;
  
  local_98 = &PTR_LAB_0115acd0;
  uVar6 = _objc_alloc(PTR__OBJC_CLASS___UIImpactFeedbackGenerator_0114ec68);
  uVar7 = _objc_msgSend(uVar6,PTR_s_initWithStyle__0114b790,3);
  puVar5 = PTR_s_impactOccurredWithIntensity__0114b7a0;
  puVar4 = PTR_s_prepare_0114b798;
  puVar3 = PTR___dispatch_main_q_01060760;
  dVar2 = DAT_00c4c268;
  dVar1 = DAT_00c4c260;
  uVar6 = DAT_00c4c228;
  iVar10 = 0;
  pcVar9 = "ex limits [%i -> %i]\n";
  while( true ) {
    _objc_msgSend(pcVar9,uVar7,puVar4);
    dVar11 = dVar1 * (double)iVar10 + 0.5;
    _objc_msgSend(dVar11,uVar7,puVar5);
    dVar8 = _dispatch_time(0,(long)((double)iVar10 * dVar1 * dVar2));
    local_c8 = PTR___NSConcreteStackBlock_01060660;
    local_c0 = uVar6;
    local_b8 = FUN_0003991c;
    puStack_b0 = &DAT_01061810;
    _objc_retain(uVar7);
    local_a8 = uVar7;
    local_a0 = dVar11;
    _dispatch_after(dVar8,puVar3,&local_c8);
    _objc_release(local_a8);
    CallSupervisor(0xb338);
    pcVar9 = (&PTR_LAB_0115b0c0)[iVar10 == 9] + (int)-(DAT_0115b0d0 ^ 0xa488a355);
    if (iVar10 == 9) break;
    iVar10 = iVar10 + 1;
  }
  _objc_release(uVar7,0x1f,0,0);
  return;
}


