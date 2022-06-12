#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
string formString(int n)
{
    string res = "";
    for (int i = 1; i <= n; i++)
    {
        res += to_string(i);
    }
    return res;
}
void solve(string& num, int n, int k, string &res)
{
    // cout<<"Num = "<<num<<" Res = "<<res<<endl;
    // Base case
    if(k==0 or n<=1)
    {
        res+=num;
        return ;
    }
    int gap = fact(n-1);
    int idx = k/gap;
    res += num[idx];
    //remove the nums[idx] from the num and form the different num 
    num = num.substr(0,idx) + num.substr(idx+1);
    //decrease the rank and form the other element
    solve(num,n-1,k%gap,res);
}
string getPermutation(int n, int k)
{
    //Form the string of 1...n
    string num = formString(n);
    string res = "";
    //k-1 because i m considering the permuation from 0 
    solve(num,n,k-1,res);
    return res;
}
//Best Approach Iterative 
string getPermutation(int n,int k)
{
    int fact = 1;
    vector<int> numbers;
    for(int i=1;i<n;i++)
    {
        fact = fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k-1;
    while(true)
    {
        ans  = ans + to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0)
        {
            break;
        }
        k = k%fact;
        fact = fact / numbers.size();
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    // cout << formString(n) << endl;
    cout<<getPermutation(n,k)<<endl;
    return 0;
}