#include "pch.h"
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace System;
using namespace std;

#define PosXY Console::SetCursorPosition

struct  Jugador
{
    char simbolo;
    int x, y;
};
char Tablero[23][57] = {
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N'},
    {' ',' ',' ',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N'},
    {' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N'},
    {' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' '},
    {' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N'},
    {' ',' ',' ',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N'},
    {' ',' ',' ',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N'},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},

};
int Presentacion[25][80] = {
{1,1,0,0,1,0,1,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,1,0,1,1,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1},
{1,1,1,0,1,1,1,0,0,1,1,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0},
{1,0,0,0,1,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0},
{1,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0},
{1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0},
{1,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0},
{1,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0},
{1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1},
{1,0,0,0,1,0,1,0,1,0,0,1,1,1,0,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,1,1,0,0,1},
{0,0,0,1,0,0,1,0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,1,1,0,0,1,1,1,0,1,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1},
{1,1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,1,1,1,1,0,0,1},
{1,1,0,1,0,1,1,0,1,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,1,0,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1},
{1,1,0,1,0,0,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1},
{1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,0,0,1,1,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1}
};
int Ganador[20][70] = {
{0,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,1,1,1,1,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
void pintarBordeInstrucciones()
{
    Random aleatorio; 
    int color; 

    bool salir = false; 

    Console::CursorVisible = false; 

    do {
        color = aleatorio.Next(1, 7);

        if (color == 1) Console::BackgroundColor = ConsoleColor::Yellow; 
        else if(color == 2) Console::BackgroundColor = ConsoleColor::Green; 
        else if (color == 3) Console::BackgroundColor = ConsoleColor::DarkMagenta;
        else if (color == 4) Console::BackgroundColor = ConsoleColor::Red;
        else if (color == 5) Console::BackgroundColor = ConsoleColor::Yellow;
        else if (color == 6) Console::BackgroundColor = ConsoleColor::DarkCyan;

        for (int i = 8; i <= 24; i++)
        {
            PosXY(9, i); cout << "|";
        }

        for (int i = 8; i <= 24; i++)
        {
            PosXY(140, i); cout << "|";
        }

        for (int i = 9; i <= 140; i++)
        {
            PosXY(i, 8); cout << "-";
        }

        for (int i = 9; i <= 140; i++)
        {
            PosXY(i, 24); cout << "-";
        }

        _sleep(250); 

        if (kbhit()) salir = true;

    } while (salir != true); 

}
void MostrarPresentacionEinstrucciones() {
    Console::SetWindowSize(90, 30);
    for (int filas = 0; filas < 25; filas++)
    {
        for (int columnas = 0; columnas < 80; columnas++)
        {
            if (Presentacion[filas][columnas] == 0)
            {
                Console::BackgroundColor = ConsoleColor::Black;
                cout << " ";
            }
            if (Presentacion[filas][columnas] == 1)
            {
                Console::BackgroundColor = ConsoleColor::Red;
                cout << " ";

            }

        }
        cout << endl;
    }

    _getch();
    Console::Clear();
    Console::SetWindowSize(150, 40);

    Console::BackgroundColor = ConsoleColor::Gray;
    Console::Clear();
    Console::ForegroundColor = ConsoleColor::Black;
    Console::BackgroundColor = ConsoleColor::Cyan;
    PosXY(55, 10); cout << "|-> INSTRUCCIONES DEL JUEGO <-|";
    Console::BackgroundColor = ConsoleColor::Gray;
    PosXY(15,12); cout << "[ 1 ]  Ambos jugadores deben ingresar su nombre al inciar el juego.";
    PosXY(15,14); cout << "[ 2 ]  Para elegir una ficha debes ingresar una FILA y COLUMNA valida.";
    PosXY(15,16); cout << "[ 3 ]  Para mover una ficha debes de elejir una posicion X e Y en la que deseas que se mueva tu ficha.";
    Console::BackgroundColor = ConsoleColor::Yellow;
    PosXY(14, 19); cout << "[ IPORTANTE ]  RECUERDA QUE LAS POSIONES EN 'X' VARIAN DE 2 EN 2 UNIDADES, Y LAS POSICIONES EN 'Y' VARIAN SOLO EN UNA UNIDAD";
    PosXY(50, 21); cout << "¡¡ DISFRUTA EL JUEGO !!";
    Console::BackgroundColor = ConsoleColor::Gray;
    pintarBordeInstrucciones();
    Console::BackgroundColor = ConsoleColor::Black;
    Console::Clear();

}
void IngresarNombres(char* nom1, char* nom2)
{
  
    Console::ForegroundColor = ConsoleColor::White;
    PosXY(2, 2);
    cout << "Nombre del jugador 1: ";
    cin >> nom1;
    strupr(nom1);

    PosXY(2, 3);
    cout << "Nombre del jugador 2: ";
    cin >> nom2;
    strupr(nom2);
}
void LanzarDado(int& J1, int& J2, char* nom1, char* nom2)
{
    Random dado;
    PosXY(2, 5);
    cout << "SE ESTAN LANZANDO LOS DADOS ....";
    _sleep(1300);

    J1 = dado.Next(1, 7);
    J2 = dado.Next(1, 7);

    PosXY(2, 7);
    if (J1 > J2)cout << "¡Puntaje mas alto! : " << nom1 << endl;
    else cout << "¡Puntaje mas alto! : " << nom2 << endl;
}
void ElegirFicha(char& F1, char& F2, char* nom1, char* nom2, int pJ1, int pJ2, int& T)
{
    int opc;

    if (pJ1 > pJ2)
    {
        T = 1;
        cout << "\n\t\t" << nom1 << " ELIGE UNA FICHA" << endl;
        cout << "\n   [1] Caracter 'A'" << endl;
        cout << "   [2] Caracter 'B'" << endl;
        cout << "   [3] Caracter 'C'" << endl;
        cout << "   [4] Caracter 'D'" << endl;
        cout << "   [5] Caracter 'E'" << endl;
        cout << "   [6] Caracter 'F'" << endl;

        do {
            PosXY(0, 19);  cout << "                                 ";
            PosXY(2, 19);  cout << "Ingrese su eleccion: ";
            cin >> opc;
        } while (opc < 1 || opc>6);


        switch (opc)
        {
        case 1: F1 = 'A'; break;
        case 2: F1 = 'B'; break;
        case 3: F1 = 'C'; break;
        case 4: F1 = 'D'; break;
        case 5: F1 = 'E'; break;
        case 6: F1 = 'F';
        }

        if (F1 == 'A')F2 = 'B';
        else if (F1 == 'B')F2 = 'A';
        else if (F1 == 'C')F2 = 'D';
        else if (F1 == 'D')F2 = 'C';
        else if (F1 == 'E')F2 = 'F';
        else if (F1 == 'F')F2 = 'E';
    }
    else
    {
        T = 2;
        cout << "\n\t\t" << nom2 << " ELIGE UNA FICHA" << endl;
        cout << "\n   [1] Caracter 'A'" << endl;
        cout << "   [2] Caracter 'B'" << endl;
        cout << "   [3] Caracter 'C'" << endl;
        cout << "   [4] Caracter 'D'" << endl;
        cout << "   [5] Caracter 'E'" << endl;
        cout << "   [6] Caracter 'F'" << endl;

        do {
            PosXY(0, 19);  cout << "                                 ";
            PosXY(2, 19);  cout << "Ingrese su eleccion: ";
            cin >> opc;
        } while (opc < 1 || opc>6);


        switch (opc)
        {
        case 1: F2 = 'A'; break;
        case 2: F2 = 'B'; break;
        case 3: F2 = 'C'; break;
        case 4: F2 = 'D'; break;
        case 5: F2 = 'E'; break;
        case 6: F2 = 'F';
        }

        if (F2 == 'A')F1 = 'B';
        else if (F2 == 'B')F1 = 'A';
        else if (F2 == 'C')F1 = 'D';
        else if (F2 == 'D')F1 = 'C';
        else if (F2 == 'E')F1 = 'F';
        else if (F2 == 'F')F1 = 'E';
    }
}
void ElegirPosicionesTablero(char F)
{
    switch (F)
    {
    case 'A':
    case 'B':

        Tablero[18][24] = 'A'; Tablero[18][28] = 'A'; Tablero[18][32] = 'A'; Tablero[18][36] = 'A';
        Tablero[19][26] = 'A'; Tablero[19][30] = 'A'; Tablero[19][34] = 'A'; Tablero[20][28] = 'A';
        Tablero[20][32] = 'A'; Tablero[21][30] = 'A';

        Tablero[8][24] = 'B'; Tablero[8][28] = 'B'; Tablero[8][32] = 'B'; Tablero[8][36] = 'B';
        Tablero[7][26] = 'B'; Tablero[7][30] = 'B'; Tablero[7][34] = 'B'; Tablero[6][28] = 'B';
        Tablero[6][32] = 'B'; Tablero[5][30] = 'B';

        break;

    case 'C':
    case 'D':
        Tablero[17][6] = 'C';  Tablero[17][10] = 'C'; Tablero[17][14] = 'C'; Tablero[17][18] = 'C';
        Tablero[16][8] = 'C';  Tablero[16][12] = 'C'; Tablero[16][16] = 'C'; Tablero[15][10] = 'C';
        Tablero[15][14] = 'C'; Tablero[14][12] = 'C';

        Tablero[9][42] = 'D';  Tablero[9][46] = 'D';  Tablero[9][50] = 'D';  Tablero[9][54] = 'D';
        Tablero[10][44] = 'D'; Tablero[10][48] = 'D'; Tablero[10][52] = 'D'; Tablero[11][46] = 'D';
        Tablero[11][50] = 'D'; Tablero[12][48] = 'D';
        break;

    case 'E':
    case 'F':
        Tablero[17][42] = 'E'; Tablero[17][46] = 'E'; Tablero[17][50] = 'E'; Tablero[17][54] = 'E';
        Tablero[16][44] = 'E'; Tablero[16][48] = 'E'; Tablero[16][52] = 'E'; Tablero[15][46] = 'E';
        Tablero[15][50] = 'E'; Tablero[14][48] = 'E';

        Tablero[9][6] = 'F';   Tablero[9][10] = 'F';  Tablero[9][14] = 'F';  Tablero[9][18] = 'F';
        Tablero[10][8] = 'F';  Tablero[10][12] = 'F'; Tablero[10][16] = 'F'; Tablero[11][10] = 'F';
        Tablero[11][14] = 'F'; Tablero[12][12] = 'F';
        break;

    }
}
void muestraTablero()
{
    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 57; j++)
        {
            PosXY(j, i);
            if (Tablero[i][j] == 'O')Console::ForegroundColor = ConsoleColor::White;
            else if (Tablero[i][j] == 'A')Console::ForegroundColor = ConsoleColor::DarkRed;
            else if (Tablero[i][j] == 'B')Console::ForegroundColor = ConsoleColor::DarkYellow;
            else if (Tablero[i][j] == 'C')Console::ForegroundColor = ConsoleColor::Magenta;
            else if (Tablero[i][j] == 'D')Console::ForegroundColor = ConsoleColor::DarkCyan;
            else if (Tablero[i][j] == 'E')Console::ForegroundColor = ConsoleColor::DarkGreen;
            else if (Tablero[i][j] == 'F')Console::ForegroundColor = ConsoleColor::DarkMagenta;

            if (Tablero[i][j] == 'N')cout << ' ';
            else cout << Tablero[i][j];
        }
        cout << endl;
    }
}
void mostrarFilaYcolumna()
{
    Console::ForegroundColor = ConsoleColor::DarkYellow;

    PosXY(6, 2); cout << "A";
    PosXY(8, 2); cout << "B";
    PosXY(10, 2); cout << "C";
    PosXY(12, 2); cout << "D";
    PosXY(14, 2); cout << "E";
    PosXY(16, 2); cout << "F";
    PosXY(18, 2); cout << "G";
    PosXY(20, 2); cout << "H";
    PosXY(22, 2); cout << "I";
    PosXY(24, 2); cout << "J";
    PosXY(26, 2); cout << "K";
    PosXY(28, 2); cout << "L";
    PosXY(30, 2); cout << "M";
    PosXY(32, 2); cout << "N";
    PosXY(34, 2); cout << "O";
    PosXY(36, 2); cout << "P";
    PosXY(38, 2); cout << "Q";
    PosXY(40, 2); cout << "R";
    PosXY(42, 2); cout << "S";
    PosXY(44, 2); cout << "T";
    PosXY(46, 2); cout << "U";
    PosXY(48, 2); cout << "V";
    PosXY(50, 2); cout << "W";
    PosXY(52, 2); cout << "X";
    PosXY(54, 2); cout << "Y";

    PosXY(2, 5); cout << "A";
    PosXY(2, 6); cout << "B";
    PosXY(2, 7); cout << "C";
    PosXY(2, 8); cout << "D";
    PosXY(2, 9); cout << "E";
    PosXY(2, 10); cout << "F";
    PosXY(2, 11); cout << "G";
    PosXY(2, 12); cout << "H";
    PosXY(2, 13); cout << "I";
    PosXY(2, 14); cout << "J";
    PosXY(2, 15); cout << "K";
    PosXY(2, 16); cout << "L";
    PosXY(2, 17); cout << "M";
    PosXY(2, 18); cout << "N";
    PosXY(2, 19); cout << "O";
    PosXY(2, 20); cout << "P";
    PosXY(2, 21); cout << "Q";

    Console::ForegroundColor = ConsoleColor::White;
}
void MostrarDatosDelJugador(char* nomJ1, char* nomJ2, char f1, char f2, int mJ1, int mJ2)
{
    PosXY(76, 9);
    cout << "________________________________________________";
    PosXY(75, 11);
    cout << "_________________________________________________";
    PosXY(75, 13);
    cout << "_________________________________________________";
    PosXY(75, 15);
    cout << "_________________________________________________";
    PosXY(76, 18);
    cout << "________________________________________________";



    for (int i = 10; i <= 18; i++)
    {
        PosXY(75, i); cout << "|";
    }

    for (int i = 10; i <= 18; i++)
    {
        PosXY(88, i); cout << "|";
    }

    for (int i = 10; i <= 18; i++)
    {
        PosXY(105, i); cout << "|";

    }

    for (int i = 10; i <= 18; i++)
    {
        PosXY(124, i); cout << "|";
    }


    PosXY(76, 12);
    cout << "POS EN X";

    PosXY(76, 14);
    cout << "POS EN Y";

    PosXY(76, 16);
    cout << "NUMERO DE  ";
    PosXY(76, 17);
    cout << "MOVIMIENTOS ";

    PosXY(91, 10);
    cout << nomJ1 << "[" << f1 << "]";
    PosXY(109, 10);
    cout << nomJ2 << "[" << f2 << "]";
    PosXY(97, 17); cout << mJ1;
    PosXY(115, 17); cout << mJ2;


}
void PintarPosAnt(Jugador* J)
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 27; j++)
            Tablero[J->y][J->x] = 'O';

    }
}
void CaracteristicasJugador(Jugador* J, char c, int xpos, int ypos)
{
    J->simbolo = c;
    J->x = xpos;
    J->y = ypos;
}
void EvaluarPosTablero(Jugador* J, int x, int y)
{
    bool saltoSimple = false, saltoDoble = false, band = false;

    if (Tablero[y][x] != 'N' && Tablero[y][x] != ' ')
    {
        if (((J->x) + 2 == x || (J->x) - 2 == x) && ((J->y) + 1 == y || (J->y) - 1 == y)) { saltoSimple = true; }
        else if (((J->x) + 4 == x || (J->x) - 4 == x) && ((J->y) + 2 == y || (J->y) - 2 == y)) saltoDoble = true;

        if (saltoSimple == true && (Tablero[y][x] != 'A' && Tablero[y][x] != 'B' && Tablero[y][x] != 'C' &&
            Tablero[y][x] != 'D' && Tablero[y][x] != 'E' && Tablero[y][x] != 'F'))
        {
            if (J->simbolo == 'A' && (J->y) > y)
            {
                J->x = x;
                J->y = y;
                band = true;
            }
            if (J->simbolo == 'B' && (J->y) < y)
            {
                J->x = x;
                J->y = y;
                band = true;
            }
            if (J->simbolo == 'C' && (J->x) < x)
            {
                J->x = x;
                J->y = y;
                band = true;
            }
            if (J->simbolo == 'D' && (J->x) > x)
            {
                J->x = x;
                J->y = y;
                band = true;
            }
            if (J->simbolo == 'E' && (J->x) > x)
            {
                J->x = x;
                J->y = y;
                band = true;
            }
            if (J->simbolo == 'F' && (J->x) < x)
            {
                J->x = x;
                J->y = y;
                band = true;
            }
        }

        if (saltoDoble == true && (Tablero[y][x] != 'A' && Tablero[y][x] != 'B' && Tablero[y][x] != 'C' &&
            Tablero[y][x] != 'D' && Tablero[y][x] != 'E' && Tablero[y][x] != 'F'))
        {
            if (J->x > x && J->y > y && (J->simbolo == 'E' || J->simbolo == 'A' || J->simbolo == 'D'))
            {
                if (Tablero[(J->y) - 1][(J->x) - 2] >= 'A' && Tablero[(J->y) - 1][(J->x) - 2] <= 'F')
                {
                    J->x = x;
                    J->y = y;
                    band = true;
                }
            }
            else if (J->x < x && J->y > y && (J->simbolo == 'C' || J->simbolo == 'A' || J->simbolo == 'F'))
            {
                if (Tablero[(J->y) - 1][(J->x) + 2] >= 'A' && Tablero[(J->y) - 1][(J->x) + 2] <= 'F')
                {
                    J->x = x;
                    J->y = y;
                    band = true;
                }
            }
            else if (J->x > x && J->y < y && (J->simbolo == 'B' || J->simbolo == 'D' || J->simbolo == 'E'))
            {
                if (Tablero[(J->y) + 1][(J->x) - 2] >= 'A' && Tablero[(J->y) + 1][(J->x) - 2] <= 'F')
                {
                    J->x = x;
                    J->y = y;
                    band = true;
                }
            }
            else if (J->x < x && J->y < y && (J->simbolo == 'F' || J->simbolo == 'B' || J->simbolo == 'C'))
            {
                if (Tablero[(J->y) + 1][(J->x) + 2] >= 'A' && Tablero[(J->y) + 1][(J->x) + 2] <= 'F')
                {
                    J->x = x;
                    J->y = y;
                    band = true;
                }
            }

        }
    }

    if (band == false) { PosXY(2, 31); cout << "NO PUEDE REALIZAR ESTE MOVIEMIENTO"; _getch(); }

}
void LimpiarPantalla()
{
    PosXY(0, 25); cout << "                                                         ";
    PosXY(0, 26); cout << "                                                         ";
    PosXY(0, 27); cout << "                                                         ";
    PosXY(0, 28); cout << "                                                         ";
    PosXY(0, 29); cout << "                                                         ";
    PosXY(0, 30); cout << "                                                         ";
    PosXY(0, 31); cout << "                                                         ";
}
void moverFicha(Jugador* J)
{
    int x, y;
    Console::BackgroundColor = ConsoleColor::Gray;
    PosXY(J->x, J->y); cout << J->simbolo;
    Console::BackgroundColor = ConsoleColor::Black;


    do
    {
        PosXY(2, 28); cout << "                                                     ";
        PosXY(2, 28); cout << "Ingrese la posicion X a la que desea moverse: ";
        cin >> x;
    } while (x < 0 || x>56);

    do
    {
        PosXY(2, 29); cout << "                                                     ";
        PosXY(2, 29); cout << "Ingrese la posicion Y a la que desea moverse: ";
        cin >> y;
    } while (y < 0 || y>23);

    EvaluarPosTablero(J, x, y);
    LimpiarPantalla();
}
void PintarPosAct(Jugador* J)
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 27; j++)
            Tablero[J->y][J->x] = J->simbolo;
    }
}
void EscogerPosicionDeFicha(Jugador* J, char* nombre, char ficha, int T, int& movimiento)
{
    int opc;
    int posX, posY;
    bool salir = false;
    char colum, fila;

    do
    {
        PosXY(0, 25);
        cout << "                                                                                ";
        PosXY(0, 26);
        cout << "                                                                                ";
        PosXY(0, 27);
        cout << "                                                                                ";
        PosXY(0, 28);
        cout << "                                                                                 ";


        PosXY(2, 25);
        cout << nombre << " ingresa la COLUMNA [A-Y] de la ficha que quieres mover: ";
        cin >> colum;

        switch (toupper(colum))
        {
        case 'A': posX = 6; break;
        case 'B': posX = 8; break;
        case 'C': posX = 10; break;
        case 'D': posX = 12; break;
        case 'E': posX = 14; break;
        case 'F': posX = 16; break;
        case 'G': posX = 18; break;
        case 'H': posX = 20; break;
        case 'I': posX = 22; break;
        case 'J': posX = 24; break;
        case 'K': posX = 26; break;
        case 'L': posX = 28; break;
        case 'M': posX = 30; break;
        case 'N': posX = 32; break;
        case 'O': posX = 34; break;
        case 'P': posX = 36; break;
        case 'Q': posX = 38; break;
        case 'R': posX = 40; break;
        case 'S': posX = 42; break;
        case 'T': posX = 44; break;
        case 'U': posX = 46; break;
        case 'V': posX = 48; break;
        case 'W': posX = 50; break;
        case 'X': posX = 52; break;
        case 'Y': posX = 54; break;

        }

        PosXY(2, 26);
        cout << nombre << " Ingresa la FILA [A-Q]  de la ficha que quieres mover: ";
        cin >> fila;

        switch (toupper(fila))
        {
        case 'A': posY = 5; break;
        case 'B': posY = 6; break;
        case 'C': posY = 7; break;
        case 'D': posY = 8; break;
        case 'E': posY = 9; break;
        case 'F': posY = 10; break;
        case 'G': posY = 11; break;
        case 'H': posY = 12; break;
        case 'I': posY = 13; break;
        case 'J': posY = 14; break;
        case 'K': posY = 15; break;
        case 'L': posY = 16; break;
        case 'M': posY = 17; break;
        case 'N': posY = 18; break;
        case 'O': posY = 19; break;
        case 'P': posY = 20; break;
        case 'Q': posY = 21; break;
        }

        if (Tablero[posY][posX] == ficha) salir = true;
        if (salir != true)
        {
            PosXY(3, 28); cout << "NO PUEDE MOVER ESTA FICHA";
            _getch();
        }

    } while (salir != true);

    if (T == 1)
    {
        PosXY(96, 14); cout << posY;
        PosXY(96, 12); cout << posX;
    }
    else
    {
        PosXY(115, 14); cout << posY;
        PosXY(115, 12); cout << posX;
    }

    CaracteristicasJugador(J, ficha, posX, posY);
    PintarPosAnt(J);
    moverFicha(J);
    PintarPosAct(J);

    if (T == 1)
    {
        PosXY(96, 14); cout << "   ";
        PosXY(96, 12); cout << "   ";
    }
    else
    {
        PosXY(115, 14); cout << "   ";
        PosXY(115, 12); cout << "   ";
    }

    if (posX != J->x && posY != J->y)movimiento++;


}
bool Ganar(Jugador* J)
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            if (J->simbolo == 'A' || J->simbolo == 'B')
            {

                if (Tablero[8][24] == 'A' && Tablero[8][28] == 'A' && Tablero[8][32] == 'A' && Tablero[8][36] == 'A' &&
                    Tablero[7][26] == 'A' && Tablero[7][30] == 'A' && Tablero[7][34] == 'A' && Tablero[6][28] == 'A' &&
                    Tablero[6][32] == 'A' && Tablero[5][30] == 'A') return true;


                else if (Tablero[18][24] == 'B' && Tablero[18][28] == 'B' && Tablero[18][32] == 'B' && Tablero[18][36] == 'B' &&
                    Tablero[19][26] == 'B' && Tablero[19][30] == 'B' && Tablero[19][34] == 'B' && Tablero[20][28] == 'B' &&
                    Tablero[20][32] == 'B' && Tablero[21][30] == 'B') return true;
            }
            else if (J->simbolo == 'C' || J->simbolo == 'D')
            {
                if (Tablero[17][6] == 'D' && Tablero[17][10] == 'D' && Tablero[17][14] == 'D' && Tablero[17][18] == 'D' &&
                    Tablero[16][8] == 'D' && Tablero[16][12] == 'D' && Tablero[16][16] == 'D' && Tablero[15][10] == 'D' &&
                    Tablero[15][14] == 'D' && Tablero[14][12] == 'D')return true;

                else if (Tablero[9][42] == 'C' && Tablero[9][46] == 'C' && Tablero[9][50] == 'C' && Tablero[9][54] == 'C' &&
                    Tablero[10][44] == 'C' && Tablero[10][48] == 'C' && Tablero[10][52] == 'C' && Tablero[11][46] == 'C' &&
                    Tablero[11][50] == 'C' && Tablero[12][48] == 'C')return true;

            }
            else if (J->simbolo == 'E' || J->simbolo == 'F')
            {
                if (Tablero[17][42] == 'F' && Tablero[17][46] == 'F' && Tablero[17][50] == 'F' && Tablero[17][54] == 'F' &&
                    Tablero[16][44] == 'F' && Tablero[16][48] == 'F' && Tablero[16][52] == 'F' && Tablero[15][46] == 'F' &&
                    Tablero[15][50] == 'F' && Tablero[14][48] == 'F')return true;

                else if (Tablero[9][6] == 'E' && Tablero[9][10] == 'E' && Tablero[9][14] == 'E' && Tablero[9][18] == 'E' &&
                    Tablero[10][8] == 'E' && Tablero[10][12] == 'E' && Tablero[10][16] == 'E' && Tablero[11][10] == 'E' &&
                    Tablero[11][14] == 'E' && Tablero[12][12] == 'E') return true;
            }


        }
    }
}
void MostrarGanador(int T, char* nom1, char* nom2)
{

    Console::SetWindowSize(70, 20);

    for (int filas = 0; filas < 20; filas++)
    {
        for (int columnas = 0; columnas < 70; columnas++)
        {
            if (Ganador[filas][columnas] == 0)
            {
                Console::BackgroundColor = ConsoleColor::White;
                cout << " ";
            }
            if (Ganador[filas][columnas] == 1)
            {
                Console::BackgroundColor = ConsoleColor::Red;
                cout << " ";


            }

        }
        cout << endl;
    }


    Console::BackgroundColor = ConsoleColor::Yellow;
    Console::ForegroundColor = ConsoleColor::Black;

    if (T == 1) { PosXY(45, 15); cout << "¡¡ " << nom2 << " !!" << endl; }
    else { PosXY(45, 15); cout << "¡¡ " << nom1 << " !!" << endl; }

}
int main()
{

    Jugador* J1 = new Jugador;
    Jugador* J2 = new Jugador;

    char* nombreJ1 = new char[20];
    char* nombreJ2 = new char[20];
    char fichaJ1, fichaJ2;
    int Turno, puntajeJ1, puntajeJ2;
    int movimientosJ1 = 0, movimientosJ2 = 0;

 
    MostrarPresentacionEinstrucciones();
    IngresarNombres(nombreJ1, nombreJ2);
    LanzarDado(puntajeJ1, puntajeJ2, nombreJ1, nombreJ2);
    ElegirFicha(fichaJ1, fichaJ2, nombreJ1, nombreJ2, puntajeJ1, puntajeJ2, Turno);
    ElegirPosicionesTablero(fichaJ1);

    Console::Clear();
    Console::CursorVisible = false;

    Console::SetWindowSize(150, 40);

    while (1)
    {
        muestraTablero();
        mostrarFilaYcolumna();
        MostrarDatosDelJugador(nombreJ1, nombreJ2, fichaJ1, fichaJ2, movimientosJ1, movimientosJ2);

       
        if (Turno == 1)
        {
            EscogerPosicionDeFicha(J1, nombreJ1, fichaJ1, Turno, movimientosJ1);
            Turno = 2;
        }
        else
        {
            EscogerPosicionDeFicha(J2, nombreJ2, fichaJ2, Turno, movimientosJ2);
            Turno = 1;
        }

        if (Ganar(J1) == true)break;
    }

    Console::Clear();
    MostrarGanador(Turno, nombreJ1, nombreJ2);

    _getch();
    return 0;

}
