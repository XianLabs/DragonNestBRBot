#include "LuaHelper.hpp"
#include <fstream>
#include <vector>
//global LUA ptr
lua_State* L;
extern HANDLE ScriptThread;
extern DWORD NPCUniqueID;

void init_lua()
{
	L = luaL_newstate();
	luaL_openlibs(L);

	lua_register(L, "Sleep", LUA_Sleep);
	lua_register(L, "SendPacket", LUA_SendPacket);
	lua_register(L, "SendAction", LUA_SendAction);
}

void execute_lua(char* stream)
{
	init_lua();

	std::ofstream tempFile;
	tempFile.open("C:\\tempScript.lua");
	tempFile << stream;
	tempFile.close();

	if (stream == NULL || strcmp(stream, "Enter script here...") == 0 || strcmp(stream, "") == 0)
	{
		MessageBoxA(0, "No script entered or found.", "TOS Scripter", 0);
		return;
	}
	else
		luaL_dofile(L, "C:\\tempScript.lua"); //execute LUA script
}

void end_lua()
{
	lua_close(L);
	TerminateThread(ScriptThread, 0);
}

int LUA_Sleep(LUA_PTR)
{
	int n = lua_gettop(L);
	int delay = lua_tonumber(L, 1);
	Sleep(delay);
	return 0;
}


static int LUA_SendPacket(LUA_PTR)
{
	const char* str = lua_tostring(L, 1);
	BYTE* hexbytes = convertStringToPacketFormat((char*)str);
	DWORD length = getPacketLength((char*)str);
	SendVillagePacket(0, hexbytes[0], hexbytes[1], hexbytes, getPacketLength((char*)str));
	return 0;
}

static int LUA_SendAction(LUA_PTR)
{
	const char* str = lua_tostring(L, 1);

	CharacterAction((char*)str);
	return 0;
}