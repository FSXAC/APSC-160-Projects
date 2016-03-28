// Experiment - Windows Beep
// Tests the Windows library alarm sounding capabilities

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define PAUSE system("pause");

int main(void) {
	printf("Playing MB_OK (default beep). . .\n");
	MessageBeep(MB_OK);
	PAUSE;

	printf("Playing MB_ICONINFORMATION (asterisk) . . .\n");
	MessageBeep(MB_ICONINFORMATION);
	PAUSE;

	printf("Playing MB_ICONQUESTION (question) . . .\n");
	MessageBeep(MB_ICONQUESTION);
	PAUSE;

	printf("Playing MB_ICONWARNING (warning) . . .\n");
	MessageBeep(MB_ICONWARNING);
	PAUSE;

	return 0;
}