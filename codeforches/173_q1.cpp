#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,i,x=0;
    string s[150];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(i=0;i<n;i++)
    {
        if((s[i]=="++X")||(s[i]=="X++"))
        {
            x=x+1;
        }
        else
        {
            x=x-1;
        }
    }
    cout<<x<<endl;

}
