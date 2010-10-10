#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>
#include <stdlib.h>
#include <time.h>
using namespace std;

void userMenu(int *newArrayOne,int *newArrayTwo);
void createARRAYS(int *arrayONE,int *arrayTWO);
double clockSTART(double& start);
double clockSTOP(double& start);
//All sort functions to call by pointer to functions
int bubbleSort(int bubble[]);
int insertionSort(int insert[]);
int mergeSort(int merge[]);
int quickSort(int quick[]);
//end functions called by pointer? I think?
bool verifySorting(int verify_one[],int verify_two[]);
void displayResults(bool doArraysMatch,double& timeONE,double& timeTWO);

const int RAND_INT = 100000;//for rand array
const int ARRAY_FUNC = 4;//for selection of sort functions
const int LIMIT = 2000;

typedef int (*funcPtrType)(int[RAND_INT]);//function pointer
const funcPtrType sortPOINTER_ARRAY[ARRAY_FUNC] = {&bubbleSort,
                                          &insertionSort,
                                          &mergeSort,
						   &quickSort};

// main()
// Main program logic. Handles getting user input
// returns:
//   0 - No error, program exited normally
// Calls:
// Implemented by:
int main()

{
  int randNUM_ONE[RAND_INT] = {0};//rand array of numbers for functions one
  int randNUM_TWO[RAND_INT] = {0};//two
 
  createARRAYS(randNUM_ONE,randNUM_TWO);
  userMenu(randNUM_ONE,randNUM_TWO);
  
}
//user selections io
void userMenu(int *randNUM_ONE,int *randNUM_TWO){
  int sorts = 0, count = 1;
  double timeONE = 0,timeTWO = 0;
  bool doArraysMatch = true;
  double clocker = 0;
  funcPtrType funcPtr;//pointer to functions choosen by user
  string choice_ONE,choice_TWO;//user menu choice
  string sortNameOne,sortNameTwo;
  
  
  
  while(choice_ONE != "E"){
  cout << "Choose two sorts you wish to compare:\n"
  <<"B = Bubble sort\n"
  <<"I = Insertion sort\n"
  <<"M = Merge sort\n"
  <<"Q = Quick sort\n"
  <<"E = Exit program"
  << endl;
  cin >> choice_ONE;
  if(choice_ONE != "E"){
  cin >> choice_TWO;
  cout << "Enter the number of times to repeat each sort (1 or more): " << endl;
  cin >> sorts;
  //take user selection and run proper functions via pointer function
  //get first choice and then run same kind of if statement below for second
  //choise. This can probably be updated to a loop later  
  while(sorts != 0){
	 cout << "Starting sort #" <<count++<<"..."<<endl; 
  if(choice_ONE == "B"){
    clockSTART(clocker);//start clock on function 
    funcPtr = sortPOINTER_ARRAY[0];//point to Bubblesort   
    cout << "BUBBLE SORT ";
    sortNameOne = "BUBBLE SORT";
  } 
  else if(choice_ONE == "I"){
    clockSTART(clocker);//start clock
    funcPtr = sortPOINTER_ARRAY[1];//point to Insertion sort
    cout << "INSERTION SORT ";
    sortNameOne = "INSERTION SORT";
  }
  else if(choice_ONE == "M"){
    clockSTART(clocker);//start clock
    funcPtr = sortPOINTER_ARRAY[2];//point to Merge Sort
    cout << "MERGE SORT ";
    sortNameOne = "MERGE SORT";
  }
  else if(choice_ONE == "Q"){
    clockSTART(clocker);//start clock
    funcPtr = sortPOINTER_ARRAY[3];//point to Quick Sort
    cout << "QUICK SORT ";
    sortNameOne = "QUICK SORT";
  }
  else if(choice_ONE == "E"){
    cout << "EXIT..." << endl;//exit will need to change
  }
  *randNUM_ONE = funcPtr(randNUM_ONE);
   timeONE = timeONE + clockSTOP(clocker);
 
  //second choice all the same as first////////////////
   if(choice_TWO == "B"){
    clockSTART(clocker);
    funcPtr = sortPOINTER_ARRAY[0];
    cout << "BUBBLE SORT ";
    sortNameTwo = "BUBBLE SORT";
  } 
  else if(choice_TWO == "I"){
    clockSTART(clocker);
    funcPtr = sortPOINTER_ARRAY[1];
    cout << "INSERTION SORT ";
    sortNameTwo = "INSERTION SORT";
  }
  else if(choice_TWO == "M"){ 
    clockSTART(clocker);
    funcPtr = sortPOINTER_ARRAY[2];
    cout << "MERGE SORT ";
    sortNameTwo = "MERGE SORT";
  }
  else if(choice_TWO == "Q"){
    clockSTART(clocker);
    funcPtr = sortPOINTER_ARRAY[3];
    cout << "QUICK SORT ";
    sortNameTwo = "QUICK SORT";
  }
  else if(choice_TWO == "E"){
    cout << "EXIT..." << endl;//need to change
  }
  *randNUM_TWO = funcPtr(randNUM_TWO);
   timeTWO = timeTWO + clockSTOP(clocker);
  
  doArraysMatch = verifySorting(randNUM_ONE,randNUM_TWO);
  displayResults(doArraysMatch,timeONE,timeTWO);
  sorts--;
  }
  if(sorts == 0){
      cout << "\nSORTING RESULTS" << endl;
      cout << sortNameOne <<" TIME: " << timeONE << endl;
      cout << sortNameTwo <<" TIME: " << timeTWO << endl;
 }
  }
  }
   
  ///end second choice
}
int randMAKE(){
  int make = 0;
  make = rand() % RAND_INT + 6;
  return make;
}
void createARRAYS(int *arrayONE,int *arrayTWO){
  srand(time(NULL));
  for(int a = 0; a < RAND_INT; a++){
    arrayONE[a] = randMAKE();
    arrayTWO[a] = arrayONE[a];

  }
}

double clockSTART(double& start){
   start = clock();
   return start;
}
double clockSTOP(double& start){
  double stop = clock();
  double time = ((double)(stop - start))/CLOCKS_PER_SEC;
  cout << "TIME: " << time << endl;
  return time;
}

// Bubblesort()
//
// Returns:
//
// Implemented by:
int bubbleSort(int bubble[])
{  bubble[0] = 5;
  int a = -99;//just for testing time
  while(a < 9999999){
    a++;
  }
   return *bubble; 
}


// insertionSort()
//
// Returns:
//
// Implemented by:
int insertionSort(int insert[])
{  insert[0] = 6;

   return *insert;
}


// mergeSort()
//
// Returns:
//
// Implemented by:
int mergeSort(int merge[])
{ merge[0] = 7;


  return *merge;
}

// quickSort()
//
// Returns:
//
// Implemented by:
int quickSort(int quick[])
{ 
  quick[0] = 5;
  int a = -99;//just for testing time
  while(a < 9999999){
    a++;
  }
   return *quick; 
}

// verifySorting()
//  verifies the sorts ran correctly
// Returns:
//
// Implemented by:
bool verifySorting(int verify_one[],int verify_two[]){
	bool theSame = true;
	for(int a = 0; a < RAND_INT; a++){
		
		if(verify_one[a] != verify_two[a]){
			theSame = false;
		}
	}
	return theSame;

}
// displayResults()
//

// Returns:
//
// Implemented by:
void displayResults(bool doArraysMatch,double& timeONE,double& timeTWO)
{
    if(doArraysMatch){
		cout << "sorts validated." << endl;
	}
	else{
		cout << "ERROR: sorts invalid" << endl;
	}

}
