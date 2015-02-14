#include<iostream>
using namespace std;
int main()
{
    int test,i,n,m,j,k;
    cout<<"Input total no of test cases : ";
    cin>>test;
    for(i=1;i<test;i++)
    {
        cin>>n;
        cin>>m;
        int a[m][2];
        int c[n];
        for(j=0;j<m;j++)
        {
            for(k=0;k<2;k++)
            {
                cin>>a[j][k];
            }
        }
    }
    return 0;

}
