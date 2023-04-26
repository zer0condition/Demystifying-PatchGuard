__int64 __fastcall KiCustomRecurseRoutine1(int a1, unsigned int *a2, __int64 a3, __int64 a4)
{
  int v4; // ecx

  v4 = a1 - 1;
  if ( v4 )
    KiCustomRecurseRoutine2(v4, a2, a3, a4);
  return *a2;
}
