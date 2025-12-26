#pragma once

#include <iostream>
using namespace std;

class InsertionSort
{

public:
    int *element;
    int size;

    InsertionSort(int arr[], int size)
    {

        this->size = size;
        element = arr;
    }

    void Sort()
    {

        for (int i = 1; i < size; i++)
        {
            int j = i - 1;
            int x = element[i];

            while (j > -1 && element[j] > x)
            {
                element[j + 1] = element[j];
                j--;
            }
            element[j + 1] = x;
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