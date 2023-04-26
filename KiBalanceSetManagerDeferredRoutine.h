LONG __fastcall KiBalanceSetManagerDeferredRoutine(__int64 a1, struct _KEVENT *a2, __int64 a3, unsigned __int64 a4)
{
  _DWORD v9[86]; // [rsp+0h] [rbp-168h] BYREF
  _DWORD *v10; // [rsp+158h] [rbp-10h]

  v10 = v9;
  memset(&v9[44], 0, 0x5Fui64);
  if ( (__int64)a2 >> 47 != -1 && (__int64)a2 >> 47 != 0 )
  {
    v9[12] = 0;
    *(_BYTE *)a1 = 0;
    *(_QWORD *)(a1 + 32) = a4 >> 8;
    *(_QWORD *)((char *)&v9[65] + 3) = a3;
    *(_QWORD *)((char *)&v9[57] + 3) = __ROL8__(a2, a3);
    *(_QWORD *)((char *)&v9[51] + 3) = __ROR8__(a1, a3);
    *(_QWORD *)(a1 + 40) ^= a4;
    *(_QWORD *)(a1 + 48) ^= a3;
    KiCustomAccessRoutine6(a2);
  }
  return KeSetEvent(a2, 10, 0);
}
