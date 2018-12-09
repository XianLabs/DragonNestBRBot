#pragma once
#include <Windows.h>
#include "PacketWriter.hpp"

unsigned char* convertStringToPacketFormat(char* convertStr);
char* convertPacketFormatToString(unsigned char* packetStr, int byteLength);
int getPacketLength(char* grabbedTextPacket);

BOOL CreatePacket(LPBYTE data, DWORD length, INT MainCmd, INT SubCmd);
BOOL CreateRecvPacket(LPBYTE data, DWORD length);

struct OutPacket {
	DWORD dwLength;
	unsigned char bData[8192];
};

typedef enum PacketDirection {
	in,
	out
};

struct ModifyRule {
	PacketDirection direction;
	int len;
	char* pattern;
	BYTE* replacement;
	SHORT opcode;
};

void Send(char* textPacket);
void Recv(char* textPacket);