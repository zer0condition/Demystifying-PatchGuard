void __fastcall IopIrpStackProfilerDpcRoutine(
        struct _KDPC *Dpc,
        __int64 DeferredContext,
        unsigned __int64 SystemArgument1,
        unsigned __int64 SystemArgument2)
{
  unsigned __int64 v8; // rdi
  unsigned int i; // ebx
  __int64 Prcb; // rax
  __int64 v11; // rdx
  _DWORD *v12; // r8
  int v13; // edx
  __int64 j; // rcx
  unsigned int k; // ebx
  __int64 v16; // rax
  _DWORD v17[84]; // [rsp+0h] [rbp-228h] BYREF
  _DWORD *v18; // [rsp+150h] [rbp-D8h]
  __int64 v19[20]; // [rsp+160h] [rbp-C8h] BYREF

  v18 = v17;
  memset(&v17[40], 0, 0x5Bui64);
  if ( DeferredContext >> 47 != -1 && DeferredContext >> 47 != 0 )
  {
    v17[12] = 0;
    Dpc->Type = 0;
    Dpc->DeferredContext = (void *)(SystemArgument2 >> 8);
    *(_QWORD *)((char *)&v17[60] + 3) = SystemArgument1;
    *(_QWORD *)((char *)&v17[44] + 3) = __ROL8__(DeferredContext, SystemArgument1);
    *(_QWORD *)((char *)&v17[54] + 3) = __ROR8__(Dpc, SystemArgument1);
    Dpc->SystemArgument1 = (void *)((unsigned __int64)Dpc->SystemArgument1 ^ SystemArgument2);
    Dpc->SystemArgument2 = (void *)((unsigned __int64)Dpc->SystemArgument2 ^ SystemArgument1);
    KiCustomAccessRoutine2(DeferredContext);
  }
  memset(v19, 0, sizeof(v19));
  v8 = 0i64;
  for ( i = 0; i < (unsigned int)KeNumberProcessors_0; ++i )
  {
    Prcb = KeGetPrcb(i);
    if ( Prcb )
    {
      v8 += (unsigned int)(*(_DWORD *)(Prcb + 35856) - *(_DWORD *)(Prcb + 35940));
      v11 = 0i64;
      v12 = (_DWORD *)(Prcb + 35776);
      do
      {
        v19[v11++] += (unsigned int)(*v12 - v12[21]);
        ++v12;
      }
      while ( v11 < 20 );
    }
  }
  v13 = 20;
  if ( v8 > (unsigned int)IopIrpStackProfilerSampleSize )
  {
    v13 = 0;
    for ( j = 0i64; j < 20; ++j )
    {
      if ( v19[j] > (unsigned __int64)(unsigned int)IopIrpStackProfilerMinSizeThreshold )
        break;
      ++v13;
    }
  }
  if ( v13 != 20 )
  {
    IopProcessIrpStackProfiler(v19);
    IopIrpStackProfilerMinSizeThreshold *= 2;
    if ( (unsigned int)IopIrpStackProfilerMinSizeThreshold > 0x1900 )
      IopIrpStackProfilerMinSizeThreshold = 6400;
    IopIrpStackProfilerSampleSize *= 2;
    if ( (unsigned int)IopIrpStackProfilerSampleSize > 0x7D00 )
      IopIrpStackProfilerSampleSize = 32000;
    for ( k = 0; k < (unsigned int)KeNumberProcessors_0; ++k )
    {
      v16 = KeGetPrcb(k);
      if ( v16 )
      {
        *(_OWORD *)(v16 + 35860) = *(_OWORD *)(v16 + 35776);
        *(_OWORD *)(v16 + 35876) = *(_OWORD *)(v16 + 35792);
        *(_OWORD *)(v16 + 35892) = *(_OWORD *)(v16 + 35808);
        *(_OWORD *)(v16 + 35908) = *(_OWORD *)(v16 + 35824);
        *(_OWORD *)(v16 + 35924) = *(_OWORD *)(v16 + 35840);
        *(_DWORD *)(v16 + 35940) = *(_DWORD *)(v16 + 35856);
      }
    }
  }
  _InterlockedOr(&IopIrpStackProfilerFlags, 4u);
}
