#include "GameFunctions.hpp"

//dwSendClass = EAX
//ECX = 0
//EDX == data
//length = ESI
//EDI == ???
int SendVillagePacket(DWORD dwClass, DWORD OpCode1, DWORD OpCode2, BYTE* data, DWORD len)
{
	__asm
	{
		mov eax, 0x01ABB7FC
		mov eax, [eax]
		add eax, 0x100
		mov eax, [eax]
		mov esi, len
		mov edi, eax	
		mov edx, [data]
		push edx
		push OpCode2
		push OpCode1
		push eax
		call dwSendVillagePacket

	}
}

VOID __declspec(naked)CharacterAction(char* action) {

	__asm {
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