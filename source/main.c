#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	gfxInitDefault();

	PrintConsole topScreen, bottomScreen;
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);

	consoleSelect(&topScreen);
	
	printf("\x1b[16;20HHello World!");
	printf("\x1b[30;30HPress Start to exit.");
	printf("\x1b[1;1HRoses are \x1b[31mred\x1b[0m,\n");
	printf("Violets are \x1b[34mblue\x1b[0m,\n");		
	printf("rus\x1b[34msi\x1b[31mans\x1b[0m are \x1b[47;31mterrorists.\x1b[0m\n");
	printf("Valeika are \x1b[33mGLORIOUS\x1b[0m;");

	consoleSelect(&bottomScreen);
	printf("\x1b[16;15H\x1b[31mAnd \x1b[47mHello \x1b[0m\x1b[42;36mMe!");

	while (aptMainLoop())
	{
		hidScanInput();

		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break;

		gfxFlushBuffers();
		gfxSwapBuffers();

		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}
