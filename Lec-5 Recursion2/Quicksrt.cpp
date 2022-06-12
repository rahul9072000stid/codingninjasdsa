#include<iostream>
using namespace std;
void swap(int& a,int& b)
{
    int t = a;
    a = b;
    b = t;
}
int partition(int a[],int l,int r)
{
    //taking first element as the pivot element 
    int f = a[l];
    //first counting the correct index of the pivot element
    int cnt = 0;
    //i am taking the smaller and equal element on the left 
    for(int i =l+1;i<=r;i++)
    {
        if(a[i]<=f)
            cnt++;
    }
    int pvt_index = l+cnt;
    swap(a[l],a[pvt_index]);
    //Now do for left and right
    int i = l;
    int j = r;
    while(i<pvt_index and j>pvt_index)  //change
    {
       
        if(a[i]<=a[pvt_index])
            i++;
        else if(a[j]>a[pvt_index])
            j--;
        else
        {
        swap(a[i],a[j]); 
            i++;
            j--;
        }
    }
    return pvt_index;
}
void qs(int a[],int l,int r)
{
    if(l<r)
    {
        int c = partition(a,l,r);
        qs(a,l,c-1);
        qs(a,c+1,r);
    }
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(size<=1)
      return;
    qs(input,0,size-1);
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


