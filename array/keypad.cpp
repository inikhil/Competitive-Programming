#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int c[]={2,22,222,3,33,333,4,44,444,5,55,555,6,66,666,7,77,777,7777,8,88,888,9,99,999,9999};

void print(vector<int> b){
    int i;
    for(i=b.size()-1;i>=0;i--){
        cout<<b[i];
    }
    cout<<"\n";
}

void solve(vector<int> a,vector<int> b,int m){
    if(m<0){
        print(b);
        return;
    }
    if(m==0){
        b.push_back(c[a[0]]);
        print(b);
        return;
    }
    else{
        b.push_back(c[a[m]]);
        solve(a,b,m-1);
        if(a[m]==a[m-1]){

        }
    }
}

int main(){
    int nt,n,t;
    cin>>nt;
    while(nt--){
        cin>>n;
        vector<int> a;
        vector<char> b;
        while(n!=0){
            a.push_back(n%10);
            n=n/10;
        }
        t=a.size();
        solve(a,b,t-1);
    }
}
