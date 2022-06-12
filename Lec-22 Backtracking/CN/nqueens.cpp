#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
bool checkPosition(vector<string> &play,int r,int c,int n)
{
    //See is it the correct position to place the Queens at (r,c)
    //Check up and upper diagonal 
    //Niche wale to abhi bhare hi nhi hai
    int upld = c-1;
    int uprd = c+1;
    r = r-1;
    while(r>=0)
    {
        //Check the upper side
        if(play[r][c]=='Q') return false;
        //Check the upper diagonal
        if(upld>=0)
        {
            //that means it;s valid diagonal
            if(play[r][upld]=='Q')
            {
                return false;
            }
            upld--;
        }
        if(uprd<n)
        {
            if(play[r][uprd]=='Q')
            {
                return false;
            }
            uprd++;
        }
        r--;
    }
    return true;
}
void solve(vector<string> &play,int r,int n,vector<vector<string> > &res)
{
    //base case
    if(r==n)
    {
        //We got the solution
        res.push_back(play);
        return ;
    }
    //We will traverse in coloumn
    for(int i=0;i<n;i++)
    {
        if(checkPosition(play,r,i,n))
        {
            play[r][i] = 'Q';
            solve(play,r+1,n,res);
            //Reverse the changes
            play[r][i] = '.';
        }
    }
}
vector<vector<string> > solveNQueens(int n)
{
    // I have to make a Playground
    vector<vector<string> > res;
    vector<string> play;
    //First from the playground
    string curr = "";
    for(int i=0;i<n;i++)
    {
        curr+= ".";
    }
    //Form the play
    for(int i=0;i<n;i++) play.push_back(curr);
    solve(play,0,n,res);
    return res;
}
int main()
{
    int n;cin>>n;
    vector<vector<string> > res = solveNQueens(n);
    //print the solution
    for(int i=0;i<res.size();i++)
    {
        //Print the res[i]
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<endl;
        }cout<<endl;
    }
    return 0;
}