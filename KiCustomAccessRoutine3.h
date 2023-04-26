__int64 __fastcall KiCustomAccessRoutine3(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rax
  __int64 v6; // rcx
  __int64 v7; // rax

  v6 = (unsigned int)(a1 & 3) + 1;
  v7 = __ROR8__(v4, v6);
  return KiCustomRecurseRoutine3(v6, a1, v7 ^ a3, v7 ^ a4);
}
