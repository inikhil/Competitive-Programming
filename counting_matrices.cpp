#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int fact(int n,int *a){
    int i,cnt=0,m;
    double t=sqrt(n);
    t=t-(int)t;
    if(n==1){return 1;}
    else if(n==2){return 2;}
    else if(n==3){return 2;}
    else if(t==0){
        for(i=1;i<sqrt(n/2);i++){
            if(n%i==0){cnt++;}
        }
        return cnt*2+1;
    }
    else{
        m=ceil(n/2);
        for(i=1;i<=sqrt(n);i++){
            if(n%i==0){cnt++;}
        }
        return cnt*2;
    }
}

int main(){
    int i,j,t,nt,n,m;
    long long ans;
    int *a=new int[1251];
    for(i=0;i<=1250;i++){a[i]=i*i;}
    t=a[1250];
    int *b=new int[t];b[0]=0;
    for(i=1;i<10;i++){
        b[i]=fact(i+1,a);
        //cout<<b[i]<<" ";
    }
    //for(i=0;i<t;i++){cout<<i+1<<" "<<b[i]<<endl;}
    for(i=1;i<10;i++){
        b[i]=b[i-1]+b[i];
    }
    scanf("%d",&nt);
    while(nt--){
        scanf("%d",&n);ans=0;i=1;
        m=ceil(n/2)*floor(n/2);
        cout<<m-1<<" ";
        cout<<b[m-2]<<" ";
        while(true){
            if(m<=a[i]){break;}
            ans+=2*b[m-a[i]-1];cout<<ans<<" ";
            i++;
        }
        printf("%lld\n",ans);
    }
}
