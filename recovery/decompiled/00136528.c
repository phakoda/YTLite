/* Decompiled from supplied 5.2.2 arm package. VA 0x136528. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void TabbarVC::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + (long)_inactiveTabs,0);
  _objc_storeStrong(param_1 + (long)_activeTabs,0);
  _objc_storeStrong(param_1 + (long)_tabbar,0);
  _objc_storeStrong(param_1 + (long)_startup,0);
  _objc_storeStrong(param_1 + (long)_tabs,0);
  _objc_storeStrong(param_1 + (long)_sections,0);
  CallSupervisor(0x4a1c);
  return;
}


