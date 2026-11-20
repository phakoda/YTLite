/* Decompiled from supplied 5.2.2 arm package. VA 0x1a3390. picker:didFinishPicking: */

/* Function Stack Size: 0x20 bytes */

void DVNMediaPicker::picker_didFinishPicking_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puStack_88;
  undefined8 uStack_80;
  code *pcStack_78;
  undefined *puStack_70;
  ID IStack_68;
  uint local_5c;
  undefined **local_58;
  
  local_58 = &PTR_LAB_011ae7b8;
  _objc_retain(param_4);
  _objc_msgSend(param_3,PTR_s_dismissViewControllerAnimated_co_0114aed0,1,0);
  lVar3 = _objc_msgSend(param_4,PTR_s_count_0114b840);
  local_5c = (uint)(lVar3 == 0);
  if (lVar3 != 0) {
    _objc_msgSend(param_4,PTR_s_firstObject_0114b748);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_itemProvider_0114dc08);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar1 = PTR_s_identifier_0114c500;
    uVar7 = *(undefined8 *)PTR__UTTypeMovie_010605e8;
    _objc_msgSend(uVar7,PTR_s_identifier_0114c500);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    uVar2 = FUN_001a9728(uVar5,PTR_s_hasItemConformingToTypeIdentifie_0114dc10,uVar6);
    _objc_release(uVar6);
    if (uVar2 != 0) {
      _objc_msgSend((&PTR_LAB_011ae7d0)[uVar2] + (int)-(uRam00000000011ae7e0 ^ 0x545188b1),uVar7,
                    puVar1);
      uVar6 = _objc_retainAutoreleasedReturnValue();
      puStack_88 = PTR___NSConcreteStackBlock_01060660;
      uStack_80 = DAT_00c4c228;
      pcStack_78 = FUN_001a35a8;
      puStack_70 = &UNK_010628e0;
      IStack_68 = param_1;
      _objc_msgSend(uVar5,PTR_s_loadFileRepresentationForTypeIde_0114dc38,uVar6,&puStack_88);
      _objc_unsafeClaimAutoreleasedReturnValue();
      _objc_release(uVar6);
    }
    _objc_release(uVar5);
    _objc_release(uVar4);
  }
  _objc_release(param_4);
  CallSupervisor(0xeaae);
  return;
}


