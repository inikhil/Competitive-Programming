#include<iostream>
#include<cstdio>
#include<list>
#include<cstring>
#include<algorithm>
using namespace std;

long long int* solve(){
    long long int *a=new long long int[100001];
    int cnt2,cnt3,cnt5,cnt7,m,i;
    long long t,tot;
    a[0]=0;a[1]=1;a[2]=2;
    for(i=3;i<=100000;i++){
        cnt2=0;cnt3=0;cnt5=0;cnt7=0;tot=0;
        m=i;
        while(m%2==0){cnt2++;m=m/2;}
        m=i;
        while(m%3==0){cnt3++;m=m/3;}
        m=i;
        while(m%5==0){cnt5++;m=m/5;}
        m=i;
        while(m%7==0){cnt7++;m=m/7;}
        tot+=max(cnt2,cnt3);
        if(cnt2==0){cnt2+=1;}
        if(cnt3==0){cnt3+=1;}
        if(cnt5==0){cnt5+=1;}
        if(cnt7==0){cnt7+=1;}
        tot+=(long long)cnt2*cnt3*cnt5*cnt7;
        a[i]=a[i-1]+tot;
        a[i]=a[i]%1000000007;
    }
    return a;
}

int main(){
    int nt,n,k;
    long long *a;
    a=solve();
    cin>>nt;
    while(nt--){
        cin>>n>>k;
        if(n>=k){cout<<a[k]<<endl;}
        else if(n==1){cout<<k<<endl;}
        else{cout<<a[k-n]<<endl;}
    }
}
