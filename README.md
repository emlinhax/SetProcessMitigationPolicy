# SetProcessMitigationPolicy
Preventing internal cheats with process mitigation policies

This function allows you to enforce various mitigations on your own process.
Reference: https://learn.microsoft.com/de-de/windows/win32/api/processthreadsapi/nf-processthreadsapi-setprocessmitigationpolicy

Examples include:
- ProcessSignaturePolicy: Preventing binaries/modules that have not been signed by microsoft from being loaded/injected into the process
- ProcessDEPPolicy: Preventing code execution in data pages (data execution prevention, dep for short)
- ProcessDynamicCodePolicy: Preventing execution of dynamically allocated code AND preventing modification of existing code.
- many more..

I have tested this on csgo and it works surprisingly well against common cheats.
It is able to prevent LoadLibrary injection as well as ManualMap injection.
