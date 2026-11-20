/* Decompiled from supplied 5.2.2 arm package. VA 0x11c868. numberOfSectionsInTableView: */

/* Function Stack Size: 0x18 bytes */

long_long DVNTableViewController::numberOfSectionsInTableView_(ID param_1,SEL param_2,ID param_3)

{
  long_long lVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + (long)_isSearching) == '\0') {
    _objc_msgSend(*(undefined8 *)(param_1 + (long)_model),PTR_s_sections_0114d240);
    uVar2 = _objc_retainAutoreleasedReturnValue();
    lVar1 = _objc_msgSend(uVar2,PTR_s_count_0114b840);
    _objc_release(uVar2);
  }
  else {
    lVar1 = 1;
  }
  return lVar1;
}


