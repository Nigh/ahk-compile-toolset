#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>

// Compile:
// tcc .\updater.c -DdownloadFilename='"download_Filename"' -DbinaryFilename='"binary_Filename"'

void newProcess(const char *path) {
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	if (CreateProcess(path, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	} else {
		printf("Failed to start process. Error: %d\n", GetLastError());
	}
}

int main(void) {
    TCHAR cmd[512];
	sprintf(cmd, "powershell -command \"Expand-Archive -Force %s .\"", downloadFilename);
	system(cmd);
	remove(downloadFilename);
	newProcess(binaryFilename);
	return 0;
}
