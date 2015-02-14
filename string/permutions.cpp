#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    sort(s.begin(),s.end());
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
}
