__int64 __fastcall KiTimerDispatch(__int64 a1, __int64 a2)
{
  unsigned int v2; // esi
  __int64 v3; // r11
  unsigned __int64 *v4; // rdx
  unsigned __int64 v5; // r11
  _QWORD *v6; // r10
  unsigned __int64 v7; // rbp
  __int64 v8; // r8
  unsigned __int64 *v9; // rcx
  char v10; // al
  unsigned int v11; // edi
  unsigned int i; // ebx
  __int64 v13; // r9
  char v14; // r8
  __int64 v15; // r8
  __int64 v16; // rdx
  __int64 v17; // rdx
  unsigned __int64 v19; // [rsp+20h] [rbp-38h] BYREF
  unsigned __int64 v20; // [rsp+28h] [rbp-30h]

  _mm_lfence();
  v2 = 16;
  v3 = a2 ^ *(_QWORD *)(a1 + 64);
  v4 = &v19;
  v19 = 0xCBC0C5CAC4C9CFCCui64;
  v5 = v3 | 0xFFFF800000000000ui64;
  v20 = 0xCEC7C3CDC8C2C6C1ui64;
  v6 = (_QWORD *)v5;
  v7 = __ROR8__(v5, v5 & 0x3F);
  v8 = 16i64;
  v9 = &v19;
  do
  {
    v10 = *(_BYTE *)v9;
    v9 = (unsigned __int64 *)((char *)v9 + 1);
    *(_BYTE *)v4 = v10 ^ 0xCC;
    v4 = (unsigned __int64 *)((char *)v4 + 1);
    --v8;
  }
  while ( v8 );
  v11 = 25;
  for ( i = 0; i < v11; ++i )
  {
    v13 = *v6;
    v14 = *v6 ^ 9;
    *v6 = v5 + (v7 ^ *v6) + i;
    v7 = v5 + __ROL8__(__ROR8__(i ^ (unsigned __int64)(200 - i), ~(_BYTE)v13 & 0x3F) ^ v7, v14 & 0x3F);
    v15 = v2;
    do
    {
      v16 = __ROL8__(*v6, 4);
      *v6 = *((unsigned __int8 *)&v19 + (v16 & 0xF)) | v16 & 0xFFFFFFFFFFFFFFF0ui64;
      --v15;
    }
    while ( v15 );
    ++v6;
    if ( i == 24 )
    {
      if ( *(_QWORD *)v5 != 0x85131481131482Ei64 )
      {
        *(v6 - 1) ^= 0x85131481131482Ei64 ^ *(_QWORD *)v5;
        v11 += *((_DWORD *)v6 - 1);
        *(v6 - 1) ^= 0x85131481131482Ei64 ^ *(_QWORD *)v5;
      }
      v2 = 1;
    }
  }
  v17 = *(_QWORD *)v5 ^ 0x85131481131482Ei64;
  *(_DWORD *)v5 = 288442414;
  return ((__int64 (__fastcall *)(unsigned __int64, __int64, _QWORD, _QWORD, unsigned __int64, unsigned __int64))v5)(
           v5,
           v17,
           0i64,
           0i64,
           v19,
           v20);
}
