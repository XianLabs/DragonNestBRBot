#pragma once
#include "Constants.hpp"
#include "Packets.hpp"

struct HOOK {
	DWORD dwAddress;
	DWORD dwReturn;
	char* szOriginalBytes;
	INT nSize;
};

VOID WriteHookBytes(HOOK hkHook, VOID* lpvHook, BOOL bEnable);

// ---Game hooks for hacking---
CONST HOOK hkSpeedHack = { dwSpeedHack, dwSpeedHack + 8, "\x89\x44\x24\x14\xDB\x44\x24\x14", 8 };
VOID MovespeedHook();

CONST HOOK hkControlPlayer = { dwControlPlayer, dwControlPlayer + 6, "\xA1\x10\xE7\x03\x01", 6 };
VOID ControlPlayerCodeCave();

CONST HOOK hkCPUReducer = { dwCPUReducer, dwCPUReducer + 5, "\x83\xEC\x18\x53\x55", 5 };
VOID CPUReducerHook();

CONST HOOK hkVillageSendPacket = { dwSendVillagePacket, dwSendVillagePacket + 5, "\xB8\x04\xC8\x00\x00", 5 };
VOID SendHook();

CONST HOOK hkRecvHook = { dwRecvVillagePacket, dwRecvVillagePacket + 5, "\xC2\x08\x00\xCC\xCC", 5 };
VOID RecvVillagePacketHook(); //used with hkRecvHook
