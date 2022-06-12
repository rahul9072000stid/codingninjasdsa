#include<iostream>
using namespace std;
int length(char str[])
{
    //base case
    if(str[0]=='\0')
    {
        return 0;
    }
    int smallStringLength = length(str+1);
    return smallStringLength+1;
}
//I am supposed to remove all the x from the string 
void removeX(char str[])
{
    //base case
    if(str[0]=='\0')
    {
        return ;
    }
    if(str[0]=='x')
    {
        //shift left by 1 position 
        int i = 1;
        for(i=1;str[i]!='\0';i++)
        {
            str[i-1] = str[i];
        }
        str[i-1] = '\0';
        removeX(str);
    }
    else
    {
        removeX(str+1);
    }
}
int main()
{
    char str[100];
    cin>>str;
    removeX(str);
    cout<<str<<endl;
    return 0;
}