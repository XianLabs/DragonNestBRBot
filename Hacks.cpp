#pragma once
#include "Hacks.hpp"
#include <Psapi.h>
#include <TlHelp32.h>

VOID WriteHackBytes(HACK hHack, BOOL bEnable) {
	if (bEnable) {
		DWORD dwOldProt;
		VirtualProtect((void*)hHack.dwAddress, hHack.nSize, PAGE_EXECUTE_READWRITE, &dwOldProt);
		memcpy((void*)hHack.dwAddress, (void*)hHack.szNewBytes, hHack.nSize);
	}
	else {
		memcpy((void*)hHack.dwAddress, (void*)hHack.szOriginalBytes, hHack.nSize);
	}
}

VOID ReduceRAM()
{
	while (1)
	{
		EmptyWorkingSet(GetCurrentProcess());
		Sleep(10000);
	}
}


int __stdcall SendFieldPacket(DWORD dwClass, DWORD OpCode1, DWORD OpCode2, BYTE* data, DWORD len) //inline assembly call for sending UDP packet
{
	__asm
	{
		mov eax, [sendClass]
			mov eax, [eax]
			mov esi, len
			mov edi, eax
			mov ecx, [data]
			push esi
			push ecx
			push OpCode2
			push OpCode1
			push edi
			xor al, al
			mov ecx, 2
			call dwSendFieldPacket
	}
}

VOID __declspec(naked)CharacterMeleeAction(char* action)
{
	__asm
	{
		pushad
		mov ecx, 0
		push ecx
		push 0
		push 0
		push 0
		push ecx
		push 0
		mov edx, [esp + 0x3C]
		push edx
		mov edi, dwActorBase
		mov edi, [edi]
		mov ecx, edi
		mov eax, dwSendPlayerAction
		call eax
		add esp, 0x04
		popad
		ret
	}
}