// Decompiled implementation evidence for RPCMedia. Not compilable source.

// -[RPCMedia videoID], 0x21af10
/* Decompiled from supplied 5.2.2 arm package. VA 0x21af10. videoID */

/* Function Stack Size: 0x10 bytes */

ID RPCMedia::videoID(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x10);
}



// -[RPCMedia setVideoID:], 0x21af18
/* Decompiled from supplied 5.2.2 arm package. VA 0x21af18. setVideoID: */

/* Function Stack Size: 0x18 bytes */

void RPCMedia::setVideoID_(ID param_1,SEL param_2,ID param_3)

{
  _objc_setProperty_nonatomic_copy();
  return;
}



// -[RPCMedia title], 0x21af20
/* Decompiled from supplied 5.2.2 arm package. VA 0x21af20. title */

/* Function Stack Size: 0x10 bytes */

ID RPCMedia::title(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x18);
}



// -[RPCMedia setTitle:], 0x21af28
/* Decompiled from supplied 5.2.2 arm package. VA 0x21af28. setTitle: */

/* Function Stack Size: 0x18 bytes */

void RPCMedia::setTitle_(ID param_1,SEL param_2,ID param_3)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0x7cb9);
  return;
}



// -[RPCMedia author], 0x21af58
/* Decompiled from supplied 5.2.2 arm package. VA 0x21af58. author */

/* Function Stack Size: 0x10 bytes */

ID RPCMedia::author(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x20);
}



// -[RPCMedia setAuthor:], 0x21af60
/* Decompiled from supplied 5.2.2 arm package. VA 0x21af60. setAuthor: */

/* Function Stack Size: 0x18 bytes */

void RPCMedia::setAuthor_(ID param_1,SEL param_2,ID param_3)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0x86b9);
  return;
}



// -[RPCMedia isPaused], 0x21af90
/* Decompiled from supplied 5.2.2 arm package. VA 0x21af90. isPaused */

/* Function Stack Size: 0x10 bytes */

bool RPCMedia::isPaused(ID param_1,SEL param_2)

{
  return (bool)*(byte *)(param_1 + 8);
}



// -[RPCMedia setIsPaused:], 0x21af98
/* Decompiled from supplied 5.2.2 arm package. VA 0x21af98. setIsPaused: */

/* Function Stack Size: 0x14 bytes */

void RPCMedia::setIsPaused_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 8) = (char)param_3;
  CallSupervisor(0x8c24);
  return;
}



// -[RPCMedia totalTime], 0x21afb8
/* Decompiled from supplied 5.2.2 arm package. VA 0x21afb8. totalTime */

/* Function Stack Size: 0x10 bytes */

double RPCMedia::totalTime(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x28);
}



// -[RPCMedia setTotalTime:], 0x21afc0
/* Decompiled from supplied 5.2.2 arm package. VA 0x21afc0. setTotalTime: */

/* Function Stack Size: 0x18 bytes */

void RPCMedia::setTotalTime_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x28) = param_3;
  CallSupervisor(0x29bd);
  return;
}



// -[RPCMedia currentTime], 0x21afe0
/* Decompiled from supplied 5.2.2 arm package. VA 0x21afe0. currentTime */

/* Function Stack Size: 0x10 bytes */

double RPCMedia::currentTime(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x30);
}



// -[RPCMedia setCurrentTime:], 0x21afe8
/* Decompiled from supplied 5.2.2 arm package. VA 0x21afe8. setCurrentTime: */

/* Function Stack Size: 0x18 bytes */

void RPCMedia::setCurrentTime_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x30) = param_3;
  CallSupervisor(0xc545);
  return;
}



// -[RPCMedia thumbnailURL], 0x21b008
/* Decompiled from supplied 5.2.2 arm package. VA 0x21b008. thumbnailURL */

/* Function Stack Size: 0x10 bytes */

ID RPCMedia::thumbnailURL(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x38);
}



