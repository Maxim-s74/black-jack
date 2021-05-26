#include "Gamer.h"

bool Gamer::addCard ( wchar_t value ) {
	if ( ind < 2 ) {
		this->cards[this->ind] = value;
		this->points = this->points + ( *(this->cardsMap) ) [this->cards[this->ind]];
//		this->points += this->cardsMap->find ( this->cards[this->ind] )->second;
		ind++;
		return false;
	}

	return true;
}

pair<wchar_t, wchar_t> Gamer::getCards() {
	pair<wchar_t, wchar_t>pntCnt ( this->cards[0], this->cards[1] );
	return pntCnt;
}

int Gamer::pointCount() {
	return this->points;
}

string* Gamer::getName() {return & ( this->name );}

Gamer& Gamer::operator = ( const Gamer& other ) {
	if ( this != &other ) {
		this->name = other.name;
		this->cards[0] = other.cards[0];
		this->cards[1] = other.cards[1];
		this->ind = other.ind;
		this->points = other.points;
		this->cardsMap = other.cardsMap;
	}

	return *this;
}
