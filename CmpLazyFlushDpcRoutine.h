void __fastcall CmpLazyFlushDpcRoutine(
        struct _KDPC *Dpc,
        __int64 DeferredContext,
        unsigned __int64 SystemArgument1,
        unsigned __int64 SystemArgument2)
{
  _WORD v8[47]; // [rsp+130h] [rbp-68h] BYREF

  memset(v8, 0, sizeof(v8));
  if ( DeferredContext >> 47 != -1 && DeferredContext >> 47 != 0 )
  {
    Dpc->Type = 0;
    Dpc->DeferredContext = (void *)(SystemArgument2 >> 8);
    *(_QWORD *)&v8[43] = SystemArgument1;
    *(_QWORD *)&v8[23] = __ROL8__(DeferredContext, SystemArgument1);
    *(_QWORD *)&v8[19] = __ROR8__(Dpc, SystemArgument1);
    Dpc->SystemArgument1 = (void *)((unsigned __int64)Dpc->SystemArgument1 ^ SystemArgument2);
    Dpc->SystemArgument2 = (void *)((unsigned __int64)Dpc->SystemArgument2 ^ SystemArgument1);
    KiCustomAccessRoutine5(DeferredContext);
  }
  KxAcquireSpinLock((PKSPIN_LOCK)(DeferredContext + 152));
  if ( CmpHoldLazyFlush )
    *(_QWORD *)(DeferredContext + 168) = 0i64;
  else
    KeSetEvent((PRKEVENT)(DeferredContext + 128), 0, 0);
  KxReleaseSpinLock((PKSPIN_LOCK)(DeferredContext + 152));
}
