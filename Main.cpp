#include <iostream>
#include <fstream>
#include "Sorting.h"
using namespace std;

int main(int argc, char** argv)
{
  if (argc != 2){
    cout << "Input Format: ./main <input file name>" << endl;
    exit(EXIT_SUCCESS);
  }  
  //read input file
  int input;
  fstream fs;
  int numValues = 10000;
  int array[10000];
  int i = 0;
  fs.open(argv[1], fstream::in);
  
  if(fs.is_open())
  {
    fs >> input;
    while(!fs.eof())
    {
      array[i] = input;
      fs >> input;
      i++;
    }//while
  }//if
  else {
    cout << "Failed to open the input file" << endl;
    return 0;

  }//else
  
  
  cout << "selection-sort (s)   merge-sort (m)    heap-sort (h)    quick-sort-fp (q)    quick-sort-rp (r)" << endl;
  cout << "Enter the algorithm: ";
  char userInput;
  cin >> userInput;

  int numComparisons;
  Sorting sort;
  switch(userInput) {
  case 's':
    numComparisons = sort.selectionSort(array, numValues);
    for(int i = 0; i < numValues; i++)
    {
      cout << array[i] << " ";
    }//for
    cout << endl;
    cout << "#Selection-sort comparisons: " << numComparisons << endl;
    break;

  case 'm':
    numComparisons = sort.mergeSort(array, 0, numValues);
    for(int i = 0; i < numValues; i++)
    {
      cout << array[i] << " ";
    }//for
    cout << endl;
    cout << "#Merge-sort comparisons: " << numComparisons << endl;
    break;

  case 'h':
    numComparisons = sort.heapSort(array, numValues);
    for(int i = 0; i < numValues; i++)
    {
      cout << array[i] << " ";
    }//for
    cout << endl;
    cout << "#Heap-sort comparisons: " << numComparisons << endl;
    break;

  case 'q':
    numComparisons = sort.quickSortFP(array, 0, numValues - 1);
    for(int i = 0; i < numValues; i++)
    {
      cout << array[i] << " ";
    }//for
    cout << endl;
    cout << "#Quick-sort-fp comparisons: " << numComparisons << endl;
    break;

  case 'r':
    numComparisons = sort.quickSortRP(array, 0, numValues - 1);
    for(int i = 0; i < numValues; i++)
    {
      cout << array[i] << " ";
    }//for
    cout << endl;
    cout << "#Quick-sort-rp comparisons: " << numComparisons << endl;
    break;
    
  default:
      cout << "Stick with the given options bud." << endl;
      break;

  }//switch
  cout << endl;
  return 0;
}//main
