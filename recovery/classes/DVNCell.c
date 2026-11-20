// Decompiled implementation evidence for DVNCell. Not compilable source.

// -[DVNCell init], 0x18f954
/* Decompiled from supplied 5.2.2 arm package. VA 0x18f954. init */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::init(ID param_1,SEL param_2)

{
  ID IVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ID local_40;
  undefined *puStack_38;
  uint local_2c;
  undefined **local_28;
  
  local_28 = &PTR_LAB_011a9740;
  puStack_38 = PTR_DVNCell_0114f0c8;
  local_40 = param_1;
  IVar1 = _objc_msgSendSuper2(&local_40,@selector(init));
  local_2c = (uint)(IVar1 == 0);
  if (IVar1 != 0) {
    _objc_msgSend(PTR__OBJC_CLASS___NSUUID_0114eec0,@selector(UUID));
    uVar2 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar2,@selector(UUIDString));
    uVar3 = _objc_retainAutoreleasedReturnValue();
    uVar4 = *(undefined8 *)(IVar1 + 0x18);
    *(undefined8 *)(IVar1 + 0x18) = uVar3;
    _objc_release(uVar4);
    _objc_release(uVar2);
  }
  return IVar1;
}



// -[DVNCell identifier], 0x190a18
/* Decompiled from supplied 5.2.2 arm package. VA 0x190a18. identifier */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::identifier(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x10);
}



// -[DVNCell setIdentifier:], 0x190a20
/* Decompiled from supplied 5.2.2 arm package. VA 0x190a20. setIdentifier: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setIdentifier_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x10,param_3);
  CallSupervisor(0xb3a9);
  return;
}



// -[DVNCell reuseIdentifier], 0x190a54
/* Decompiled from supplied 5.2.2 arm package. VA 0x190a54. reuseIdentifier */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::reuseIdentifier(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x18);
}



// -[DVNCell title], 0x190a5c
/* Decompiled from supplied 5.2.2 arm package. VA 0x190a5c. title */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::title(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x20);
}



// -[DVNCell setTitle:], 0x190a64
/* Decompiled from supplied 5.2.2 arm package. VA 0x190a64. setTitle: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setTitle_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x20,param_3);
  return;
}



// -[DVNCell subtitle], 0x190a70
/* Decompiled from supplied 5.2.2 arm package. VA 0x190a70. subtitle */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::subtitle(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x28);
}



// -[DVNCell setSubtitle:], 0x190a78
/* Decompiled from supplied 5.2.2 arm package. VA 0x190a78. setSubtitle: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setSubtitle_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x28,param_3);
  CallSupervisor(0xfc8c);
  return;
}



// -[DVNCell detailText], 0x190aac
/* Decompiled from supplied 5.2.2 arm package. VA 0x190aac. detailText */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::detailText(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x30);
}



// -[DVNCell setDetailText:], 0x190ab4
/* Decompiled from supplied 5.2.2 arm package. VA 0x190ab4. setDetailText: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setDetailText_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x30,param_3);
  CallSupervisor(0xe61c);
  return;
}



// -[DVNCell key], 0x190ae8
/* Decompiled from supplied 5.2.2 arm package. VA 0x190ae8. key */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::key(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x38);
}



// -[DVNCell setKey:], 0x190af0
/* Decompiled from supplied 5.2.2 arm package. VA 0x190af0. setKey: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setKey_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x38,param_3);
  CallSupervisor(0x8106);
  return;
}



// -[DVNCell placeholder], 0x190b24
/* Decompiled from supplied 5.2.2 arm package. VA 0x190b24. placeholder */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::placeholder(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x40);
}



// -[DVNCell setPlaceholder:], 0x190b2c
/* Decompiled from supplied 5.2.2 arm package. VA 0x190b2c. setPlaceholder: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setPlaceholder_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x40,param_3);
  return;
}



// -[DVNCell titleIndexes], 0x190b38
/* Decompiled from supplied 5.2.2 arm package. VA 0x190b38. titleIndexes */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::titleIndexes(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x48);
}



