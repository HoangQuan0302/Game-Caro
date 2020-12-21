#include "caro.h"


int main()
{
	int mode=-1;
	Data data;
	while (mode != 0)
	{
		switch (mode)
		{
		case -1:
			mode = Menu();
			break;
		case 1:
			mode = Offline(mode,data);
			break;
		/*case 2:
			mode = Online();
			break;*/
		case 3:
			mode = Continue();
			break;
		case 5:
			mode = 0;
			system("cls");
			gotoXY(38, 12);
			cout << ">>>>>>>>>>>>>>> E N D G A M E <<<<<<<<<<<<<<<<";
			gotoXY(57, 13);
			cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300);
			system("cls");
			gotoXY(57, 13);
			cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300);
			system("cls");
			gotoXY(57, 13);
			cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300);
			system("cls");
			Sleep(1000);
			break;
		}
	}
}