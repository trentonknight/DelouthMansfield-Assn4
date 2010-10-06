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
  char pickASort_ONE, pickASort_TWO;
  int randNUM[RAND_INT];
  int randNUM_ONE[RAND_INT];
  int randNUM_TWO[RAND_INT] = {0};
  funcPtrType ptrToSortFunctions;//define pointer to sort functions
  int arrayONE[RAND_INT];//arrays for sorting
  int arrayTWO[RAND_INT];
  //allow user to select which sort functions  they want to use, will need to expand this oviously
  cout << "First sort functions?" << endl;
  cin >> pickASort_ONE;
  cout << "Second sort function?" << endl;
  cin >> pickASort_TWO;

  //this is just a rough example of a if statement or a switch we will need to expand of course
  if(pickASort_ONE == 'B'){

          ptrToSortFunctions = sortPOINTER_ARRAY[0];
        }
 else//and so forth to pick which function to call via ptrToSortFunctions for both pickASort_ONE  one and then pickASort_TWO

   //getRandomNum(randNUM_ONE,randNUM_TWO);//create random array of numbers that match
  ptrToSortFunctions = sortPOINTER_ARRAY[ARRAY_FUNC];

  //verifySorting(randNUM_ONE,randNUM_TWO);//now run copied arrays through verification

    return 0;
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
