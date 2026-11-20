/* Decompiled from supplied 5.2.2 arm package. VA 0x26045c. _av_log_default_callback */

void _av_log_default_callback(undefined8 param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  size_t sVar6;
  long lVar7;
  undefined4 local_1460;
  undefined4 local_145c;
  char local_1458 [1024];
  undefined8 local_1058 [128];
  undefined8 local_c58;
  undefined8 local_858;
  undefined8 local_458 [128];
  long local_58;
  
  lVar7 = *(long *)PTR____stack_chk_guard_01060708;
  if ((int)param_2 < 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = param_2 >> 8 & 0xff;
    param_2 = param_2 & 0xff;
  }
  local_58 = lVar7;
  piVar5 = (int *)(*(code *)_av_log_level)();
  if ((int)param_2 <= *piVar5) {
    _pthread_mutex_lock((pthread_mutex_t *)&DAT_011d3208);
    FUN_00260144(param_1,param_2,param_3,param_4,local_1058,&DAT_011d3200,&local_1460);
    ___snprintf_chk(local_1458,0x400,0,0x400,"%s%s%s%s");
    if (DAT_0122afe4 == 0) {
      iVar2 = _isatty(2);
      DAT_0122afe4 = -1;
      if (iVar2 != 0) {
        DAT_0122afe4 = 1;
      }
    }
    iVar2 = DAT_0122afe4;
    if ((((DAT_011d3200 == 0) || ((DAT_0122afe8 & 1) == 0)) ||
        (iVar3 = _strcmp(local_1458,&DAT_0122afec), iVar3 != 0)) ||
       ((local_1458[0] == '\0' || (sVar6 = _strlen(local_1458), local_1458[sVar6 - 1] == '\r')))) {
      if (0 < DAT_0122afe0) {
        _fprintf(*(FILE **)PTR____stderrp_01060710,"    Last message repeated %d times\n");
        DAT_0122afe0 = 0;
      }
      ___strcpy_chk(&DAT_0122afec,local_1458,0x400);
      FUN_002606d8(local_1058[0]);
      FUN_0026070c(local_1460,0,local_1058[0]);
      FUN_002606d8(local_c58);
      FUN_0026070c(local_145c,0,local_c58);
      FUN_002606d8(local_858);
      iVar2 = (int)param_2 >> 3;
      iVar3 = 7;
      if (iVar2 < 8) {
        iVar3 = iVar2;
      }
      iVar1 = 0;
      if (-1 < iVar2) {
        iVar1 = iVar3;
      }
      FUN_0026070c(iVar1,uVar4,local_858);
      FUN_002606d8(local_458[0]);
      FUN_0026070c(iVar1,uVar4,local_458[0]);
    }
    else {
      DAT_0122afe0 = DAT_0122afe0 + 1;
      if (iVar2 == 1) {
        _fprintf(*(FILE **)PTR____stderrp_01060710,"    Last message repeated %d times\r");
      }
    }
    _av_bprint_finalize(local_458,0);
    uVar4 = _pthread_mutex_unlock((pthread_mutex_t *)&DAT_011d3208);
    piVar5 = (int *)(ulong)uVar4;
  }
  if (lVar7 != local_58) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(piVar5);
  }
  return;
}


