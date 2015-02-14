#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,i,j,t,sum=0;
    long long int k;
    double m;
    scanf("%d",&n);
    scanf("%lld",&k);
    long long int **a=new long long int*[n];
    for(i=0;i<n;i++){a[i]=new long long int[n];}
    for(i=0;i<n;i++){for(j=0;j<n;j++){a[i][j]=0;}}
    for(i=0;i<n;i++){scanf("%lld",&a[i][i]);}
    t=1;
    while(t!=n){
        for(i=0,j=t;i<n-t;i++,j++){
            a[i][j]=a[i+1][j]+a[i][j-1]-a[i+1][j-1];
        }
        t++;
    }
   // for(i=0;i<n;i++){for(j=0;j<n;j++){cout<<a[i][j]<<" ";}cout<<"\n";}
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            t=j-i+1;
            m=(double) a[i][j]/t;//cout<<m<<" ";
            if(m>=k){sum++;}
        }
    }
    printf("%d\n",sum);
}
