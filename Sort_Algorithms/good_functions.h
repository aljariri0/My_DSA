#pragma once
#include <iostream>
using namespace std;

class GoodFunctions
{

public:
    static void Swap(int &a, int &b)
    {

        int temp = a;
        a = b;
        b = temp;
    }
};