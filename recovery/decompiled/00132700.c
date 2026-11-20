/* Decompiled from supplied 5.2.2 arm package. VA 0x132700. tableView:numberOfRowsInSection: */

/* Function Stack Size: 0x20 bytes */

long_long TabbarVC::tableView_numberOfRowsInSection_
                    (ID param_1,SEL param_2,ID param_3,long_long param_4)

{
  undefined8 uVar1;
  long_long lVar2;
  
  _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),PTR_s_objectAtIndexedSubscript__0114aeb0,
                param_4);
  uVar1 = _objc_retainAutoreleasedReturnValue();
  lVar2 = _objc_msgSend(uVar1,PTR_s_count_0114b840);
  _objc_release(uVar1);
  return lVar2;
}


