#include<iostream>
using namespace std;
//I have to solve this problem recursively
int firstIndex(int arr[], int n, int x) {
    //Base case
    if(n==0)
    {
        return -1;
    }
    if(arr[0]==x)
    {
        return 0;
    }
    //Now call the recursion for the ans
    int rec = firstIndex(arr+1,n-1,x);
    if(rec!=-1)
    {
        return rec+1;
    }
    return -1;
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
    
    cout << firstIndex(input, n, x) << endl;
    return 0;
}