// -[DVNCell setTitleIndexes:], 0x190b40
/* Decompiled from supplied 5.2.2 arm package. VA 0x190b40. setTitleIndexes: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setTitleIndexes_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x48,param_3);
  CallSupervisor(0x260c);
  return;
}



// -[DVNCell imageIndexes], 0x190b74
/* Decompiled from supplied 5.2.2 arm package. VA 0x190b74. imageIndexes */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::imageIndexes(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x50);
}



// -[DVNCell setImageIndexes:], 0x190b7c
/* Decompiled from supplied 5.2.2 arm package. VA 0x190b7c. setImageIndexes: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setImageIndexes_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x50,param_3);
  return;
}



// -[DVNCell dividerValue], 0x190b88
/* Decompiled from supplied 5.2.2 arm package. VA 0x190b88. dividerValue */

/* Function Stack Size: 0x10 bytes */

double DVNCell::dividerValue(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x58);
}



// -[DVNCell setDividerValue:], 0x190b90
/* Decompiled from supplied 5.2.2 arm package. VA 0x190b90. setDividerValue: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setDividerValue_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x58) = param_3;
  CallSupervisor(0xddd3);
  return;
}



// -[DVNCell minimumValue], 0x190bb0
/* Decompiled from supplied 5.2.2 arm package. VA 0x190bb0. minimumValue */

/* Function Stack Size: 0x10 bytes */

double DVNCell::minimumValue(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x60);
}



// -[DVNCell setMinimumValue:], 0x190bb8
/* Decompiled from supplied 5.2.2 arm package. VA 0x190bb8. setMinimumValue: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setMinimumValue_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x60) = param_3;
  CallSupervisor(0x9b33);
  return;
}



// -[DVNCell maximumValue], 0x190bd8
/* Decompiled from supplied 5.2.2 arm package. VA 0x190bd8. maximumValue */

/* Function Stack Size: 0x10 bytes */

double DVNCell::maximumValue(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x68);
}



// -[DVNCell setMaximumValue:], 0x190be0
/* Decompiled from supplied 5.2.2 arm package. VA 0x190be0. setMaximumValue: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setMaximumValue_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x68) = param_3;
  CallSupervisor(0x124c);
  return;
}



// -[DVNCell sliderFormat], 0x190c00
/* Decompiled from supplied 5.2.2 arm package. VA 0x190c00. sliderFormat */

/* Function Stack Size: 0x10 bytes */

long_long DVNCell::sliderFormat(ID param_1,SEL param_2)

{
  return *(long_long *)(param_1 + 0x70);
}



// -[DVNCell setSliderFormat:], 0x190c08
/* Decompiled from supplied 5.2.2 arm package. VA 0x190c08. setSliderFormat: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setSliderFormat_(ID param_1,SEL param_2,long_long param_3)

{
  *(long_long *)(param_1 + 0x70) = param_3;
  CallSupervisor(0x517f);
  return;
}



// -[DVNCell reloadsCell], 0x190c28
/* Decompiled from supplied 5.2.2 arm package. VA 0x190c28. reloadsCell */

/* Function Stack Size: 0x10 bytes */

bool DVNCell::reloadsCell(ID param_1,SEL param_2)

{
  return (bool)*(byte *)(param_1 + 8);
}



// -[DVNCell setReloadsCell:], 0x190c30
/* Decompiled from supplied 5.2.2 arm package. VA 0x190c30. setReloadsCell: */

/* Function Stack Size: 0x14 bytes */

void DVNCell::setReloadsCell_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 8) = (char)param_3;
  CallSupervisor(0xa540);
  return;
}



// -[DVNCell reloadsTable], 0x190c50
/* Decompiled from supplied 5.2.2 arm package. VA 0x190c50. reloadsTable */

/* Function Stack Size: 0x10 bytes */

bool DVNCell::reloadsTable(ID param_1,SEL param_2)

{
  return (bool)*(byte *)(param_1 + 9);
}



// -[DVNCell setReloadsTable:], 0x190c58
/* Decompiled from supplied 5.2.2 arm package. VA 0x190c58. setReloadsTable: */

/* Function Stack Size: 0x14 bytes */

void DVNCell::setReloadsTable_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 9) = (char)param_3;
  CallSupervisor(0xd27b);
  return;
}



