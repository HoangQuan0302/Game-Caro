#include "caro.h"
struct moto
{
	char kytu;
	int mau;
};
moto buffer[25][77];
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224) // special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE hConsoleOut;
	COORD Home = { 0,0 };
	DWORD dummy;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gano(int x, int y, char c, int mamau)
{
	buffer[y][x].kytu = c;
	buffer[y][x].mau = mamau;
}
void khoi_tao_buffer()
{
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 77; j++)
			gano(j, i, ' ');
}
void ve_ban_co()
{
	for (int i = 0; i < 25; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < 77; j++)
				if (j % 4 == 0) gano(j, i, 197);
				else gano(j, i, 196);
		}
		else
		{
			for (int j = 0; j < 77; j++)
				if (j % 4 == 0) gano(j, i, 179);
		}
	}
}
char ban_co[12][19];
void khoi_tao_ban_co()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 19; j++)
			ban_co[i][j] = ' ';
}
void hien_thi(int x, int y)
{
	gotoXY(0, 25);
	TextColor(Color_Green);
	cout << "Nhan S de luu game!!!";
	gotoXY(25, 25);
	TextColor(Color_Red);
	cout << "Nhan B de quay ve!!!";
	//reset buffer
	khoi_tao_buffer();
	//ve ban co len buffer
	ve_ban_co();
	//in cac quan co cua ban co len buffer
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 19; j++)
			gano(2 + j * 4, 1 + i * 2, ban_co[i][j]);
	//in con tro len buffer
	gano(x - 1, y, buffer[y][x - 1].kytu, 176);
	gano(x, y, buffer[y][x].kytu, 176);
	gano(x + 1, y, buffer[y][x + 1].kytu, 176);
	//in buffer ra console
	gotoXY(0, 0);
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 77; j++)
		{
			TextColor(buffer[i][j].mau);
			putchar(buffer[i][j].kytu);
		}
		if (i < 24) putchar('\n');
	}
}


int dieu_khien(int& x, int& y, int& nguoi,int &B1,int &B2,Data &data)
{
	int key = inputKey();
	if (key == key_Up && y >= 3)
	{
		y -= 2;
		return 1;
	}
	if (key == key_Down && y <= 21)
	{
		y += 2;
		return 1;
	}
	if (key == key_Left && x >= 6)
	{
		x -= 4;
		return 1;
	}
	if (key == key_Right && x <= 70)
	{
		x += 4;
		return 1;
	}
	// Save game
	if (key == 's')
	{
		return 3;
	}
	if (key == 'b')
	{
		return -1;
	}
	if (key == 13)
	{
		if (nguoi == 1 && ban_co[(y - 1) / 2][(x - 2) / 4] == ' ')
		{
			B1++;
			char obj = 'X';
			ban_co[(y - 1) / 2][(x - 2) / 4] = obj;
			nguoi = 2;
			// set data luu file
			Obj temp;
			temp.TD.x = (y - 1) / 2;
			temp.TD.y = (x - 2) / 4;
			temp.kitu = obj;
			data.obj.push_back(temp);
			return 2;
		}
		else if (ban_co[(y - 1) / 2][(x - 2) / 4] == ' ')
		{
			B2++;
			char obj = 'O';
			ban_co[(y - 1) / 2][(x - 2) / 4] = obj;
			nguoi = 1;
			Obj temp;
			temp.TD.x = (y - 1) / 2;
			temp.TD.y = (x - 2) / 4;
			temp.kitu = obj;
			data.obj.push_back(temp);
			return 2;
		}
		return 0;
	}
	return 0;
}
int xet_thang_thua(int x, int y)
{
	int dem, i, j, h, c;
	c = (x - 2) / 4;
	h = (y - 1) / 2;
	if (ban_co[h][c] == ' ') return 2;
	//xet hang ngang
	dem = 0;
	for (j = c; j >= 0; j--)
	{
		if (ban_co[h][j] != ban_co[h][c]) break;
		else dem++;
	}
	for (j = c + 1; j < 19; j++)
	{
		if (ban_co[h][j] != ban_co[h][c]) break;
		else dem++;
	}
	if (dem >= 5)
	{
		if (ban_co[h][c] == 'X') return 1;
		else return 0;
	}
	//xet hang doc
	dem = 0;
	for (int i = h; i >= 0; i--)
	{
		if (ban_co[i][c] != ban_co[h][c]) break;
		else dem++;
	}
	for (i = h + 1; i < 12; i++)
	{
		if (ban_co[i][c] != ban_co[h][c]) break;
		else dem++;
	}
	if (dem >= 5)
	{
		if (ban_co[h][c] == 'X') return 1;
		else return 0;
	}
	//xet duong cheo len
	dem = 0;
	for (i = h, j = c; i >= 0 && j < 19; i--, j++)
	{
		if (ban_co[i][j] != ban_co[h][c]) break;
		else dem++;
	}
	for (i = h + 1, j = c - 1; i < 12, j >= 0; i++, j--)
	{
		if (ban_co[i][j] != ban_co[h][c]) break;
		else dem++;
	}
	if (dem >= 5)
	{
		if (ban_co[h][c] == 'X') return 1;
		else return 0;
	}
	//xet duong cheo xuong
	dem = 0;
	for (i = h, j = c; i < 120 && j < 19; i++, j++)
	{
		if (ban_co[i][j] != ban_co[h][c]) break;
		else dem++;
	}
	for (i = h - 1, j = c - 1; i >= 0, j >= 0; i--, j--)
	{
		if (ban_co[i][j] != ban_co[h][c]) break;
		else dem++;
	}
	if (dem >= 5)
	{
		if (ban_co[h][c] == 'X') return 1;
		else return 0;
	}
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 19; j++)
		{
			if (ban_co[i][j] == ' ') return 2;
		}
	}
	//Kiem tra hoa
	int KT_hoa = 0;
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 19; j++)
		{
			if (ban_co[i][j] != ' ')
			{
				KT_hoa++;
			}
		}
	}
	if (KT_hoa == 228)
	{
		return 3;
	}
}
