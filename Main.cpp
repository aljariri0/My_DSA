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

using namespace std;

int main()
{
    int arr[] = {8, 5, 7, 3, 2};
    SelectionSort s(arr, 5);

    s.Display();
    s.Sort();
    s.Display();
}
