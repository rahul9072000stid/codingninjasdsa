#include<iostream>
using namespace std;
int fibo_DP(int n)
{
    int* ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2;i<=n;i++)
    {
        ans[i] = ans[i-1]+ans[i-2];
    }
    return ans[n];
}
//Recursion
int fibo(int n)
{
    if(n<=1) return n;
    return fibo(n-1) + fibo(n-2);
}
//Memoization
int fiboBetter(int n,int* ans)
{
    if(n<=1)
    {
        ans[n] = n;
        return n;
    }
    if(ans[n-1]==0)
    {
        ans[n-1] = fiboBetter(n-1,ans);
    }
    if(ans[n-2]==0)
    {
        ans[n-2] = fiboBetter(n-2,ans);
    }
    return ans[n-1]+ans[n-2];
}
int main()
{
    int n;cin>>n;
    cout<<fibo_DP(n)<<endl;
    return 0;
}