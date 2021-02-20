#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int* xp, int* yp)
{
    if (xp == yp)
        return;
    *xp = *xp + *yp;
    *yp = *xp - *yp;
    *xp = *xp - *yp;
}
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
            
          swap(&arr[min_idx], &arr[i]);  
    }  
}  
  
  
int main()  
{  
    int t;cin>>t;int arr[t];  
    for (int i=0;i<t&&cin>>arr[i];i++){}
    int n = sizeof(arr)/sizeof(arr[0]);  
    selectionSort(arr, n);  
    for (int i=0;i<t&&cout<<arr[i]<<"\n";i++){}
     return 0;  
}  