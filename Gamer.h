#ifndef GAMER_H
#define GAMER_H

#include "main.h"


class Gamer {
  private:
	string name{""};
	wchar_t cards[2];
	int ind{0};
	int points{0};
	map<wchar_t, int>* cardsMap{nullptr};
  public:
	Gamer ( string name, map<wchar_t, int>* cardsMap ) {this->name = name; this->cardsMap = cardsMap;};
	Gamer ( const Gamer & other ) {
		if ( this != &other ) {
			this->name = other.name;
			this->cards[0] = other.cards[0];
			this->cards[1] = other.cards[1];
			this->ind = other.ind;
			this->points = other.points;
			this->cardsMap = other.cardsMap;
		}
	}

	Gamer& operator = (const Gamer& other);
	bool addCard ( wchar_t value );
	void cardsShow();
	pair<wchar_t, wchar_t> getCards();
	int pointCount();
	string* getName();
};

#endif // GAMER_H
