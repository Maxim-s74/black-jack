#include <iostream>
#include "Deck.h"

using namespace std;

void Deck::Clear() { top = EMPTY; }
bool Deck::IsEmpty() { return top == EMPTY; }
bool Deck::IsFull() { return top == FULL; }
int Deck::GetCount() { return top + 1; }

void Deck::Push(char c) { if (!IsFull()) card[++top] = c; }
char Deck::Pop() {
	if (!IsEmpty()) return card[top--];
	else return 0;
}

void Deck::ShowDeck() {
	for (int i = top; i > EMPTY; i--) {
		cout << card[i] << endl;
	}
}
