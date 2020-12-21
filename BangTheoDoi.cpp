#include "caro.h"

void BangTheoDoi(int &T1,int &T2) {
    gotoXY(90, 3);
    TextColor(Color_Cyan);
    cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220);
    TextColor(Color_White);
    cout << " Ti So ";
    TextColor(Color_Cyan);
    cout << char(220) << char(220) << char(220) << char(220) << char(220) << char(220) << char(220);
    gotoXY(90, 4);
    TextColor(14);
    cout << "     P1         P2";

    for (int i = 0; i <= 21; i++) {
        gotoXY(90 + i, 4 + 18);
        TextColor(Color_Cyan);
        cout << char(223);
    }
    for (int i = 4; i <= 21; i++) {
        gotoXY(90, i);
        cout << char(219);
        gotoXY(111, i);
        cout << char(219);
        gotoXY(101, i);
        cout << char(219);
    }
    Tiso(T1,T2);
}
void Tiso(int &T1,int &T2) {
    for (int i = 0; i < T1; i++) {
        gotoXY(92, 6 + i);
        TextColor(Color_Yellow);
        cout << "X";
    }
    for (int i = 0; i < T2; i++) {
        gotoXY(103, 6 + i);
        TextColor(Color_Yellow);
        cout << "O";
    }
}

void SoBuoc(int& B1, int& B2)
{
    TextColor(Color_Yellow);
    gotoXY(90, 1);
    cout << "B1: "<<B1<<"        "<<"B2: "<<B2;
}