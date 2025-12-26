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
#include "Sort_Algorithms/count_sort.h"

using namespace std;

int main()
{
    int arr1[] = {2, 10, 18, 20, 23};

    CountSort s(arr1, 5);
    s.Sort();
    s.Display();
}
