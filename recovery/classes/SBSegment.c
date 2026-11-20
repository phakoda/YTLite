// Decompiled implementation evidence for SBSegment. Not compilable source.

// -[SBSegment uuid], 0x19435c
/* Decompiled from supplied 5.2.2 arm package. VA 0x19435c. uuid */

/* Function Stack Size: 0x10 bytes */

ID SBSegment::uuid(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x10);
}



// -[SBSegment setUuid:], 0x194364
/* Decompiled from supplied 5.2.2 arm package. VA 0x194364. setUuid: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setUuid_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x10,param_3);
  CallSupervisor(0x193f);
  return;
}



// -[SBSegment category], 0x194398
/* Decompiled from supplied 5.2.2 arm package. VA 0x194398. category */

/* Function Stack Size: 0x10 bytes */

ID SBSegment::category(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x18);
}



// -[SBSegment setCategory:], 0x1943a0
/* Decompiled from supplied 5.2.2 arm package. VA 0x1943a0. setCategory: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setCategory_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x18,param_3);
  CallSupervisor(0xbc0a);
  return;
}



// -[SBSegment actionType], 0x1943d4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1943d4. actionType */

/* Function Stack Size: 0x10 bytes */

ID SBSegment::actionType(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x20);
}



// -[SBSegment setActionType:], 0x1943dc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1943dc. setActionType: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setActionType_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x20,param_3);
  CallSupervisor(0x1d09);
  return;
}



// -[SBSegment segmentDescription], 0x194410
/* Decompiled from supplied 5.2.2 arm package. VA 0x194410. segmentDescription */

/* Function Stack Size: 0x10 bytes */

ID SBSegment::segmentDescription(ID param_1,SEL param_2)

{
  return *(ID *)(param_1 + 0x28);
}



// -[SBSegment setSegmentDescription:], 0x194418
/* Decompiled from supplied 5.2.2 arm package. VA 0x194418. setSegmentDescription: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setSegmentDescription_(ID param_1,SEL param_2,ID param_3)

{
  _objc_storeStrong(param_1 + 0x28,param_3);
  CallSupervisor(0xb8b3);
  return;
}



// -[SBSegment start], 0x19444c
/* Decompiled from supplied 5.2.2 arm package. VA 0x19444c. start */

/* Function Stack Size: 0x10 bytes */

double SBSegment::start(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x30);
}



// -[SBSegment setStart:], 0x194454
/* Decompiled from supplied 5.2.2 arm package. VA 0x194454. setStart: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setStart_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x30) = param_3;
  CallSupervisor(0x199f);
  return;
}



// -[SBSegment end], 0x194474
/* Decompiled from supplied 5.2.2 arm package. VA 0x194474. end */

/* Function Stack Size: 0x10 bytes */

double SBSegment::end(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x38);
}



// -[SBSegment setEnd:], 0x19447c
/* Decompiled from supplied 5.2.2 arm package. VA 0x19447c. setEnd: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setEnd_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x38) = param_3;
  CallSupervisor(0x96a9);
  return;
}



// -[SBSegment videoDuration], 0x19449c
/* Decompiled from supplied 5.2.2 arm package. VA 0x19449c. videoDuration */

/* Function Stack Size: 0x10 bytes */

double SBSegment::videoDuration(ID param_1,SEL param_2)

{
  return *(double *)(param_1 + 0x40);
}



// -[SBSegment setVideoDuration:], 0x1944a4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1944a4. setVideoDuration: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setVideoDuration_(ID param_1,SEL param_2,double param_3)

{
  *(double *)(param_1 + 0x40) = param_3;
  CallSupervisor(0xb16f);
  return;
}



// -[SBSegment locked], 0x1944c4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1944c4. locked */

/* Function Stack Size: 0x10 bytes */

bool SBSegment::locked(ID param_1,SEL param_2)

{
  return (bool)*(byte *)(param_1 + 8);
}



// -[SBSegment setLocked:], 0x1944cc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1944cc. setLocked: */

/* Function Stack Size: 0x14 bytes */

void SBSegment::setLocked_(ID param_1,SEL param_2,bool param_3)

{
  *(char *)(param_1 + 8) = (char)param_3;
  return;
}



// -[SBSegment votes], 0x1944d4
/* Decompiled from supplied 5.2.2 arm package. VA 0x1944d4. votes */

