#include "value.h"
#include <iostream>
#include <iterator>	
#include <string>
#include <cstdlib>
using namespace std;


//call this function if input value is dec
void Value::setDecValue(int n) 
{
	//set inputed value
	decval=n;

	//convertion
	if (n >= 0) //для положительных чисел
		decToBin(0);
	else if (n < 0) { //для отрицательных чисел
		//n = n * (-1); //delete
		decToBin(1);
		//по алгоритму:
		//положительное в двоичное
		//inverse

		//нужно сделать в 16 разрядов!
		int counter(0);
		for(int i(0); i < size_of_bin/*-1*/; i++, counter++) { //последний не трогать
			//заменить на логическое
			if (binval[i] == 1)
				binval[i] = 0;
			else if (binval[i] == 0)
				binval[i] = 1;
		}
		//расширяем "маску"
		if (counter < 15) { //TMP?
			binval[size_of_bin]=1;
		}
		
		while (counter < 15) {
			binval.push_back(1); //проверить!
			size_of_bin++;
			counter++;
		}
		
		//test
		//cout << "Inverse: " << endl;
		//showBinValue();

		//+1
		binval[0] += 1;
		for(int i(1); i < size_of_bin; i++) {
			if (binval[i-1] == 2) {
				binval[i-1] = 0;
				binval[i] += 1; 
			}
		}
		if (binval[size_of_bin-1] == 2) {
			binval[size_of_bin-1] = 0;
			binval.push_back(1);
		}
		//test
		//cout << "+1: " << endl;
		//showBinValue();

		//в конце последний элемент вектора заменить на 1
		binval[binval.size()-1]=1;
	}
}

//call this function if input value is bin
void Value::setBinValue(string n) 
{
	/* 
	* Warning!
	* In my vector first bit is first element in vector
	* and last bit - last element in vector!!!
	*/

	//set inputed value
	size_of_bin=n.size()-1;

	for(int i(size_of_bin); i>-1; i--) {
		if (n[i] == '0')
			binval.insert(binval.end(), 0);
		else if (n[i] == '1')
			binval.insert(binval.end(), 1);
	}

	//tmp value for work
	vector<int> tmp_bin = binval;

	//convertion
	if (n[0] == '0') { //положит. число
		binToDec(n);
	}
	else if (n[0] == '1') { //отрицательное число
			
		//-1
		tmp_bin[0] -= 1;
		for(int i(1); i < size_of_bin; i++) {
			if (tmp_bin[i-1] == -1) {
				tmp_bin[i-1] += 2;
				tmp_bin[i] -= 1; 
			}
		}
		
		/* For test
		cout << "-1: ";
		for(int i(size_of_bin); i>-1; i--)
			cout << tmp_bin[i];
		cout << endl;
		*/

		//inverse
		for(int i(0); i <= size_of_bin; i++) { //за счёт <= "трогаем" последний элемент
			//заменить на логическое
			if (tmp_bin[i] == 1)
				tmp_bin[i] = 0;
			else if (tmp_bin[i] == 0)
				tmp_bin[i] = 1;
		}

		/* For test
		cout << "inverse: ";
		for(int i(size_of_bin); i>-1; i--)
			cout << tmp_bin[i];
		cout << endl;
		*/

		//TODO make new function:
		int Rslt = 0;
    	int Mask = 1;
    	for (int i = 0; i <= size_of_bin; ++i, Mask <<= 1) {
        	if (tmp_bin[i] != 0) {
            	Rslt |= Mask;
        	}
   		}
    	decval=Rslt;
    	decval *= (-1);
    	
    	//void binToDec(tmp_bin);
	}
}

void Value::setValue(string n) 
{
	//if input value is bin
	if (n[0] == '0' || ( n[0]== '1' && n.size() == 16) ) {
		//set input value in this function and find decimal result
		setBinValue(n);
	}
	//if input value is dec
	else {
		decval=stoi(n);
		setDecValue(decval);
	}

	//TEST
	//TODO move in another place
	showDecValue();
	showBinValue();
}


//returns dec value
int Value::getValue() 
{
	return decval;
}
void Value::showDecValue() 
{
	cout << "Decimal value: " << getValue() << endl;
}
void Value::showBinValue() 
{
	cout << "Binary value: ";
	for(int i(size_of_bin); i>-1; i--)
		cout << binval[i];
	cout << endl;
}

//sign ==0 -> +, sign ==1 -> 1
void Value::decToBin(int sign)
{
	//TODO Make it more simple???
	
	int decval_tmp=decval;
	size_of_bin=0;
	if (sign==1) {
		decval_tmp = decval_tmp * (-1);
	}

	for (;decval_tmp; decval_tmp /= 2, size_of_bin++);	//"узнаем" размерность массива
	
	int size_of_bin_tmp=size_of_bin;
	decval_tmp = decval;
	if (sign==1) {
		decval_tmp = decval * (-1);
	}

	for (; size_of_bin_tmp > -1; size_of_bin_tmp--, decval_tmp/=2) {
	   //binval[size_of_bin_tmp]=decval_tmp%2;
	   //binval.insert(binval.begin(),decval_tmp%2);	//тоже перенести в for?
		binval.push_back(decval_tmp%2);
	}
}

void Value::binToDec(string a)
{
	int Rslt = 0;
    int Mask = 1;
    for (int i = a.length()-1; i >= 0; --i, Mask <<= 1) {
    //for (int i = 0; i <= a.length()-1; ++i, Mask <<= 1) {
        if (a.at(i) != '0') {
            Rslt |= Mask;
        }
    }
    decval=Rslt;
}
/*
void Value::binToDec(vector<int> & tmp_bin)
{
	int Rslt = 0;
    int Mask = 1;
    for (int i = 0; i <= size_of_bin; ++i, Mask <<= 1) {
        if (tmp_bin[i] != 0) {
            Rslt |= Mask;
        }
   	}
    decval=Rslt;
    decval *= (-1);
}
*/

//for lab3
bool Value::equal(Value first, Value second)
{
	if (first.decval==second.decval)
		return 1;
	else
		return 0;
}

/*
Value Value::max(Value first, Value second)
{
	if (first.decval>second.decval)
		return first;
	else
		return second;
}
*/