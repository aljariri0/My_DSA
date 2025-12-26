#pragma once

#include <iostream>
using namespace std;

class CountSort
{

private:
    int size;
    int *element;
    int *Count;
    int max;

public:
    CountSort(int arr[], int size)
    {

        this->size = size;
        element = arr;
    }

    void Sort()
    {
        max = element[0];

        for (size_t i = 1; i < size; i++)
        {
            if (max < element[i])
                max = element[i];
        }

        Count = new int[max + 1]{};

        for (size_t i = 0; i < size; i++)
        {
            Count[element[i]]++;
        }

        for (int i = 0, j = 0; i <= max; i++)
        {
            if (Count[i] != 0)
            {
                while (Count[i] > 0)
                {
                    element[j++] = i;
                    Count[i]--;
                }
            }
        }
    }

    void Display()
    {

        for (size_t i = 0; i < size; i++)
        {
            cout << element[i] << " ";
        }

        cout << "\n";
    }

    ~CountSort()
    {

        delete[] Count;
    }
};