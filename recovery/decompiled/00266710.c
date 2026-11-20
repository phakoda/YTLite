/* Decompiled from supplied 5.2.2 arm package. VA 0x266710. _av_opt_serialize */

/* WARNING: Removing unreachable block (ram,0x0026691c) */

uint _av_opt_serialize(long param_1,uint param_2,uint param_3,undefined8 *param_4,uint param_5,
                      uint param_6)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined1 local_47b;
  undefined1 local_47a;
  undefined1 local_479;
  long local_478;
  undefined1 local_46a;
  undefined1 local_469;
  undefined1 auStack_468 [1032];
  
  local_47a = (undefined1)param_5;
  local_47b = (undefined1)param_6;
  local_479 = 0;
  local_46a = local_47b;
  local_469 = local_47a;
  if (((((param_6 & 0xff) == 0) || ((param_5 & 0xff) == 0x5c)) || ((param_6 & 0xff) == 0x5c)) ||
     (((param_5 & 0xff) == 0 || (param_6 == param_5)))) {
    _av_log(param_1,0x10,"Invalid separator(s) found.");
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0xffffffea;
    if ((param_1 != 0) && (param_4 != (undefined8 *)0x0)) {
      *param_4 = 0;
      _av_bprint_init(auStack_468,0x40,0xffffffff);
      puVar3 = (undefined8 *)0x0;
      iVar4 = 0;
      while (puVar3 = (undefined8 *)_av_opt_next(param_1,puVar3), puVar3 != (undefined8 *)0x0) {
        if ((*(int *)((long)puVar3 + 0x14) != 10) &&
           ((((uVar2 = *(uint *)(puVar3 + 6), (param_3 & 2) == 0 ||
              (uVar2 = param_2, *(uint *)(puVar3 + 6) == param_2)) && ((uVar2 & param_2) == param_2)
             ) && (((param_3 & 1) == 0 ||
                   (iVar1 = _av_opt_is_set_to_default(param_1,puVar3), iVar1 < 1)))))) {
          uVar2 = _av_opt_get(param_1,*puVar3,0,&local_478);
          if ((int)uVar2 < 0) {
            _av_bprint_finalize(auStack_468,0);
            return uVar2;
          }
          if (local_478 != 0) {
            if (iVar4 != 0) {
              _av_bprint_append_data(auStack_468,&local_46a,1);
            }
            _av_bprint_escape(auStack_468,*puVar3,&local_47b,1,0);
            _av_bprint_append_data(auStack_468,&local_469,1);
            _av_bprint_escape(auStack_468,local_478,&local_47b,1,0);
            _av_freep(&local_478);
            iVar4 = iVar4 + 1;
          }
        }
      }
      uVar2 = _av_bprint_finalize(auStack_468,param_4);
      uVar2 = uVar2 & (int)uVar2 >> 0x1f;
    }
  }
  return uVar2;
}


