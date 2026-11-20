/* Decompiled from supplied 5.2.2 arm package. VA 0x1069d0. FUN_001069d0 */

undefined1  [16] FUN_001069d0(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined1 auVar15 [16];
  
  puVar6 = PTR__OBJC_CLASS___NSURL_0114eb78;
  puVar5 = PTR_s_URL_0114c578;
  if (param_2 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x20);
    uVar2 = *(undefined8 *)(param_1 + 0x28);
    _objc_retain(param_2);
    _objc_msgSend(uVar2,puVar5);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    puVar4 = PTR_s_URLWithString__0114b3d0;
    _objc_msgSend(puVar6,PTR_s_URLWithString__0114b3d0,uVar7);
    uVar8 = _objc_retainAutoreleasedReturnValue();
    puVar6 = PTR__OBJC_CLASS___NSURL_0114eb78;
    _objc_msgSend(*(undefined8 *)(param_1 + 0x30),puVar5);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar6,puVar4,uVar9);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    puVar5 = PTR_s_contentLength_0114cea0;
    uVar2 = *(undefined8 *)(param_1 + 0x38);
    uVar3 = *(undefined8 *)(param_1 + 0x40);
    uVar14 = *(undefined8 *)(param_1 + 0x48);
    uVar11 = _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_contentLength_0114cea0);
    uVar12 = _objc_msgSend(*(undefined8 *)(param_1 + 0x30),puVar5);
    uVar13 = _objc_msgSend(*(undefined8 *)(param_1 + 0x28),PTR_s_approxDurationMs_0114cec0);
    FUN_0011341c(uVar1,PTR_s_downloadVideoWithUrl_audioUrl_fi_0114cec8,uVar8,uVar10,uVar2,uVar3,
                 uVar14,uVar11,uVar12,uVar13,param_2,*(undefined8 *)(param_1 + 0x50));
    _objc_release(param_2);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
  }
  CallSupervisor(0x40ea);
  auVar15._8_8_ = 0x1f;
  auVar15._0_8_ = 0x1a;
  return auVar15;
}


