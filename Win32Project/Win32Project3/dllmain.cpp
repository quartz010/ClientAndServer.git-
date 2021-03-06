// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

HMODULE g_hDllModule; //定义Dll本身的句柄，方便自身函数回调


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("\nprocess attach of dll\n");

		//保存Dll 自身的句柄
		g_hDllModule = (HMODULE)hModule;

	case DLL_THREAD_ATTACH:
		printf("\nthread attach of dll\n");

	case DLL_THREAD_DETACH:
		printf("\nthread detach of dll\n");

	case DLL_PROCESS_DETACH:
		printf("\nprocess detach of dll\n");

		break;
	}
	return TRUE;
}

int _stdcall Add(int a, int b)
{
	return a + b;
}