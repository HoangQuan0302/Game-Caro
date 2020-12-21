#include "caro.h"


int Menu()
{
	gotoXY(44, 6);
	TextColor(Color_Cyan);
	cout << char(42) << char(42) << char(42) << char(42) << char(42) << char(42) << char(42) << char(42) << char(42) << char(42);
	TextColor(COLOR_3DFACE);
	cout << " C A R O ";
	TextColor(Color_Green);
	cout << char(42) << char(42) << char(42) << char(42) << char(42) << char(42) << char(42) << char(42) << char(42);
	for (int i = 0; i <= 29; i++) {
		gotoXY(43 + i,17);
		TextColor(Color_Blue);
		cout << char(42);
	}
	for (int i = 6; i <= 16; i++) {
		gotoXY(43, i);
		cout << char(42);
		gotoXY(72, i);
		cout << char(42);
	}
	int n;
	TextColor(Color_Yellow);
	gotoXY(53, 10);
	cout << "1.	Offline" << endl;
	gotoXY(53, 11);
	cout << "2. Online" << endl;
	gotoXY(53, 12);
	cout << "3. Continue" << endl;
	gotoXY(53, 13);
	cout << "4. Tutorual" << endl;
	gotoXY(53, 14);
	cout << "5. Exit" << endl;
	gotoXY(0,0);
	cin >> n;
	return n;
}