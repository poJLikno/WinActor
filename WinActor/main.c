#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

//#pragma comment(linker, "/subsystem:WINDOWS")
//#pragma comment(linker, "/entry:mainCRTStartup")

unsigned char win_flag = 0;
unsigned char office_flag = 0;
unsigned char activate_flag = 1;
unsigned char clear_flag = 0;

/* Catches errors */
void throw(char *error){
	MessageBoxA(NULL, error, "Error!", MB_OK);
	exit(0);
}

void CheckFlags(const char *flags_str, int length);

void WinSetKey();
void WinClearKey();
void OfficeSetKey();
void OfficeClearKey();

int main(int argc, const char **argv) {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_HIDE);
	
	/* Check arguments */
	if (argc <= 1) {
		throw("No arguments!");
	}

	/* Parse arguments */
	int length = 0;
	for (int i = 1; i < argc; ++i) {
		if (memcmp(argv[i], (const void *)"-", 1) != 0 || (length = strlen(argv[i])) < 2) {
			continue;
		}

		CheckFlags(argv[i], length);
	}

	/* Start activating */
	if (clear_flag) {
		if (win_flag) {
			WinClearKey();
		}
		if (office_flag) {
			OfficeClearKey();
		}
	}
	if (activate_flag) {
		if (win_flag) {
			WinSetKey();
		}
		if (office_flag) {
			OfficeSetKey();
		}
	}

	//system("pause");

	return 0;
}

void CheckFlags(const char *flags_str, int length) {
	/* Set flags */
	for (int i = 1; i < length; ++i) {
		switch (flags_str[i]) {
		case 'W':
		case 'w':
			win_flag = 1;
			break;

		case 'O':
		case 'o':
			office_flag = 1;
			break;

		case 'C':
		case 'c':
			activate_flag = 0;
			clear_flag = 1;
			break;

		case 'R':
		case 'r':
			activate_flag = 1;
			clear_flag = 1;
			break;

		default:
			throw("Unsupported flag");
			break;
		}
	}
}

void WinSetKey() {
	int result = 0;
	if (system("wmic os | find /i \"pro\"") == 0) {
		result = system("cscript //nologo c:\\windows\\system32\\slmgr.vbs /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX || cscript //nologo c:\\windows\\system32\\slmgr.vbs /ipk MH37W-N47XK-V7XM9-C7227-GCQG9");
	}
	else {
		if (system("wmic os | find /i \"home\"") == 0) {
			result = system("cscript //nologo c:\\windows\\system32\\slmgr.vbs /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99 || cscript //nologo c:\\windows\\system32\\slmgr.vbs /ipk 3KHY7-WNT83-DGQKR-F7HPR-844BM || cscript //nologo c:\\windows\\system32\\slmgr.vbs /ipk 7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH || cscript //nologo c:\\windows\\system32\\slmgr.vbs /ipk PVMJN-6DFY6-9CCP6-7BKTT-D3WVR");
		}
	}

	if (result == 0) {
		system("cscript //nologo c:\\windows\\system32\\slmgr.vbs /skms kms.digiboy.ir && cscript //nologo c:\\windows\\system32\\slmgr.vbs /ato");
	}
	else {
		MessageBoxA(NULL, "Could't activate Windows!", "Attention!", MB_OK);
	}
}

void WinClearKey() {
	system("cscript //nologo c:\\windows\\system32\\slmgr.vbs /upk");
}

void OfficeSetKey() {
	system("cscript //nologo \"C:\\Program Files\\Microsoft Office\\Office16\\ospp.vbs\" /sethst:kms.03k.org");
	system("cscript //nologo \"C:\\Program Files\\Microsoft Office\\Office16\\ospp.vbs\" /act");
}

void OfficeClearKey() {
	system("cscript \"C:\\Program Files\\Microsoft Office\\Office16\\ospp.vbs\" /remhst");
	system("cscript \"C:\\Program Files\\Microsoft Office\\Office16\\ospp.vbs\" /rearm");
}
