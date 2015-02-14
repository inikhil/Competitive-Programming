#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if((97<=s[0])&&(s[0]<=122))
    {
        s[0]=s[0]-32;
    }
    cout<<s;
    return 0;
}
