// Decompiled hook evidence for MDXLocalNetworkPermissions. This is not compilable Logos source.

// -[MDXLocalNetworkPermissions lastKnownPermissionsStatus], original IMP slot 0x01225b08
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bd20. FUN_0001bd20 */

undefined8 FUN_0001bd20(void)

{
  return 1;
}



// -[MDXLocalNetworkPermissions isAuthorized], original IMP slot 0x01225b10
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bd28. FUN_0001bd28 */

undefined8 FUN_0001bd28(void)

{
  return 1;
}



// -[MDXLocalNetworkPermissions localNetworkPermissionCheckRequired], original IMP slot 0x01225b18
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bd30. FUN_0001bd30 */

undefined8 FUN_0001bd30(void)

{
  return 0;
}



// -[MDXLocalNetworkPermissions verifyAccessWithCompletion:], original IMP slot 0x01225b20
/* Decompiled from supplied 5.2.2 arm package. VA 0x1bd38. FUN_0001bd38 */

undefined1  [16] FUN_0001bd38(undefined8 param_1,undefined8 param_2,long param_3)

{
  if (param_3 != 0) {
    (**(code **)(param_3 + 0x10))(param_3,1);
  }
  CallSupervisor(0x73d9);
  return ZEXT816(0x1f);
}


