//Have to print all subsequence whose sum is k
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void PrintAllSubsequencesSumK(int idx,vector<int> &ds,int s,int sum,int arr[],int n)
{
    //Base Case
    if(idx==n)
    {
        if(s==sum)
        {
            for(int i=0;i<ds.size();i++)
            {
                cout<<ds[i]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    //Take or Pick the particular index into the subsequence
    ds.push_back(arr[idx]);
    s+=arr[idx];
    PrintAllSubsequencesSumK(idx+1,ds,s,sum,arr,n);
    ds.pop_back();
    s-=arr[idx];
    //Not pick the particular index into the subsequences
    PrintAllSubsequencesSumK(idx+1,ds,s,sum,arr,n);
}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum;cin>>sum;
    vector<int> ds;
    PrintAllSubsequencesSumK(0,ds,0,sum,arr,n);
    return 0;
}