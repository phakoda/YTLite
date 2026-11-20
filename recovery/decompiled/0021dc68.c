/* Decompiled from supplied 5.2.2 arm package. VA 0x21dc68. sendBody */

/* Function Stack Size: 0x10 bytes */

void YTPDiscordRPC::sendBody(ID param_1,SEL param_2)

{
  bool bVar1;
  long lVar2;
  undefined8 uVar3;
  undefined *puVar4;
  double dVar5;
  
  _objc_msgSend(param_1,PTR_s_buildBody_0114e5f8);
  lVar2 = _objc_retainAutoreleasedReturnValue();
  if (lVar2 == 0) goto LAB_0021ddc8;
  _objc_msgSend(PTR__OBJC_CLASS___NSDate_0114ebb8,PTR_s_date_0114b4d0);
  uVar3 = _objc_retainAutoreleasedReturnValue();
  bVar1 = *(long *)(param_1 + 0x10) == 0;
  puVar4 = (&PTR_LAB_011cdf08)[bVar1] + (int)-(uRam00000000011cdf18 ^ 0x98709ab4);
  if (bVar1) {
LAB_0021dda0:
    _objc_storeStrong(puVar4,(long *)(param_1 + 0x10),uVar3);
    _objc_msgSend(param_1,PTR_s__send__0114e5d8,lVar2);
  }
  else {
    dVar5 = (double)_objc_msgSend(uVar3,PTR_s_timeIntervalSinceDate__0114e488);
    puVar4 = (&PTR_LAB_011cdf20)[dVar5 < 1.0] + (int)-(uRam00000000011cdf30 ^ 0x5489e549);
    if (dVar5 >= 1.0) goto LAB_0021dda0;
  }
  _objc_release(uVar3);
LAB_0021ddc8:
  (*(code *)PTR__objc_release_01061028)(lVar2);
  return;
}


