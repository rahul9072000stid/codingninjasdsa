#include<iostream>
#include<string>
#include<vector>
using namespace std;
int subsequences(string ip,string op[])
{
    //base case
    if(ip.empty())
    {
        op[0] = "";
        return 1;
    }
    string smallString  = ip.substr(1);
    int smallOp = subsequences(smallString,op);
    //now form our result 
    for(int i=0;i<smallOp;i++)
    {
        op[i+smallOp] = ip[0] + op[i];
    }
    return 2*smallOp;
}
int main()
{
    string str;cin>>str;
    string* op = new string[1000];
    int cnt = subsequences(str,op);
    //Print all the subsequences
    for(int i=0;i<cnt;i++)
    {
        cout<<op[i]<<" ";
    }cout<<endl;
    return 0;
}