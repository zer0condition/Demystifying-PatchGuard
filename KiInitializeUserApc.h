unsigned __int64 __fastcall KiInitializeUserApc(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        char a7)
{
  struct _KTHREAD *CurrentThread; // rcx
  _QWORD *v9; // rdi
  int v10; // eax
  int v11; // r15d
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rbx
  _QWORD *v14; // rcx
  _QWORD *v15; // r14
  _DWORD *v16; // r13
  _QWORD *v17; // rax
  unsigned __int64 result; // rax
  _QWORD *v19; // r8
  const char *i; // rax
  unsigned int v21; // r9d
  __int64 v22; // rdx
  __int64 v23; // rcx
  unsigned int Size; // [rsp+34h] [rbp-194h]
  _QWORD *v27; // [rsp+58h] [rbp-170h]
  _QWORD *v29; // [rsp+88h] [rbp-140h]
  _WORD v30[8]; // [rsp+A8h] [rbp-120h] BYREF
  struct _KTHREAD *v31; // [rsp+B8h] [rbp-110h]
  _QWORD *v32; // [rsp+C0h] [rbp-108h]
  _QWORD *v33; // [rsp+C8h] [rbp-100h]
  SIZE_T v34; // [rsp+D0h] [rbp-F8h]
  __int64 UnbiasedInterruptTime; // [rsp+D8h] [rbp-F0h]
  ULONG_PTR v36[19]; // [rsp+F0h] [rbp-D8h] BYREF

  memset(v36, 0, sizeof(v36));
  CurrentThread = KeGetCurrentThread();
  v31 = CurrentThread;
  if ( a1 )
  {
    v11 = 1048603;
    v12 = 0i64;
    if ( (a7 & 2) != 0 && (KeFeatureBits & 0x800000) != 0 )
    {
      v11 = 1048667;
      v12 = (MEMORY[0xFFFFF780000003D8] | MEMORY[0xFFFFF78000000708]) & 0xFFFFFFFFFFFFFFFCui64;
    }
    if ( (CurrentThread->MiscFlags & 0x100000) != 0 )
    {
      v11 |= 0x100040u;
      v13 = v12 | 0x800;
    }
    else
    {
      v13 = v12 & 0xFFFFFFFFFFFFF7FFui64;
    }
    v14 = *(_QWORD **)(a2 + 384);
    v27 = v14;
    v15 = v14;
    Size = 0;
    if ( (v11 & 0x100040) == 1048640 )
    {
      Size = RtlpGetNonLegacyXStateAreaLength(v13);
      v15 = (_QWORD *)(((unsigned __int64)v15 - Size) & 0xFFFFFFFFFFFFFFC0ui64);
      v14 = v27;
    }
    v29 = (_QWORD *)((unsigned __int64)(v15 - 5) & 0xFFFFFFFFFFFFFFF0ui64);
    v32 = v29;
    v16 = v29 - 8;
    v33 = v29 - 8;
    v9 = v29 - 162;
    v34 = (char *)v14 - (char *)(v29 - 162);
    ProbeForWrite(v29 - 162, v34, 0x10u);
    v17 = v29 - 4;
    *(_OWORD *)v17 = 0i64;
    v17[2] = 0i64;
    *(_DWORD *)v17 = 1;
    *((_DWORD *)v17 + 1) = 2;
    if ( (a7 & 1) != 0 )
      *((_DWORD *)v17 + 1) = 3;
    if ( (v11 & 0x100040) == 1048640 )
    {
      *v16 = -1232;
      v16[1] = *(_DWORD *)(a2 + 384) - (_DWORD)v9;
      v16[2] = -1232;
      v16[3] = 1232;
      v16[4] = (_DWORD)v15 - (_DWORD)v16;
      v16[5] = *(_DWORD *)(a2 + 384) - (_DWORD)v15;
      memset(v15, 0, Size);
      if ( (MEMORY[0xFFFFF780000003EC] & 2) != 0 )
        v15[1] = v13 | 0x8000000000000000ui64;
    }
    *((_DWORD *)v9 + 12) = v11;
    KeContextFromKframes(a2, a1, v9);
    *(_QWORD *)(((unsigned __int64)(v15 - 5) & 0xFFFFFFFFFFFFFFF0ui64) + 0x18) = v9[19];
    *v29 = v9[31];
    KePopulateContinuationContext();
  }
  else
  {
    v9 = *(_QWORD **)(a2 + 208);
    if ( (CurrentThread->MiscFlags & 0x100000) != 0 )
    {
      v10 = KiUnwindUserSspForApcContextCopyBypass(v9);
      if ( v10 < 0 )
        RtlRaiseStatus((unsigned int)v10);
    }
  }
  *v9 = a4;
  v9[1] = a5;
  v9[2] = a6;
  v9[3] = a3;
  *(_QWORD *)(a2 + 384) = v9;
  *(_QWORD *)(a2 + 360) = qword_140D07188;
  *(_WORD *)(a2 + 368) = 51;
  if ( *(_BYTE *)(a2 + 43) != 2 )
    KiSetupForInstrumentationReturn(a2);
  LOBYTE(CurrentThread) = 1;
  result = KiQueryUnbiasedInterruptTime(CurrentThread);
  if ( result >= qword_140C4EE30 )
  {
    __sidt(v30);
    v19 = *(_QWORD **)&v30[1];
    for ( i = *(const char **)&v30[1]; (unsigned __int64)i < *(_QWORD *)&v30[1] + 848i64; i += 64 )
      _mm_prefetch(i, 0);
    v21 = 848;
    v22 = qword_140C4EE20;
    v23 = (unsigned int)qword_140C4EE28;
    while ( v21 >= 8 )
    {
      v22 = __ROR8__(v22 - *v19++, qword_140C4EE28);
      v21 -= 8;
    }
    while ( v21 )
    {
      v22 = __ROR8__(v22 - *(unsigned __int8 *)v19, qword_140C4EE28);
      v19 = (_QWORD *)((char *)v19 + 1);
      --v21;
    }
    if ( qword_140C4EE38 != v22 )
    {
      if ( qword_140C4EDF0 )
        goto LABEL_34;
      qword_140C4EDF0 = (unsigned int)__ROR4__(150994945, 88);
      qword_140C4EDF8 = 0i64;
      qword_140C4EE00 = 0i64;
      qword_140C4EE08 = 269i64;
      qword_140C4EE10 = *(_QWORD *)&v30[1];
    }
    if ( !qword_140C4EDF0 )
    {
LABEL_37:
      LOBYTE(v23) = 1;
      UnbiasedInterruptTime = KiQueryUnbiasedInterruptTime(v23);
      result = UnbiasedInterruptTime + 41929663 * (__rdtsc() >> 4) % 0x12A05F2000i64 + 288000000000i64;
      qword_140C4EE30 = result;
      return result;
    }
LABEL_34:
    if ( (KDEFERRED_ROUTINE *)Dpc.DeferredRoutine != KiSchedulerDpc )
    {
      Dpc.TargetInfoAsUlong = 275;
      Dpc.DeferredRoutine = (void (__fastcall *)(_KDPC *, void *, void *, void *))KiSchedulerDpc;
      Dpc.DeferredContext = &Dpc;
      Dpc.DpcData = 0i64;
      Dpc.ProcessorHistory = 0i64;
    }
    qword_140C4EE18 = 977184i64;
    KeInsertQueueDpc(&Dpc, 0i64, 0i64);
    goto LABEL_37;
  }
  return result;
}
