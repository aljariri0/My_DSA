#pragma once

#include <iostream>
using namespace std;

namespace Heap
{

    class clsHeap
    {

    private:
        int size;
        int *elements;
        int length = -1;

    public:
        clsHeap(int elements[], int size, int length)
        {

            this->size = size;
            this->elements = new int[size];

            for (int i = 0; i <= length && i < size; i++)
            {
                Insert(elements[i]);
            }
        }

        int GetLength()
        {

            return length;
        }

        int GetParentIndex(int value)
        {

            int index = 0;

            for (int i = 0; i <= length; i++)
            {
                if (elements[i] == value)
                {

                    index = i;
                    break;
                }
            }

            return (index - 1) / 2;
        }

        void Swap(int &a, int &b)
        {

            int temp = a;
            a = b;
            b = temp;
        }

        void Insert(int value)
        {

            if (size - 1 == length)
                return;

            length++;
            int i = length; // first insert the value at last element
            elements[i] = value;

            while (i != 0 && elements[i] > elements[(i - 1) / 2])
            {

                Swap(elements[i], elements[(i - 1) / 2]);

                i = (i - 1) / 2;
            }
        }

        void DisplayHeap()
        {

            for (int i = 0; i <= length; i++)
            {

                cout << this->elements[i] << " ";
            }

            cout << "\n";
        }

        void Display()
        {

            for (int i = 0; i <= size; i++)
            {

                cout << this->elements[i] << " ";
            }

            cout << "\n";
        }

        void Delete()
        {

            if (length < 0)
                return;

            int i = 0;

            int deleted_value = elements[0];

            elements[0] = elements[length];
            length--;

            while (true)
            {

                int left = (2 * i + 1);
                int right = (2 * i + 2);
                int largest = i; // assume the parent is the largest

                if (left <= length && elements[left] > elements[largest])
                {
                    largest = left;
                }

                if (right <= length && elements[right] > elements[largest])
                {

                    largest = right;
                }

                if (largest != i)
                {

                    Swap(elements[i], elements[largest]);
                    i = largest;
                }

                else
                    break;
            }

            elements[length + 1] = deleted_value;
        }

        ~clsHeap()
        {
            delete[] elements;
        }
    };

}