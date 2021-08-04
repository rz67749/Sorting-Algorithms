#ifndef SORTING_H
#define SORTING_H
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Sorting{
public:
    // Selection Sort 
    int selectionSort(int values[], int numValues);
    int minIndex(int values[], int start, int end, long& count); 
    
    // Merge Sort
    int mergeSort(int values[], int first, int last);
    void merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast, long& count);
    
    // Heap Sort
    int heapSort(int values[], int numValues);
    void reHeapDown(int values[], int root, int bottom, long& count);
    
    // Quick Sort FP
    int quickSortFP(int values[], int first, int last);
    void split(int values[], int first, int last, int& splitPoint, long& count);
    
    // Quick Sort RP
    int quickSortRP(int values[], int first, int last);
    
}; // Sorting
#endif
