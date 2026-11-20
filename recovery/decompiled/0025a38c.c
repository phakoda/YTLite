/* Decompiled from supplied 5.2.2 arm package. VA 0x25a38c. _av_fifo_realloc2 */

undefined8 _av_fifo_realloc2(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  if ((uint)(param_1[6] - *param_1) < param_2) {
    iVar1 = param_1[8];
    iVar2 = param_1[9];
    puVar3 = (undefined8 *)_av_fifo_alloc(param_2);
    if (puVar3 == (undefined8 *)0x0) {
      return 0xfffffff4;
    }
    iVar2 = iVar2 - iVar1;
    _av_fifo_generic_read(param_1,*puVar3,iVar2,0);
    puVar3[2] = puVar3[2] + (long)iVar2;
    *(int *)((long)puVar3 + 0x24) = *(int *)((long)puVar3 + 0x24) + iVar2;
    _av_free(*(void **)param_1);
    *(undefined8 *)(param_1 + 8) = puVar3[4];
    uVar4 = puVar3[2];
    *(undefined8 *)(param_1 + 6) = puVar3[3];
    *(undefined8 *)(param_1 + 4) = uVar4;
    uVar4 = *puVar3;
    *(undefined8 *)(param_1 + 2) = puVar3[1];
    *(undefined8 *)param_1 = uVar4;
    _av_free(puVar3);
  }
  return 0;
}


