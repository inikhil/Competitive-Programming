#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main(){
    string s,t;
    int m,n=0;
    cin>>s>>t;
    while(s.find(t)!=string::npos){
        m=s.find(t);
        cout<<n+m<<" ";
        n=n+m+1;
        s=s.substr(m+1);
    }
}
