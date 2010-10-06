#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>
#include <ctime>

using namespace std;


int getRandomNum(int rand_one[],int rand_two[]);
//All sort functions to call by pointer to functions
int bubbleSort(int bubble[]);
int insertionSort(int insert[]);
int mergeSort(int merge[]);
int quickSort(int quick[]);
//end functions called by pointer? I think?
int verifySorting(int verify_one[],int verify_two[]);
void clockTime();
void displayResults();

const int RAND_INT = 100000;//will change to 100,000 after it works
const int ARRAY_FUNC = 4;

typedef int (*funcPtrType)(int[]);
const funcPtrType sortPOINTER_ARRAY[ARRAY_FUNC] = {&bubbleSort,
                                          &insertionSort,
                                          &mergeSort,
                                          &quickSort};

const string sortDescriptions[ARRAY_FUNC] = {"BUBBLE_SORT","INSERTION_SORT","MERGE_SORT","QUICK_SORT"};

// main()
// Main program logic. Handles getting user input
// returns:
//   0 - No error, program exited normally
// Calls:
// Implemented by:
int main()
{

}
// getRandomNum()
// Generate 100,000 random numbers between 1 and 30,000 and place them into two 100,000-element arrays
// Returns:
//
// Implemented by:
int getRandomNum(int rand_one[],int rand_two[]){}


// Bubblesort()
//
// Returns:
//
// Implemented by:
int bubbleSort(int bubble[])
{

}


// insertionSort()
//
// Returns:
//
// Implemented by:
int insertionSort(int insert[])
{

}


// mergeSort()
//
// Returns:
//
// Implemented by:
int mergeSort(int merge[])
{
  static int tempList[RAND_INT];

}

// quickSort()
//
// Returns:
//
// Implemented by:
int quickSort(int quick[])
{

}

// verifySorting()
//  verifies the sorts ran correctly
// Returns:
//
// Implemented by:
int verifySorting(int verify_one[],int verify_two[]){

}

// clockTime()
// calculate how long the sort took
// Returns:
//
// Implemented by:
void clockTime()
{

}

// displayResults()
//
// Returns:
//
// Implemented by:
void displayResults()
{

}
