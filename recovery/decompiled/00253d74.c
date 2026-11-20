/* Decompiled from supplied 5.2.2 arm package. VA 0x253d74. _av_strireplace */

void _av_strireplace(char *param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  size_t sVar2;
  long lVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 local_460;
  undefined1 auStack_458 [8];
  uint local_450;
  uint uStack_44c;
  long local_58;
  
  puVar4 = &local_460;
  lVar5 = *(long *)PTR____stack_chk_guard_01060708;
  local_460 = 0;
  local_58 = lVar5;
  sVar1 = _strlen(param_3);
  sVar2 = _strlen(param_2);
  _av_bprint_init(auStack_458,1,0xffffffff);
  while (lVar3 = _av_stristr(param_1,param_2), lVar3 != 0) {
    _av_bprint_append_data(auStack_458,param_1,(int)lVar3 - (int)param_1);
    param_1 = (char *)(lVar3 + sVar2);
    _av_bprint_append_data(auStack_458,param_3,sVar1 & 0xffffffff);
  }
  sVar1 = _strlen(param_1);
  _av_bprint_append_data(auStack_458,param_1,sVar1);
  if (uStack_44c <= local_450) {
    puVar4 = (undefined8 *)0x0;
  }
  _av_bprint_finalize(auStack_458,puVar4);
  if (lVar5 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(local_460);
  }
  return;
}


