#include "Sorting.h"
#include <cstdlib>
#include <ctime>

// Selection Sort 

// finds index of smallest number in portion being searched
int Sorting::minIndex(int values[], int start, int end, long& count)
{
  int indexOfMin = start;
  for(int i = start + 1; i <= end; i++)
  {
    if(values[i] < values[indexOfMin])
    {
      indexOfMin = i;
    }//if
    count++;
  }//for
  return indexOfMin;
}//MinIndex

int Sorting::selectionSort(int values[], int numValues)
{
  long numComparisons = 0;
  int endIndex = numValues - 1;
  for(int i = 0; i <= endIndex; i++)
  {
    int minimum = minIndex(values, i , endIndex, numComparisons);
    int temp = values[i]; // swap with min value found 
    values[i] = values[minimum];
    values[minimum] = temp;
    
  }//for
  return numComparisons;
}//sort





// Merge Sort
int Sorting::mergeSort(int values[], int first, int last)
{
  long numComparisons = 0;
  
  if(first < last)
  {
    int middle = (first + last) / 2;
    numComparisons += mergeSort(values, first, middle);
    numComparisons += mergeSort(values, middle + 1, last);
    merge(values, first, middle, middle + 1, last, numComparisons);
  }//if
  return numComparisons;
  
}//sort

// merges sorted lists into a single sorted list 
void Sorting::merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast, long& count)
{
  int tempArray[10000];
  int index = leftFirst;
  int saveFirst = leftFirst;

  while((leftFirst <= leftLast) && (rightFirst <= rightLast))
  {
    if(values[leftFirst] < values[rightFirst])
    {
      tempArray[index] = values[leftFirst];
      leftFirst++;
      count++;
    }//if
    else {
      tempArray[index] = values[rightFirst];
      rightFirst++;
      count++;
    }//else
    index++;
  }//while

  //Copying remaining items from left half
  while(leftFirst <= leftLast)
  {
    tempArray[index] = values[leftFirst];
    leftFirst++;
    index++;
  }//while
  
  //Copying remaining items from right half
  while(rightFirst <= rightLast)
  {
    tempArray[index] = values[rightFirst];
    rightFirst++;
    index++;
  }//while

  for(index = saveFirst; index <= rightLast; index++)
  {
    values[index] = tempArray[index];
  }//for
}//merge





// Heap Sort
int Sorting::heapSort(int values[], int numValues)
{
  long numComparisons = 0;

  int index;
  //Convert array into a heap
  for(index = numValues/2 -1; index >= 0; index--)
  {
    reHeapDown(values, index, numValues - 1, numComparisons);
  }//for
  //Sort the array
  for(index = numValues - 1; index >= 1; index--)
  {
    int temp = values[0];
    values[0] = values[index];
    values[index] = temp;
    reHeapDown(values, 0, index - 1, numComparisons);
  }//for
  return numComparisons;
}//sort

// reheaping remaining unsorted elements in the heap
void Sorting::reHeapDown(int values[], int root, int bottom, long& count)
{
  int maxChild;
  int leftChild;
  int rightChild;

  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;

  if(leftChild <= bottom)
  {
    if(leftChild == bottom)
    {
      maxChild = leftChild;
      count++;
    }//if
    else {
      if(values[leftChild] <= values[rightChild])
      {
	maxChild = rightChild;
 count++;
      }//if
      else {
	maxChild = leftChild;
 count++;
      }//else
    }//else
    if(values[root] < values[maxChild])
    {
      int temp = values[root];
      values[root] = values[maxChild];
      values[maxChild] = temp;
      reHeapDown(values, maxChild, bottom, count);
    }//if
  }//if

}//reHeapDown






// Quick Sort FP
int Sorting::quickSortFP(int values[], int first, int last)
{
  long numComparisons = 0;
  
  if(first < last)
  {
    int splitPoint = first;
    split(values, first, last, splitPoint, numComparisons);
    numComparisons += quickSortFP(values, first, splitPoint - 1);
    numComparisons += quickSortFP(values, splitPoint + 1, last);
  }//if
  return numComparisons;
}//sort

void Sorting::split(int values[], int first, int last, int& splitPoint, long& count)
{
    int saveFirst = first;
    first++; // start comparisons at this point
    while(first <= last){
        // moving index of first 
        while (values[first] <= values[splitPoint] && first <= last){
            first++;
            count++;
        }// while
        // moving index of last
        while (values[last] > values[splitPoint] && first <= last){
            last--;
            count++;
        }
        if (first <= last){ // make sure first and last maintain order
            // first and last swap places
            int temp = values[first];
            values[first] = values[last];
            values[last] = temp;
            first++;
            last--;
        }
    }// while

    // swap saveFirst value with last value 
    int temp = values[saveFirst];
    values[saveFirst] = values[last];
    values[last] = temp;
    splitPoint = last;
}//split







// Quick Sort RP
int Sorting::quickSortRP(int values[], int first, int last)
{
  long numComparisons = 0;  
  if(first < last)
  {
    // swap first with a random pivot point 
    srand(time(0));
    int size = last - first + 1;
    int r = (rand() % size) + first; // random number in this portion of the array
    int temp = values[first];
    values[first] = values[r];
    values[r] = temp;
  
    int splitPoint = first;
    split(values, first, last, splitPoint, numComparisons);
    numComparisons += quickSortRP(values, first, splitPoint - 1);
    numComparisons += quickSortRP(values, splitPoint + 1, last);
  }//if
  return numComparisons;
}//sort

