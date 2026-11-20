/* Decompiled from supplied 5.2.2 arm package. VA 0x1cce24. init */

/* Function Stack Size: 0x10 bytes */

ID Downloader::init(ID param_1,SEL param_2)

{
  undefined *puVar1;
  ID IVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ID local_50;
  undefined *puStack_48;
  uint local_3c;
  undefined **local_38;
  
  local_38 = &PTR_LAB_011b6008;
  puStack_48 = PTR_Downloader_0114f100;
  local_50 = param_1;
  IVar2 = _objc_msgSendSuper2(&local_50,PTR_s_init_0114d960);
  local_3c = (uint)(IVar2 == 0);
  if (IVar2 != 0) {
    *(undefined8 *)(IVar2 + 0x20) = 0x500000;
    *(undefined8 *)(IVar2 + 0x30) = 0;
    puVar1 = PTR__OBJC_CLASS___NSURLSession_0114eeb0;
    _objc_msgSend(PTR__OBJC_CLASS___NSURLSessionConfiguration_0114ef88,
                  PTR_s_defaultSessionConfiguration_0114df00);
    uVar3 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(PTR__OBJC_CLASS___NSOperationQueue_0114ed28,PTR_s_mainQueue_0114c4a8);
    uVar4 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(puVar1,PTR_s_sessionWithConfiguration_delegat_0114df08,uVar3,IVar2,uVar4);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = *(undefined8 *)(IVar2 + 8);
    *(undefined8 *)(IVar2 + 8) = uVar5;
    _objc_release(uVar6);
    _objc_release(uVar4);
    _objc_release(uVar3);
  }
  return IVar2;
}


