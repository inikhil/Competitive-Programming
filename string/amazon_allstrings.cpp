#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

void print(char *b ,int k){
    int i;
    for(i=0;i<=k;i++){
        cout<<b[i];
    }
    cout<<endl;
}

void solve(char *a, int m,int n, int k,char* b){
    int i;
    if(m>k){
        print(b,k);
        return;
    }
    for(i=0;i<n;i++){
        b[m]=a[i];
        solve(a,m+1,n,k,b);
    }
}


int main(){
    int n,k,i;
    cin>>n>>k;
    char *a=new char[n];
    for(i=0;i<n;i++){cin>>a[i];}
    char *b=new char[k];
    solve(a,0,n,k-1,b);
}
