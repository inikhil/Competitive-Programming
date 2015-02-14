#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;

char c[10][5]={"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};

void print(vector<char>b ){
    int i;
    for(i=0;i<b.size();i++){
        cout<<b[i];
    }
    cout<<endl;
}

void solve(int *a,int st,int en,vector<char> b){
    int i;
    if(st==en){
        print(b);
        return;
    }
    for(i=0;i<strlen(c[a[st]]);i++){
        b.push_back(c[a[st]][i]);
        solve(a,st+1,en,b);
        b.pop_back();
        if (a[st] == 0 || a[st] == 1)
            return;
    }
}

int main(){
    int n;
    int i;
    cin>>n;
    int *a=new int[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    vector<char> b;
    solve(a,0,n,b);

}
