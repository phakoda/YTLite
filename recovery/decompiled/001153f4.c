/* Decompiled from supplied 5.2.2 arm package. VA 0x1153f4. setSelected:animated: */

/* Function Stack Size: 0x18 bytes */

void YTPTableViewCell::setSelected_animated_(ID param_1,SEL param_2,bool param_3,bool param_4)

{
  ID local_50;
  undefined *puStack_48;
  bool local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_0118b518;
  puStack_48 = PTR_YTPTableViewCell_0114f098;
  local_50 = param_1;
  _objc_msgSendSuper2(&local_50,PTR_s_setSelected_animated__0114d0c0,param_3,param_4);
  local_3c = param_3;
                    /* WARNING: Could not recover jumptable at 0x0011546c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(local_38[param_3] + (int)-(DAT_0118b528 ^ 0x4df2eae4)))();
  return;
}


