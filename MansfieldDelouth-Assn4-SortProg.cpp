/////////////////////////////////////////////////////////////////////////////////////////////
//  CODE FILENAME: DelouthMansfield-Assn4-SortProg.cpp
//  DESCRIPTION: Program to compare how long it takes to sort a list, using the 
//               bubble sort, merge sort, insertion sort and quick sort
//  DATE:	 October 2010
//  DESIGNER:    Natasha Delouth, Jason Mansfield
//  FUNCTIONS:	 main- main program logic
/////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstddef>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;

void pickSorts(string& choice);
void runSorts(string choice,int *randNumOne,int *randNumTwo,double timeOne,double timeTwo,int& count,double& totalTimeOne,double& totalTimeTwo
,string& sortNameOne,string& sortNameTwo);
void createArrays(int *arrayOne,int *arrayTwo);
double clockStart(double& start);
double clockStop(double& start);
//All sort functions to call by pointer to functions
int bubbleSort(int bubble[]);
int insertionSort(int insert[]);
int quickSort(int quick[]);
void qkSort(int quick[], int left, int right);
int partition(int qslist[], int left, int right);
int mergeGET(int numbers[]);
void merge(int numbers[], int temp[], int left, int mid, int right);
int mergesort(int numbers[], int temp[], int left, int right);
//end functions called by pointer
bool verifySorting(int verify_one[],int verify_two[]);
void displayResults(bool doArraysMatch);
bool menuErrorCheck(string inChoice);

const int RAND_INT = 100000;//for rand array
const int ARRAY_FUNC = 4;//for selection of sort functions
const int RAND_LIMITER = 30000;
typedef int (*funcPtrType)(int[RAND_INT]);//function pointer
const funcPtrType sortPOINTER_ARRAY[ARRAY_FUNC] = {&bubbleSort,&insertionSort,&mergeGET,&quickSort};
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    main
///INPUT:
///
///Parameters: *randNumOne,randNumTwo hold random arrays of numbers.
///             timeOne and timeTwo are returned to main with clock ticks.
///             totalTimeOne and totalTimeTwo are returned to main with total of.
///             clock ticks continually.
///
///OUTPUT: return 0 if program runs without issue. 
///Parameters: Name and description of the output parameters
///CALLS TO:  createArrays,displayResults,pickSorts,runSorts,verifySorting
///IMPLEMENTED BY: both NATASHA and JASON
///////////////////////////////////////////////////////////////////////////////////
int main()

