#pragma once
#define LUA_PTR lua_State* L
#include "Packets.hpp"
//LUA includes: loaded into binary
#include "LUA/lua.hpp"
#include "LUA/lauxlib.h"
#include "LUA/lualib.h"
#include "GameFunctions.hpp"

void init_lua(); //has hooks installed here, don't forget.
void execute_lua(char* stream);
void end_lua();

static int LUA_Sleep(LUA_PTR);
static int LUA_SendPacket(LUA_PTR);
static int LUA_SendAction(LUA_PTR);