#include <iostream>
#include <time.h>
#include <cstdio>
#include <locale.h>

#ifndef __MINGW32__
#include <ncurses.h>
#endif // __MINGW32__

#include "main.h"
#include "Stack.h"
#include "Gamer.h"

//#define DEBUG

using namespace std;

// Создание колоды
void DeckCreating ( map<wchar_t, int> &cardsMap, vector<wchar_t> &vect_cards ) {

	for ( int i = 1; i < CARDS_COUNT; i++ ) {
		if ( (i%16) % 12 != 0 && (i%16) % 15 != 0 && i % 16 != 0 ) {
			vect_cards.push_back ( ( wchar_t ) ( i + 0x1F0A0 ) );
			int cardValue = i % 16;

			if ( cardValue > 10 ) {
				cardValue = 10;
			} else if ( cardValue == 1 ) {
				cardValue = 11;
			}

			pair<wchar_t, int> element ( vect_cards.back(), cardValue );
			cardsMap.insert ( element );
		}
	}
}

void HTMLwrite ( Gamer** gamer, int gamersCount );
void HTMLwrite ( Gamer** gamer, int gamersCount, map<wchar_t, int>* cardsMap );

int main() {
	setlocale ( LC_ALL, "" );

	map<wchar_t, int> cardsMap;
	vector<wchar_t> vect_cards;

	DeckCreating ( cardsMap, vect_cards );

// Перемешивание колоды
	Stack deck;
	srand ( time ( NULL ) );

	#ifdef DEBUG
	CODEModify ( "Элементов в стеке: " );
	cout << deck.GetCount() << endl;
	cout<< deck.IsFull()<<endl;
	cout<< vect_cards.size()<<endl;
	#endif // DEBUG

	while ( !deck.IsFull() ) {
		int index = ( rand() % ( vect_cards.size() ) );
		#ifdef DEBUG
		cout<< index <<" , " << vect_cards[index] << endl;
		#endif // DEBUG
		deck.Push ( vect_cards[index] );
		vect_cards.erase ( vect_cards.begin() + index );
	}

	#ifdef DEBUG
	CODEModify ( "Элементов в стеке: " );
	cout << deck.GetCount() << endl;
	deck.ShowStack();
	#endif // DEBUG


	// Игроки

	Gamer** gamer;

	CODEModify ( "Сколько человек играет? - " );
	string inputStr = "";
	int gamersCount = 0;

	for ( ;; ) {
		try {
			getline ( cin, inputStr );

			if ( inputStr == "" ) {		// Расширить список исключений
				throw "Ошибка. Введите положительное число!";
			}

			gamersCount = stoi ( inputStr );
			gamer = new Gamer*[gamersCount];
			break;

		} catch ( string g ) {
			CODEModify ( g.c_str() );
		}
	}

	for ( int i = 0; i < gamersCount; i++ ) {
		CODEModify ( "Введите имя " );
		cout << i + 1;
		CODEModify ( "-го игрока: " );
		getline ( cin, inputStr );

		if ( inputStr == "" ) {
			inputStr = "Инкогнито";
		}

		gamer[i] = new Gamer ( inputStr, &cardsMap );
	}

	#ifdef DEBUG
	cout << gamersCount << endl;
	#endif // DEBUG

	// Раздача карт

	CODEModify ( "Раздача карт\n" );

	for ( int i = 0; i < gamersCount; i++ ) {
		for ( int j = 0; j < 2; j++ ) {
			gamer[i]->addCard ( deck.Pop() );
		}
	}

	#ifdef DEBUG
	HTMLwrite ( gamer, gamersCount, &cardsMap );
	#else
	HTMLwrite ( gamer, gamersCount );
	#endif // DEBUG

	string operate = "xdg-open ";
	string filen = FILE_RW;

	system ( ( operate + filen ).c_str() );

	for ( int i = 0; i < gamersCount; i++ ) {
		delete gamer[i];
	}

	delete gamer;
}



























