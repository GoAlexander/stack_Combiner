//lab3 functional

#pragma once
#include "value.h"

struct node
{
    Value key;
    struct node *left; //можно не писать struct, т к C++
    struct node *right;
    int height;
    node(Value new_key) { key = new_key; left = right = 0; height = 1; } //типо конструктора :)
};