// -[DVNCell shouldHideDetail], 0x190c78
/* Decompiled from supplied 5.2.2 arm package. VA 0x190c78. shouldHideDetail */

/* Function Stack Size: 0x10 bytes */

bool DVNCell::shouldHideDetail(ID param_1,SEL param_2)

{
  return (bool)*(byte *)(param_1 + 10);
}



// -[DVNCell setShouldHideDetail:], 0x190c80
/* Decompiled from supplied 5.2.2 arm package. VA 0x190c80. setShouldHideDetail: */

/* Function Stack Size: 0x14 bytes */

void DVNCell::setShouldHideDetail_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 10) = (char)param_3;
  CallSupervisor(0x52fe);
  return;
}



// -[DVNCell renderingMode], 0x190ca0
/* Decompiled from supplied 5.2.2 arm package. VA 0x190ca0. renderingMode */

/* Function Stack Size: 0x10 bytes */

long_long DVNCell::renderingMode(ID param_1,SEL param_2)

{
  return *(long_long *)(param_1 + 0x78);
}



// -[DVNCell setRenderingMode:], 0x190ca8
/* Decompiled from supplied 5.2.2 arm package. VA 0x190ca8. setRenderingMode: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setRenderingMode_(ID param_1,SEL param_2,long_long param_3)

{
  *(long_long *)(param_1 + 0x78) = param_3;
  CallSupervisor(0xb1e9);
  return;
}



// -[DVNCell icon], 0x190cc8
/* Decompiled from supplied 5.2.2 arm package. VA 0x190cc8. icon */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::icon(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x80);
}



// -[DVNCell setIcon:], 0x190cd0
/* Decompiled from supplied 5.2.2 arm package. VA 0x190cd0. setIcon: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setIcon_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x80,param_3);
  CallSupervisor(0xbad3);
  return;
}



// -[DVNCell image], 0x190d04
/* Decompiled from supplied 5.2.2 arm package. VA 0x190d04. image */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::image(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x88);
}



// -[DVNCell setImage:], 0x190d0c
/* Decompiled from supplied 5.2.2 arm package. VA 0x190d0c. setImage: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setImage_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x88,param_3);
  CallSupervisor(0xff73);
  return;
}



// -[DVNCell accessoryIcon], 0x190d40
/* Decompiled from supplied 5.2.2 arm package. VA 0x190d40. accessoryIcon */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::accessoryIcon(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x90);
}



// -[DVNCell setAccessoryIcon:], 0x190d48
/* Decompiled from supplied 5.2.2 arm package. VA 0x190d48. setAccessoryIcon: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setAccessoryIcon_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x90,param_3);
  CallSupervisor(0x746);
  return;
}



// -[DVNCell type], 0x190d7c
/* Decompiled from supplied 5.2.2 arm package. VA 0x190d7c. type */

/* Function Stack Size: 0x10 bytes */

long_long DVNCell::type(ID param_1,SEL param_2)

{
  return *(long_long *)(param_1 + 0x98);
}



// -[DVNCell setType:], 0x190d84
/* Decompiled from supplied 5.2.2 arm package. VA 0x190d84. setType: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setType_(ID param_1,SEL param_2,long_long param_3)

{
  *(long_long *)(param_1 + 0x98) = param_3;
  CallSupervisor(0xb182);
  return;
}



// -[DVNCell tintColor], 0x190da4
/* Decompiled from supplied 5.2.2 arm package. VA 0x190da4. tintColor */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::tintColor(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0xa0);
}



// -[DVNCell setTintColor:], 0x190dac
/* Decompiled from supplied 5.2.2 arm package. VA 0x190dac. setTintColor: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setTintColor_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0xa0,param_3);
  return;
}



// -[DVNCell sourceView], 0x190db8
/* Decompiled from supplied 5.2.2 arm package. VA 0x190db8. sourceView */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::sourceView(ID param_1,SEL param_2)

{
  ID IVar1;
  
  _objc_loadWeakRetained(param_1 + 0xa8);
  IVar1 = _objc_autoreleaseReturnValue();
  return IVar1;
}



