#pragma once

#include <iostream>
using namespace std;

class SelectionSort
{

private:
    int size;
    int *element;

public:
    SelectionSort(int arr[], int size)
    {

        this->size = size;
        element = arr;
    }

    void Swap(int &a, int &b)
    {

        int temp = a;
        a = b;
        b = temp;
    }

    void Sort()
    {

        int i, j, k;

        for (i = 0; i < size - 1; i++)
        {
            for (j = k = i; j < size; j++)
            {
                if (element[j] < element[k])
                    k = j;
            }

            Swap(element[i], element[k]);
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