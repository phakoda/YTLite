/* Decompiled from supplied 5.2.2 arm package. VA 0x1ce510. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void Downloader::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_destroyWeak(param_1 + 0x58);
  _objc_storeStrong(param_1 + 0x40,0);
  _objc_storeStrong(param_1 + 0x38,0);
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  _objc_storeStrong(param_1 + 8,0);
  CallSupervisor(0xb5b);
  return;
}


