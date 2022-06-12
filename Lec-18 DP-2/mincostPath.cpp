#include<iostream>
#include<climits>
using namespace std;
//Can move in 3 direction 
//left
//down
//diagonally
int minCostPath(int** input,int m,int n,int i,int j)
{
    //Edge Cases 
    if(i>=m or j>=n) return INT_MAX;
    //Base Case
    if(i==m-1 and j==n-1)
    {
        return input[i][j];
    }
    //Recursive Call 
    int x = minCostPath(input,m,n,i+1,j);
    int y = minCostPath(input,m,n,i,j+1);
    int z = minCostPath(input,m,n,i+1,j+1);
    //Samll Calculation 
    return min(x,min(y,z)) + input[i][j];
}
int main()
{
    int m,n;
    cin>>m>>n;
    int** input = new int*[m];
    for(int i=0;i<n;i++)
    {
        input[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>input[i][j];
        }
    }
    cout<<minCostPath(input,m,n,0,0)<<endl;
    return 0;
}