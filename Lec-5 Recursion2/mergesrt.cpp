#include <iostream>
using namespace std;
//Merge 2 sorted arrays into single sorted arrays
void merge(int a[],int s,int e)
{
    int temp[e-s+2];
    int m = (s+e)/2;
    int i = s;
    int j = m+1;
    int k =0;
    while(i<=m && j<=e)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=e)
    {
        temp[k]=a[j];
        j++;
        k++;
    }
    //Copy to whole
    k = 0;
    for(int i =s;i<=e;i++)
    {
        a[i]=temp[k];
        k++;
    }
}
void mergesrt(int a[],int s,int e)
{
    if(s<e)
    {
        int m = (s+e)/2;
        mergesrt(a,s,m);
        mergesrt(a,m+1,e);
        merge(a,s,e);
    }
}
void mergeSort(int a[], int n){
	// Write your code here
    mergesrt(a,0,n-1);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}