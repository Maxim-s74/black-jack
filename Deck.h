#ifndef DECK_H
#define DECK_H

#include "main.h"

class Deck {
	enum { EMPTY = -1, FULL = 51 };	//Нижняя и верхняя границы стека
	wchar_t card[CARDS_COUNT];		//Массив для хранения данных
	int top{EMPTY};				//Указательна вершину стека
  public:
	Deck(){}	//конструктор
//	~Deck();

	void Push (char c);	//Добавление элемента
	char Pop();	//Извлечение элемента
	bool IsEmpty();	//Проверка на пустоту
	bool IsFull();	//Проверка на заполненность
	int GetCount();	//Количество элементов в стеке
	void Clear();	//Очистка стека
	void ShowDeck();
};


#endif // DECK_H
