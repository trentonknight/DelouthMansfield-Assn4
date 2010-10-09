#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>
#include <ctime>

using namespace std;

void merge(int numbers[], int temp[], int left, int mid, int right);


void mergesort(int numbers[], int temp[], int left, int right)

{
  int mid;

  if (right > left)

  {
   



    mid = (right + left) / 2;

    mergesort(numbers, temp, left, mid);
     
    cout << "Sort Left >> left: "<< left<< " mid " << mid << endl;

    mergesort(numbers, temp, mid+1, right);
    
    cout << "Sort Right >>  right: " << right <<" mid "<< mid+1 << endl;

    cout << "MERGE >> " << "[" << left << "][" << mid+1 << "][" << right << "]" << endl;

    
     cout << "Before Merge Sublist: " << endl;
    
   for(int a = 0; a < right; a++){

     if(a > left){
     cout << "[" << numbers[a] << "]";
     }
  }
    cout << endl;

    cout << "BEFORE LIST: " << endl;
    
   for(int a = 0; a < 10; a++){

     
     cout << "[" << numbers[a] << "]";
     
  }
    cout << endl;



    merge(numbers, temp, left, mid+1, right);

  
    cout << "After Merge Sublist: " << endl;
    
   for(int a = 0; a < right; a++){

     if(a > left){
     cout << "[" << numbers[a] << "]";
     }
  }
    cout << endl;

  }
 cout << "AFTER LIST: " << endl;
    
   for(int a = 0; a < 10; a++){

     
     cout << "[" << numbers[a] << "]";
     
  }
    cout << endl;


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

int main(){
  int numbers[10] = {1,10,9,8,5,6,2,3,4,7};
  int temp [10] = {0};
  int a, b;

 cout << "Begin Merge Sort: " << endl;

 for(a = 0; a < 10; a++){

   cout << "[" << numbers[a] << "]";
  }
  cout << endl;

  mergesort(numbers,temp,0,9);
  
cout << "Completed Merge Sort: " << endl;
for(b = 0; b < 10; b++){

   cout << "[" << numbers[b] << "]";
  }
  cout << endl;
 
}
