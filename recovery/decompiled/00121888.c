/* Decompiled from supplied 5.2.2 arm package. VA 0x121888. sliderValueChanged: */

/* Function Stack Size: 0x18 bytes */

void DVNTableViewController::sliderValueChanged_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined2 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  float fVar12;
  double dVar13;
  double dVar14;
  
  _objc_retain(param_3);
  puVar1 = PTR_s_tag_0114b868;
  uVar5 = _objc_msgSend(param_3,PTR_s_tag_0114b868);
  _objc_msgSend(param_1,PTR_s__cellForTag__0114d510,uVar5);
  lVar6 = _objc_retainAutoreleasedReturnValue();
  puVar3 = PTR_s_dividerValue_0114d558;
  if (lVar6 != 0) {
    dVar13 = (double)_objc_msgSend(lVar6,PTR_s_dividerValue_0114d558);
    puVar2 = PTR_s_value_0114cdf0;
    if (0.0 < dVar13) {
      fVar12 = (float)_objc_msgSend((&PTR_LAB_0118dd78)[0.0 < dVar13] +
                                    (int)-(uRam000000000118dd88 ^ 0x503aa305),param_3,
                                    PTR_s_value_0114cdf0);
      dVar13 = (double)_objc_msgSend(lVar6,puVar3);
      dVar14 = (double)_objc_msgSend(lVar6,puVar3);
      _objc_msgSend((float)(dVar14 * (double)(long)((double)fVar12 / dVar13)),param_3,
                    PTR_s_setValue__0114d560);
    }
    _objc_msgSend(param_1,PTR_s_defaults_0114d278);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar11 = _objc_msgSend(param_3,puVar2);
    _objc_msgSend(lVar6,PTR_s_key_0114c8f8);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar11,uVar5,PTR_s_setFloat_forKey__0114d518,uVar7);
    _objc_release(uVar7);
    _objc_release(uVar5);
    lVar8 = _objc_msgSend(param_3,puVar1);
    uVar4 = _objc_msgSend(param_3,puVar1);
    _objc_msgSend(PTR__OBJC_CLASS___NSIndexPath_0114ee10,PTR_s_indexPathForRow_inSection__0114d250,
                  uVar4,lVar8 >> 0x10);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(param_1,PTR_s_tableView_0114d120);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,PTR_s_cellForRowAtIndexPath__0114d298,uVar5);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_release(uVar7);
    fVar12 = (float)_objc_msgSend(param_3,puVar2);
    uVar7 = _objc_msgSend(lVar6,PTR_s_sliderFormat_0114d418);
    _objc_msgSend((double)fVar12,param_1,PTR_s_formatSliderValue_format__0114d420,uVar7);
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,PTR_s_detailTextLabel_0114b8e8);
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar10,PTR_s_setText__0114b388,uVar7);
    _objc_release(uVar10);
    _objc_release(uVar7);
    _objc_release(uVar9);
    _objc_release(uVar5);
  }
  _objc_release(lVar6);
  _objc_release(param_3);
  CallSupervisor(0x256c);
  return;
}


