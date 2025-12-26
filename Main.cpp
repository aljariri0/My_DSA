#include <iostream>
// #include "LinkedList.h"
// #include "CircularLinkedList.h"
// #include "DoublyLinkedList.h"
// #include "CircularDoublyLinkedList.h"
// #include "Stack.h"
// #include "Queue.h"
#include "clsTree.h"
#include "Sort_Algorithms/bubble_sort.h"
#include "Sort_Algorithms/insertion_sort.h"
#include "Sort_Algorithms/selection_sort.h"
#include "Sort_Algorithms/good_functions.h"

using namespace std;

int main()
{
    int arr1[] = {2, 10, 18, 20, 23};
    int arr2[] = {4, 9, 19, 25};

    int *arr3 = new int[4 + 5];

    arr3 = GoodFunctions::Merge(arr1, arr2, 5, 4);

    for (int i = 0; i < 9; i++)
    {
        cout << arr3[i] << " ";
    }
}
