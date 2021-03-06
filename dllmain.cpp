// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
//#include <string>
//#include <iostream>
//#include <fstream>
#include <emmintrin.h>
//#include <unordered_map>
#include "Header.h"
using namespace std;
#define uint32_t unsigned int
#define BASE 0x7FF729E20000
#define GNAMEFUN  0x7FF62D249540-BASE //gnamefun E8 ? ? ? ? 48 8B D0 48 8D 4D 37 ->
#define GOBJFUN   0x7FF62E5B6B50-BASE     //E8 ? ? ? ? 39 78 38
#define CHUNK_SIZE 0x4180
#define GOBJMAX_ADDR 0x7FF631484B10
#define CLASSOFFSET 0x10          //33 FF 4C 89 74 24 40 0F 29 74 24 30
#define OUTEROFFSET 0x20         //4C 8B DC 53 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 48 8B F9
#define NAMEINDEXOFFSET 0x28      //0F 85 ? ? ? ? 44 38 A1 ? ? ? ?
#define NAMENUMBEROFFSET 0x2C

using DecryptNameEntryFn = __int64(__fastcall*)(__int64);
using myfun = __m128i * (__fastcall *)(int *p_index, __int64 a2);
using DecryptFunction = __int64(__fastcall *)(__int64);
using fun2 = __int64(__fastcall *)(__int64, unsigned __int8);
using fun3 = __int64(__fastcall *)(__int64, unsigned int);
DecryptFunction* decrytable;
extern "C" __int64 __fastcall  localplayershell(__int64 in);
extern "C" __int64 __fastcall  localplayercontrollershell(__int64 in);
extern "C" __int64 __fastcall  gameinstanceshell(__int64 in);


void x();

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{



	switch (ul_reason_for_call)
	{


	case DLL_PROCESS_ATTACH:

		
		x();



	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}





#define uint64_t ull
uint64_t decrypt_game_instance(uint64_t uworld)
{


	//return gameinstanceshell(uworld);

	uint64_t a1 = *(uint64*)(uworld+0x200);
	int v1; // eax
	int v2; // eax
	unsigned int v3; // eax
	unsigned __int64 v4; // rcx
	int v5; // ecx
	int v6; // eax
	unsigned int v7; // eax
	__int64 v9; // [rsp+10h] [rbp+10h]

	if (a1 & 1)
		v1 = a1 ^ 0x70447570 | 1;
	else
		v1 = (a1 ^ 0xD00403BD) & 0xFFFFFFFE;
	v2 = v1 - 1421107355;
	if (v2 & 1)
		v3 = v2 ^ 0xE1447571 | 1;
	else
		v3 = (v2 ^ 0x6B0403BC) & 0xFFFFFFFE;
	v4 = a1 >> 32;
	LODWORD(v9) = v3 ^ 0xAB4B9F65;
	if (v4 & 1)
		v5 = v4 ^ 0xFFA32A89 | 1;
	else
		v5 = (v4 ^ 0x3533C6E8) & 0xFFFFFFFE;
	v6 = v5 + 709110405;
	if (((_BYTE)v5 - 123) & 1)
		v7 = (v6 ^ 0x70A32A88 | 1) ^ 0xD5BBD57B;
	else
		v7 = (v6 ^ 0xD033C6E9) & 0xFFFFFFFE ^ 0xD5BBD57B;
	HIDWORD(v9) = v7;
	return v9;


}

uint64_t decrypt_local_player(uint64_t localplayerarray)
{
	
	return reinterpret_cast<DecryptFunction>(0x7FF72A1166B0 +(uint64)GetModuleHandle(0)-BASE)(*(uint64*)localplayerarray);
}

uint64_t decrypt_controller(__int64 localplayer)
{

	return localplayercontrollershell(localplayer);

}

uint64_t decrypt_ULevel(uint64_t a1)
{
	uint64_t v3 = *(uint64_t*)(a1);
	uint64_t v32 = __ROL4__((__ROL4__(v3 ^ 0x39A603BD, 8) - 732691220) ^ 0xD4A603BD, 8) ^ 0xD45404EC;
	uint64_t v33 = __ROR4__((__ROR4__((v3 >> 32) ^ 0x9ED5C6E8, 16) - 747908244) ^ 0x39D5C6E8, 16) ^ 0x2C942C94;
	return __PAIR__(v33, v32);
}

uint64_t decrypt_actors(uint64_t v)
{
	uint64_t a1 = *(uint64_t*)(v);
	unsigned __int64 v1; // r10
	unsigned int v2; // er8
	unsigned int v3; // edx
	__int64 v5; // [rsp+10h] [rbp+10h]

	v1 = a1 >> 32;
	v2 = ((unsigned __int16)a1 ^ ((unsigned int)a1 >> 16) | ((unsigned __int16)__ROR2__(WORD1(a1), 8) << 16)) + 404273256;
	v3 = (HIDWORD(a1) & 0xFFFF0000 | (unsigned __int16)__ROL2__(WORD2(a1) ^ WORD1(v1), 8)) + 392632168;
	LODWORD(v5) = ((v2 >> 16) ^ (unsigned __int16)((a1 ^ WORD1(a1)) - 18328) | ((unsigned __int16)__ROR2__(HIWORD(v2), 8) << 16)) ^ 0x1818B868;
	HIDWORD(v5) = (v3 & 0xFFFF0000 | (unsigned __int16)__ROL2__(v3 ^ HIWORD(v3), 8)) ^ 0xE898E898;
	return v5;
}

uint64_t decrypt_rootComponnent(uint64_t v)
{
	uint64_t v10 = *(uint64_t*)(v);
	uint64_t v19;
	LODWORD(v19) = __ROL4__(__ROL4__(v10 + 1592394685, 16) - 1283212876, 16) ^ 0xB999B5F7;
	HIDWORD(v19) = __ROR4__(__ROR4__(HIDWORD(v10) - 1021720856, 8) - 1766850753, 8) ^ 0xC769C7A9;
	return v19;
}

int decrypt_id(uint64_t a)
{
	int v = *(int*)(a);
	int t = __ROR4__(v ^ 0x3886F1D9, 11);
	t = t ^ (t << 16) ^ 0x71186F4C;
	return t;
}

void x()
{
	
	DecryptFunction xray;

	uintptr_t UWorld = **(uintptr_t**)((LPBYTE)GetModuleHandle(0) + 0x7FF72DE20D10 -BASE);
	uintptr_t GameInstance = decrypt_game_instance(UWorld);
	uintptr_t LocalPlayerArray = *(uint64_t*)(GameInstance + 0x68);//??
	uintptr_t LocalPlayer = decrypt_local_player(LocalPlayerArray);
	uintptr_t PlayerController = decrypt_controller(LocalPlayer);




	*(char *)(PlayerController + 0xC50) = false;
	xray = reinterpret_cast<DecryptFunction>(0x7FF72B8E6D90 - (__int64)BASE + (__int64)GetModuleHandle(0));
	auto it = (__int64)xray + (0x7FF779C16ED5 - 0x7FF779C16D90);
	*(char*)(it) = 0x90;
	*(char*)(it + 1) = 0x90;
	*(char*)(it + 2) = 0x90;
	*(char*)(it + 3) = 0x90;
	*(char*)(it + 4) = 0x90;
	*(char*)(it + 5) = 0x90;


	xray(PlayerController);
}