// -[RPCMedia setThumbnailURL:], 0x21b010
/* Decompiled from supplied 5.2.2 arm package. VA 0x21b010. setThumbnailURL: */

/* Function Stack Size: 0x18 bytes */

void RPCMedia::setThumbnailURL_(ID param_1,SEL param_2,ID param_3)

{
  _objc_setProperty_nonatomic_copy();
  CallSupervisor(0x496d);
  return;
}



// -[RPCMedia .cxx_destruct], 0x21b040
/* Decompiled from supplied 5.2.2 arm package. VA 0x21b040. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void RPCMedia::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x38,0);
  _objc_storeStrong(param_1 + 0x20,0);
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  return;
}



// +[RPCMedia mediaWithPlayer:], 0x21aaf0
/* Decompiled from supplied 5.2.2 arm package. VA 0x21aaf0. mediaWithPlayer: */

/* Function Stack Size: 0x18 bytes */

ID RPCMedia::mediaWithPlayer_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  ID IVar11;
  undefined *puVar12;
  undefined8 uVar13;
  undefined *puVar14;
  
  _objc_retain(param_3);
  puVar14 = @selector(playerResponse);
  puVar1 = @selector(respondsToSelector:);
  uVar3 = FUN_0021b09c(param_3,@selector(respondsToSelector:),@selector(playerResponse));
  puVar2 = @selector(contentPlayerResponse);
  puVar12 = (&PTR_LAB_011cce50)[uVar3] + (int)-(DAT_011cce60 ^ 0x9f09908);
  if (uVar3 == 0) {
    uVar3 = FUN_0021b404(param_3,puVar1,@selector(contentPlayerResponse));
    uVar13 = 0;
    puVar12 = (&PTR_LAB_011cce68)[uVar3] + (int)-(uRam00000000011cce78 ^ 0xd18c5f8a);
    puVar14 = puVar2;
    if (uVar3 == 0) goto LAB_0021aee4;
  }
  _objc_msgSend(puVar12,param_3,puVar14);
  lVar4 = _objc_retainAutoreleasedReturnValue();
  uVar13 = 0;
  if (lVar4 != 0) {
    uVar13 = _objc_alloc_init(PTR_RPCMedia_0114ead0);
    _objc_msgSend(param_3,@selector(currentVideoID));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,@selector(setVideoID:),uVar5);
    _objc_release(uVar5);
    puVar1 = @selector(playerData);
    _objc_msgSend(lVar4,@selector(playerData));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    puVar14 = @selector(videoDetails);
    _objc_msgSend(uVar5,@selector(videoDetails));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(title));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,@selector(setTitle:),uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(lVar4,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar14);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(author));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,@selector(setAuthor:),uVar7);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    puVar12 = @selector(activeVideo);
    _objc_msgSend(param_3,@selector(activeVideo));
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(totalMediaTime));
    _objc_msgSend(uVar13,@selector(setTotalTime:));
    _objc_release(uVar5);
    _objc_msgSend(param_3,puVar12);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,@selector(currentVideoTime));
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(time));
    _objc_msgSend(uVar13,@selector(setCurrentTime:));
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_msgSend(lVar4,puVar1);
    uVar5 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar5,puVar14);
    uVar6 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar6,@selector(thumbnail));
    uVar7 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar7,@selector(thumbnailsArray));
    uVar8 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar8,@selector(objectAtIndexedSubscript:),0);
    uVar9 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar9,@selector(URL));
    uVar10 = _objc_retainAutoreleasedReturnValue();
    _objc_msgSend(uVar13,@selector(setThumbnailURL:),uVar10);
    _objc_release(uVar10);
    _objc_release(uVar9);
    _objc_release(uVar8);
    _objc_release(uVar7);
    _objc_release(uVar6);
    _objc_release(uVar5);
    _objc_release(lVar4);
  }
LAB_0021aee4:
  _objc_release(param_3);
  IVar11 = (*(code *)PTR__objc_autoreleaseReturnValue_01060fb0)(uVar13);
  return IVar11;
}