// -[DVNCell setSourceView:], 0x190dd0
/* Decompiled from supplied 5.2.2 arm package. VA 0x190dd0. setSourceView: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setSourceView_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeWeak(param_1 + 0xa8,param_3);
  CallSupervisor(0x617e);
  return;
}



// -[DVNCell controllerModel], 0x190e04
/* Decompiled from supplied 5.2.2 arm package. VA 0x190e04. controllerModel */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::controllerModel(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0xb0);
}



// -[DVNCell setControllerModel:], 0x190e0c
/* Decompiled from supplied 5.2.2 arm package. VA 0x190e0c. setControllerModel: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setControllerModel_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0xb0,param_3);
  CallSupervisor(0x323e);
  return;
}



// -[DVNCell customData], 0x190e40
/* Decompiled from supplied 5.2.2 arm package. VA 0x190e40. customData */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::customData(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0xb8);
}



// -[DVNCell setCustomData:], 0x190e48
/* Decompiled from supplied 5.2.2 arm package. VA 0x190e48. setCustomData: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setCustomData_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0xb8,param_3);
  return;
}



// -[DVNCell handler], 0x190e54
/* Decompiled from supplied 5.2.2 arm package. VA 0x190e54. handler */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::handler(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0xc0);
}



// -[DVNCell setHandler:], 0x190e5c
/* Decompiled from supplied 5.2.2 arm package. VA 0x190e5c. setHandler: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setHandler_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0xef5a);
  return;
}



// -[DVNCell selfHandler], 0x190e8c
/* Decompiled from supplied 5.2.2 arm package. VA 0x190e8c. selfHandler */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::selfHandler(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 200);
}



// -[DVNCell setSelfHandler:], 0x190e94
/* Decompiled from supplied 5.2.2 arm package. VA 0x190e94. setSelfHandler: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setSelfHandler_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0xf075);
  return;
}



// -[DVNCell handlerWithCompletion], 0x190ec4
/* Decompiled from supplied 5.2.2 arm package. VA 0x190ec4. handlerWithCompletion */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::handlerWithCompletion(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0xd0);
}



// -[DVNCell setHandlerWithCompletion:], 0x190ecc
/* Decompiled from supplied 5.2.2 arm package. VA 0x190ecc. setHandlerWithCompletion: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setHandlerWithCompletion_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(2);
  return;
}



// -[DVNCell subtitleProvider], 0x190efc
/* Decompiled from supplied 5.2.2 arm package. VA 0x190efc. subtitleProvider */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::subtitleProvider(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0xd8);
}



// -[DVNCell setSubtitleProvider:], 0x190f04
/* Decompiled from supplied 5.2.2 arm package. VA 0x190f04. setSubtitleProvider: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setSubtitleProvider_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0xfdb3);
  return;
}



// -[DVNCell titleIndexesProvider], 0x190f34
/* Decompiled from supplied 5.2.2 arm package. VA 0x190f34. titleIndexesProvider */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::titleIndexesProvider(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0xe0);
}



// -[DVNCell setTitleIndexesProvider:], 0x190f3c
/* Decompiled from supplied 5.2.2 arm package. VA 0x190f3c. setTitleIndexesProvider: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setTitleIndexesProvider_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0x697e);
  return;
}



// -[DVNCell validationHandler], 0x190f6c
/* Decompiled from supplied 5.2.2 arm package. VA 0x190f6c. validationHandler */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::validationHandler(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0xe8);
}



// -[DVNCell setValidationHandler:], 0x190f74
/* Decompiled from supplied 5.2.2 arm package. VA 0x190f74. setValidationHandler: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setValidationHandler_(ID param_1,SEL param_2,ID param_3,undefined4 param_4)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0x1ec5);
  return;
}



// -[DVNCell errorText], 0x190fa4
/* Decompiled from supplied 5.2.2 arm package. VA 0x190fa4. errorText */

/* Function Stack Size: 0x10 bytes */

ID DVNCell::errorText(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0xf0);
}



// -[DVNCell setErrorText:], 0x190fac
/* Decompiled from supplied 5.2.2 arm package. VA 0x190fac. setErrorText: */

/* Function Stack Size: 0x18 bytes */

void DVNCell::setErrorText_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0xf0,param_3);
  CallSupervisor(0xd446);
  return;
}



