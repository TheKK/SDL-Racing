/*
 *Author: KK <thumbd03803@gmail.com>
 *
 *configLoader.h
 *
 */

#ifndef CONFIG_LOADER
#define CONFIG_LOADER

#include <iostream>
#include <cstdio>

extern "C" {
#include <lua5.2/lua.hpp>
}

class ConfigLoader {
	public:
		static int Lua_GetGlobalInt( char* globalVariable_Name ); 
	private:
};
#endif
