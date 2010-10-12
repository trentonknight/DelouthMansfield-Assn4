#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>
#include <ctime>

using namespace std;

void merge(int numbers[], int temp[], int left, int mid, int right);


void mergesort(int numbers[], int temp[], int left, int right,int& count,int& m)

{
  int mid;
  
  count++;
  

  if (right > left)

  {
   
    mid = (right + left) / 2;
    cout << "INDICES: " << "["<<left <<"] => ["<< mid <<"] / [" <<mid+1<<"] <= ["<< right << "]"<< endl;
    cout << "MergeSort: " << count << " ["<<numbers[left] <<"] => ["<< numbers[mid] <<"] / ["<<numbers[mid+1]<<"] <= [" << numbers[right] << "]"<< endl;


int c = mid;
   cout << "LEFT SORT: ";
   while(c >= left){
  
   cout << "[" << numbers[c] << "]";
   c--;
}
  cout << endl;
  
  

   int b = mid+1;
   cout << "RIGHT SORT: ";
   while(b <= right){
  
   cout << "[" << numbers[b] << "]";
   b++;
}
    cout << endl;
    mergesort(numbers, temp, left, mid,count,m);
    mergesort(numbers, temp, mid +1, right,count,m);
    merge(numbers, temp, left, mid+1, right);
    
    cout << "After Merge "<< m++ << " " << endl;
    
 for(int a = 0; a < 10; a++){

   cout << "[" << numbers[a] << "]";
  }
  cout << endl;

}

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
      
      cout << "LEFT MERGE: " << numbers[left] << " TO: " << left << endl;

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
    
    cout << "RIGHT MERGE: " << numbers[mid -1] << " TO: " << mid +1<< endl;

  }



  for (i=0; i <= num_elements; i++)

  {

    numbers[right] = temp[right];

    right = right - 1;

  }

}

int main(){
  int numbers[10] = {50,16,64,37,24,75,92,41};
  int temp [10] = {0};
  int a, b;
  int count = 0;
  int m = 1;

 cout << "Begin Merge Sort: " << endl;

 for(a = 0; a < 10; a++){

   cout << "[" << numbers[a] << "]";
  }
  cout << endl;

  mergesort(numbers,temp,0,7,count,m);
  
cout << "Completed Merge Sort: " << endl;
for(b = 0; b < 10; b++){

   cout << "[" << numbers[b] << "]";
  }
  cout << endl;
 
}
