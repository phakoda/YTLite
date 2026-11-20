/* Decompiled from supplied 5.2.2 arm package. VA 0x256364. _av_parse_cpu_flags */

uint _av_parse_cpu_flags(undefined8 param_1)

{
  uint uVar1;
  undefined **local_20;
  uint local_14;
  
  local_14 = 0;
  local_20 = &PTR_s_cpuflags_01063e10;
  uVar1 = _av_opt_eval_flags(&local_20,&PTR_s_flags_01063cd0,param_1,&local_14);
  if (-1 < (int)uVar1) {
    uVar1 = local_14 & 0x7fffffff;
  }
  return uVar1;
}


