# PatchGuard-Win11
This repository contains some information for PatchGuard for Windows 11 (build 22000.xxx), to potentially help researchers, security professionals, and enthusiasts looking into PatchGuard for Windows 11.

<h2>KiFilterFiberContext/PatchGuardTVCallback.h</h2>
<p>This header file contains the decompiled notification callback function (a PatchGuard check routine) found at the entry of 'KiFilterFiberContext' if 'PsIntegrityCheckEnabled' is greater than zero. It is similar to the historical and well-known huge 'FsRtlMdlReadCompleteDevEx'.</p>
<img src="https://i.imgur.com/ypKeYLd.png" alt="TVCallbackRegister">

<p>'ExCreateCallback' opens an existing callback object 'TV' which is registered at boot-time by an external binary.</p>

<h2>PspProcessDelete.h</h2>
<p>This header file contains the decompiled function 'PspProcessDelete', You are probably wondering why it has anything to do with PatchGuard, technically it does not but it serves an purpose for integrity checking. This function is used usually for termination of threads and it's processes' but other than that, there appears to be an <b>integrity check for KeServiceDescriptorTable and KeServiceDescriptorTableShadow</b> inside it which is<b> independent on PatchGuard context or a dedicated thread</b>, as shown in the image below. <b>'qword_140C4ECB0'</b> the checksum occurs depending on the random value generated with <b>KiQueryUnbiaisedInterruptTime</b>. And finally the DPC is inserted using <b>KeInsertQueueDpc</b> triggering a BugCheck.
<img src="https://i.imgur.com/Fg5Sp6T.png" alt="SneakyBugCheck">
