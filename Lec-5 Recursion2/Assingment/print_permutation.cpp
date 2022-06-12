#include <iostream>
#include <string>
using namespace std;
//Approach is to fix the first character and then 
//find the permuaton for rest and then swap with other character to first
//and find the permutation for the other
void printPermutations(string str,string op){
    //Base case
    if(str.size()==0)
    {
        cout<<op<<endl;
        return ;
    }
    for(int i=0;str[i]!='\0';i++)
    {
        //first character is fixed 
        //find the permutation of remaining string 
        string rem = str.substr(0,i) + str.substr(i+1);
        printPermutations(rem,op+str[i]);
    }
}

int main() {
    string str;
    cin >> str;
    printPermutations(str,"");
    for(int i=0;str[i]!='\0';i++)
    {
        //first character is fixed 
        //find the permutation of other elements
        string rem = str.substr(0,i) + str.substr(i+1);
        // printPermutations(rem,op+str[i]);
        cout<<"i = "<<i<<" rem = "<<rem<<endl;
    }
    return 0;
}