/* Function Stack Size: 0x10 bytes */

long_long SBSegment::votes(ID param_1,SEL param_2)

{
  return *(long_long *)(param_1 + 0x48);
}



// -[SBSegment setVotes:], 0x1944dc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1944dc. setVotes: */

/* Function Stack Size: 0x18 bytes */

void SBSegment::setVotes_(ID param_1,SEL param_2,long_long param_3)

{
  *(long_long *)(param_1 + 0x48) = param_3;
  CallSupervisor(0x8cc1);
  return;
}



// -[SBSegment .cxx_destruct], 0x1944fc
/* Decompiled from supplied 5.2.2 arm package. VA 0x1944fc. .cxx_destruct */

/* Function Stack Size: 0x10 bytes */

void SBSegment::_cxx_destruct(ID param_1,SEL param_2)

{
  _objc_storeStrong(param_1 + 0x28,0);
  _objc_storeStrong(param_1 + 0x20,0);
  _objc_storeStrong(param_1 + 0x18,0);
  _objc_storeStrong(param_1 + 0x10,0);
  return;
}



// +[SBSegment segmentWithDictionary:], 0x193a60
/* Decompiled from supplied 5.2.2 arm package. VA 0x193a60. segmentWithDictionary: */

/* Function Stack Size: 0x18 bytes */

ID SBSegment::segmentWithDictionary_(ID param_1,SEL param_2,ID param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ID IVar10;
  
  DAT_012277d0 = 1;
  _objc_retain(param_3);
  puVar1 = @selector(objectForKeyedSubscript:);
  if (param_3 == 0) {
    uVar6 = 0;
  }
  else {
    _objc_msgSend(param_3,@selector(objectForKeyedSubscript:),
                  @"segment");
    uVar5 = _objc_retainAutoreleasedReturnValue();
    uVar6 = _objc_msgSend(PTR__OBJC_CLASS___NSArray_0114ec18,@selector(class));
    iVar4 = FUN_00194900(uVar5,@selector(isKindOfClass:),uVar6);
    uVar6 = 0;
    if (iVar4 != 0) {
      lVar7 = _objc_msgSend(uVar5,@selector(count));
      uVar6 = 0;
      if (lVar7 == 2) {
        uVar6 = _objc_alloc_init(PTR_SBSegment_0114eed8);
        _objc_msgSend(param_3,puVar1,@"UUID");
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,@selector(setUuid:),uVar8);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,@"category");
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,@selector(setCategory:),uVar8);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,@"actionType");
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,@selector(setActionType:),uVar8);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,@"description");
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar6,@selector(setSegmentDescription:),uVar8);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,@"segment");
        uVar8 = _objc_retainAutoreleasedReturnValue();
        puVar2 = @selector(objectAtIndexedSubscript:);
        _objc_msgSend(uVar8,@selector(objectAtIndexedSubscript:),0);
        uVar9 = _objc_retainAutoreleasedReturnValue();
        puVar3 = @selector(doubleValue);
        _objc_msgSend(uVar9,@selector(doubleValue));
        _objc_msgSend(uVar6,@selector(setStart:));
        _objc_release(uVar9);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,@"segment");
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar2,1);
        uVar9 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar9,puVar3);
        _objc_msgSend(uVar6,@selector(setEnd:));
        _objc_release(uVar9);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,@"videoDuration");
        uVar8 = _objc_retainAutoreleasedReturnValue();
        _objc_msgSend(uVar8,puVar3);
        _objc_msgSend(uVar6,@selector(setVideoDuration:));
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,@"locked");
        uVar8 = _objc_retainAutoreleasedReturnValue();
        uVar9 = FUN_00194818(uVar8,@selector(boolValue));
        _objc_msgSend(uVar6,@selector(setLocked:),uVar9);
        _objc_release(uVar8);
        _objc_msgSend(param_3,puVar1,@"votes");
        uVar8 = _objc_retainAutoreleasedReturnValue();
        uVar9 = _objc_msgSend(uVar8,@selector(integerValue));
        _objc_msgSend(uVar6,@selector(setVotes:),uVar9);
        _objc_release(uVar8);
      }
    }
    _objc_release(uVar5);
  }
  _objc_release(param_3);
  IVar10 = _objc_autoreleaseReturnValue(uVar6);
  return IVar10;
}


