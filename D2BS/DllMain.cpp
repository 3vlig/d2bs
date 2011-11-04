#include <windows.h>
#include <shlwapi.h>
#include <io.h>
#include <fcntl.h>

#include "sqlite3.h"
#include "Engine.hpp"
#include "D2Api.hpp"

using namespace Core;

Engine* engine = nullptr;
HINSTANCE hModule;
char base[MAX_PATH] = "";
bool isGuarded = false;
sqlite3* settings = nullptr;

BOOL WINAPI DllMain(HINSTANCE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch(dwReason)
	{
		case DLL_PROCESS_ATTACH: {
			DisableThreadLibraryCalls(hMod);
			if(lpReserved != nullptr)
			{
				// handle cGuard loading
			}
			else
			{
				hModule = hMod;
				GetModuleFileName(hMod, base, MAX_PATH);
				PathRemoveFileSpec(base);
				strcat_s(base, MAX_PATH, "\\");
			}

#ifdef DEBUG
			char errlog[MAX_PATH] = "";
			sprintf_s(errlog, MAX_PATH, "%sd2bs.log", base);
			AllocConsole();
			int handle = _open_osfhandle((long)GetStdHandle(STD_ERROR_HANDLE), _O_TEXT);
			FILE* f = _fdopen(handle, "wt");
			*stderr = *f;
			setvbuf(stderr, nullptr, _IONBF, 0);
			freopen_s(&f, errlog, "a+t", f);
#endif

			sqlite3_initialize();

			char settingspath[MAX_PATH] = "";
			sprintf_s(settingspath, MAX_PATH, "%sd2bs.sqlite", base);
			sqlite3_open_v2(settingspath, &settings, SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE|SQLITE_OPEN_FULLMUTEX, nullptr);

			Init();

			break;
		}
		case DLL_PROCESS_DETACH: {
			sqlite3_close(settings);
			sqlite3_shutdown();
			break;
		}
	}
	return TRUE;
}
