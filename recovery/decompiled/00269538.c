/* Decompiled from supplied 5.2.2 arm package. VA 0x269538. _av_add_q */

long _av_add_q(long param_1,long param_2)

{
  long local_18;
  
  local_18 = param_1;
  _av_reduce(&local_18,(ulong)&local_18 | 4,
             (long)(int)param_1 * (param_2 >> 0x20) + (param_1 >> 0x20) * (long)(int)param_2,
             (param_1 >> 0x20) * (param_2 >> 0x20),0x7fffffff);
  return local_18;
}


