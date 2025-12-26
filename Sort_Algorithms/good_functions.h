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

    static int *Merge(int a[], int b[], int m, int n)
    {
        int *merged_array = new int[m + n];
        int i = 0, j = 0, k = 0;

        while (i < m && j < n)
        {
            if (a[i] < b[j])
                merged_array[k++] = a[i++];

            else if (a[i] > b[j])
                merged_array[k++] = b[j++];
        }

        for (; i < m; i++)
            merged_array[k++] = a[i];

        for (; j < n; j++)
            merged_array[k++] = b[j];

        return merged_array;
    }
};