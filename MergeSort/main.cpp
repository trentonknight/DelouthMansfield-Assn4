#include <iostream>
#include <iomanip>
#include <string>
#include <cstddef>
#include <ctime>

using namespace std;

void mergesort(int list[],int tempArray[],int lo,int hi);
void merge(int list[],int tempArray[],int lo,int mid,int hi);

int main()
{
    int list[10] = {1,19,2,10,6,5,4,7,9,8};
    int tempArray[10] = {0};
    for(int a = 0; a < 10; a++){
        cout << "before: " << list[a] << endl;
}
    mergesort(list,tempArray,0,10);

    for(int a = 0; a < 10; a++){
        cout << "after: " << list[a] << endl;}


    return 0;
}

void mergesort(int list[],int tempArray[],int lo,int hi)
{
  int mid = 0;

    if (lo<hi)
    {
        mid=(lo+hi)/2;
        mergesort(list,tempArray,lo,mid);
        mergesort(list,tempArray,mid+1,hi);
        merge(list,tempArray,lo,mid+1,hi);
    }
}

// Straightforward variant
void merge(int list[],int tempArray[],int lo,int mid,int hi)
{
  int left = lo;
  int right = mid + 1;
  int temp = lo;
  tempArray[mid] = list[mid];

  while((left <= mid) && (right <=hi)){
    if(tempArray[left] <= tempArray[right]){
      list[temp] = tempArray[left];
      left++;
    }
    else{
      list[temp] = tempArray[right];
      right++;
    }
    temp++;
  }
  //loop 2 add elements left side
  while(left <= mid){
    list[temp] = tempArray[left];
    temp++;
    left++;
  }
  //loop 3 add elements right
  while(right <= hi)
    {
      list[temp] = tempArray[right];
      temp++;
      right++;
    }  
 
}
