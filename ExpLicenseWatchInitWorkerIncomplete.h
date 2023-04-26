__int64 ExpLicenseWatchInitWorker()
{
  __int64 v0; // rax
  __int64 v1; // rdi
  __int64 (__fastcall *v2)(__int64); // rsi
  unsigned __int8 v3; // bl
  char v4; // r10
  char v5; // r8
  unsigned __int64 v6; // r9
  __int64 result; // rax

  _mm_lfence();
  v0 = KiProcessorBlock;
  v1 = *(_QWORD *)(KiProcessorBlock + 120);
  v2 = *(__int64 (__fastcall **)(__int64))(KiProcessorBlock + 112);
  *(_QWORD *)(KiProcessorBlock + 120) = 0i64;
  *(_QWORD *)(v0 + 112) = 0i64;
  v3 = MEMORY[0xFFFFF780000002D4] >> 1;
  v4 = ((_DWORD)InitSafeBootMode != 0) & ((int)KiSwInterruptPresent() < 0);
  v5 = 1;
  v6 = __rdtsc() >> 3;
  result = 100 * ((unsigned int)v6 / 0x64);
  if ( (unsigned int)v6 % 0x64 <= 3 )
    v5 = v4;
  if ( !(v3 | (unsigned __int8)v5) )
  {
    result = v2(v1);
    if ( (_DWORD)result != 1 )
      KeBugCheckEx(0x9Au, 0x42424242ui64, 0xC000026Aui64, 0i64, 0i64);
  }
  return result;
}
