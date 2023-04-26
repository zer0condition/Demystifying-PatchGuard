__int64 __fastcall KiCustomRecurseRoutine0(int a1, unsigned int *a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rcx

  v4 = (unsigned int)(a1 - 1);
  if ( (_DWORD)v4 )
    KiCustomRecurseRoutine1(v4, a2, a3, a4);
  return *a2;
}
