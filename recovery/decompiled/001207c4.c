/* Decompiled from supplied 5.2.2 arm package. VA 0x1207c4. pickerView:numberOfRowsInComponent: */

/* Function Stack Size: 0x20 bytes */

long_long DVNTableViewController::pickerView_numberOfRowsInComponent_
                    (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined8 uVar1;
  double dVar2;
  
  uVar1 = _objc_msgSend(param_3,PTR_s_tag_0114b868);
  _objc_msgSend(param_1,PTR_s__cellForTag__0114d510,uVar1);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  dVar2 = (double)_objc_msgSend(uVar1,PTR_s_maximumValue_0114d408);
  _objc_release(uVar1);
  return (long)(dVar2 + 1.0);
}


