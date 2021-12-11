#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27
#define s_key 115
#define S_key 83
#define z_key 122
#define Z_key 90

enum KierunekRuchu {
    wLewo,
    wGore,
    wPrawo,
    wDol,
    zostan
};

struct Wspolrzedne {
    int x, y;
    Wspolrzedne(int x, int y) : x(x), y(y) {};
};


