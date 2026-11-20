/* Decompiled from supplied 5.2.2 arm package. VA 0x11c698. tableView:heightForFooterInSection: */

/* Function Stack Size: 0x20 bytes */

double DVNTableViewController::tableView_heightForFooterInSection_
                 (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  double in_d2;
  double in_d3;
  double dVar4;
  undefined8 uStack_58;
  undefined8 uStack_50;
  long local_48;
  
  local_48 = *(long *)PTR____stack_chk_guard_01060708;
  _objc_retain(param_3);
  _objc_msgSend(param_1,PTR_s_tableView_titleForFooterInSectio_0114d360,param_3,param_4);
  lVar1 = _objc_retainAutoreleasedReturnValue();
  if (lVar1 == 0) {
    dVar4 = 0.0;
  }
  else {
    _objc_msgSend(param_3,PTR_s_frame_0114c8b0);
    uStack_58 = *(undefined8 *)PTR__NSFontAttributeName_01060368;
    _objc_msgSend(0x402a000000000000,*(undefined8 *)PTR__UIFontWeightLight_01060568,
                  PTR__OBJC_CLASS___UIFont_0114ec08,PTR_s_systemFontOfSize_weight__0114d330);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    uStack_50 = uVar2;
    _objc_msgSend(PTR__OBJC_CLASS___NSDictionary_0114eb40,
                  PTR_s_dictionaryWithObjects_forKeys_co_0114b420,&uStack_50,&uStack_58,1);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(in_d2 + -40.0,0x7fefffffffffffff,lVar1,
                  PTR_s_boundingRectWithSize_options_att_0114d368,1,uVar3,0);
    _objc_release(uVar3);
    _objc_release(uVar2);
    dVar4 = (double)(long)in_d3 + 10.0;
  }
  _objc_release(lVar1);
  _objc_release(param_3);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_48) {
    return dVar4;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


