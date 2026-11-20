/* Decompiled from supplied 5.2.2 arm package. VA 0x26dc20. _av_tree_enumerate */

void _av_tree_enumerate(undefined8 *param_1,undefined8 param_2,code *param_3,code *param_4)

{
  int iVar1;
  
  do {
    if (param_1 == (undefined8 *)0x0) {
      return;
    }
    if (param_3 == (code *)0x0) {
      iVar1 = 0;
LAB_0026dc70:
      _av_tree_enumerate(*param_1,param_2,param_3,param_4);
      if (iVar1 != 0) {
        return;
      }
      (*param_4)(param_2,param_1[2]);
    }
    else {
      iVar1 = (*param_3)(param_2,param_1[2]);
      if (-1 < iVar1) goto LAB_0026dc70;
    }
    param_1 = (undefined8 *)param_1[1];
  } while( true );
}


