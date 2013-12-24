/*
 *Author: KK <thumbd03803@gmail.com>
 *
 *configLoader.cpp
 *
 */

#define LUA_SCRIPT_PATH "./lua/config.lua"
#include "configLoader.h"

int ConfigLoader::Lua_GetGlobalInt( char* globalVariable_Name )
{
	lua_State* L = luaL_newstate();
	luaL_openlibs( L );

	if( luaL_loadfile( L, LUA_SCRIPT_PATH ) || lua_pcall( L, 0, 0, 0 ) ){
		fprintf( stderr, "Lua error in config file: %s\n",
				lua_tostring( L, -1 ) );
		return -1;
	}
	
	lua_getglobal( L, globalVariable_Name );
	if( lua_type( L, -1 ) == LUA_TNUMBER ){
		return lua_tointeger( L, -1 );
	}
	else{
		fprintf( stderr, "Lua error in config file: global %s is not integer\n",
				globalVariable_Name );
		printf("type: %s\n", lua_typename( L, lua_type( L, -1 ) ) );
		return -1;
	}
}	
