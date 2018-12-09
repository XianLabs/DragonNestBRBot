#include "Hooks.hpp"
#include "Pointer.hpp"

VOID WriteHookBytes(HOOK hkHook, VOID* lpvHook, BOOL bEnable) {
	if (bEnable) {
		DWORD dwOldProt;
		VirtualProtect((void*)hkHook.dwAddress, (DWORD)hkHook.dwReturn - (DWORD)hkHook.dwAddress, PAGE_EXECUTE_READWRITE, &dwOldProt);
		*(UCHAR *)hkHook.dwAddress = 0xE9;
		*(UINT*)(hkHook.dwAddress + 1) = (DWORD)lpvHook - hkHook.dwAddress - 5;
		for (int i = 0; i < hkHook.nSize - 5; i++) {
			memcpy((VOID*)(hkHook.dwAddress + i + 5), (VOID*) "\x90", 1);
		}
	}
	else {
		memcpy((VOID*)hkHook.dwAddress, (VOID*)hkHook.szOriginalBytes, hkHook.nSize);
	}
}

BYTE* SendData;
INT SendLength;
INT MainCmd;
INT SubCmd;

VOID __declspec(naked)SendHook()
{
	__asm
	{
		mov eax, esi; length
		mov SendLength, eax
		mov eax, edx
		mov SendData, eax
		mov eax, [esp + 0x08]
		mov MainCmd, eax
		mov eax, [esp + 0x0C]
		mov SubCmd, eax
		pushad
	}


	CreatePacket(SendData, SendLength, MainCmd, SubCmd);

	__asm
	{
		popad
		mov eax, 0x0000C804
		jmp hkVillageSendPacket.dwReturn
	}
}


//Hack hooks
int MovespeedMultiplier = 5;
VOID __declspec(naked) MovespeedHook()
{
	__asm
	{
		pushfd
		imul eax, MovespeedMultiplier
		popfd
		mov[esp + 0x14], eax
		fild dword ptr[esp + 0x14]
		jmp hkSpeedHack.dwReturn
	}
}

DWORD TargetCharUID;
VOID __declspec(naked) ControlPlayerCodeCave() {

	__asm {
		push eax
		mov eax, [esp + 0x08]
		mov TargetCharUID, eax
		pop eax
		push esi
		push edi
		push 0x00DD92F0
		jmp hkControlPlayer.dwReturn
	}
}

VOID __declspec(naked) CPUReducerHook() {

	__asm
	{
		pushad
	}

	Sleep(50); //sleeps inside main thread to reduce cpu

	__asm
	{
		popad
		sub esp, 0x18
		push ebx
		push ebp
		jmp hkCPUReducer.dwReturn
	}
}

BYTE* recvBufferPtr = 0;
VOID __declspec(naked) RecvVillagePacketHook() {

	__asm {
		push eax
		mov eax, [esp + 0x0C]
		mov recvBufferPtr, eax
		pop eax
		pushad
	}

	__asm {
		popad
		ret 0x08
	}

}


struct BYTE3
{
	operator unsigned char* () { return data; }
	BYTE3() { data[0] = 0; data[1] = 0; data[2] = 0; }
	unsigned char data[3];
};

float DecompressFloat(BYTE* in)
{
	unsigned int temp = 0x00000000;

	temp |= ((unsigned int)in[0]) << 16;
	temp |= ((unsigned int)in[1]) << 8;
	temp |= ((unsigned int)in[2]) << 0;

	unsigned int value = 0x00000000;

	value |= ((temp & 0x00C00000) << 8);
	value |= ((temp & 0x00380000) << 5);
	value |= ((temp & 0x0007FFFF) << 5);

	return *(float*)(unsigned int*)(&value);
}


//unsigned short Opcode;
//LPBYTE RecvBuffer;
//DWORD UID;
//FLOAT x, y, z;
//VOID __declspec(naked) JewHook()
//{
//	__asm
//	{
//		push eax
//		mov eax, [esp + 0x0C]
//		mov RecvBuffer, eax
//		pop eax
//		pushad
//	}
//
//	memcpy(&Opcode, &RecvBuffer[2], sizeof(short));
//
//	switch (Opcode)
//	{
//		//case 0x0204:
//		//{
//		//	memcpy(&UID, &RecvBuffer[4], 4);
//		//	if (UID == TargetCharUID && isUsingAutoFollow)
//		//	{
//		//		x = DecompressFloat(&RecvBuffer[8]);
//		//		y = DecompressFloat(&RecvBuffer[14]);
//		//		//z = DecompressFloat(&RecvBuffer[14]);
//		//		WritePointer<FLOAT>(dwActorBase, dwOfsCharX, x);
//		//		WritePointer<FLOAT>(dwActorBase, dwOfsCharY, y);
//		//		//WritePointer<FLOAT>(dwActorBase, dwOfsCharZ, z);
//		//	}
//		//}
//		default: break;
//	};
//
//
//
//	__asm
//	{
//		popad
//		ret 0x08
//	}
//}