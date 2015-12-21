#include <iostream>
#include "stack.h"
using namespace std;

void Stack::push(Value el)
{
	Elem * tmp_elem=new Elem; //taking resource for new structure
	tmp_elem->val=el;
	tmp_elem->next=Head;
	Head=tmp_elem; //new pointer on top
}

int Stack::pop()
{
	if (Head!=NULL)
	{
		Value tmp_elem_val = Head->val; //value of top element in tmp 
		Elem * tmp_elem = Head; //to show top element in the next string
		Head=Head->next;
		delete tmp_elem;
		return 0;
	}
	else 
		return 1;
}

Value Stack::top(int * error)
{
	Elem * tmp_elem=Head; //call of top element
	if (Head!=NULL)
	{
		*error=0;
		return tmp_elem->val;
	}
	else
		*error=1;		
}

int Stack::is_empty()
{
	if (Head==NULL)
		return 0;
	else
		return 1;		
}

void Stack::show() //перенести в другой файл?
{
 	//вывод списка сначала (т е как будто мы стек "разгружаем")
 	Elem * tmp_elem=Head;//Временно указываем на адрес первого элемента
    while (tmp_elem!=NULL) //Пока не встретим пустое значение
    {
    	cout<<tmp_elem->val.getValue()<<" "; //Выводим каждое считанное значение на экран
    	tmp_elem=tmp_elem->next; //Смена адреса на адрес следующего элемента
    }
    cout<<"\n";
}

//for lab3
//Bubblesort
void Stack::sorting() 
{	
	for(Elem *end = NULL; end!= Head; )
	{
		Elem *curr = Head, *past = NULL;
		while (curr!=end && curr->next!= end)
		{
			if (curr->val.getValue() < curr->next->val.getValue())
			{
				Elem *tmp = curr->next;
				swapping(past, curr, curr->next);
				past = tmp;
			}
			else
			{
				past = curr;
				curr = curr->next;
			}
		}
		end = curr;
	}	 
}

void Stack::swapping(Elem *past, Elem *curr, Elem *follow)
{
	if (past == NULL)
	{
		curr->next = follow->next;
		follow->next = curr;
		Head = follow;
	}
	else
	{
		curr->next = follow->next;
		follow->next = curr;
		past->next = follow;
	}
}
