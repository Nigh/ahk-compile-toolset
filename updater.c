
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>

// Compile:
// tcc .\updater.c -o updater.exe
// Run:
// updater.exe download.zip app.exe

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

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: updater.exe <download_file> <binary_file>\n");
		printf("Example: updater.exe app.zip app.exe\n");
		return 1;
	}

	const char *downloadFilename = argv[1];
	const char *binaryFilename = argv[2];

	char cmd[512];
	sprintf(cmd, "powershell -command \"Expand-Archive -Force %s .\"", downloadFilename);
	system(cmd);
	remove(downloadFilename);
	newProcess(binaryFilename);
	return 0;
}
