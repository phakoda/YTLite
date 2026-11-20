/* Decompiled from supplied 5.2.2 arm package. VA 0x254a8c. _av_bprint_strftime */

void _av_bprint_strftime(long *param_1,char *param_2,tm *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  ulong uVar6;
  long lVar7;
  char acStack_468 [1024];
  long local_68;
  
  lVar7 = *(long *)PTR____stack_chk_guard_01060708;
  local_68 = lVar7;
  if (*param_2 != '\0') {
    do {
      uVar2 = *(uint *)(param_1 + 1);
      uVar3 = *(uint *)((long)param_1 + 0xc);
      uVar1 = uVar3;
      if (uVar2 <= uVar3) {
        uVar1 = uVar2;
      }
      uVar3 = uVar3 - uVar1;
      if (uVar3 == 0) {
        sVar5 = _strlen(param_2);
        uVar6 = sVar5 + 1;
      }
      else {
        sVar5 = _strftime((char *)(*param_1 + (ulong)uVar2),(ulong)uVar3,param_2,param_3);
        if (sVar5 != 0) {
          if (lVar7 == local_68) {
            FUN_00254898(param_1,sVar5 & 0xffffffff);
            return;
          }
          goto LAB_00254c34;
        }
        uVar6 = (ulong)(uVar3 * 2);
        if (uVar3 >> 0x1e != 0) {
          uVar6 = 0x7fffffff;
        }
      }
      iVar4 = FUN_00254704(param_1,uVar6);
    } while (iVar4 == 0);
    uVar2 = *(uint *)((long)param_1 + 0xc);
    uVar1 = uVar2;
    if (*(uint *)(param_1 + 1) <= uVar2) {
      uVar1 = *(uint *)(param_1 + 1);
    }
    uVar3 = uVar2 - uVar1;
    if ((uVar3 < 0x400) && (sVar5 = _strftime(acStack_468,0x400,param_2,param_3), sVar5 != 0)) {
      _av_bprintf(param_1,"%s");
    }
    else if (uVar2 != uVar1) {
      sVar5 = (size_t)uVar3;
      _memset((void *)(*param_1 + (ulong)*(uint *)(param_1 + 1)),0x21,sVar5);
      if (0x1a < uVar3) {
        sVar5 = 0x1b;
      }
      _memcpy((void *)(*param_1 + (ulong)*(uint *)(param_1 + 1)),"[truncated strftime output]",sVar5
             );
      FUN_00254898(param_1,uVar3);
    }
  }
  if (lVar7 == local_68) {
    return;
  }
LAB_00254c34:
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


