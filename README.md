# PatchGuard-Win11-22000.xxx
This repository contains some information for PatchGuard for Windows 11 (build 22000), to potentially help researchers, security professionals, and enthusiasts looking into PatchGuard for Windows 11.

<h2>KiFilterFiberContext/PatchGuardTVCallback.h</h2>
<p>This header file contains the decompiled notification callback function (a PatchGuard check routine) registered at the entry of 'KiFilterFiberContext' if 'PsIntegrityCheckEnabled' is greater than zero. It is very similar to the historical and well known verification routine 'FsRtlMdlReadCompleteDevEx' with some subtle difference</p>
<img src="https://i.imgur.com/ypKeYLd.png" alt="TVCallbackRegister">