// -[DVNCell .cxx_destruct], 0x190fe0
/* Decompiled from supplied 5.2.2 arm package. VA 0x190fe0. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void DVNCell::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0xf0,0);
  _objc_storeStrong(param_1 + 0xe8,0);
  _objc_storeStrong(param_1 + 0xe0,0);
  _objc_storeStrong(param_1 + 0xd8,0);
  _objc_storeStrong(param_1 + 0xd0,0);
  _objc_storeStrong(param_1 + 200,0);
  _objc_storeStrong(param_1 + 0xc0,0);
  _objc_storeStrong(param_1 + 0xb8,0);
  _objc_storeStrong(param_1 + 0xb0,0);
  _objc_destroyWeak(param_1 + 0xa8);
  _objc_storeStrong(param_1 + 0xa0,0);
  _objc_storeStrong(param_1 + 0x90,0);
  _objc_storeStrong(param_1 + 0x88,0);
  _objc_storeStrong(param_1 + 0x80,0);
  _objc_storeStrong(param_1 + 0x50,0);
  _objc_storeStrong(param_1 + 0x48,0);
  _objc_storeStrong(param_1 + 0x40,0);
  _objc_storeStrong(param_1 + 0x38,0);
  _objc_storeStrong(param_1 + 0x30,0);
  _objc_storeStrong(param_1 + 0x28,0);
  _objc_storeStrong(param_1 + 0x20,0);
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  CallSupervisor(0xf2e4);
  return;
}



// +[DVNCell controllerCellWithModel:title:subtitle:icon:], 0x18fa30
/* Decompiled from supplied 5.2.2 arm package. VA 0x18fa30. controllerCellWithModel:title:subtitle:icon: */

/* Function Stack Size: 0x30 bytes */

ID DVNCell::controllerCellWithModel_title_subtitle_icon_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setControllerModel:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setTitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setIcon:),param_6);
  _objc_release(param_6);
  _objc_msgSend(uVar2,@selector(setType:),4);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitleIndexes:key:], 0x18fb20
/* Decompiled from supplied 5.2.2 arm package. VA 0x18fb20. cellWithTitleIndexes:key: */

/* Function Stack Size: 0x20 bytes */

ID DVNCell::cellWithTitleIndexes_key_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitleIndexes:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setKey:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setType:),1);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithImageIndexes:key:], 0x18fbb8
/* Decompiled from supplied 5.2.2 arm package. VA 0x18fbb8. cellWithImageIndexes:key: */

/* Function Stack Size: 0x20 bytes */

ID DVNCell::cellWithImageIndexes_key_(ID param_1,SEL param_2,ID param_3,ID param_4)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setImageIndexes:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setKey:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setType:),1);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitle:subtitle:handler:], 0x18fc50
/* Decompiled from supplied 5.2.2 arm package. VA 0x18fc50. cellWithTitle:subtitle:handler: */

/* Function Stack Size: 0x28 bytes */

ID DVNCell::cellWithTitle_subtitle_handler_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setHandler:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setType:),5);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitle:subtitle:selfHandler:], 0x18fd10
/* Decompiled from supplied 5.2.2 arm package. VA 0x18fd10. cellWithTitle:subtitle:selfHandler: */

/* Function Stack Size: 0x28 bytes */

ID DVNCell::cellWithTitle_subtitle_selfHandler_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setSelfHandler:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setType:),5);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitle:subtitle:type:key:], 0x18fdd0
/* Decompiled from supplied 5.2.2 arm package. VA 0x18fdd0. cellWithTitle:subtitle:type:key: */

/* Function Stack Size: 0x30 bytes */

ID DVNCell::cellWithTitle_subtitle_type_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,long_long param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_6);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setType:),param_5);
  _objc_msgSend(uVar2,@selector(setKey:),param_6);
  _objc_release(param_6);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitle:subtitle:icon:type:key:], 0x18fe9c
/* Decompiled from supplied 5.2.2 arm package. VA 0x18fe9c. cellWithTitle:subtitle:icon:type:key: */

/* Function Stack Size: 0x38 bytes */

ID DVNCell::cellWithTitle_subtitle_icon_type_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,long_long param_6,ID param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_7);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setIcon:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setType:),param_6);
  _objc_msgSend(uVar2,@selector(setKey:),param_7);
  _objc_release(param_7);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitle:subtitle:imageIndexes:key:], 0x18ff90
