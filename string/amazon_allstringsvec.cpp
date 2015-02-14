#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

void print(vector<char>b ,int k){
    int i;
    for(i=0;i<=k;i++){
        cout<<b[i];
    }
    cout<<endl;
}

void solve(char *a, int m,int n, int k,vector<char> b){
    int i;
    if(m>k){
        print(b,k);
        return;
    }
    for(i=0;i<n;i++){
        b.push_back(a[i]);
        solve(a,m+1,n,k,b);
        b.pop_back();
    }
}


int main(){
    int n,k,i;
    cin>>n>>k;
    char *a=new char[n];
    for(i=0;i<n;i++){cin>>a[i];}
    vector<char> b;
    solve(a,0,n,k-1,b);
}

