#include<iostream>
using namespace std;
//In this Approach i am breaking the problem in way like 
//first part is doing recursion ie first n-1 elements are handled by recursion 
//and last element is performed by us
int allIndexes(int arr[], int n, int x, int output[]) {
    //Base Case
    if(n==0)
    {
        //Returning the number of element found in Array equals to x 
        return 0;
    }
    int rec = allIndexes(arr+1,n-1,x,output);
    for(int i=0;i<rec;i++)
    {
        output[i]+=1;
    }
    //if the element at 0th index is x
    if(arr[0]==x)
    {
        //shift 
        for(int i=rec;i>0;i--)
        {
            output[i] = output[i-1];
        }
        output[0] = 0;
        return rec+1;
    }
    return rec;
}
//In this Approach i will break my array into 2 parts such that first n-1 elements
//will handle with rrecursion and the last part is done by me
int allIndexes(int arr[],int n,int x,int op[])
{
    //base case
    if(n==0)
    {
        return 0;
    }
    //Calling Recursion 
    int rec = allIndexes(arr,n-1,x,op);
    if(arr[n-1]==x)
    {
        op[rec] = n-1;
        rec++;
    }
    return rec;
}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