/* Decompiled from supplied 5.2.2 arm package. VA 0x18ff90. cellWithTitle:subtitle:imageIndexes:key: */

/* Function Stack Size: 0x30 bytes */

ID DVNCell::cellWithTitle_subtitle_imageIndexes_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setImageIndexes:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setType:),2);
  _objc_msgSend(uVar2,@selector(setKey:),param_6);
  _objc_release(param_6);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitle:subtitle:titleIndexes:key:], 0x190080
/* Decompiled from supplied 5.2.2 arm package. VA 0x190080. cellWithTitle:subtitle:titleIndexes:key: */

/* Function Stack Size: 0x30 bytes */

ID DVNCell::cellWithTitle_subtitle_titleIndexes_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setTitleIndexes:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setType:),2);
  _objc_msgSend(uVar2,@selector(setKey:),param_6);
  _objc_release(param_6);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitle:subtitle:titleIndexes:type:key:], 0x190170
/* Decompiled from supplied 5.2.2 arm package. VA 0x190170. cellWithTitle:subtitle:titleIndexes:type:key: */

/* Function Stack Size: 0x38 bytes */

ID DVNCell::cellWithTitle_subtitle_titleIndexes_type_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,long_long param_6,ID param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_7);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setTitleIndexes:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setType:),param_6);
  _objc_msgSend(uVar2,@selector(setKey:),param_7);
  _objc_release(param_7);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitle:subtitle:icon:accessoryIcon:type:key:], 0x190264
/* Decompiled from supplied 5.2.2 arm package. VA 0x190264. cellWithTitle:subtitle:icon:accessoryIcon:type:key: */

/* Function Stack Size: 0x40 bytes */

ID DVNCell::cellWithTitle_subtitle_icon_accessoryIcon_type_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,long_long param_7,
             ID param_8)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_8);
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setIcon:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setAccessoryIcon:),param_6);
  _objc_release(param_6);
  _objc_msgSend(uVar2,@selector(setType:),param_7);
  _objc_msgSend(uVar2,@selector(setKey:),param_8);
  _objc_release(param_8);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitle:subtitle:icon:accessoryIcon:type:handler:], 0x190388
/* Decompiled from supplied 5.2.2 arm package. VA 0x190388. cellWithTitle:subtitle:icon:accessoryIcon:type:handler: */

/* Function Stack Size: 0x40 bytes */

ID DVNCell::cellWithTitle_subtitle_icon_accessoryIcon_type_handler_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,long_long param_7,
             ID param_8,undefined4 param_9)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_8);
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setIcon:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setAccessoryIcon:),param_6);
  _objc_release(param_6);
  _objc_msgSend(uVar2,@selector(setType:),param_7);
  _objc_msgSend(uVar2,@selector(setHandler:),param_8);
  _objc_release(param_8);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell cellWithTitle:subtitle:image:accessoryIcon:type:handler:], 0x1904ac
/* Decompiled from supplied 5.2.2 arm package. VA 0x1904ac. cellWithTitle:subtitle:image:accessoryIcon:type:handler: */

/* Function Stack Size: 0x40 bytes */

ID DVNCell::cellWithTitle_subtitle_image_accessoryIcon_type_handler_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6,long_long param_7,
             ID param_8,undefined4 param_9)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_8);
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setImage:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setRenderingMode:),1);
  _objc_msgSend(uVar2,@selector(setAccessoryIcon:),param_6);
  _objc_release(param_6);
  _objc_msgSend(uVar2,@selector(setType:),param_7);
  _objc_msgSend(uVar2,@selector(setSelfHandler:),param_8);
  _objc_release(param_8);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell sliderCellWithMinimum:maximum:divider:key:], 0x1905e4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1905e4. sliderCellWithMinimum:maximum:divider:key: */

/* Function Stack Size: 0x30 bytes */

ID DVNCell::sliderCellWithMinimum_maximum_divider_key_
             (ID param_1,SEL param_2,double param_3,double param_4,double param_5,ID param_6)

