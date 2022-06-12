#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void PrintAllSubsequences(int idx,vector<int> &ds,int arr[],int n)
{
    //Base Case
    if(idx==n)
    {
        for(int i=0;i<ds.size();i++)
        {
            cout<<ds[i]<<" ";
        }

        if(ds.size()==0)
        {
            cout<<"{}";
        }cout<<endl;
        return ;
    }
    //Take or Pick the particular index into the subsequence
    ds.push_back(arr[idx]);
    PrintAllSubsequences(idx+1,ds,arr,n);
    ds.pop_back();
    //Not pick the particular index into the subsequences
    PrintAllSubsequences(idx+1,ds,arr,n);
}
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> ds;
    PrintAllSubsequences(0,ds,arr,n);
    return 0;
}