#pragma once

#include <iostream>
#include "good_functions.h"
using namespace std;

class BubbleSort
{
private:
    int *element;
    int size;

public:
    // bubble sort is adoptive and stable
    BubbleSort(int arr[], int size)
    {

        this->size = size;
        element = arr;
    }

    void Sort()
    {
        int flag = 0;

        for (int i = 0; i < size - 1; i++)
        {

            flag = 0;
            for (int j = 0; j < size - 1 - i; j++)
            {

                if (element[j] > element[j + 1])
                {

                    GoodFunctions::Swap(element[j], element[j + 1]);
                    flag = 1;
                }
            }

            if (flag == 0)
                return;
        }
    }

    void Display()
    {

        for (int i = 0; i < size; i++)
        {
            cout << element[i] << " ";
        }

        cout << "\n";
    }
};