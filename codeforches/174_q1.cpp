#include<iostream>
#include<cmath>
using namespace std;
bool is_prime(int i,int p)
{
    double x,j;
    x=i%p;
    for(j=1;j<p-1;j++)
    {
        if(fmod((pow(x,j)-1),p)==0)
        {
            return false;
        }
    }
    if(fmod((pow(x,p-1)-1),p)==0)
    {
        return true;
    }
    return false;
}
int main()
{
    int i,p,count=0;
    cin>>p;
    for(i=1;i<=p;i++)
    {
        if(is_prime(i,p)==true)
        {
                count=count+1;
        }
    }
    cout<<count;
}
