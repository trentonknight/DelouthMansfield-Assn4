#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>

using namespace std;

 
int getRandomNum(**GETrandNUM_ONE,**GETrandNUM_TWO);
//all sort functions to call by pointer to functions
int bubbleSort(**randNUM);
int insertionSort(**randNUM);
int mergeSort(**randNUM);
int quickSort(**randNUM);
//end functions called by pointer? I think?
int verifySorting(**VERIFYrandNUM_ONE, **VERIFYrandNUM_TWO);
clockTime();
displayResults();

const int ARRAY_MAX = 5;//will change to 100,000 after it works
typedef int (*sortPOINTER)(**randARRAY);//pointer to all sort functions
// main()
// Main program logic. Handles getting user input 
// returns:
//   0 - No error, program exited normally
// Calls: 
// Implemented by: 
int main()
{
  char pickASort_ONE, pickASort_TWO;

  sortPOINTER ptrToSortFunctions;//define pointer to sort functions
  int arrayONE[ARRAY_MAX] = {1,2,3,4,5};//arrays for sorting
  int arrayTWO[ARRAY_MAX] = {1,2,3,4,5};
  //allow user to select which sort functions  they want to use, will need to expand this oviously
  cout << "First sort functions?" << endl;
  cin >> pickASort_ONE;
  cout << "Second sort function?" << endl;
  cin >> pickASort_TWO;

  //this is just a rough example of a if statement or a switch we will need to expand of course
  if(pickASort_ONE == "B"){
         
          ptrToSortFunctions = &bubbleSort;
	} 
 else//and so forth to pick which function to call via ptrToSortFunctions for both pickASort_ONE  one and then pickASort_TWO

  getRandomNum(**GETrandNUM_ONE,**GETrandNUM_TWO);//create random array of numbers that match
  VERIFYrandNUM_ONE = (*ptrToSortFunctions)(**arrayONE);//copy newly sorted array 1 to another array 1
  VERIFYrandNUM_TWO = (*ptrToSortFunctions)(**arrayTWO);//copy newly sorted array 2 to another array 2
  int verifySorting(**VERIFYrandNUM_ONE, **VERIFYrandNUM_TWO);//now run copied arrays through verification
      
    return 0;
}
// getRandomNum()
// Generate 100,000 random numbers between 1 and 30,000 and place them into two 100,000-element arrays 
// Returns:
//  
// Implemented by: 
int getRandomNum(**GETrandNUM_ONE,**GETrandNUM_TWO);
{

}


// bubbleSort()
// 
// Returns:
//  
// Implemented by: 
int bubbleSort(**randNUM)
{

}


// insertionSort()
// 
// Returns:
//  
// Implemented by: 
int insertionSort(**randNUM)
{

}


// mergeSort()
// 
// Returns:
//  
// Implemented by: 
int mergeSort(**randNUM)
{

}

// quickSort()
// 
// Returns:
//  
// Implemented by: 
int quickSort(**randNUM)
{

}

// verifySorting()
//  verifies the sorts ran correctly
// Returns:
//  
// Implemented by: 
int verifySorting(**VERIFYrandNUM_ONE, **VERIFYrandNUM_TWO){

}

// clockTime()
// calculate how long the sort took
// Returns:
//  
// Implemented by: 
clockTime()
{

}

// displayResults()
// 
// Returns:
//  
// Implemented by: 
displayResults()
{

}
