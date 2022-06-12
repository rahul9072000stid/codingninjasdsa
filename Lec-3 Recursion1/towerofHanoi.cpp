// { Driver Code Starts
#include <iostream>

using namespace std;

// avoid space at the starting of the string in "move disk....."
long long toh(int N, int src, int dest, int helper)
{
    // Have to print the Disc number also
    // base case
    long long res = 0;
    if (N == 1)
    {
        cout << "move disk " << N << " from rod " << src << " to rod " << dest << endl;
        return res+1;
    }
    // first push the n-1 disk from src to helper using dest
    res += toh(N - 1, src, helper, dest);
    // Do your work
    cout << "move disk " << N << " from rod " << src << " to rod " << dest << endl;
    // Call recursion again for rest of the work
    res += toh(N - 1, helper, dest, src);
    return res + 1;
}

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T; // testcases
    while (T--)
    {

        int N;
        cin >> N; // taking input N

        // calling toh() function

        cout << toh(N, 1, 3, 2) << endl;
    }
    return 0;
}

// Position this line where user code will be pasted.  // } Driver Code Ends