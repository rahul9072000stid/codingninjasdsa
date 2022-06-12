#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;cin>>s;
    cout<<s<<endl;
    string* sp = new string ;
    *sp = "def";
    cout<<sp<<endl;
    cout<<(*sp)<<endl;
    string s2 = s + (*sp);
    cout<<s2<<endl;
    //Size of the string 
    cout<<s2.size()<<endl;
    //Substr Function 
    //starting from 3rd index till the end
    cout<<s2.substr(3)<<endl;
    //3rd index se dede aur 3 length ka
    cout<<s2.substr(3,3)<<endl;
    //to find the substring in a  string 
    //phli occurence return krenge 
    cout<<s2.find("def")<<endl;
    return 0;
}