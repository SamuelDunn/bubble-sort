/*
 This client program will test the myBubbleSort() function with a variety
 different input arrays and will compare the time-cost of using the bubble sort
 algorithm in each of these different situations.
 */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "my_bubble_sort.hpp"
using namespace std;

const int ARRAY_SIZE = 10000;
const int NUMBER_RANGE = 50000;

int main() {

   srand(static_cast<unsigned>(time(0)));
   long startClock, stopClock;
   int randomArray[ARRAY_SIZE];
   int reverseOrderedArray[ARRAY_SIZE];
   int orderedArray[ARRAY_SIZE];
   int uniformArray[ARRAY_SIZE];
   int nearlyOrderedArray[ARRAY_SIZE];
   int orderedWithDuplicateElements[ARRAY_SIZE];


   for(int count = 0; count < ARRAY_SIZE; count ++) {
      randomArray[count] = rand() % (NUMBER_RANGE + 1);
   }
   for(int count = 0; count < ARRAY_SIZE; count ++) {
      reverseOrderedArray[count] = (ARRAY_SIZE - 1) - count;
   }
   for(int count = 0; count < ARRAY_SIZE; count ++) {
      orderedArray[count] = count;
   }
   int element = rand() % (NUMBER_RANGE + 1);
   for(int count = 0; count < ARRAY_SIZE; count ++) {
      uniformArray[count] = element;
   }
   for(int count = 0; count < ARRAY_SIZE; count ++) {
      if( count % 6 == 0)
         nearlyOrderedArray[count] = rand() % (NUMBER_RANGE + 1);
      else
         nearlyOrderedArray[count] = count;
   }
   for(int count = 0, count2 = 0; count < ARRAY_SIZE; count ++) {
      if(count % 6 == 0)
         count2 ++;
      orderedWithDuplicateElements[count] = count2;
   }


   cout <<  "Time-cost using myBubbleSort() with 10000 element array:"
   << endl << endl;
   cout << fixed << setprecision(4);

   startClock = clock();
   myBubbleSort(orderedArray, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort orderedArray" << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(orderedArray[count] > orderedArray[count + 1])
         cout << "ERROR" << endl;
   }

   startClock = clock();
   myBubbleSort(randomArray, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort randomArray" << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(randomArray[count] > randomArray[count + 1])
         cout << "ERROR" << endl;
   }

   startClock = clock();
   myBubbleSort(reverseOrderedArray, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort reverseOrderedArray" << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(reverseOrderedArray[count] > reverseOrderedArray[count + 1])
         cout << "ERROR" << endl;
   }

   startClock = clock();
   myBubbleSort(uniformArray, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort uniformArray" << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(uniformArray[count] > uniformArray[count + 1])
         cout << "ERROR" << endl;
   }

   startClock = clock();
   myBubbleSort(nearlyOrderedArray, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort nearlyOrderedArray" << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(nearlyOrderedArray[count] > nearlyOrderedArray[count + 1])
         cout << "ERROR" << endl;
   }

   startClock = clock();
   myBubbleSort(orderedWithDuplicateElements, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort orderedWithDuplicateElements" << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(orderedWithDuplicateElements[count] > orderedWithDuplicateElements[count + 1])
         cout << "ERROR" << endl;
   }
   cout << endl;

   return 0;
}


































