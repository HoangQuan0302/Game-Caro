#include "caro.h"

int Continue()
{
	int mode;
	system("cls");
	gotoXY(55, 12);
	TextColor(Color_Yellow);
	string Code;
	cout << "Game Code: "; cin >> Code;
	Data data;
	mode=LoadGame(data,Code);
	mode=hienthi_continue(data);
	return mode;
}