{
  int randNumOne[RAND_INT] = {0};//rand array of numbers for functions one
  int randNumTwo[RAND_INT] = {0};//two
  double timeOne = 0,timeTwo = 0;
  double totalTimeOne, totalTimeTwo;
  bool doArraysMatch = true;
  int sorts = 0;
  string choice,sortNameOne,sortNameTwo;
  int count = 0;
  
 
  do{
  pickSorts(choice); 
  if(choice[0] != 'E'){ 
  cout << "Enter the number of times to repeat each sort (1 or more): " ;
  cin >> sorts;
  while(sorts != 0 && choice[0] != 'E'){
  count++;
  createArrays(randNumOne,randNumTwo);
  runSorts(choice,randNumOne,randNumTwo,timeOne,timeTwo,count,totalTimeOne,totalTimeTwo,sortNameOne,sortNameTwo);
  doArraysMatch = verifySorting(randNumOne,randNumTwo);
  displayResults(doArraysMatch);
  sorts--;
  }
  cout << "\nSORTING RESULTS" << endl;
  cout << "---------------" << endl;
  cout.precision(7);
  cout << fixed << sortNameOne <<" : " << totalTimeOne/count << " clock ticks on average" << endl;
  cout << sortNameTwo <<" : " << totalTimeTwo/count << " clock ticks on average" << endl;  
}
  }while(choice[0] != 'E');
  return 0;
  
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    pickSorts
///DESCRIPTION:  retrieve user input to chooce two sort functions
///INPUT:
///Parameters: string choice[0] and choice[1] (NULL)
///OUTPUT:   
///Return Val: string choice[0] and choice[1] (with sorts selections)
///CALLS TO:  menuErrorCheck, pickSorts (if error function recurses)
///IMPLEMENTED BY: NATASHA
///////////////////////////////////////////////////////////////////////////////////
void pickSorts(string& choice){
  		
  cout << "\nChoose two sorts you wish to compare:\n"
  <<"\tB = Bubble sort\n"
  <<"\tI = Insertion sort\n"
  <<"\tM = Merge sort\n"
  <<"\tQ = Quick sort\n"
  <<"\tEE = Exit program"
  << endl;
  cout << "\nEnter two letter choices (or EE to exit): ";
  cin >> choice;
  if(!menuErrorCheck(choice)){
	  pickSorts(choice);
  }
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    runSorts
///DESCRIPTION:    Description of purpose of function
///INPUT:
///Parameters: *randNumOne,*randNumTwo (two matching arrays of random numbers)
///            double totalTimeOne,totalTimeTwo(double which maintain a total of each sorts clock time until
///            user selected choices completes)
///            string choice[0] and choice[1] contain users selected char for selecting sortPOINTER_ARRAY
///            which points to proper function for each selected sort method.
///OUTPUT:   
///Return Value: *randNumOne, *randNumTwo sorted; timeOne,TimeTwo new clock numbers, totalTimeOne,totalTimeTwo
///             are increased and returned with current total of clock times, sortNameOne,sortNameTwo contain
///             selectedd names of sorts run.
///Parameters: *randNumOne,*randNumTwo (returned after being run through choosen sorts with sorted indexes in arrays)
///            double timeOne, timeTwo (doubles used to return new clock times everytime
///            runSorts is called)
///            string sortNameOne,sortNameTwo(returns user selection in string for display at the end of sorting loop in the main)
///            
///CALLS TO:   clockStart, clockStop, function pointer funcPtr calls from all:
///            sortPOINTER_ARRAY[ARRAY_FUNC] = {&bubbleSort,&insertionSort,&mergeGET,&quickSort};
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
void runSorts(string choice, int *randNumOne,int *randNumTwo,double timeOne,double timeTwo,int& count,double& totalTimeOne,double& totalTimeTwo
,string& sortNameOne,string& sortNameTwo){ 
  double clocker = 0;
  funcPtrType funcPtr;//pointer to functions choosen by user
   
  cout << "\nStarting sort # " <<count<<"..."<<endl;
  
  if(choice[0] == 'B'){
    clockStart(clocker);//start clock on function 
    funcPtr = sortPOINTER_ARRAY[0];//point to Bubblesort   
    cout << "\tBUBBLE SORT ";
    sortNameOne = "BUBBLE SORT";
  } 
  else if(choice[0] == 'I'){
    clockStart(clocker);//start clock
    funcPtr = sortPOINTER_ARRAY[1];//point to Insertion sort
    cout << "\tINSERTION SORT ";
    sortNameOne = "INSERTION SORT";
  }
  else if(choice[0] == 'M'){
    clockStart(clocker);//start clock
    funcPtr = sortPOINTER_ARRAY[2];//point to Merge Sort
    cout << "\tMERGE SORT ";
    sortNameOne = "MERGE SORT";
  }
  else if(choice[0] == 'Q'){
    clockStart(clocker);//start clock
    funcPtr = sortPOINTER_ARRAY[3];//point to Quick Sort
    cout << "\tQUICK SORT ";
    sortNameOne = "QUICK SORT";
  }
  else if(choice[0] == 'E'){
  
  }
  *randNumOne = funcPtr(randNumOne);
   timeOne = timeOne + clockStop(clocker);
   totalTimeOne = (totalTimeOne + timeOne);
 
  //second choice all the same as first////////////////
   if(choice[1] == 'B'){
    clockStart(clocker);
    funcPtr = sortPOINTER_ARRAY[0];
    cout << "\tBUBBLE SORT ";
    sortNameTwo = "BUBBLE SORT";
  } 
  else if(choice[1] == 'I'){
    clockStart(clocker);
    funcPtr = sortPOINTER_ARRAY[1];
    cout << "\tINSERTION SORT ";
    sortNameTwo = "INSERTION SORT";
  }
  else if(choice[1] == 'M'){ 
    clockStart(clocker);
    funcPtr = sortPOINTER_ARRAY[2];
    cout << "\tMERGE SORT ";
    sortNameTwo = "MERGE SORT";
  }
  else if(choice[1] == 'Q'){
    clockStart(clocker);
    funcPtr = sortPOINTER_ARRAY[3];
    cout << "\tQUICK SORT ";
    sortNameTwo = "QUICK SORT";
  }
  else if(choice[1] == 'E'){
  
  }
  *randNumTwo = funcPtr(randNumTwo);
   timeTwo = timeTwo + clockStop(clocker);
   totalTimeTwo = (totalTimeTwo + timeTwo);
    
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    randMAKE
///DESCRIPTION: simple function uses rand to return random int
///INPUT:
///Parameters: calls rand()
///OUTPUT:   
///Return Val: random int 
///Parameters: returns int make
///CALLS TO:  n/a
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
int randMAKE(){
  int make = 0;
  make = rand() % RAND_LIMITER + 6;
  return make;
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    createArrays
///DESCRIPTION: inserts random int into arrays
///INPUT:
///Parameters: random int make
///OUTPUT:   
///Return Val: int *arrayOne and *arrayTwo filled with random int 
///CALLS TO:  randMAKE
///IMPLEMENTED BY: NATASHA
///////////////////////////////////////////////////////////////////////////////////
void createArrays(int *arrayOne,int *arrayTwo){
  srand(time(NULL));
  for(int a = 0; a <= RAND_INT; a++){
    arrayOne[a] = randMAKE();
    arrayTwo[a] = arrayOne[a];
  }
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:   clockStart
///DESCRIPTION:  returns clock time
///INPUT:
///Parameters: clock() start time
///OUTPUT:   
///Return Val: double& start with clock time 
///CALLS TO: n/a
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
double clockStart(double& start){
   start = clock();
   return start;
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:   clockStop
///DESCRIPTION: displays time required to run sort 
///Parameters: clock() stop time
///OUTPUT:   
///Return Val: clock stop time minus start time giving total time of sort run
///CALLS TO: n/a
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
double clockStop(double& start){
  double stop = clock();
  double time = ((double)(stop - start));
  cout.precision(7);
  cout << fixed << "TIME: " << time << endl;
  return time;
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    bubbleSort
///DESCRIPTION: Common Bubble Sort function
///INPUT:
///Parameters:  one array of random int: bubble[]
///OUTPUT:   
///Return Val:  sorted array: bubble[]
///Parameters:  bubble[]
///CALLS TO: n/a
///IMPLEMENTED BY: NATASHA
///////////////////////////////////////////////////////////////////////////////////
int bubbleSort(int bubble[])
{   bool swap = true;
    int j = 0;
    int temp;

      while(swap) 
      {
            swap = false;
            j++;

            for (int i = 0; i < RAND_INT - j; i++) 
            {
                  if (bubble[i] > bubble[i + 1]) 
                  {
                        temp = bubble[i];
                        bubble[i] = bubble[i + 1];
                        bubble[i + 1] = temp;
                        swap = true;
                  }
            }
      }
      return *bubble;
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    insertionSort
///DESCRIPTION: Common Insertion Sort function
///INPUT:
///Parameters:  one array of random int: insert[]
///OUTPUT:   
///Return Val:  sorted array: insert[]
///Parameters:  insert[]
///CALLS TO: n/a
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
int insertionSort(int insert[])
{ int i = 0;
  int j = 0;
  int tmp = 0;
  
  for(i = 1; i < RAND_INT; i++){
  j = i;
  while(j > 0 && insert[j - 1] > insert[j]){
  tmp = insert[j];
  insert[j] = insert[j - 1];
  insert[j - 1] = tmp;
  j--; 
  }
  } 
  return *insert;
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    quickSort
///DESCRIPTION: retrieves random array and calls qkSort to sort array
///INPUT:
///Parameters: quick[]: random array
///OUTPUT:   
///Return Val: quick[]: sorted array
///Parameters: int quick[]
///CALLS TO:  qkSort
///IMPLEMENTED BY: NATASHA
///////////////////////////////////////////////////////////////////////////////////
int quickSort(int quick[])
{
     qkSort(quick,0,RAND_INT-1);
	 return 0;
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    qkSort
///DESCRIPTION: recursivly runs arrays through functions until sort complete
///INPUT:
///Parameters: quick[], int left, int right
///OUTPUT:   
///Return Val: returns fully sorted array
///Parameters: quick[] completely sorted
///CALLS TO:  partition and calls itself for recurs qkSort
///IMPLEMENTED BY: NATASHA
///////////////////////////////////////////////////////////////////////////////////
void qkSort(int quick[], int left, int right)
{
      
      int middle;
      
      if(left<right)
      {
         middle=partition(quick,left,right);
         qkSort(quick,left,middle);
         qkSort(quick,middle+1,right);
      }
      return;   
      
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    partition
///DESCRIPTION: enters sorted indexes into array in proper place
///INPUT:
///Parameters: qslist[], int left, int right
///OUTPUT:   
///Return Val: qslist[] indexes moved and int j of current index
///Parameters: qslist[], int j
///CALLS TO:  n/a
///IMPLEMENTED BY: NATASHA
///////////////////////////////////////////////////////////////////////////////////
int partition(int qslist[], int left, int right)
{
    int x=qslist[left];
    int i= left-1;
    int j= right +1;
    int temp=0;
    
    do
    {
        do
        {
              j--;
               
        }while(x>qslist[j]);
        
        do
        {
         i++;
         
        }while(x<qslist[i]);
        
        if(i<j)
        {
               temp=qslist[i];
               qslist[i]=qslist[j];
               qslist[j]=temp;
        }
    }while(i<j);
    return j;
    
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    mergeGET
///DESCRIPTION: allows merge sort function to be called as function pointer
///INPUT:
///Parameters: numbers[] random array
///OUTPUT:   
///Return Val: numbers[] sorted array
///Parameters: *numbers
///CALLS TO:  mergesort
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
int mergeGET(int numbers[]){
 static int temp[RAND_INT] = {0};
 int left = 0;
 int right = RAND_INT;
 mergesort(numbers,temp,left,right);
 return *numbers;
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    mergesort
///DESCRIPTION: sorts int 
///INPUT:
///
///Parameters: numbers[] random array,temp[] = NULL, right = top of array.
///            numbers[] is continually updated for sorting after each merge until
///            sort is complete.    
///OUTPUT:   
///Return Val: fully sorted numbers[]
///Parameters: numbers[]
///CALLS TO:  merge and recursivly calls itself mergesort
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
int mergesort(int numbers[], int temp[], int left, int right)

{
  int mid;

  if (right > left)

  {

    mid = (right + left) / 2;
    mergesort(numbers, temp, left, mid);
    mergesort(numbers, temp, mid+1, right);
    merge(numbers, temp, left, mid+1, right);

  }
  return *temp;
}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    merge
///DESCRIPTION: merges int in index in accordance with their value
///INPUT:
///Parameters: numbers[], int left, mid, right
///            left,mid,and right are used to determine placing
///            of int in index
///OUTPUT:   
///Return Val: moved int in index for sorting numbers[]
///Parameters: int is moved within array in accordance with its value and
///            then array is returned for furthur sorting until sort is complete
///CALLS TO: n/a
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
void merge(int numbers[], int temp[], int left, int mid, int right)

{

  int i, left_end, num_elements, tmp_pos;


  left_end = mid - 1;

  tmp_pos = left;

  num_elements = right - left + 1;



  while ((left <= left_end) && (mid <= right))

  {

    if (numbers[left] <= numbers[mid])

    {

      temp[tmp_pos] = numbers[left];

      tmp_pos = tmp_pos + 1;

      left = left +1;

    }

    else

    {

      temp[tmp_pos] = numbers[mid];

      tmp_pos = tmp_pos + 1;

      mid = mid + 1;

    }

  }



  while (left <= left_end)

  {

    temp[tmp_pos] = numbers[left];

    left = left + 1;

    tmp_pos = tmp_pos + 1;

  }

  while (mid <= right)

  {

    temp[tmp_pos] = numbers[mid];

    mid = mid + 1;

    tmp_pos = tmp_pos + 1;

  }



  for (i=0; i <= num_elements; i++)

  {

    numbers[right] = temp[right];

    right = right - 1;

  }

}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    verifySorting
///DESCRIPTION: simple function that loops through index in arrays and compairs them to each other
///INPUT:
///Parameters: two arrays fully sorted: verify_one[] and verify_two[]
///OUTPUT:   
///Return Val: bool theSame = false or true
///Parameters: returns true or false if arrays match
///CALLS TO:  n/a
///IMPLEMENTED BY: NATASHA
///////////////////////////////////////////////////////////////////////////////////
bool verifySorting(int verify_one[],int verify_two[]){
	bool theSame = false;
	for(int a = 0; a < RAND_INT; a++){
		
		if(verify_two[a] == verify_one[a] || verify_two[a] < verify_one[a + 1]||verify_two[a + 1] > verify_one[a] ){
			theSame = true;
			
		}
	}
	return theSame;

}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    displayResults
///DESCRIPTION: displays if sorts were indeed valid
///INPUT:
///Parameters: bool doArraysMatch
///OUTPUT:   
///Parameters: displays if sorts were valid to user
///IMPLEMENTED BY: NATASHA
///////////////////////////////////////////////////////////////////////////////////
void displayResults(bool doArraysMatch)
{
    if(doArraysMatch){
		cout << "sorts validated." << endl;
	}
	else{
		cout << "ERROR: sorts invalid" << endl;
	}

}
//////////////////////////////////////////////////////////////////////////////////
///FUNCTION:    menuErrorCheck
///DESCRIPTION: verifies user input for mistakes
///INPUT:
///Parameters: string inChoice[0] and inChoice[1]
///OUTPUT:   
///Return Val: true of false if user submitted valid choices
///Parameters: bool check
///IMPLEMENTED BY: JASON
///////////////////////////////////////////////////////////////////////////////////
bool menuErrorCheck(string inChoice)
{    bool check = false;
     switch(inChoice[0]){
     case 'M':
       check = true;
       break;
     case 'Q':
       check = true;
       break;
     case 'I':
       check = true;
       break;
     case 'B':
       check = true;
       break;
     case 'E':
       check = true;
       break;
     default:
       cout << "Whoops! Please enter TWO characters in UPPERCASE shown below:" << endl;
       check = false;
     }
switch(inChoice[1]){
     case 'M':
       check = true;
       break;
     case 'Q':
       check = true;
       break;
     case 'I':
       check = true;
       break;
     case 'B':
       check = true;
       break;
     case 'E':
       check = true;
       break;
     default:
       cout << "Whoops! Please enter TWO characters in UPPERCASE shown below:" << endl;
       check = false;
     }
      return check;

}
