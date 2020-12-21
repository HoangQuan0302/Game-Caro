#include "caro.h"


void HandlingString(string str, string& str1, string& str2, string& str3)
{
	int temp = 0;
	if (str[0] == '/')
	{
		for (int i = 1; i <= str.length(); i++)
		{
			if (str[i] != '-')
			{
				if (temp == 0)
				{
					str1.push_back(str[i]);
				}
				else if (temp == 1)
				{
					str2.push_back(str[i]);
				}
				else
				{
					str3.push_back(str[i]);
				}
			}
			else
			{
				temp++;
			}
		}
	}
	else
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != '-')
			{
				if (temp == 0)
				{
					str1.push_back(str[i]);
				}
				else if (temp == 1)
				{
					str2.push_back(str[i]);
				}
				else
				{
					str3.push_back(str[i]);
				}
			}
			else
			{
				temp++;
			}
		}
	}
}
void LoadInfor(ifstream& Infile, Data& data)
{
	getline(Infile, data.Code, '-');
	Infile >> data.T1;
	Infile >> data.T2;
	Infile >> data.B1;
	Infile >> data.B2;
	for (int i =0; i < data.B1 + data.B2; i++)
	{
		Obj obj;
		string str;
		string str1, str2, str3;
		getline(Infile, str, '\n');
		HandlingString(str, str1, str2, str3);
		obj.TD.x = atoi(str1.c_str());
		obj.TD.y = atoi(str2.c_str());
		obj.kitu = str3[0];
		data.obj.push_back(obj);
	}
}

int LoadGame(Data& data, string Code)
{
	int mode;
	vector<Data> DT;
	ifstream InFile;
	InFile.open("Data.txt", ios::in, ios::binary);
	string str;
	getline(InFile, str, '-');
	InFile.close();
	if (str == "")
	{
		gotoXY(55, 13);
		cout << "No data found !!!";
		Sleep(2000);
		system("cls");
		mode = Menu();
		return mode;
	}
	InFile.open("Data.txt", ios::in, ios::binary);
	while (!InFile.eof())
	{
		Data data_Temp;
		LoadInfor(InFile, data_Temp);
		DT.push_back(data_Temp);
	}
	vector<Data>::iterator iter_name;
	for (iter_name = DT.begin(); iter_name != DT.end(); iter_name++) {
		Data data_tam;
		data_tam = *iter_name;
		if (data_tam.Code == Code)
		{
			data = data_tam;
			break;
		}
		else if(iter_name==DT.end()-1)
		{
			gotoXY(55, 13);
			cout << "No data found !!!";
			Sleep(2000);
			system("cls");
			mode = Menu();
			return mode;
		}
	}
	return -2;
}

int hienthi_continue(Data data)
{
	int mode;
	vector<Obj> Obj_temp;
	Obj_temp = data.obj;
	vector<Obj>::iterator iter_name;
	for (iter_name = Obj_temp.begin(); iter_name != Obj_temp.end(); iter_name++) {
		Obj obj_tam;
		obj_tam = *iter_name;
	}
	mode=Offline(3,data);
	return mode;
}