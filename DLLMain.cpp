#include "HWID.hpp"
#include "Multi.hpp"
#include <vector>
#include <iostream>

using namespace std;

HMODULE hInstDLL;

extern int Main();

VOID Startup()
{
	//std::string HWID = GenerateHWID();

	//if (HWID.compare("SF Heavy Equipment-1284220259") != 0) {
	//	__asm {
	//		mov eax, 4562
	//			push eax
	//			push ecx
	//			push ebx
	//			add ebp, 0x0060410
	//			sub esp, 0x41
	//			ret
	//	}
	//}

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&MultiTrue, NULL, NULL, NULL);
	Main(); //launch winform GUI
}



EXTERN_C BOOL WINAPI _DllMainCRTStartup(HINSTANCE hInstDll, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:

		hInstDLL = hInstDll;

		HANDLE mainThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Startup, NULL, 0, NULL);
		break;
	};

	return TRUE;
}