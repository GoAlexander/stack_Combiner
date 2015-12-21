#include <iostream>
#include <limits>
#include <cstdlib>
#include "stack.h"
#include "avltree.h"

using namespace std;


void checking_input(int * x_number)
{
	while (!cin) //if edit class Value -> edit this if
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Incorrect argument! Enter number:\n>";
		cin >> * x_number;
	}
}


int main()
{
	int operation_number, error;
	Stack Mystack;
	AvlTree MyAvlTree;

	cout << "\nImplementation of stack with singly linked list." << endl;
	
	//Menu + checking argument
	for(;;)
	{
		cout << "=========================================" << endl;
		cout << "Supported operations:" << endl;
		cout << "\t1. Push (add the element)" << endl;
		cout << "\t2. Pop (delete the element)" << endl;
		cout << "\t3. Top (show the top element)" << endl;
		cout << "\t4. Isempty (checking the void of stack)" << endl;
		cout << "\t5. Exit from program" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "\tFunctional of lab2:" << endl;
		cout << "\t6. Show all stack" << endl;
		cout << "\t7. Sort stack" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "\tFunctional of lab3:" << endl;
		cout << "\t8. Show AVL-tree visualization (of all stack)." << endl;
		cout << "\t9. Show AVL-tree preorder (of all stack)." << endl;
		cout << ">";

		cin >> operation_number;
		checking_input(&operation_number);
				
		cout << "=========================================" << endl;
		
		if (operation_number==1)
		{
			string pushing_number;
			Value Myvalue;
			cout << "Rules for pushing: " << endl;
			cout << "\tFor decimal or negative decimal - simply enter. Example: <10> or <-10>" << endl;
			cout << "\tBinary number should begin from <0>. Example: <01010>" << endl;
			cout << "\tTwo's Complement number should begin from <1> and have 16 bits. Example: <1111111111111010>" << endl;
			cout << "\tPush new element (dec/bin):\n>";
			cin >> pushing_number;
			//write new function checking_input()
			
			Myvalue.setValue(pushing_number);
			Mystack.push(Myvalue);
		}

		else if (operation_number==2)
			if (Mystack.pop()==0)
				cout << "The element poped successful." << endl;
			else
				cout << "Warning! Stack is empty!" << endl;

		else if (operation_number==3)
		{
			Mystack.top(&error);
			if (error==0)
				cout << "Top element is " << Mystack.top(&error).getValue() << "." << endl; //Mystack.top(&error).getValue()
			if (error==1)
				cout << "Can not show element! Stack is empty!" << endl;
		}

		else if (operation_number==4)
			if (Mystack.is_empty()==0)
				cout << "Stack is empty." << endl;
			else
				cout << "Stack is not empty." << endl;

		else if (operation_number==5)
		{
			cout << "Program closed!" << endl;	
			return 0;
		}

		//lab2 functional
		else if (operation_number==6)
		{
			Mystack.show();	
		}
		else if (operation_number==7)
		{
			Mystack.sorting();
			cout << "Stack sorted!" << endl;
		}

		//lab3 functional
		else if (operation_number==8)
		{
			//showing tree from current list
    		for (Elem *tmp_elem=Mystack.Head; tmp_elem!=NULL; tmp_elem=tmp_elem->next)
			{
    			MyAvlTree.insert(tmp_elem->val ); //Выводим каждое считанное значение на экран
    		}
			MyAvlTree.displayTree(1);
			cout << endl;
		}

		else if (operation_number==9)
		{	
			//showing tree from current list
    		for (Elem *tmp_elem=Mystack.Head; tmp_elem!=NULL; tmp_elem=tmp_elem->next)
			{
    			MyAvlTree.insert(tmp_elem->val ); //Выводим каждое считанное значение на экран
    		}
			MyAvlTree.preOrder();
			cout << endl;
		}

		else
			cout << "Incorrect argument, enter again!" << endl;
	}

	return 0;
}