/* Decompiled from supplied 5.2.2 arm package. VA 0x254d94. _av_bprint_escape */

void _av_bprint_escape(undefined8 param_1,char *param_2,char *param_3,int param_4,uint param_5)

{
  bool bVar1;
  bool bVar2;
  char *pcVar3;
  void *pvVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  char cVar8;
  
  if (param_4 == 2) {
    _av_bprint_chars(param_1,0x27,1);
    do {
      cVar8 = *param_2;
      if (cVar8 == '\'') {
        _av_bprintf(param_1,"\'\\\'\'");
      }
      else {
        if (cVar8 == '\0') {
          _av_bprint_chars(param_1,0x27,1);
          return;
        }
        _av_bprint_chars(param_1,(int)cVar8,1);
      }
      param_2 = param_2 + 1;
    } while( true );
  }
  lVar7 = 0;
  do {
    cVar8 = param_2[lVar7];
    uVar6 = (ulong)cVar8;
    if (uVar6 == 0) {
      return;
    }
    if (lVar7 == 0) {
      bVar2 = true;
    }
    else {
      bVar2 = param_2[lVar7 + 1] == '\0';
    }
    uVar5 = 1L << (uVar6 & 0x3f);
    if ((param_3 == (char *)0x0) || (pcVar3 = _strchr(param_3,(int)cVar8), pcVar3 == (char *)0x0)) {
      pvVar4 = _memchr("\'\\",(int)cVar8,3);
      bVar1 = pvVar4 != (void *)0x0;
      if (pvVar4 == (void *)0x0 && ((uVar6 & 0xffffffff) < 0x40 && (uVar5 & 0x100002601) != 0)) {
        bVar1 = (param_5 & 1) != 0;
      }
      if (((param_5 & 2) == 0) &&
         ((bool)(bVar2 & ((uVar6 & 0xffffffff) < 0x40 && (uVar5 & 0x100002601) != 0)) || bVar1))
      goto LAB_00254f2c;
    }
    else {
LAB_00254f2c:
      _av_bprint_chars(param_1,0x5c,1);
      cVar8 = param_2[lVar7];
    }
    _av_bprint_chars(param_1,(int)cVar8,1);
    lVar7 = lVar7 + 1;
  } while( true );
}


