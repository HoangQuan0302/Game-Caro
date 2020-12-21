#pragma once
#include <stdio.h>
#include <conio.h>
#include<iostream>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
#define Color_BLACK      0
#define Color_DarkBlue  1
#define Color_DarkGreen  2
#define Color_DarkCyan  3
#define Color_DarkRed  4
#define Color_DarkPink  5
#define Color_DarkYellow 6
#define Color_DarkWhite  7
#define Color_Grey   8
#define Color_Blue   9
#define Color_Green   10
#define Color_Cyan   11
#define Color_Red   12
#define Color_Pink   13
#define Color_Yellow  14
#define Color_White   15
#define key_Up  1072
#define key_Down 1080
#define key_Left 1075
#define key_Right 1077
#define key_none -1




struct ToaDo
{
	int x, y;
};
struct Obj
{
	ToaDo TD;
	char kitu;
};
struct Data
{
	int T1, T2, B1, B2;
	vector<Obj> obj;
	string Code;
};


int inputKey();
void clrscr();
void gotoXY(int column, int line);
int whereX();
int whereY();
void TextColor(int color);
void gano(int x, int y, char c, int mamau = 7);
void khoi_tao_buffer();
void ve_ban_co();
void khoi_tao_ban_co();
void hien_thi(int x, int y);
int dieu_khien(int& x, int& y, int& nguoi,int &B1,int &B2,Data &data);
int xet_thang_thua(int x, int y);
int Menu();
int Offline(int mode,Data data);
int Continue();
void Tiso(int& T1, int& T2);
void BangTheoDoi(int& T1, int& T2);
void SoBuoc(int& B1, int& B2);
void SaveGame(Data data);
void LoadInfor(ifstream& Infile, Data& data);
void hien_thi_2(int x, int y,char kitu);
int LoadGame(Data &data,string Code);
void HandlingString(string str, string& str1, string& str2, string& str3);
int hienthi_continue(Data data);