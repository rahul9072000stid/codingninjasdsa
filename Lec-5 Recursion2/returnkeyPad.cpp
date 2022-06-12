#include <iostream>
#include <string>
using namespace std;
#include <string>
using namespace std;
string keys[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num, string out[]){
    //b
    if(num==0)
    {
        out[0]="";
        return 1;
    }
    string out1[5000];
    int sm = keypad((num/10),out1);
    string c = keys[num%10];
    int l = c.length();
    // int k=0;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<sm;j++)
        {
            out[sm*i+j]=out1[j]+c[i];
            // k++;
        }
    }
    return sm*l;
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
