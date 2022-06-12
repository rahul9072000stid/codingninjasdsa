//Have to print any 1 subsequence with sum equals to k
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool PrintAllSubsequencesSumK(int idx,vector<int> &ds,int s,int sum,int arr[],int n)
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
            return true;
        }
        return false;
    }
    //Take or Pick the particular index into the subsequence
    ds.push_back(arr[idx]);
    s+=arr[idx];
    if(PrintAllSubsequencesSumK(idx+1,ds,s,sum,arr,n)) return true;
    ds.pop_back();
    s-=arr[idx];
    //Not pick the particular index into the subsequences
    if(PrintAllSubsequencesSumK(idx+1,ds,s,sum,arr,n)) return true;
    return false;
}
//Count the number of subsequences whose sum is k
int CntAllSubsequencesSumK(int idx,int s,int sum,int arr[],int n)
{
    //Base Case
    if(idx==n)
    {
        if(s==sum)
        {
            return 1;
        }
        return 0;
    }
    //Take or Pick the particular index into the subsequence
    s+=arr[idx];
    int l = CntAllSubsequencesSumK(idx+1,s,sum,arr,n);
    s-=arr[idx];
    //Not pick the particular index into the subsequences
    int r = CntAllSubsequencesSumK(idx+1,s,sum,arr,n);
    return l+r;
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
    cout<<CntAllSubsequencesSumK(0,0,sum,arr,n)<<endl;
    return 0;
}