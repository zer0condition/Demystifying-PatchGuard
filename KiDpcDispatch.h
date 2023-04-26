__int64 __fastcall KiDpcDispatch(__int64 a1, __int64 a2)
{
  __int64 v2; // rcx
  _QWORD *v3; // r10
  __int64 v4; // rdx

  *(_QWORD *)(a1 + 72) ^= a2;
  *(_QWORD *)(a1 + 80) ^= a2;
  v2 = a1 + 72;
  *(_QWORD *)(v2 + 16) ^= a2;
  *(_QWORD *)(v2 + 24) ^= a2;
  *(_QWORD *)(v2 + 32) ^= a2;
  *(_QWORD *)(v2 + 40) ^= a2;
  *(_QWORD *)(v2 + 48) ^= a2;
  *(_QWORD *)(v2 + 56) ^= a2;
  *(_QWORD *)(v2 + 64) ^= a2;
  *(_QWORD *)(v2 + 72) ^= a2;
  *(_QWORD *)(v2 + 80) ^= a2;
  *(_QWORD *)(v2 + 88) ^= a2;
  *(_QWORD *)(v2 + 96) ^= a2;
  *(_QWORD *)(v2 + 104) ^= a2;
  *(_QWORD *)(v2 + 112) ^= a2;
  *(_QWORD *)(v2 + 120) ^= a2;
  *(_QWORD *)(v2 + 128) ^= a2;
  *(_QWORD *)(v2 + 136) ^= a2;
  *(_QWORD *)(v2 + 144) ^= a2;
  *(_QWORD *)(v2 + 152) ^= a2;
  *(_QWORD *)(v2 + 160) ^= a2;
  *(_QWORD *)(v2 + 168) ^= a2;
  *(_QWORD *)(v2 + 176) ^= a2;
  *(_QWORD *)(v2 + 184) ^= a2;
  *(_QWORD *)(v2 + 192) ^= a2;
  *(_DWORD *)v2 ^= a2;
  v3 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 - 72 + 64) + 32i64) ^ *(_QWORD *)(*(_QWORD *)(v2 - 72 + 64) + 64i64) | 0xFFFF800000000000ui64);
  v4 = *v3 ^ 0x85131481131482Ei64;
  *(_DWORD *)v3 = 288442414;
  return ((__int64 (__fastcall *)(_QWORD *, __int64))v3)(v3, v4);
}
