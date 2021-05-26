#ifndef STACK_H
#define STACK_H

#include "main.h"

using namespace std;

class Stack {
	enum { EMPTY = -1, FULL = 51 };	//Нижняя и верхняя границы стека
	wchar_t card[CARDS_COUNT];		//Массив для хранения данных
	int top{EMPTY};				//Указательна вершину стека
  public:
	Stack() {}	//конструктор
	void Push ( wchar_t c );	//Добавление элемента
	wchar_t Pop();	//Извлечение элемента
	bool IsEmpty();	//Проверка на пустоту
	bool IsFull();	//Проверка на заполненность
	int GetCount();	//Количество элементов в стеке
	void Clear();	//Очистка стека
	void ShowStack();
};

#endif // STACK_H
