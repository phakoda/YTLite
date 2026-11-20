/* Decompiled from supplied 5.2.2 arm package. VA 0x1e1bd4. tableView:heightForRowAtIndexPath: */

/* Function Stack Size: 0x20 bytes */

double TranslatorVC::tableView_heightForRowAtIndexPath_
                 (ID param_1,SEL param_2,ID param_3,ID param_4)

{
  long lVar1;
  long lVar2;
  double dVar3;
  
  lVar1 = _objc_msgSend(param_4,PTR_s_section_0114af60);
  lVar2 = _objc_msgSend(*(undefined8 *)(param_1 + (long)_sections),PTR_s_indexOfObject__0114b020,
                        *(undefined8 *)(param_1 + (long)_translation));
  dVar3 = DAT_00c4c238;
  if (lVar1 != lVar2) {
    dVar3 = *(double *)PTR__UITableViewAutomaticDimension_010605d8;
  }
  return dVar3;
}


