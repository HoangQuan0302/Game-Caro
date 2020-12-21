#include "caro.h"


int Offline(int mode, Data data)
{
	int k, kt, nguoi, x, y, van_moi, mode_1, T1=0, T2=0, B1, B2;
	char c;
	if (mode == 3)
	{
		T1 = data.T1;
		T2 = data.T2;
	}
	Data data_1;
loop:;
	khoi_tao_ban_co();
	clrscr();
	if (mode != 3)
	{
		B1 = 0; B2 = 0;
	}
	van_moi = 1;
	nguoi = 1;
	x = 42;
	y = 11;
	while (1)
	{
		if (mode == 3)
		{
			B1 = data.B1;
			B2 = data.B2;
		}
		else
		{
			B1 = 0;
			B2 = 0;
		}
		data_1.B1 = B1;
		data_1.B2 = B2;
	rw: hien_thi(x, y);
		BangTheoDoi(T1, T2);
		SoBuoc(B1, B2);
		if (van_moi) { kt = 2; van_moi = 0; }
		else kt = xet_thang_thua(x, y);
		if (kt == 1)
		{
			T1++;
			data.obj.clear();
			gotoXY(80, 23);
			TextColor(Color_Yellow);
			cout << "NGUOI CHOI X THANG!";
			gotoXY(80, 24);
			cout << "choi lai? y:yes  n:no";
			do { c = _getch(); } while (c != 'y' && c != 'n');
			if (c == 'y') goto loop;
			else goto ketthuc;
		}
		else if (kt == 0)
		{
			data.obj.clear();
			T2++;
			gotoXY(80, 23);
			TextColor(Color_Yellow);
			cout << "NGUOI CHOI O THANG!";
			gotoXY(80, 24);
			cout << "choi lai? y:yes  n:no";
			do { c = _getch(); } while (c != 'y' && c != 'n');
			if (c == 'y') goto loop;
			else goto ketthuc;
		}
		else if (kt == 3)
		{
			gotoXY(80, 23);
			TextColor(Color_Yellow);
			cout << "VAN CO NAY HOA!";
			gotoXY(80, 24);
			cout << "choi lai? y:yes  n:no";
			do { c = _getch(); } while (c != 'y' && c != 'n');
			if (c == 'y') goto loop;
			else goto ketthuc;
		}
	loop1:; k = dieu_khien(x, y, nguoi, B1, B2, data);
		if (k == 0) goto loop1;
		if (k == 1)
		{
			goto rw;
		}
		if (k == -1 || k == 3)
		{
			goto ketthuc;
		}
	}
ketthuc:;
	data_1.T1 = T1;
	data_1.T2 = T2;
	if (k == 3)
	{
		SaveGame(data);
	}
	system("cls");
	mode_1 = Menu();
	return mode_1;
}