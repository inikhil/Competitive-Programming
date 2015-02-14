#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
    int i,cnt=0;
    string a,b,c;
    int *p=new int[256];
    int *q=new int[256];
    int *r=new int[256];
    cin>>a>>b>>c;
    for(i=0;i<a.length();i++){p[a[i]]=1;}
    for(i=0;i<b.length();i++){q[b[i]]=1;}
    for(i=0;i<c.length();i++){r[c[i]]=1;}
    for(i=0;i<256;i++){
        //if(p[i]!=0 && p[i]==q[i] && p[i]==r[i]){cnt++;}
        cout<<p[i]<<" ";
    }
    cout<<cnt<<endl;
}
