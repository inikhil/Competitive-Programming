#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int x,y,m=-1,r;
    cin>>x;
    cin>>y;
    int a[2];
    a[0]=x;
    a[1]=y;
    if((x==1)&&(y==0))
    {
        return 0;
    }
    r=sqrt(x*x+y*y);
    return r+1;

}
