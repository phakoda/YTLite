/* Decompiled from supplied 5.2.2 arm package. VA 0x18ef44. addCell: */

/* Function Stack Size: 0x18 bytes */

void DVNSection::addCell_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined8 uVar3;
  ID local_40;
  long local_38;
  
  puVar2 = PTR__OBJC_CLASS___NSArray_0114ec18;
  puVar1 = PTR_s_arrayWithObjects_count__0114b600;
  local_38 = *(long *)PTR____stack_chk_guard_01060708;
  local_40 = param_3;
  _objc_retain(param_3);
  _objc_msgSend(puVar2,puVar1,&local_40,1);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  _objc_msgSend(param_1,PTR_s__appendCells__0114d9b0,uVar3);
  _objc_release(param_3);
  _objc_release(uVar3);
  CallSupervisor(0x7690);
  if (*(long *)PTR____stack_chk_guard_01060708 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(0x1a,0x1f,0,0);
}


