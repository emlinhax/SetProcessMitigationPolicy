#pragma warning(disable:4996)
#include <Windows.h>
#include <iostream>

void protect()
{
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    std::cout << "[*] Applying mitigations..." << std::endl;

    PROCESS_MITIGATION_DYNAMIC_CODE_POLICY PMDCP{};
    PMDCP.AllowRemoteDowngrade = 0;
    PMDCP.ProhibitDynamicCode = 1;
    SetProcessMitigationPolicy(ProcessDynamicCodePolicy, &PMDCP, sizeof(PMDCP));
    std::cout << "[+] Applied ProcessDynamicCodePolicy!" << std::endl;

    PROCESS_MITIGATION_DEP_POLICY PMDP{};
    PMDP.Enable = 1;
    PMDP.Permanent = 1;
    SetProcessMitigationPolicy(ProcessDEPPolicy, &PMDP, sizeof(PMDP));
    std::cout << "[+] Applied ProcessDEPPolicy!" << std::endl;

    PROCESS_MITIGATION_CONTROL_FLOW_GUARD_POLICY PMCFGP{};
    PMCFGP.EnableControlFlowGuard = 1;
    PMCFGP.StrictMode = 1;
    SetProcessMitigationPolicy(ProcessControlFlowGuardPolicy, &PMCFGP, sizeof(PMCFGP));
    std::cout << "[+] Applied ProcessControlFlowGuardPolicy!" << std::endl;

    PROCESS_MITIGATION_BINARY_SIGNATURE_POLICY PMBSP{};
    PMBSP.MicrosoftSignedOnly = 1;
    SetProcessMitigationPolicy(ProcessSignaturePolicy, &PMBSP, sizeof(PMBSP));
    std::cout << "[+] Applied ProcessSignaturePolicy!" << std::endl;

    std::cout << "[!] We are done! The game is now secured!" << std::endl;
}

bool __stdcall DllMain(HINSTANCE__* hModule, unsigned long ul_reason_for_call, void* lpReserved)
{
    if (ul_reason_for_call == 1)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)protect, 0,0,0);

    return TRUE;
}

