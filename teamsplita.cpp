#include<iostream>
#include<cstdio>
using namespace std;
void solve(){
    int n,a,b,c,d,m,i,k,kk,ans=0,s1,s2,tt,p,q,r;
    long long t;
    scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
    m=1000000;
    int *ss=new int[m];
    int *s=new int[m];
    s1=d;k=d;ss[s1]=1;
    for(i=1;i<n;i++){
        t=(long long)s1*s1;t=t%m;
        t=(long long)t*a;t=t%m;tt=s1*b;
        s2=(t+tt%m+c)%m;//cout<<s2<<" ";
        k=max(k,s2);
        s[s1]=s2;
        if(ss[s2]==1){
            p=n-1-i;
            q=s[s2];
            while(q!=s2){r++;q=s[q];}
        }
        else{ss[s2]=1;}
        //if(s1==s2){if((n-i)%2==0){ss[s2]=(ss[s2]+1)%2;}break;}
        s1=s2;
    }
    kk=1;
    for(i=k;i>=0;i--){
        if(ss[i]==1){
            if(kk==1){ans=ans+i;kk=0;}
            else{ans=ans-i;kk=1;}
        }
    }
    printf("%d\n",ans);
}
int main(){
    int nt;
    scanf("%d",&nt);
    while(nt--){solve();}
}

