/* Decompiled from supplied 5.2.2 arm package. VA 0x238360. speedControls */

/* Function Stack Size: 0x10 bytes */

ID YTPSpeedControlView::speedControls(ID param_1,SEL param_2)

{
  undefined8 uVar1;
  ID IVar2;
  
  uVar1 = _objc_alloc(PTR_YTPSpeedControlView_0114f030);
  _objc_msgSend(*(undefined8 *)PTR__CGRectZero_01060260,
                *(undefined8 *)(PTR__CGRectZero_01060260 + 8),
                *(undefined8 *)(PTR__CGRectZero_01060260 + 0x10),
                *(undefined8 *)(PTR__CGRectZero_01060260 + 0x18),uVar1,PTR_s_initWithFrame__0114b770
               );
  IVar2 = _objc_autoreleaseReturnValue();
  return IVar2;
}


