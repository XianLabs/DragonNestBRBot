#pragma once
#include "Constants.hpp"
#include "Pointer.hpp"
#include "Speedhack.hpp"

struct HACK {
	DWORD dwAddress;
	char* szOriginalBytes;
	char* szNewBytes;
	INT nSize;
};

VOID WriteHackBytes(HACK hHack, BOOL bEnable);

VOID ReduceRAM();

CONST HACK hInstantEnhance = { dwEnhanceItem, "\x6a\x12", "\x6a\x13", 2 };
CONST HACK hNoclip = { dwNoClip, "\x81\xEC\xA8\x00\x00\x00", "\xC2\x1C\x00\x90\x90\x90", 6 };
CONST HACK hInstantCraft = { dwInstantCraft, "\x6a\x06", "\x6a\x08", 2 };
CONST HACK hInstantPetLoot = { dwNoDelayPetLoot, "\x7f\x0c", "\xeb\x0C", 2 };

int __stdcall SendFieldPacket(DWORD dwClass, DWORD OpCode1, DWORD OpCode2, BYTE* data, DWORD len);

VOID CharacterMeleeAction(char* action);