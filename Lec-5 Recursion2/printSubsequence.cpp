#include<iostream>
using namespace std;
void print_subs(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<endl;
        return ;
    }
    print_subs(ip.substr(1),op);
    print_subs(ip.substr(1),op+ip[0]);
}
int main()
{
    string ip;cin>>ip;
    print_subs(ip,"");
    return 0;
}