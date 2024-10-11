#include "ConsoleWindow.h"
#include <iostream>

UConsoleWindow::UConsoleWindow()
{

}

void UConsoleWindow::BeginPlay()
{
	for (size_t y = 0; y < 10; y++)
	{
		for (size_t x = 0; x < 20; x++)
		{
			Arr[y][x] = '*';
		}

		Arr[y][20] = 0;
	}
}

void UConsoleWindow::SetPixel(int _X, int _Y, char _Text)
{
	Arr[_Y][_X] = _Text;
}

void UConsoleWindow::UConsoleWindow::Clear()
{

}

void UConsoleWindow::ScreenRender()
{
	for (size_t y = 0; y < 10; y++)
	{
		char* Ptr = &Arr[y][0];
		printf_s(Ptr);
		printf_s("\n");
	}


}