{
  ID IVar1;
  
  IVar1 = _objc_msgSend(param_1,@selector(sliderCellWithMinimum:maximum:divider:format:key:),0,param_6);
  return IVar1;
}



// +[DVNCell sliderCellWithMinimum:maximum:divider:format:key:], 0x1905f8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1905f8. sliderCellWithMinimum:maximum:divider:format:key: */

/* Function Stack Size: 0x38 bytes */

ID DVNCell::sliderCellWithMinimum_maximum_divider_format_key_
             (ID param_1,SEL param_2,double param_3,double param_4,double param_5,long_long param_6,
             ID param_7)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_7);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(param_3,uVar2,@selector(setMinimumValue:));
  _objc_msgSend(param_4,uVar2,@selector(setMaximumValue:));
  _objc_msgSend(param_5,uVar2,@selector(setDividerValue:));
  _objc_msgSend(uVar2,@selector(setSliderFormat:),param_6);
  _objc_msgSend(uVar2,@selector(setType:),6);
  _objc_msgSend(uVar2,@selector(setKey:),param_7);
  _objc_release(param_7);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell textFieldCellWithTitle:subtitle:placeholder:key:], 0x1906d8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1906d8. textFieldCellWithTitle:subtitle:placeholder:key: */

/* Function Stack Size: 0x30 bytes */

ID DVNCell::textFieldCellWithTitle_subtitle_placeholder_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,ID param_5,ID param_6)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_6);
  _objc_retain(param_5);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(uVar2,@selector(setPlaceholder:),param_5);
  _objc_release(param_5);
  _objc_msgSend(uVar2,@selector(setType:),10);
  _objc_msgSend(uVar2,@selector(setKey:),param_6);
  _objc_release(param_6);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell timePickerWithTitle:subtitle:minimum:maximum:format:key:], 0x1907c8
/* Decompiled from supplied 5.2.2 arm package. VA 0x1907c8. timePickerWithTitle:subtitle:minimum:maximum:format:key: */

/* Function Stack Size: 0x40 bytes */

ID DVNCell::timePickerWithTitle_subtitle_minimum_maximum_format_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,double param_5,double param_6,
             long_long param_7,ID param_8)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_8);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(param_5,uVar2,@selector(setMinimumValue:));
  _objc_msgSend(param_6,uVar2,@selector(setMaximumValue:));
  _objc_msgSend(uVar2,@selector(setSliderFormat:),param_7);
  _objc_msgSend(uVar2,@selector(setType:),7);
  _objc_msgSend(uVar2,@selector(setKey:),param_8);
  _objc_release(param_8);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}



// +[DVNCell stepperCellWithTitle:subtitle:minimum:maximum:step:format:key:], 0x1908e0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1908e0. stepperCellWithTitle:subtitle:minimum:maximum:step:format:key: */

/* Function Stack Size: 0x48 bytes */

ID DVNCell::stepperCellWithTitle_subtitle_minimum_maximum_step_format_key_
             (ID param_1,SEL param_2,ID param_3,ID param_4,double param_5,double param_6,
             double param_7,long_long param_8,ID param_9)

{
  undefined *puVar1;
  undefined8 uVar2;
  ID IVar3;
  
  puVar1 = PTR_DVNCell_0114ee98;
  _objc_retain(param_9);
  _objc_retain(param_4);
  _objc_retain(param_3);
  uVar2 = _objc_alloc_init(puVar1);
  _objc_msgSend(uVar2,@selector(setTitle:),param_3);
  _objc_release(param_3);
  _objc_msgSend(uVar2,@selector(setSubtitle:),param_4);
  _objc_release(param_4);
  _objc_msgSend(param_5,uVar2,@selector(setMinimumValue:));
  _objc_msgSend(param_6,uVar2,@selector(setMaximumValue:));
  _objc_msgSend(param_7,uVar2,@selector(setDividerValue:));
  _objc_msgSend(uVar2,@selector(setSliderFormat:),param_8);
  _objc_msgSend(uVar2,@selector(setType:),9);
  _objc_msgSend(uVar2,@selector(setKey:),param_9);
  _objc_release(param_9);
  IVar3 = _objc_autoreleaseReturnValue(uVar2);
  return IVar3;
}


