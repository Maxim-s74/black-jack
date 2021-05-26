#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <fstream>

#define CARDS_COUNT 64
#define FILE_RW "index.html"

using namespace std;


#ifdef __MINGW32__
#include <windows.h>
#include <conio.h>
#include <math.h>
#define CLEAR_SCREEN "cls"
#pragma execution_character_set( "utf-8" )
#define SET_CONSOLE //SetConsoleOutputCP (65001)

#else
#include "code_linux.h"
#define CLEAR_SCREEN "clear"
#endif


inline void CODEModify (const char stringfPrint[]) {
	#ifdef SET_CONSOLE
	wchar_t wstr[128];
	MultiByteToWideChar (CP_UTF8, 0, stringfPrint, 128, wstr, 128);
	wcout << wstr;
	#else
	cout << stringfPrint;
	#endif // SET_CONSOLE
}

//ЦВЕТА ТЕКСТА
#define	BLACK "\033[1;30m"
#define	BLUE "\033[1;34m"
#define	GREEN "\033[1;32m"
#define	RED "\033[1;31m"
#define	YELLOW "\033[1;33m"
#define	WHITE "\033[1;37m"

#endif // MIAN_H
