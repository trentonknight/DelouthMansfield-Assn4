// MansfASSN3-wk4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;
void arrayCheck(int array[]);
bool swapped = false;
int boolNUM;
int countTRUE;

int main()
{
   int array[10] = {2,10,6,8,1,3,4,9,5,7};
   
   cout <<endl<< "Using BUBBLE SORT with: int array[10] = {2,10,6,8,1,3,4,9,5,7};" << endl;
   cout << "DO WHILE LOOP until all index are TRUE" << endl;
   
   do{
       while(!swapped){
       
       cout << "PASS ==>" << endl;
       for(int y=0; y < 10-1; y++)
           
       {
           
           arrayCheck(array);
           cout << endl;
           cout << "array[y]: = " << array[y] << "\narray[y + 1] = ";
           cout << array[y + 1] << endl<< endl;
           cout <<endl << "Is " << array[y]<< " Greater Than " << array[y + 1]<< " ? " << endl;
           countTRUE++;

           if(array[y]>array[y+1])
               
           {
               countTRUE = 0;
               cout << "Yes so swap: " << endl;
               cout << "array [y + 1] " << array[y + 1] << " swapped with array[y] making it equal " << array[y] << endl;
               int temp = array[y+1];
               array[y+1] = array[y];
               array[y] = temp;
               cout << "array[y] swapped with array[y+1] making it equal: "<< temp << endl<< endl;     
           }
           else{
               if(countTRUE > 9){
                   cout << "ALL INDEX FOUND TRUE!" << endl;
                   swapped = true;
               }
               else{
               cout << "NO continue to next index ==>" << endl;
               }
           }
           
           
       }
       
       }    
       
   }while (!swapped);
   cout << "EXIT DO WHILE LOOP all index are true" << endl;
   
   system("PAUSE");
   return 0;
}

void arrayCheck(int array[]){
   cout << "array";
   for(int z = 0; z < 10; z++){
       cout << "["<<array[z]<<"]";
   }
   cout << endl;
}

