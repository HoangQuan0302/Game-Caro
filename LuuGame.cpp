#include "caro.h"


void SaveGame(Data data)
{
	ifstream InFile;
replace: system("cls");
	gotoXY(45, 8);
	TextColor(Color_Yellow);
	cout << "File Name: "; cin >> data.Code;
	InFile.open("Data.txt", ios::in, ios::binary);
	vector<Data> DT;
	string str;
	getline(InFile, str, '-');
	InFile.close();
	if(str=="")
	{
		goto write;
	}
	else
	{
		InFile.open("Data.txt", ios::in, ios::binary);
		while (!InFile.eof())
		{
			Data data_Temp;
			LoadInfor(InFile, data_Temp);
			//LoadCoord(InFile, data_Temp);
			DT.push_back(data_Temp);
		}
		InFile.close();
		vector<Data>::iterator iter_name_1;
		for (iter_name_1 = DT.begin(); iter_name_1 != DT.end(); iter_name_1++) {
			Data data_tam;
			data_tam = *iter_name_1;
			if (data_tam.Code == data.Code)
			{
				gotoXY(45, 9);
				cout << "File Name da ton tai, vui long nhap File Name khac!!!" << endl;
				Sleep(2000);
				goto replace;
			}
		}
	}
write:ofstream OutFile;
	OutFile.open("Data.txt", ios::app | ios::out, ios::binary);
	OutFile << data.Code << "-" << endl;
	OutFile << data.T1 << endl;
	OutFile << data.T2 << endl;
	OutFile << data.B1 << endl;
	OutFile << data.B2 << "/";
	vector<Obj>::iterator iter_name; // Khai báo con trỏ để duyệt
	for (iter_name = data.obj.begin(); iter_name != data.obj.end(); iter_name++) {
		Obj obj;
		obj = *iter_name;
		OutFile << obj.TD.x << "-";
		OutFile << obj.TD.y << "-";
		OutFile << obj.kitu << endl;
	}
	gotoXY(45, 9);
	cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300);
	system("cls");
	gotoXY(45, 9);
	cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300);
	system("cls");
	gotoXY(45, 9);
	cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300); cout << "."; Sleep(300);
	gotoXY(45, 9);
	cout << "Saved!!!" << endl;
	Sleep(2000);
	OutFile.close();
}