#pragma once //защита от двойного подключения
#include "elem.h"

class Stack
{
	
public:
	Elem *Head; //вернуть в private
	Stack() {Head=NULL;}
    int pop();
	void push(Value el);
	Value top(int * error);
	int is_empty();
	void show();
	void sorting();
	void swapping (Elem *past, Elem *curr, Elem *follow);
	//int* get_for_tree(); //конвертация из Value в int [DELETE!]
	//Elem* getHead();

	/*
	???
	~Stack()
	{
		while (Head != NULL)
		Pop();
	}
	*/
};