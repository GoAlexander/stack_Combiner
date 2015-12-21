#pragma once //защита от двойного подключения
#include "value.h"

struct Elem 
{
  Value val;
  struct Elem * next; //struct можно не использовать, т. к. C++
};