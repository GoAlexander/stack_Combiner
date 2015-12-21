#pragma once //защита от двойного подключения
#include <vector>
#include <iterator>
#include <string>
#include <cstdlib>
using namespace std;

//TODO make some functions private
class Value
{
public:
	//const int size = 8;
	int decval;
	vector<int> binval; //только вводить в вектор с конца!
						//выводить начиная с элемента size_of_bin  
	int size_of_bin;

	void setDecValue(int n);
	void setBinValue(string n);

	void setValue(string n);
	int getValue(); //returns dec Value
	void showBinValue();
	void showDecValue();
	void decToBin(int sign);
	void binToDec(string a);
	//void binToDec(vector<int> & tmp_bin);
	bool equal(Value first, Value second);
	//Value max(Value first, Value second);
};