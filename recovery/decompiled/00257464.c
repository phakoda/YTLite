/* Decompiled from supplied 5.2.2 arm package. VA 0x257464. _av_dict_get_string */

/* WARNING: Removing unreachable block (ram,0x002575e8) */

void _av_dict_get_string(int *param_1,undefined8 *param_2,uint param_3,uint param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined1 local_45d;
  undefined1 local_45c;
  undefined1 local_45b;
  undefined1 local_45a;
  undefined1 local_459;
  undefined1 auStack_458 [1032];
  
  local_45c = (undefined1)param_3;
  local_45d = (undefined1)param_4;
  local_45b = 0;
  if (((((param_2 != (undefined8 *)0x0) && ((param_4 & 0xff) != 0)) && ((param_3 & 0xff) != 0x5c))
      && (((param_4 & 0xff) != 0x5c && ((param_3 & 0xff) != 0)))) && (param_4 != param_3)) {
    local_45a = local_45d;
    local_459 = local_45c;
    if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
      uVar1 = _av_strdup("");
      *param_2 = uVar1;
    }
    else {
      _av_bprint_init(auStack_458,0x40,0xffffffff);
      iVar3 = 0;
      puVar2 = (undefined8 *)0x0;
      while (puVar2 = (undefined8 *)_av_dict_get(param_1,"",puVar2,2), puVar2 != (undefined8 *)0x0)
      {
        if (iVar3 != 0) {
          _av_bprint_append_data(auStack_458,&local_45a,1);
        }
        _av_bprint_escape(auStack_458,*puVar2,&local_45d,1,0);
        _av_bprint_append_data(auStack_458,&local_459,1);
        _av_bprint_escape(auStack_458,puVar2[1],&local_45d,1,0);
        iVar3 = iVar3 + -1;
      }
      _av_bprint_finalize(auStack_458,param_2);
    }
  }
  return;
}


