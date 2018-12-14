/*
 This file contains the declarations for the function used to impliment the
 bubble sort algorighm

 void myBubbleSort(int *arrayToSort, int endIndex);
 Takes a plain old array of type int and sorts its elements in ascending
 order. This pricess is accomplished by iteratively moving the largest element
 in the unsorted portion of the array to the end of the array and recursively
 repeating this process until the entire array is sorted.
*/

#include "my_bubble_sort.hpp"
#include <iostream>

void myBubbleSort(int *arrayToSort, int endIndex) {
   int numSwaps = 0;
   for(int count = 0; count < endIndex - 1; count ++) {
      if(arrayToSort[count] > arrayToSort[count + 1]) {
         std::swap(arrayToSort[count], arrayToSort[count + 1]);
         numSwaps++;
      }
   }
   if(numSwaps == 0) {
      return;
   }
   else {
      myBubbleSort(arrayToSort, endIndex - 1);
   }
}
