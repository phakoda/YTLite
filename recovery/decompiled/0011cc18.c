/* Decompiled from supplied 5.2.2 arm package. VA 0x11cc18. tableView:cellForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

ID DVNTableViewController::tableView_cellForRowAtIndexPath_
             (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  ID IVar7;
  long lVar8;
  undefined8 uVar9;
  
  DAT_012272f0 = 1;
  _objc_retain(param_4);
  _objc_msgSend(param_1,PTR_s__cellForIndexPath__0114d370,param_4);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_alloc(PTR_YTPTableViewCell_0114ee38);
  puVar1 = PTR_s_type_0114b050;
  lVar5 = _objc_msgSend(uVar3,PTR_s_type_0114b050);
  if (lVar5 != 0xc) {
    lVar5 = _objc_msgSend((&PTR_LAB_0118d4f0)[lVar5 == 0xc] +
                          (int)-(uRam000000000118d500 ^ 0x9588c42a),uVar3,puVar1);
    if ((lVar5 != 6) &&
       (lVar5 = _objc_msgSend((&PTR_LAB_0118d508)[lVar5 == 6] +
                              (int)-(uRam000000000118d518 ^ 0x45b80716),uVar3,puVar1), lVar5 != 0xb)
       ) {
      uVar9 = 3;
      goto LAB_0011d0cc;
    }
  }
  uVar9 = 1;
LAB_0011d0cc:
  _objc_msgSend(uVar3,PTR_s_reuseIdentifier_0114d378);
  uVar6 = _objc_retainAutoreleasedReturnValue();
  uVar4 = _objc_msgSend(uVar4,PTR_s_initWithStyle_reuseIdentifier__0114b8d8,uVar9,uVar6);
  _objc_release(uVar6);
  _objc_msgSend(uVar3,PTR_s_setSourceView__0114b8b8,uVar4);
  puVar2 = PTR_s_title_0114c7f0;
  _objc_msgSend(uVar3,PTR_s_title_0114c7f0);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  _objc_release();
  if (lVar5 != 0) {
    _objc_msgSend(uVar3,puVar2);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_textLabel_0114b8e0);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar4,PTR_s_setText__0114b388,uVar9);
    _objc_release(uVar4);
    _objc_release(uVar9);
    _objc_msgSend(uVar3,PTR_s_subtitle_0114d1e8);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0011d228. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar7 = (*(code *)((&PTR_LAB_0118d560)[lVar5 == 0] + (int)-(uRam000000000118d570 ^ 0x5e65afda)))
                      ();
    return IVar7;
  }
  _objc_msgSend((&PTR_LAB_0118d540)[lVar5 == 0] + (int)-(uRam000000000118d550 ^ 0x41243c52),uVar3,
                PTR_s_subtitle_0114d1e8);
  lVar5 = _objc_retainAutoreleasedReturnValue();
  puVar2 = PTR_s_subtitleProvider_0114d380;
  if (lVar5 == 0) {
    _objc_msgSend(uVar3,PTR_s_subtitleProvider_0114d380);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
    if (lVar5 != 0) {
      _objc_msgSend((&PTR_LAB_0118d5d8)[lVar5 == 0] + (int)-(uRam000000000118d5e8 ^ 0x61fa3116),
                    uVar3,puVar2);
      lVar5 = _objc_retainAutoreleasedReturnValue();
      (**(code **)(lVar5 + 0x10))();
      uVar9 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_detailTextLabel_0114b8e8);
      uVar4 = _objc_retainAutoreleasedReturnValue();
      _objc_msgSend(uVar4,PTR_s_setText__0114b388,uVar9);
      _objc_release(uVar4);
      _objc_release(uVar9);
      _objc_release(lVar5);
    }
    _objc_msgSend(uVar3,PTR_s_icon_0114cc30);
    lVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_release();
                    /* WARNING: Could not recover jumptable at 0x0011d528. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    IVar7 = (*(code *)((&PTR_LAB_0118d5f8)[lVar5 == 0] + (int)-(uRam000000000118d608 ^ 0xcf807cc0)))
                      ();
    return IVar7;
  }
  lVar8 = _objc_msgSend((&PTR_LAB_0118d5a0)[lVar5 == 0] + (int)-(uRam000000000118d5b0 ^ 0xb8262d79),
                        uVar3,puVar1);
  _objc_release(lVar5);
                    /* WARNING: Could not recover jumptable at 0x0011d3ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IVar7 = (*(code *)((&PTR_LAB_0118d5b8)[lVar8 == 3] + (int)-(uRam000000000118d5c8 ^ 0xd3040ec9)))()
  ;
  return IVar7;
}


