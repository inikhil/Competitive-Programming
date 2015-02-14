#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length()){cout<<"False";return 0;}
    s1=s1+s1;
    //cout<<s1.find(s2);
    if(s1.find(s2)!=-1){cout<<"TRUE";}
    else{cout<<"False";}
}

