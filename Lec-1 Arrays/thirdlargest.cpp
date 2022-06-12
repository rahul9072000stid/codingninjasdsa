#include<iostream>
#include<algorithm>
using namespace std;
//It's given all elments are distinct 
int thirdLargest(int arr[],int n)
{
    //THere should be atleast 3 elements
    if(n<3)
    {
        return INT_MIN;
    }
    //Find first largest element
    int first = arr[0];
    for(int i=1;i<n;i++)
    {
        first = max(first,arr[i]);
    }
    //Find Second largest element
    int second = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>second and arr[i]<first)
            second = arr[i];
    }
    //Find the third largest element
    int third  = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>third and arr[i]<second)
            third = arr[i];
    }
    return third;
}
//Third Largest element efficient Approach 
void thirdLargestEfficient(int arr[],int n)
{
    if(n<3)
    {
        cout<<"Invalid Input"<<endl;
        return ;
    }
    //Taking 3 variable and initializing
    int first  = arr[0] , second = INT_MIN , third = INT_MIN;
    //Traverse the array 
    for(int i=0;i<n;i++)
    {
        if(arr[i]>first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if(arr[i]>second)
        {
            third = second;
            second = arr[i];
        }
        else if(arr[i]>third)
        {
            third = arr[i];
        }
    }
    cout<<third<<endl;
}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // cout<<thirdLarges(arr,n)<<endl;
    thirdLargestEfficient(arr,n);
    return 0;
}