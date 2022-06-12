#include<iostream>
using namespace std;
int lastIndex(int arr[], int n, int x) {
    //Edge Case
    if(n==0) return -1;
    //First call the recursion 
    int recWork = lastIndex(arr+1,n-1,x);
    if(recWork!=-1)
    {
        return recWork+1;
    }
    else
    {
        if(arr[0]==x)
        {
            return 0;
        }
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
    
    cout << lastIndex(input, n, x) << endl;

}
