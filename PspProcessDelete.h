void __fastcall PspProcessDelete(ULONG_PTR BugCheckParameter2)
{
  _QWORD *v1; // rsi
  struct _KTHREAD *CurrentThread; // rbx
  __int64 v4; // rcx
  _QWORD *v5; // rax
  void *v6; // rcx
  void *v7; // rcx
  __int64 v8; // rcx
  HANDLE ProcessId; // rax
  __int64 v10; // rax
  bool v11; // zf
  void *v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rcx
  __int128 *v15; // r9
  __int64 v16; // r8
  int v17; // r10d
  unsigned int v18; // r11d
  __int64 v19; // rdx
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // rdx
  _QWORD *v23; // rbx
  const char *v24; // rax
  unsigned int v25; // r10d
  unsigned __int64 v26; // rcx
  __int64 v27; // r9
  unsigned __int64 v28; // rax
  __int64 v29; // rax
  __int128 *v30; // r10
  __int64 v31; // rax
  int v32; // r9d
  __int64 v33; // rcx
  __int64 v34; // rax
  volatile signed __int32 *v35; // rcx
  __int64 v36; // rcx
  void *v37; // rcx
  __int16 v38; // bx
  unsigned int v39; // ebx
  _QWORD *v40; // rax
  __int64 v41; // rcx
  struct _EX_RUNDOWN_REF *v42; // rax
  __int128 v43[3]; // [rsp+38h] [rbp-50h] BYREF

  *(_DWORD *)(BugCheckParameter2 + 1124) &= ~0x4000000u;
  v1 = (_QWORD *)(BugCheckParameter2 + 1096);
  memset(v43, 0, sizeof(v43));
  CurrentThread = KeGetCurrentThread();
  if ( *(_QWORD *)(BugCheckParameter2 + 1096) )
  {
    --CurrentThread->SpecialApcDisable;
    ExAcquirePushLockExclusiveEx((ULONG_PTR)&PspActiveProcessLock, 0i64);
    v4 = *v1;
    if ( *(_QWORD **)(*v1 + 8i64) != v1 || (v5 = (_QWORD *)v1[1], (_QWORD *)*v5 != v1) )
      __fastfail(3u);
    *v5 = v4;
    *(_QWORD *)(v4 + 8) = v5;
    PspUnlockProcessListExclusive(CurrentThread);
  }
  v6 = *(void **)(BugCheckParameter2 + 1472);
  if ( v6 )
  {
    ExFreePoolWithTag(v6, 0);
    *(_QWORD *)(BugCheckParameter2 + 1472) = 0i64;
  }
  ObClearProcessDeviceMap(BugCheckParameter2);
  if ( *(_QWORD *)(BugCheckParameter2 + 2464) )
    ZwDeleteWnfStateName();
  v7 = *(void **)(BugCheckParameter2 + 1400);
  if ( v7 )
  {
    ObfDereferenceObject(v7);
    *(_QWORD *)(BugCheckParameter2 + 1400) = 0i64;
  }
  v8 = *(_QWORD *)(BugCheckParameter2 + 1200);
  if ( v8 )
  {
    ObfDereferenceObject((PVOID)(v8 & 0xFFFFFFFFFFFFFFF8ui64));
    *(_QWORD *)(BugCheckParameter2 + 1200) = 0i64;
  }
  ProcessId = PsGetProcessId((PEPROCESS)BugCheckParameter2);
  WbRemoveWarbirdProcess(ProcessId);
  if ( (*(_DWORD *)(BugCheckParameter2 + 1124) & 0x40000) != 0 )
  {
    KiStackAttachProcess(BugCheckParameter2);
    if ( (*(_DWORD *)(BugCheckParameter2 + 1120) & 0x400) != 0 )
      (*((void (__fastcall **)(ULONG_PTR))&xmmword_140C1BD30 + 1))(BugCheckParameter2);
    PspExitProcess(0i64, BugCheckParameter2);
    KiUnstackDetachProcess(v43, 0i64);
    MmDeleteProcessAddressSpace(BugCheckParameter2);
  }
  if ( *(_QWORD *)(BugCheckParameter2 + 1296) )
  {
    PspRemoveProcessFromJobChain(BugCheckParameter2);
    ObDereferenceObjectDeferDeleteWithTag(*(PVOID *)(BugCheckParameter2 + 1296), 0x73507350u);
    *(_QWORD *)(BugCheckParameter2 + 1296) = 0i64;
    *(_QWORD *)(BugCheckParameter2 + 1256) = 0i64;
    *(_QWORD *)(BugCheckParameter2 + 2160) = MmBadPointer;
  }
  if ( *(_QWORD *)(BugCheckParameter2 + 2520) )
    PsDereferencePartition();
  if ( *(_QWORD *)(BugCheckParameter2 + 992) )
    KeUnsecureProcess(BugCheckParameter2);
  if ( *(_QWORD *)(BugCheckParameter2 + 1088) )
  {
    --CurrentThread->SpecialApcDisable;
    v10 = ExMapHandleToPointer(PspCidTable, *(_QWORD *)(BugCheckParameter2 + 1088));
    if ( !v10 )
      KeBugCheck(0x17u);
    ExDestroyHandle(PspCidTable, *(_QWORD *)(BugCheckParameter2 + 1088), v10);
    v11 = CurrentThread->SpecialApcDisable++ == -1;
    if ( v11 && ($52EAA7366E9607A22D070977C3EFB536 *)CurrentThread->ApcState.ApcListHead[0].Flink != &CurrentThread->152 )
      KiCheckForKernelApcDelivery();
  }
  if ( *(_QWORD *)(BugCheckParameter2 + 1208) )
    SeDeassignPrimaryToken(BugCheckParameter2);
  v12 = *(void **)(BugCheckParameter2 + 1328);
  if ( v12 )
  {
    ExFreePoolWithTag(v12, 0);
    PsReturnProcessNonPagedPoolQuota(BugCheckParameter2, 24616i64);
  }
  v13 = SmpKeyedStoreEntryGet((ULONG_PTR)&qword_140D321C8);
  if ( v13 )
  {
    v38 = *(_WORD *)(v13 + 16);
    CmSiFreeMemory((PPRIVILEGE_SET)v13);
    v39 = v38 & 0x3FF;
    v40 = (_QWORD *)SmKmStoreRefFromStoreIndex(&SmGlobals, v39);
    SmKmStoreDeleteWhenEmpty(v41, *v40, 1i64);
    v42 = (struct _EX_RUNDOWN_REF *)SmKmStoreRefFromStoreIndex(&SmGlobals, v39);
    ExReleaseRundownProtection(v42 + 1);
  }
  EtwExitProcess(BugCheckParameter2);
  LpcExitProcess(BugCheckParameter2);
  ExWnfExitProcess(BugCheckParameter2, 1i64);
  IoSetDiskIoAttributionOnProcess(0i64, BugCheckParameter2);
  PoEnergyContextCleanup(BugCheckParameter2);
  v14 = *(_QWORD *)(BugCheckParameter2 + 2288);
  if ( v14 )
  {
    VmpProcessContextCleanup();
    ExFreePoolWithTag(*(PVOID *)(BugCheckParameter2 + 2288), 0);
  }
  LOBYTE(v14) = 1;
  if ( KiQueryUnbiasedInterruptTime(v14) >= (unsigned __int64)qword_140C4ECB0 )
  {
    v15 = &KeServiceDescriptorTable;
    _mm_prefetch((const char *)&KeServiceDescriptorTable, 0);
    v16 = qword_140C4ECA0;
    v17 = 64;
    v18 = qword_140C4ECA8;
    v19 = qword_140C4ECA0;
    v20 = 8i64;
    do
    {
      v19 = __ROR8__(v19 - *(_QWORD *)v15, qword_140C4ECA8);
      v15 = (__int128 *)((char *)v15 + 8);
      v17 -= 8;
      --v20;
    }
    while ( v20 );
    for ( ; v17; --v17 )
    {
      v21 = *(unsigned __int8 *)v15;
      v15 = (__int128 *)((char *)v15 + 1);
      v19 = __ROR8__(v19 - v21, qword_140C4ECA8);
    }
    v11 = qword_140C4ECB8 == v19;
    v22 = qword_140C4EC70;
    if ( !v11 && !qword_140C4EC70 )
    {
      v18 = qword_140C4ECA8;
      v16 = qword_140C4ECA0;
      v22 = (unsigned int)__ROR4__(2120, 35);
      qword_140C4EC70 = (unsigned int)v22;
      xmmword_140C4EC78 = 0i64;
      qword_140C4EC88 = 267i64;
      qword_140C4EC90 = (__int64)&KeServiceDescriptorTable;
    }
    v23 = (_QWORD *)KeServiceDescriptorTable;
    v24 = (const char *)KeServiceDescriptorTable;
    v25 = 4 * xmmword_140E018D0;
    v26 = KeServiceDescriptorTable + (unsigned int)(4 * xmmword_140E018D0);
    if ( (unsigned __int64)KeServiceDescriptorTable < v26 )
    {
      do
      {
        _mm_prefetch(v24, 0);
        v24 += 64;
      }
      while ( (unsigned __int64)v24 < v26 );
    }
    v27 = v16;
    if ( v25 >= 8 )
    {
      v28 = (unsigned __int64)v25 >> 3;
      do
      {
        v27 = __ROR8__(v27 - *v23++, v18);
        v25 -= 8;
        --v28;
      }
      while ( v28 );
    }
    for ( ; v25; --v25 )
    {
      v29 = *(unsigned __int8 *)v23;
      v23 = (_QWORD *)((char *)v23 + 1);
      v27 = __ROR8__(v27 - v29, v18);
    }
    if ( qword_140C4ECC0 != v27 && !v22 )
    {
      v18 = qword_140C4ECA8;
      v16 = qword_140C4ECA0;
      v22 = (unsigned int)__ROR4__(1111490560, 150);
      qword_140C4EC70 = (unsigned int)v22;
      xmmword_140C4EC78 = 0i64;
      qword_140C4EC88 = 267i64;
      qword_140C4EC90 = KeServiceDescriptorTable;
    }
    v30 = &KeServiceDescriptorTableShadow;
    _mm_prefetch((const char *)&KeServiceDescriptorTableShadow, 0);
    v31 = 4i64;
    v32 = 32;
    do
    {
      v33 = v18;
      v16 = __ROR8__(v16 - *(_QWORD *)v30, v18);
      v30 = (__int128 *)((char *)v30 + 8);
      v32 -= 8;
      --v31;
    }
    while ( v31 );
    for ( ; v32; --v32 )
    {
      v34 = *(unsigned __int8 *)v30;
      v33 = v18;
      v30 = (__int128 *)((char *)v30 + 1);
      v16 = __ROR8__(v16 - v34, v18);
    }
    if ( qword_140C4ECC8 != v16 && !v22 )
    {
      qword_140C4EC88 = 267i64;
      v22 = (unsigned int)__ROR4__(603979780, 186);
      qword_140C4EC70 = (unsigned int)v22;
      xmmword_140C4EC78 = 0i64;
      qword_140C4EC90 = (__int64)&KeServiceDescriptorTableShadow;
    }
    if ( (_QWORD)KeServiceDescriptorTableShadow != (_QWORD)KeServiceDescriptorTable
      || (_DWORD)xmmword_140D07010 != (_DWORD)xmmword_140E018D0 )
    {
      if ( v22 )
        goto LABEL_57;
      v22 = (unsigned int)__ROR4__(4240, 68);
      qword_140C4EC70 = (unsigned int)v22;
      xmmword_140C4EC78 = 0i64;
      qword_140C4EC88 = 267i64;
      qword_140C4EC90 = KeServiceDescriptorTableShadow;
    }
    if ( !v22 )
    {
LABEL_62:
      LOBYTE(v33) = 1;
      qword_140C4ECB0 = KiQueryUnbiasedInterruptTime(v33)
                      + 41929663 * (__rdtsc() >> 4) % 0x12A05F2000i64
                      + 288000000000i64;
      goto LABEL_63;
    }
LABEL_57:
    if ( (KDEFERRED_ROUTINE *)DeferredContext.DeferredRoutine != KiSchedulerDpc )
      KeInitializeDpc(&DeferredContext, KiSchedulerDpc, &DeferredContext);
    qword_140C4EC98 = 1845792i64;
    KeInsertQueueDpc(&DeferredContext, 0i64, 0i64);
    goto LABEL_62;
  }
LABEL_63:
  v35 = *(volatile signed __int32 **)(BugCheckParameter2 + 1384);
  if ( v35 )
  {
    _InterlockedAdd(v35 + 129, 0xFFFFFFFF);
    PspDereferenceQuotaBlock((PVOID)v35);
  }
  v36 = *(_QWORD *)(BugCheckParameter2 + 1024);
  if ( v36 )
    ExSaFree(v36, 16i64);
  v37 = *(void **)(BugCheckParameter2 + 1408);
  if ( v37 )
  {
    ExFreePoolWithTag(v37, 0);
    *(_QWORD *)(BugCheckParameter2 + 1408) = 0i64;
  }
}
