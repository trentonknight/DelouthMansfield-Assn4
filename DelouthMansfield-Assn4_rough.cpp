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
int quickSort(int quick[]);
void QUICKsort(int quick[], int left, int right);
int partition(int qslist[], int left, int right);
int mergeGET(int numbers[]);
void merge(int numbers[], int temp[], int left, int mid, int right);
int mergesort(int numbers[], int temp[], int left, int right);
//end functions called by pointer? I think?
bool verifySorting(int verify_one[]);
bool menuErrorCheck(string inChoice);
void displayResults(bool doArraysMatch,double& timeONE,double& timeTWO);

const int RAND_INT = 1000;//for rand array change to 100000
const int ARRAY_FUNC = 4;//for selection of sort functions

typedef int (*funcPtrType)(int[RAND_INT]);//function pointer
const funcPtrType sortPOINTER_ARRAY[ARRAY_FUNC] = {&bubbleSort,
                                          &insertionSort,
                                          &mergeGET,
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
  return 0;
}
//user selections io
void userMenu(int *randNUM_ONE,int *randNUM_TWO){
  int sorts = 0, count = 1;
  double timeONE = 0,timeTWO = 0;
  bool doArraysMatch = true;
  double clocker = 0;
  funcPtrType funcPtr;//pointer to functions choosen by user
  string choice;//user menu choice
  string sortNameOne,sortNameTwo;
  
  while(choice[0] != 'E'){
  cout << "Choose two sorts you wish to compare:\n"
  <<"B = Bubble sort\n"
  <<"I = Insertion sort\n"
  <<"M = Merge sort\n"
  <<"Q = Quick sort\n"
  <<"E = Exit program"
  << endl;
  cin >> choice;
  if(!menuErrorCheck(choice)){
	  userMenu(randNUM_ONE,randNUM_TWO);
  }
  if(choice[0] != 'E'){
  cout << "Enter the number of times to repeat each sort (1 or more): " << endl;
  cin >> sorts;
  //take user selection and run proper functions via pointer function
  //get first choice and then run same kind of if statement below for second
  //choise. This can probably be updated to a loop later  
  while(sorts != 0){
	cout << "Starting sort # " <<count++<<"..."<<endl; 
  if(choice[0] == 'B'){
    clockSTART(clocker);//start clock on function 
    funcPtr = sortPOINTER_ARRAY[0];//point to Bubblesort   
    verifySorting(randNUM_ONE);
    cout << "BUBBLE SORT ";
    sortNameOne = "BUBBLE SORT";
  } 
  else if(choice[0] == 'I'){
    clockSTART(clocker);//start clock
    funcPtr = sortPOINTER_ARRAY[1];//point to Insertion sort
    cout << "INSERTION SORT ";
    sortNameOne = "INSERTION SORT";
  }
  else if(choice[0] == 'M'){
    clockSTART(clocker);//start clock
    funcPtr = sortPOINTER_ARRAY[2];//point to Merge Sort
    cout << "MERGE SORT ";
    sortNameOne = "MERGE SORT";
  }
  else if(choice[0] == 'Q'){
    clockSTART(clocker);//start clock
    funcPtr = sortPOINTER_ARRAY[3];//point to Quick Sort
    cout << "QUICK SORT ";
    sortNameOne = "QUICK SORT";
  }
  else if(choice[0] == 'E'){
    cout << "EXIT..." << endl;//exit will need to change
  }
  *randNUM_ONE = funcPtr(randNUM_ONE);
   timeONE = timeONE + clockSTOP(clocker);
 
  //second choice all the same as first////////////////
   if(choice[1] == 'B'){
    clockSTART(clocker);
    funcPtr = sortPOINTER_ARRAY[0];
    cout << "BUBBLE SORT ";
    sortNameTwo = "BUBBLE SORT";
  } 
  else if(choice[1] == 'I'){
    clockSTART(clocker);
    funcPtr = sortPOINTER_ARRAY[1];
    cout << "INSERTION SORT ";
    sortNameTwo = "INSERTION SORT";
  }
  else if(choice[1] == 'M'){ 
    clockSTART(clocker);
    funcPtr = sortPOINTER_ARRAY[2];
    cout << "MERGE SORT ";
    sortNameTwo = "MERGE SORT";
  }
  else if(choice[1] == 'Q'){
    clockSTART(clocker);
    funcPtr = sortPOINTER_ARRAY[3];
    cout << "QUICK SORT ";
    sortNameTwo = "QUICK SORT";
  }
  else if(choice[1] == 'E'){
    cout << "EXIT..." << endl;//need to change
  }
  *randNUM_TWO = funcPtr(randNUM_TWO);
   timeTWO = timeTWO + clockSTOP(clocker);
  
  doArraysMatch = verifySorting(randNUM_ONE);
  displayResults(doArraysMatch,timeONE,timeTWO);
  sorts--;
  }
  if(sorts == 0){
      cout << "\nSORTING RESULTS" << endl;
      cout << sortNameOne <<" TIME: " << timeONE/count << endl;
      cout << sortNameTwo <<" TIME: " << timeTWO/count << endl;
 }
//end while if E for exit
 ///end second choice
}
}
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

bool menuErrorCheck(string inChoice)
{
	bool check = true;
	if(inChoice[0] == 'E'){
		cout << "Continuing..." << endl;
	}
	else{
     if(inChoice.length()<2)
     {
       cout << "Whoops! Please enter two choices before hitting ENTER" << endl;
       check = false;
     }
     
     if(isdigit(inChoice[0])||isdigit(inChoice[1]))
     {
      cout << "Error. Enter two letters from the list" << endl;
      check = false;
      }
  }
      return check;
}

// Bubblesort()
//
// Returns:
//
// Implemented by:
int bubbleSort(int bubble[])
{ 
    bool swap = true;
    int j ;
    int temp;

      for(j=1; j < RAND_INT; j++)
      {
            
            

            for (int i = 0; i < RAND_INT-j; i++) 
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


// insertionSort()
//
// Returns:
//
// Implemented by:
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


// quickSort()
//
// Returns:
//
// Implemented by:
int quickSort(int quick[])
{
     QUICKsort(quick,0,RAND_INT-1);
     return *quick;
}

// quickSort()
//
// Returns:
//
// Implemented by:
void QUICKsort(int quick[], int left, int right)
{
      
      int middle;
      
      if(left<right)
      {
         middle=partition(quick,left,right);
        // cout << "partition" << endl;
         QUICKsort(quick,left,middle);
         //cout << "low" << endl;
         QUICKsort(quick,middle+1,right);
        // cout << "high" << endl;
      }
      //return;   
      //cout << "THE END" << endl;
}

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

int mergeGET(int numbers[]){
 int temp[RAND_INT] = {0};
 int left = 0;
 int right = RAND_INT;
 mergesort(numbers,temp,left,right);
 return *numbers;
}
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

// verifySorting()
//  verifies the sorts ran correctly
// Returns:
//
// Implemented by:
bool verifySorting(int verify_one[])
{
     int i=0;
     int j=0;
     bool notSorted=false;
     
     for (i=0; i<RAND_INT; i++)
     {
         j=i+1;
         
         if(verify_one[i]>verify_one[j])
         {
         // cout << "ERROR!!!" ;
          notSorted=true;
          break;
          }
     }
     return notSorted;
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


