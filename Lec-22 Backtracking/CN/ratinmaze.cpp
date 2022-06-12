#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
void solve(vector<vector<int> > &maze,int r,int c,int n,vector<vector<bool> > &play,string path,vector<string> &res)
{
    //Edge Cases
    if(r>=n or r<0 or c>=n or c<0 or (maze[r][c]==0) or (play[r][c]==true)) return ;
    //Base Case
    if(r==n-1 and c==n-1)
    {
        //that's our answer
        res.push_back(path);
        return ;
    }
    //mark yourself as true
    play[r][c] = true;
    //Explore all the paths ie all the 4 dirextion 
    //Left 
    solve(maze,r,c-1,n,play,path+"L",res);
    //right
    solve(maze,r,c+1,n,play,path+"R",res);
    //Up
    solve(maze,r-1,c,n,play,path+"U",res);
    //Down
    solve(maze,r+1,c,n,play,path+"D",res);
    //Reverse the changes
    play[r][c] = false;
}
vector<string> findPath(vector<vector<int> > &m, int n)
{
    //Will try backtracking approach 
    //have to form the 2d array to avoid going to the same place 
    //will maintain the string for the result 
    string path = "";
    vector<string> res;
    //Form the 2D Array of bool 
    vector<vector<bool> > play;
    for(int i=0;i<m.size();i++)
    {
        vector<bool> curr;
        for(int j=0;j<m[i].size();j++)
        {
            curr.push_back(false);
        }
        play.push_back(curr);
    }
    solve(m,0,0,n,play,path,res);
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int> > m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        vector<string> result = findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} 