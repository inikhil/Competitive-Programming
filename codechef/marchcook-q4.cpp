#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
    char t;
    int i,m=1;
    vector<char> c;
    while(m!=0)
    {
        cin>>t;
        if(atoi(t)==13)
            m=0;
        c.push_back(t);
    }
    for(i=0;i<c.size();i++)
    {
        cout<<c[i];
    }
}
