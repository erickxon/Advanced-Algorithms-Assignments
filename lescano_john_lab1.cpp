#include <iostream>
using namespace std;
//500562687 - John Lescano


//Q1.
//Create a program (C++) that will perform a few sorting algorithms on an array of size n. In this
//assignment n is the size of an array to be sorted.
//Example array: 6,1,3,5,3,8,7,4


void bubbleSort(int size, int *nums){
    for(int i = size - 1; i >= 0; i--)
        for(int j = 0; j < i; j++)
            if(nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
}

void insertionSort(int size, int *nums){
      if(size== 0 || size == 1) return;
      for(int i = 1; i < size; i++){
          int tmp = nums[i];
          int j = i - 1;
          while(j >= 0 && nums[j] > tmp){
              nums[j + 1] = nums[j];
              j--;
          }
          nums[j + 1] = tmp;
      }
  }



  void quickSort(int* nums, int l, int r){
      if(l >= r) return;
      int i = l;
      for(int j = l; j <= r - 1; j++){
          if(nums[j] <= nums[r]){
              swap(nums[i], nums[j]);
              i++;
          }
      }
      swap(nums[i], nums[r]);
      quickSort(nums, l, i - 1);
      quickSort(nums, i + 1, r);
  }

  void swap(int *xp, int *yp)
  {
      int temp = *xp;
      *xp = *yp;
      *yp = temp;
  }

  void selectionSort(int arr[], int n)
  {
      int i, j, idx;
      for (i = 0; i < n-1; i++)
      {
          // Find the minimum element in unsorted array
          idx = i;
          for (j = i+1; j < n; j++)
          if (arr[j] < arr[idx])
              idx = j;


          swap(&arr[idx], &arr[i]);
      }
  }


  void printArray(int arr[], int size)
  {
      int i;
      for (i=0; i < size; i++)
          cout << arr[i] << " ";
      cout << endl;
  }

  void merge(int *nums, int l, int m, int r){
        int tmp[r - l + 1];
        int i = l;
        int j = m + 1;
        int k = 0;
        while(i <= m && j <= r){
            if(nums[i] <= nums[j]){
                tmp[k] = nums[i];
                i++;
            }else{
                tmp[k] = nums[j];
                j++;
            }
            k++;
        }
        while(i <= m){
            tmp[k] = nums[i];
            i++;
            k++;
        }
        while(j <= r){
            tmp[k] = nums[j];
            j++;
            k++;
        }
        for(i = 0; i < k; i++) nums[l + i] = tmp[i];
    }
    void mergeSort(int *nums, int l, int r){
        if(l >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }


int main(int argc, char* argv[])
{
  //Q1
  std::cout<<"===Question 2==== "<<endl;
  int arr[] = {6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4};
  //cout << (sizeof(arr)/sizeof(*arr));
  int size = (sizeof(arr)/sizeof(*arr));
  std::clock_t start;
  double duration;
  start = std::clock();
  bubbleSort(size,arr);
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
//  for (int i = size - 1; i >= 0; i--)
//    cout << arr[i] <<endl;
  std::cout<<"bubble sort duration: "<< duration <<'\n';



//------------------------------------
  int arr2[] = {6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4};
  int size2 = (sizeof(arr)/sizeof(*arr));
  std::clock_t start2;
  double duration2;
  start2 = std::clock();
  insertionSort(size,arr);
  duration2 = ( std::clock() - start2 ) / (double) CLOCKS_PER_SEC;
//  for (int i = size - 1; i >= 0; i--)
//    cout << arr[i] <<endl;
  std::cout<<"insertion sort duration: "<< duration2 <<'\n';

//------------------------------------
  int arr3[] = {6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4};
  int size3 = (sizeof(arr)/sizeof(*arr));

  std::clock_t start3;
  double duration3;
  start3 = std::clock();
  quickSort(arr3,0,size-1);
  duration3 = ( std::clock() - start3 ) / (double) CLOCKS_PER_SEC;
//  for (int i = size - 1; i >= 0; i--)
//    cout << arr[i] <<endl;
  std::cout<<"quick sort duration: "<< duration3 <<'\n';

int arr4[] = {6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4};
int size4 = sizeof(arr4)/sizeof(arr4[0]);
std::clock_t start4;
double duration4;
start4 = std::clock();
selectionSort(arr4, size4);
duration4 = ( std::clock() - start4 ) / (double) CLOCKS_PER_SEC;
std::cout<<"selection sort duration: "<< duration4 <<'\n';
//  for (int i = size - 1; i >= 0; i--)
//    cout << arr[i] <<endl;
//printArray(arr4, n);

int arr5[] = {6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4};
int size5 = sizeof(arr5)/sizeof(arr5[0]);
std::clock_t start5;
double duration5;
start5 = std::clock();
mergeSort(arr5, 0,size5-1);
duration5 = ( std::clock() - start5 ) / (double) CLOCKS_PER_SEC;
std::cout<<"merge sort duration: "<< duration5 <<'\n';

//Q2 Create an array of random elements between 1 and 4n, to populate the array of size n.
std::cout<<"===Question 2==== "<<endl;
std::cout<<"a)Selection Sort"<<endl;
int arr6[] = {6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4,6,1,3,5,3,8,7,4};
int n4 = sizeof(arr5)/sizeof(arr5[0])/4;
int random[n4];
srand(time(NULL));
for(int i = 0;i<n4;i++){
  int n = rand()%32+1;
  random[i]=arr6[n];
}

selectionSort(random, n4);
printArray(random,n4);

std::cout<<"b)Merge Sort"<<endl;
int random2[n4];
//srand(time(0));
for(int i = 0;i<n4;i++){
  int n = rand()%32+1;
  random2[i]=arr6[n];
}
selectionSort(random2, n4);
printArray(random2,n4);

std::cout<<"===Question 3==== "<<endl;
std::cout<<"n="<<n4<<endl;
for(int i = 0;i<12;i++){
  //cout << i << endl;
  int randoms[n4];
  //randoms[i]=arr6[n];
    for(int j = 0;j<n4;j++){
      int n = rand()%n4+1;
      //cout << n << endl;
      randoms[j]=arr6[n];
    }

    if(i<6){
      std::clock_t starts;
      double durations;
      starts = std::clock();
      mergeSort(randoms, 0,n4);
      durations = ( std::clock() - starts ) / (double) CLOCKS_PER_SEC;
      std::cout<< "Trial " << i << ":merge sort duration: "<< durations <<'\n';
      printArray(randoms,n4);
    }
    else{

      std::clock_t starts;
      double durations;
      starts = std::clock();
      selectionSort(randoms, n4);
      durations = ( std::clock() - starts ) / (double) CLOCKS_PER_SEC;
      std::cout<< "Trial " << i << ":selection sort duration: "<< durations <<'\n';
      printArray(randoms,n4);
     }
}

std::cout<<"===Question 4==== "<<endl;
std::cout<<"Selection sort is better when n is smaller, use merge sort when n > 6"<<endl;
std::cout<<"n="<<n4<<endl;
for(int i = 0;i<6;i++){
  //cout << i << endl;
  int randoms[n4];
  //randoms[i]=arr6[n];
    for(int j = 0;j<n4;j++){
      int n = rand()%n4+1;
      //cout << n << endl;
      randoms[j]=arr6[n];
    }

    if(n4>6){
      std::clock_t starts;
      double durations;
      starts = std::clock();
      mergeSort(randoms, 0,n4);
      durations = ( std::clock() - starts ) / (double) CLOCKS_PER_SEC;
      std::cout<< "Trial " << i << ": merge sort duration: "<< durations <<'\n';
      printArray(randoms,n4);
    }
    else{

      std::clock_t starts;
      double durations;
      starts = std::clock();
      selectionSort(randoms, n4);
      durations = ( std::clock() - starts ) / (double) CLOCKS_PER_SEC;
      std::cout<< "Trial " << i << ": selection sort duration: "<< durations <<'\n';
      printArray(randoms,n4);
     }
}


	return 0;
}
