#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int main(){
    int n,m,l,i,j,i1,j1;
    long long int sum1=0,sum2=0,ans;
    scanf("%d %d",&n,&m);
    long long int **a=new long long int*[n];
    for(i=0;i<n;i++){a[i]=new long long int[m];}
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){scanf("%lld",&a[i][j]);}
    }
    //cout<<a[0][0]<<endl;
    scanf("%d",&l);
    while(l--){
        scanf("%d %d",&i1,&j1);
        if(i1>0 && i1<=n){
            if(j1>0 && j1<=m){if(sum1!=-1){sum1+=a[i1-1][j1-1];}}
            else{sum1=-1;}
        }
        else{sum1=-1;}
        if(j1>0 && j1<=n){
            if(i1>0 && i1<=m){if(sum2!=-1){sum2+=a[j1-1][i1-1];}}
            else{sum2=-1;}
        }
        else{sum2=-1;}
        //cout<<sum1<<endl;//<<sum2<<endl;
    }

    ans=max(sum1,sum2);
    printf("%lld\n",ans);
}
