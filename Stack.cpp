#include "main.h"
#include "Stack.h"

void Stack::Clear() { top = EMPTY; }
bool Stack::IsEmpty() { return top == EMPTY; }
bool Stack::IsFull() { return top == FULL; }
int Stack::GetCount() { return top + 1; }

void Stack::Push ( wchar_t c ) { if ( !IsFull() ) card[++top] = c; }

wchar_t Stack::Pop() {
	if ( !IsEmpty() ) {
		return card[top--];
	} else {
		return 0;
	}
}

void Stack::ShowStack() {
	for ( int i = top; i > EMPTY; i-- ) {
		wcout << card[i] << endl;
	}
}
