#include<iostream>
using namespace std;
int main()
{
    int a[100];
    int n,i=0,j;
    while(n!=42)
    {
        cin>>n;
        a[i]=n;
        i++;
    }
    cin>>n;
    j=i-1;
    for(i=0;i<j;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
