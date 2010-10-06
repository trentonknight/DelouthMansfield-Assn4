#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>
#include <ctime>

using namespace std;

void userMenu();
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
  userMenu();

}
//user selections io
void userMenu(){

  funcPtrType funcPtr;//pointer to functions choosen by user
  int randNUM_ONE[RAND_INT] = {0};//rand array of numbers for functions one
  int randNUM_TWO[RAND_INT] = {0};//two
  char choice;//user menu choice
  int index;//index for function pointer numbers in rand array
  getRandomNum(randNUM_ONE,randNUM_TWO);   
  cout << "Choose two sorts you wish to compare:\n"
  <<"B = Bubble sort\n"
  <<"I = Insertion sort\n"
  <<"M = Merge sort\n"
  <<"Q = Quick sort\n"
  <<"E = Exit program"
  << endl;
  cin >> choice;
  
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
