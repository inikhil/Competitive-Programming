#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main(){
    string s;cin>>s;
    int i,t,p,q,cnt,j;
    int n=s.length();
    int nt;cin>>nt;
    long long f;
    int r;
    long long *a=new long long[n];
    while(nt--){
        for(i=0;i<n;i++){a[i]=0;}
        cin>>p>>q;cnt=0;
        for(i=n-1;i>=0;i--){
            t=1;r=s[i]-'0';
            for(j=n-1-i;j>=0;j--){
                f=a[j];
                r=(long long)r*t;
                a[j]=(long long)r%p;
                r=a[j];
                a[j]=(long long)f+a[j];
                a[j]=(long long)a[j]%p;
                t=10;
                if(a[j]==q){cnt++;}
                //cout<<a[j]<<" ";
            }
        }
        cout<<cnt<<endl;
    }
}
