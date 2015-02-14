#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

int main(){
    int x;
    int y=7;
    cin>>x;
    cout<< (x ^ y)<<endl;;
    int t;
    vector<int> a;
    while(x!=0){
        a.push_back(x%2);
        x=x/2;
    }
    while(a.size()>0){
        t=a.back();
        a.pop_back();
        if(t==1){cout<<0;}
        else{cout<<1;}
    }
}
