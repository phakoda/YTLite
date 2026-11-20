// Decompiled implementation evidence for SBPlayerDecorationData. Not compilable source.

// -[SBPlayerDecorationData segments], 0x1a30c4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a30c4. segments */

/* Function Stack Size: 0x10 bytes */

ID SBPlayerDecorationData::segments(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 8);
}



// -[SBPlayerDecorationData setSegments:], 0x1a30cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a30cc. setSegments: */

/* Function Stack Size: 0x18 bytes */

void SBPlayerDecorationData::setSegments_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 8,param_3);
  CallSupervisor(0xf4d4);
  return;
}



// -[SBPlayerDecorationData playerBarWidth], 0x1a3100
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a3100. playerBarWidth */

/* Function Stack Size: 0x10 bytes */

double SBPlayerDecorationData::playerBarWidth(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x10);
}



// -[SBPlayerDecorationData setPlayerBarWidth:], 0x1a3108
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a3108. setPlayerBarWidth: */

/* Function Stack Size: 0x18 bytes */

void SBPlayerDecorationData::setPlayerBarWidth_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x10) = param_3;
  CallSupervisor(0xeb56);
  return;
}



// -[SBPlayerDecorationData mediaDuration], 0x1a3128
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a3128. mediaDuration */

/* Function Stack Size: 0x10 bytes */

double SBPlayerDecorationData::mediaDuration(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x18);
}



// -[SBPlayerDecorationData setMediaDuration:], 0x1a3130
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a3130. setMediaDuration: */

/* Function Stack Size: 0x18 bytes */

void SBPlayerDecorationData::setMediaDuration_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x18) = param_3;
  CallSupervisor(0xd511);
  return;
}



// -[SBPlayerDecorationData barView], 0x1a3150
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a3150. barView */

/* Function Stack Size: 0x10 bytes */

ID SBPlayerDecorationData::barView(ID param_1,SEL param_2)

{
  ID IVar1;
  
  _objc_loadWeakRetained(param_1 + 0x20);
  IVar1 = _objc_autoreleaseReturnValue();
  return IVar1;
}



// -[SBPlayerDecorationData setBarView:], 0x1a3168
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a3168. setBarView: */

/* Function Stack Size: 0x18 bytes */

void SBPlayerDecorationData::setBarView_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeWeak(param_1 + 0x20,param_3);
  return;
}



// -[SBPlayerDecorationData .cxx_destruct], 0x1a3174
/* Decompiled from supplied 5.2.2 arm package. VA 0x1a3174. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void SBPlayerDecorationData::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_destroyWeak(param_1 + 0x20);
  _objc_storeStrong(param_1 + 8,0);
  return;
}


