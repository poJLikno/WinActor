#include <stdio.h>
#include <stdlib.h>

static void RunCmd(const char *command) {
	if (system(command)) {
		printf("Command wasn't excecuted successefully!");
		system("pause");
		exit(1);
	}
}

int main(int argc, const char **argv) {
	printf("   WinActor Installer by poJLikno\n");
	printf("====================================\n");
	RunCmd("mkdir C:\\Windows\\WinActor\\");
	RunCmd("copy /y .\\WinActor.exe C:\\Windows\\WinActor\\");
	RunCmd("copy /y \"Windows Activation Info.bat\" C:\\Windows\\WinActor\\");
	RunCmd("copy /y \"Office Activation Info.bat\" C:\\Windows\\WinActor\\");
	RunCmd("copy /y \"Create Schedule Task Template.bat\" C:\\Windows\\WinActor\\");
	RunCmd("copy /y \"WinActor schedule.xml\" C:\\Windows\\WinActor\\");

	RunCmd("schtasks /create /xml \"WinActor schedule.xml\" /tn WinActor");

	RunCmd("pause");

	return 0;
}