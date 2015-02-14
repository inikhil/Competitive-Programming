#include <stdio.h>
#include <iostream>
using namespace std;

int dst(int i,int j,int n,int m)
{
i = i<(n-i-1) ? i : n-i-1;
j = j<(m-j-1) ? j : m-j-1;
return i<j?i:j;

}
void disp(int n,int m)
{
int i,j;
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
printf("%2c",dst(i,j,n,m)%2?'O':'X');
printf("\n");
}
}

int main()
{
int x,y;
cin>>x>>y;
disp(x,y);
return 0;
}
