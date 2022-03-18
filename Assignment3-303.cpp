#include <iostream>
#include <fstream>
using namespace std;

int countone=0;
int countthree=0;
void bubbleSort(int array[], int num)
{
int i;
int j;
int count=0;
for(i=0; i<(num-1); i++)
    {
        for(j=0; j<(num-i-1); j++)
        {
            if(array[j]>array[j+1])
            {
                count++;
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
}
    cout << "Bubble Sort: " << count <<endl;
}
    
void merge(int array[], int a, int b, int c)
{
    int num1=(b-a)+1;
    int num2=c-a;
    int arr1[num1];
    int arr2[num2];
        for(int i=0;i<num1;i++)
            arr1[i]=array[a+i+1];
        for(int j=0;j<num2;j++)
            arr2[j]=array[a+j];
            int i=0;
            int j=0;
            int k=a;
    while(i<num1 && j<num2) 
    {
    countone=countone+1;

    if(arr1[i]<arr2[j]) 
    {
        array[k]=arr1[i];
        k++;
        i++;
    } 
    else 
    {
        array[k]=arr2[j];
        k++;
        j++;
    }
} 

while(i<num1) 
{
countone=countone+1;
array[k]=arr1[i];
k++;
i++;
} 

while(j<num2) 
{
countone=countone+1;
array[k]=arr2[j];
k++;
j++;
}

}

void mergeSort(int A[], int p, int r) {
if(p < r) {
int q = (p + r) / 2;
mergeSort(A, p, q);
mergeSort(A, q+1, r);
merge(A, p, q, r);
}
}
  
int PARTITION(int A[], int p, int r) {
int x = A[r];
int i = p-1;
int temp;
for(int j = p; j < r; j++) {
countthree = countthree+1;
if(A[j] <= x) {
i += 1;
temp = A[i];
A[i] = A[j];
A[j] = temp;
}
} temp = A[i+1];
A[i+1] = A[r];
A[r] = temp;
return (i+1);
}

void QUICKSORT(int A[], int p, int r) {
if(p < r) {
int q = PARTITION(A, p, r);
QUICKSORT(A, p, q-1);
QUICKSORT(A, q+1, r);
}
}


void shellSort(int array[], int n) {
        int count2=0;
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
        count2++;
      }
      array[j] = temp;
    }
    
  }
  
  cout<<"Shell Sort: "<<count2<<endl;
}


int selectionSort(int arr[], int n)
{
int i, j, minId, cnt = 0;;
for (i = 0; i < n - 1; i++)
{
minId = i;
for (j = i + 1; j < n; j++) {
if (arr[j] < arr[minId]) {
minId = j;
}
}
int t = arr[minId];
arr[minId] = arr[i];
arr[i] = t;
cnt++;
}
return cnt;
}



int main()
{
    
    int i=0,n;
    int arr1[1000],arr2[1000],arr3[1000],temp[1000];
    
        for(i=0;i< 1000 ;i++){
                arr1[i]=rand()%1000;
        }
        
        
        for(i=0;i< 1000 ;i++){
                arr2[i]=rand()%1000;
        }
        
        
        for(i=0;i< 1000 ;i++){
                arr3[i]=rand()%1000;
        }
                for(i=0;i< 1000 ;i++){
                  temp[i]=arr1[i];
                }
         
        bubbleSort(temp,1000);
                for(i=0;i< 1000 ;i++){
                  temp[i]=arr2[i];
                }
                bubbleSort(temp,1000);
         
           for(i=0;i< 1000 ;i++){
                  temp[i]=arr3[i];
                }
                bubbleSort(temp,1000);


        
         for(i=0;i< 1000 ;i++){
                  temp[i]=arr1[i];
        }
        
        shellSort(temp,1000);
    for(i=0;i< 1000 ;i++){
                  temp[i]=arr2[i];
        }
        
        shellSort(temp,1000);

     for(i=0;i< 1000 ;i++){
                  temp[i]=arr3[i];
        }
        
        shellSort(temp,1000);
   
    for(i=0;i< 1000 ;i++){
                  temp[i]=arr3[i];
        }
   
    QUICKSORT(temp,0,1000);     
        cout<<"Quick Sort: "<<countthree<<endl;
    
   countthree=0;
   
    for(i=0;i< 1000 ;i++){
                  temp[i]=arr1[i];
        }
   
    QUICKSORT(temp,0,1000);     
        cout<<"Quick Sort: "<<countthree<<endl;
    
   countthree=0;
    
    for(i=0;i< 1000 ;i++){
                  temp[i]=arr2[i];
        }
   
    QUICKSORT(temp,0,1000);     
        cout<<"Quick Sort: "<<countthree<<endl;
    
   countthree=0;
   
   for(i=0;i< 1000 ;i++){
                  temp[i]=arr3[i];
        }
      mergeSort(temp,0,1000);
        cout<<"Merge Sort: "<<countone<<endl;
    countone=0;
        
        
     for(i=0;i< 1000 ;i++){
                  temp[i]=arr2[i];
        }
                
        
        mergeSort(temp,0,1000);
        cout<<"Merge Sort: "<<countone<<endl;
    countone=0;
        
                
     for(i=0;i< 1000 ;i++){
                  temp[i]=arr3[i];
        }
                
        
        mergeSort(temp,0,1000);
        cout<<"Merge Sort: "<<countone<<endl;
    countone=0;

for(i=0;i< 1000 ;i++){
                  temp[i]=arr1[i];
                }






 selectionSort(temp,1000);
        cout<<"Selection Sort: "<<countone<<endl;
    countthree=0;
        
        
     for(i=0;i< 1000 ;i++){
                  temp[i]=arr2[i];
        }
                
        
        selectionSort(temp,1000);
        cout<<"Selection Sort: "<<countone<<endl;
    countone=0;
        
                
     for(i=0;i<1000 ;i++){
                  temp[i]=arr3[i];
        }
                
        
        selectionSort(temp, 1000);
        cout<<"Selection Sort: "<<countone<<endl;
    countone=0;

for(i=0;i<1000 ;i++){
                  temp[i]=arr1[i];
                }
   
 return 0; 
}