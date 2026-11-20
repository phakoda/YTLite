/* Decompiled from supplied 5.2.2 arm package. VA 0x107068. getThumbnail: */

/* Function Stack Size: 0x18 bytes */

void DownloadMenuHelper::getThumbnail_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puStack_68;
  undefined8 uStack_60;
  code *pcStack_58;
  undefined *puStack_50;
  long lStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_0118a9d0;
  _objc_retain(param_3);
  puVar7 = PTR_s_playerResponse_0114c7c0;
  puVar1 = PTR_s_respondsToSelector__0114af58;
  local_3c = FUN_001135cc(param_3,PTR_s_respondsToSelector__0114af58,PTR_s_playerResponse_0114c7c0);
  puVar2 = PTR_s_contentPlayerResponse_0114c7c8;
  puVar6 = local_38[local_3c] + (int)-(DAT_0118a9e0 ^ 0x320f6bb5);
  if (local_3c == 0) {
    uVar3 = FUN_001135f4(param_3,puVar1,PTR_s_contentPlayerResponse_0114c7c8);
    puVar6 = (&PTR_LAB_0118a9e8)[uVar3] + (int)-(DAT_0118a9f8 ^ 0x55ca9387);
    puVar7 = puVar2;
    if (uVar3 == 0) goto LAB_00107208;
  }
  _objc_msgSend(puVar6,param_3,puVar7);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  if (lVar4 != 0) {
    _dispatch_get_global_queue(0,0);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puStack_68 = PTR___NSConcreteStackBlock_01060660;
    uStack_60 = DAT_00c4c228;
    pcStack_58 = FUN_0010723c;
    puStack_50 = &DAT_01061420;
    lStack_48 = lVar4;
    _objc_retain(lVar4);
    _dispatch_async(uVar5,&puStack_68);
    _objc_release(uVar5);
    _objc_release(lStack_48);
    _objc_release(lVar4);
  }
LAB_00107208:
  _objc_release(param_3);
  CallSupervisor(0x65c1);
  return;
}


