#pragma once
#include "FindPattern.hpp"

CONST DWORD dwEnhanceItem = FindPattern((unsigned char*)InstanceEnhancePattern, "xxxxxxxxxx", 0, 0x00400000); //
CONST DWORD dwSpeedHack = FindPattern((unsigned char*)SpeedHackPattern, "xxxxxxxxxxxxxxx", 0, 0x005C0000);//83 7C 24 48 10 89 44 24 14 db 44 24 14
CONST DWORD dwControlPlayer = FindPattern((unsigned char*)ControlPlayerPattern, "xxx????xxxxxx????xxxxxxxxx????", 0, 0x00500000); //56 57 68 ? ? ? ? BE 07 00 00 00 E8 ? ? ? ? 8B 44 24 10 89 44 24 10 A1 ? ? ? ? UPDATE FOR EU
CONST DWORD dwActorBase = FindPointerAddressPattern((unsigned char*)CharBasePattern, "????xxxxxx????xx????xx????xxxx????xx?", 0, 0x00400000);//? ? ? ? 33 ff 3b c7 0f 84 ? ? ? ? 8b 0d ? ? ? ? 8b
CONST DWORD dwOfsCharUID = 0xC38;
CONST DWORD dwOfsCharX = 0xC84;
CONST DWORD dwOfsCharZ = dwOfsCharX + 4;
CONST DWORD dwOfsCharY = dwOfsCharX + 8;


CONST DWORD sendClass = 0x01ABB7FC;//FindPointerAddressPattern((unsigned char*)SendClassPattern, "???xxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxx", 0, 0x00400000);
CONST DWORD dwSendVillagePacket = 0x00C24930;
CONST DWORD dwSendFieldPacket = FindPattern((unsigned char*)FieldSendPattern, "xxxxxxxxxxxxxxxxxx", 0, 0x00A00000);
CONST DWORD dwRecvVillagePacket = FindPattern((unsigned char*)RecvHookPattern, "xxxxxxxxxxxxx????xxxxxxxxx", 0, 0x00B00000);

CONST DWORD dwCPUReducer = FindPattern((unsigned char*)CPUReducerPattern, "xxxxxxxxxxxxx????xx????xxxx", 0, 0x00500000);//83 EC 18 53 55 8B 6C 24 24 56 57 FF 15 [[ [[ [[ [[ 8b 15 [[ [[ [[ [[ 33 c9 89 82
CONST DWORD dwNoClip = FindPattern((unsigned char*)NoClipPattern, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 0, 0x00500000);//81 EC A8 00 00 00 53 55 8B AC 24 B4 00 00 00 56 8B B4 24 BC 00 00 00 81 C5 70 01 00 00
CONST DWORD dwInstantCraft = FindPattern((unsigned char*)InstantCraftPattern, "xxxxxxxxxx", 0, 0x00400000);
CONST DWORD dwSendPlayerAction = 0x006596E0; // FindPattern((unsigned char*)SendPlayerActionPattern, "xxxxxxxxxxxxxxxxxxxxxxxxxx", 0, 0x00650000);//CC CC CC CC CC CC 55 8B EC 83 E4 F8 51 8B 45 1C D9 45 10 8b 55 14 57 50 8b 45 0C 8b F9 8B 4D 18 51 52 51 8B 4D 08 D9 1C 24

CONST DWORD dwDebugString = 0x007B0570; //EC 08 08 00 00 A1 ?? ?? ?? ?? 33 C4 89 84 24 04 08 00 00
CONST DWORD dwNoDelayPetLoot = 0x006515A0; //7F ?? 81 FA 2C 01 00 00 0F 82 ?? ?? ?? ?? 89 86 ?? ?? ?? ?? A1 ?? ?? ?? ?? 6A 09

CONST DWORD dwMapIndex = 0x017DCA60;
CONST DWORD dwMapIndexOffset = 0x90;
//PTR 8B 15 ?? ?? ?? ?? 88 8A ?? 00 00 00 8A 40 ?? 8B 8B ?? ?? ?? ?? 8B 51 ??

CONST DWORD dwMoneyBase = 0x01ABB8B0;
CONST DWORD dwMoneyOfs = 0x68; //update this
//00 A1 ? ? ? 01 3B C3 74 ? 88 98 ? 00 00 00