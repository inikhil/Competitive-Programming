#include<iostream>
#include<vector>
using namespace std;
bool is_abundant(int n)
{
    int i,cunt=1;
    for(i=2;i<=n/2;i++){
        if(n%i==0){
            cunt+=i;
        }
    }
    if(n<cunt){
        return true;
    }
    return false;
}
int main(){
    int *a= new int[28123];
    int *b= new int[28122];
    int i,m=0,t=0,j=0,k=0,g,l=0;
    for(i=10;i<28123;i++){
        if(is_abundant(i)==true){
            a[m]=i;
            m++;
        }
    }
    for(i=0;i<28122;i++){
        b[i]=0;
    }
    for(i=0;i<3800;i++){
        for(j=i;j<m;j++){
            t=a[i]+a[j];
            if(t<28123){
                b[t-1]=1;
            }
        }
    }
    m=0;
    for(i=0;i<28122;i++){
        if(b[i]==0){
            m=m+i+1;
        }
    }
    cout<<m<<" ";
}
